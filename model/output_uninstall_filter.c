#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_uninstall_filter.h"



output_uninstall_filter_t *output_uninstall_filter_create(
    char *schema,
    int result
    ) {
    output_uninstall_filter_t *output_uninstall_filter_local_var = malloc(sizeof(output_uninstall_filter_t));
    if (!output_uninstall_filter_local_var) {
        return NULL;
    }
    output_uninstall_filter_local_var->schema = schema;
    output_uninstall_filter_local_var->result = result;

    return output_uninstall_filter_local_var;
}


void output_uninstall_filter_free(output_uninstall_filter_t *output_uninstall_filter) {
    if(NULL == output_uninstall_filter){
        return ;
    }
    listEntry_t *listEntry;
    if (output_uninstall_filter->schema) {
        free(output_uninstall_filter->schema);
        output_uninstall_filter->schema = NULL;
    }
    free(output_uninstall_filter);
}

cJSON *output_uninstall_filter_convertToJSON(output_uninstall_filter_t *output_uninstall_filter) {
    cJSON *item = cJSON_CreateObject();

    // output_uninstall_filter->schema
    if(output_uninstall_filter->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_uninstall_filter->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_uninstall_filter->result
    if (!output_uninstall_filter->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "Result", output_uninstall_filter->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_uninstall_filter_t *output_uninstall_filter_parseFromJSON(cJSON *output_uninstall_filterJSON){

    output_uninstall_filter_t *output_uninstall_filter_local_var = NULL;

    // output_uninstall_filter->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_uninstall_filterJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_uninstall_filter->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(output_uninstall_filterJSON, "Result");
    if (!result) {
        goto end;
    }

    
    if(!cJSON_IsBool(result))
    {
    goto end; //Bool
    }


    output_uninstall_filter_local_var = output_uninstall_filter_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        result->valueint
        );

    return output_uninstall_filter_local_var;
end:
    return NULL;

}
