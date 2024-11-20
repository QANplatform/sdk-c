#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_new_filter.h"



input_new_filter_t *input_new_filter_create(
    char *schema,
    filter_object_t *filter_object
    ) {
    input_new_filter_t *input_new_filter_local_var = malloc(sizeof(input_new_filter_t));
    if (!input_new_filter_local_var) {
        return NULL;
    }
    input_new_filter_local_var->schema = schema;
    input_new_filter_local_var->filter_object = filter_object;

    return input_new_filter_local_var;
}


void input_new_filter_free(input_new_filter_t *input_new_filter) {
    if(NULL == input_new_filter){
        return ;
    }
    listEntry_t *listEntry;
    if (input_new_filter->schema) {
        free(input_new_filter->schema);
        input_new_filter->schema = NULL;
    }
    if (input_new_filter->filter_object) {
        filter_object_free(input_new_filter->filter_object);
        input_new_filter->filter_object = NULL;
    }
    free(input_new_filter);
}

cJSON *input_new_filter_convertToJSON(input_new_filter_t *input_new_filter) {
    cJSON *item = cJSON_CreateObject();

    // input_new_filter->schema
    if(input_new_filter->schema) {
    if(cJSON_AddStringToObject(item, "$schema", input_new_filter->schema) == NULL) {
    goto fail; //String
    }
    }


    // input_new_filter->filter_object
    if (!input_new_filter->filter_object) {
        goto fail;
    }
    cJSON *filter_object_local_JSON = filter_object_convertToJSON(input_new_filter->filter_object);
    if(filter_object_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "FilterObject", filter_object_local_JSON);
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

input_new_filter_t *input_new_filter_parseFromJSON(cJSON *input_new_filterJSON){

    input_new_filter_t *input_new_filter_local_var = NULL;

    // define the local variable for input_new_filter->filter_object
    filter_object_t *filter_object_local_nonprim = NULL;

    // input_new_filter->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(input_new_filterJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // input_new_filter->filter_object
    cJSON *filter_object = cJSON_GetObjectItemCaseSensitive(input_new_filterJSON, "FilterObject");
    if (!filter_object) {
        goto end;
    }

    
    filter_object_local_nonprim = filter_object_parseFromJSON(filter_object); //nonprimitive


    input_new_filter_local_var = input_new_filter_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        filter_object_local_nonprim
        );

    return input_new_filter_local_var;
end:
    if (filter_object_local_nonprim) {
        filter_object_free(filter_object_local_nonprim);
        filter_object_local_nonprim = NULL;
    }
    return NULL;

}
