#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_syncing.h"



output_syncing_t *output_syncing_create(
    char *schema,
    sync_status_t *sync_status
    ) {
    output_syncing_t *output_syncing_local_var = malloc(sizeof(output_syncing_t));
    if (!output_syncing_local_var) {
        return NULL;
    }
    output_syncing_local_var->schema = schema;
    output_syncing_local_var->sync_status = sync_status;

    return output_syncing_local_var;
}


void output_syncing_free(output_syncing_t *output_syncing) {
    if(NULL == output_syncing){
        return ;
    }
    listEntry_t *listEntry;
    if (output_syncing->schema) {
        free(output_syncing->schema);
        output_syncing->schema = NULL;
    }
    if (output_syncing->sync_status) {
        sync_status_free(output_syncing->sync_status);
        output_syncing->sync_status = NULL;
    }
    free(output_syncing);
}

cJSON *output_syncing_convertToJSON(output_syncing_t *output_syncing) {
    cJSON *item = cJSON_CreateObject();

    // output_syncing->schema
    if(output_syncing->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_syncing->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_syncing->sync_status
    if (!output_syncing->sync_status) {
        goto fail;
    }
    cJSON *sync_status_local_JSON = sync_status_convertToJSON(output_syncing->sync_status);
    if(sync_status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "SyncStatus", sync_status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_syncing_t *output_syncing_parseFromJSON(cJSON *output_syncingJSON){

    output_syncing_t *output_syncing_local_var = NULL;

    // define the local variable for output_syncing->sync_status
    sync_status_t *sync_status_local_nonprim = NULL;

    // output_syncing->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_syncingJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_syncing->sync_status
    cJSON *sync_status = cJSON_GetObjectItemCaseSensitive(output_syncingJSON, "SyncStatus");
    if (!sync_status) {
        goto end;
    }

    
    sync_status_local_nonprim = sync_status_parseFromJSON(sync_status); //nonprimitive


    output_syncing_local_var = output_syncing_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        sync_status_local_nonprim
        );

    return output_syncing_local_var;
end:
    if (sync_status_local_nonprim) {
        sync_status_free(sync_status_local_nonprim);
        sync_status_local_nonprim = NULL;
    }
    return NULL;

}
