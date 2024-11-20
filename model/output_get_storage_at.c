#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_get_storage_at.h"



output_get_storage_at_t *output_get_storage_at_create(
    char *schema,
    char *value
    ) {
    output_get_storage_at_t *output_get_storage_at_local_var = malloc(sizeof(output_get_storage_at_t));
    if (!output_get_storage_at_local_var) {
        return NULL;
    }
    output_get_storage_at_local_var->schema = schema;
    output_get_storage_at_local_var->value = value;

    return output_get_storage_at_local_var;
}


void output_get_storage_at_free(output_get_storage_at_t *output_get_storage_at) {
    if(NULL == output_get_storage_at){
        return ;
    }
    listEntry_t *listEntry;
    if (output_get_storage_at->schema) {
        free(output_get_storage_at->schema);
        output_get_storage_at->schema = NULL;
    }
    if (output_get_storage_at->value) {
        free(output_get_storage_at->value);
        output_get_storage_at->value = NULL;
    }
    free(output_get_storage_at);
}

cJSON *output_get_storage_at_convertToJSON(output_get_storage_at_t *output_get_storage_at) {
    cJSON *item = cJSON_CreateObject();

    // output_get_storage_at->schema
    if(output_get_storage_at->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_get_storage_at->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_get_storage_at->value
    if (!output_get_storage_at->value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Value", output_get_storage_at->value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_get_storage_at_t *output_get_storage_at_parseFromJSON(cJSON *output_get_storage_atJSON){

    output_get_storage_at_t *output_get_storage_at_local_var = NULL;

    // output_get_storage_at->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_get_storage_atJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_get_storage_at->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(output_get_storage_atJSON, "Value");
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }


    output_get_storage_at_local_var = output_get_storage_at_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(value->valuestring)
        );

    return output_get_storage_at_local_var;
end:
    return NULL;

}
