#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_xlink_valid.h"



output_xlink_valid_t *output_xlink_valid_create(
    char *schema,
    char *validity
    ) {
    output_xlink_valid_t *output_xlink_valid_local_var = malloc(sizeof(output_xlink_valid_t));
    if (!output_xlink_valid_local_var) {
        return NULL;
    }
    output_xlink_valid_local_var->schema = schema;
    output_xlink_valid_local_var->validity = validity;

    return output_xlink_valid_local_var;
}


void output_xlink_valid_free(output_xlink_valid_t *output_xlink_valid) {
    if(NULL == output_xlink_valid){
        return ;
    }
    listEntry_t *listEntry;
    if (output_xlink_valid->schema) {
        free(output_xlink_valid->schema);
        output_xlink_valid->schema = NULL;
    }
    if (output_xlink_valid->validity) {
        free(output_xlink_valid->validity);
        output_xlink_valid->validity = NULL;
    }
    free(output_xlink_valid);
}

cJSON *output_xlink_valid_convertToJSON(output_xlink_valid_t *output_xlink_valid) {
    cJSON *item = cJSON_CreateObject();

    // output_xlink_valid->schema
    if(output_xlink_valid->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_xlink_valid->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_xlink_valid->validity
    if (!output_xlink_valid->validity) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Validity", output_xlink_valid->validity) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_xlink_valid_t *output_xlink_valid_parseFromJSON(cJSON *output_xlink_validJSON){

    output_xlink_valid_t *output_xlink_valid_local_var = NULL;

    // output_xlink_valid->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_xlink_validJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_xlink_valid->validity
    cJSON *validity = cJSON_GetObjectItemCaseSensitive(output_xlink_validJSON, "Validity");
    if (!validity) {
        goto end;
    }

    
    if(!cJSON_IsString(validity))
    {
    goto end; //String
    }


    output_xlink_valid_local_var = output_xlink_valid_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(validity->valuestring)
        );

    return output_xlink_valid_local_var;
end:
    return NULL;

}
