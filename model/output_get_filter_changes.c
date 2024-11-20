#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_get_filter_changes.h"



output_get_filter_changes_t *output_get_filter_changes_create(
    char *schema,
    any_type_t *result
    ) {
    output_get_filter_changes_t *output_get_filter_changes_local_var = malloc(sizeof(output_get_filter_changes_t));
    if (!output_get_filter_changes_local_var) {
        return NULL;
    }
    output_get_filter_changes_local_var->schema = schema;
    output_get_filter_changes_local_var->result = result;

    return output_get_filter_changes_local_var;
}


void output_get_filter_changes_free(output_get_filter_changes_t *output_get_filter_changes) {
    if(NULL == output_get_filter_changes){
        return ;
    }
    listEntry_t *listEntry;
    if (output_get_filter_changes->schema) {
        free(output_get_filter_changes->schema);
        output_get_filter_changes->schema = NULL;
    }
    if (output_get_filter_changes->result) {
        _free(output_get_filter_changes->result);
        output_get_filter_changes->result = NULL;
    }
    free(output_get_filter_changes);
}

cJSON *output_get_filter_changes_convertToJSON(output_get_filter_changes_t *output_get_filter_changes) {
    cJSON *item = cJSON_CreateObject();

    // output_get_filter_changes->schema
    if(output_get_filter_changes->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_get_filter_changes->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_get_filter_changes->result
    if (!output_get_filter_changes->result) {
        goto fail;
    }
    cJSON *result_local_JSON = _convertToJSON(output_get_filter_changes->result);
    if(result_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "Result", result_local_JSON);
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

output_get_filter_changes_t *output_get_filter_changes_parseFromJSON(cJSON *output_get_filter_changesJSON){

    output_get_filter_changes_t *output_get_filter_changes_local_var = NULL;

    // define the local variable for output_get_filter_changes->result
    _t *result_local_nonprim = NULL;

    // output_get_filter_changes->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_get_filter_changesJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_get_filter_changes->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(output_get_filter_changesJSON, "Result");
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = _parseFromJSON(result); //custom


    output_get_filter_changes_local_var = output_get_filter_changes_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        result_local_nonprim
        );

    return output_get_filter_changes_local_var;
end:
    if (result_local_nonprim) {
        _free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
