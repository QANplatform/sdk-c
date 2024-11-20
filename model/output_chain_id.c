#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_chain_id.h"



output_chain_id_t *output_chain_id_create(
    char *schema,
    char *chain_id
    ) {
    output_chain_id_t *output_chain_id_local_var = malloc(sizeof(output_chain_id_t));
    if (!output_chain_id_local_var) {
        return NULL;
    }
    output_chain_id_local_var->schema = schema;
    output_chain_id_local_var->chain_id = chain_id;

    return output_chain_id_local_var;
}


void output_chain_id_free(output_chain_id_t *output_chain_id) {
    if(NULL == output_chain_id){
        return ;
    }
    listEntry_t *listEntry;
    if (output_chain_id->schema) {
        free(output_chain_id->schema);
        output_chain_id->schema = NULL;
    }
    if (output_chain_id->chain_id) {
        free(output_chain_id->chain_id);
        output_chain_id->chain_id = NULL;
    }
    free(output_chain_id);
}

cJSON *output_chain_id_convertToJSON(output_chain_id_t *output_chain_id) {
    cJSON *item = cJSON_CreateObject();

    // output_chain_id->schema
    if(output_chain_id->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_chain_id->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_chain_id->chain_id
    if (!output_chain_id->chain_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ChainId", output_chain_id->chain_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_chain_id_t *output_chain_id_parseFromJSON(cJSON *output_chain_idJSON){

    output_chain_id_t *output_chain_id_local_var = NULL;

    // output_chain_id->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_chain_idJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_chain_id->chain_id
    cJSON *chain_id = cJSON_GetObjectItemCaseSensitive(output_chain_idJSON, "ChainId");
    if (!chain_id) {
        goto end;
    }

    
    if(!cJSON_IsString(chain_id))
    {
    goto end; //String
    }


    output_chain_id_local_var = output_chain_id_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(chain_id->valuestring)
        );

    return output_chain_id_local_var;
end:
    return NULL;

}
