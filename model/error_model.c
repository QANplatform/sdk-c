#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "error_model.h"



error_model_t *error_model_create(
    char *schema,
    char *detail,
    list_t *errors,
    char *instance,
    long status,
    char *title,
    char *type
    ) {
    error_model_t *error_model_local_var = malloc(sizeof(error_model_t));
    if (!error_model_local_var) {
        return NULL;
    }
    error_model_local_var->schema = schema;
    error_model_local_var->detail = detail;
    error_model_local_var->errors = errors;
    error_model_local_var->instance = instance;
    error_model_local_var->status = status;
    error_model_local_var->title = title;
    error_model_local_var->type = type;

    return error_model_local_var;
}


void error_model_free(error_model_t *error_model) {
    if(NULL == error_model){
        return ;
    }
    listEntry_t *listEntry;
    if (error_model->schema) {
        free(error_model->schema);
        error_model->schema = NULL;
    }
    if (error_model->detail) {
        free(error_model->detail);
        error_model->detail = NULL;
    }
    if (error_model->errors) {
        list_ForEach(listEntry, error_model->errors) {
            error_detail_free(listEntry->data);
        }
        list_freeList(error_model->errors);
        error_model->errors = NULL;
    }
    if (error_model->instance) {
        free(error_model->instance);
        error_model->instance = NULL;
    }
    if (error_model->title) {
        free(error_model->title);
        error_model->title = NULL;
    }
    if (error_model->type) {
        free(error_model->type);
        error_model->type = NULL;
    }
    free(error_model);
}

cJSON *error_model_convertToJSON(error_model_t *error_model) {
    cJSON *item = cJSON_CreateObject();

    // error_model->schema
    if(error_model->schema) {
    if(cJSON_AddStringToObject(item, "$schema", error_model->schema) == NULL) {
    goto fail; //String
    }
    }


    // error_model->detail
    if(error_model->detail) {
    if(cJSON_AddStringToObject(item, "detail", error_model->detail) == NULL) {
    goto fail; //String
    }
    }


    // error_model->errors
    if(error_model->errors) {
    cJSON *errors = cJSON_AddArrayToObject(item, "errors");
    if(errors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *errorsListEntry;
    if (error_model->errors) {
    list_ForEach(errorsListEntry, error_model->errors) {
    cJSON *itemLocal = error_detail_convertToJSON(errorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(errors, itemLocal);
    }
    }
    }


    // error_model->instance
    if(error_model->instance) {
    if(cJSON_AddStringToObject(item, "instance", error_model->instance) == NULL) {
    goto fail; //String
    }
    }


    // error_model->status
    if(error_model->status) {
    if(cJSON_AddNumberToObject(item, "status", error_model->status) == NULL) {
    goto fail; //Numeric
    }
    }


    // error_model->title
    if(error_model->title) {
    if(cJSON_AddStringToObject(item, "title", error_model->title) == NULL) {
    goto fail; //String
    }
    }


    // error_model->type
    if(error_model->type) {
    if(cJSON_AddStringToObject(item, "type", error_model->type) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

error_model_t *error_model_parseFromJSON(cJSON *error_modelJSON){

    error_model_t *error_model_local_var = NULL;

    // define the local list for error_model->errors
    list_t *errorsList = NULL;

    // error_model->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(error_modelJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // error_model->detail
    cJSON *detail = cJSON_GetObjectItemCaseSensitive(error_modelJSON, "detail");
    if (detail) { 
    if(!cJSON_IsString(detail) && !cJSON_IsNull(detail))
    {
    goto end; //String
    }
    }

    // error_model->errors
    cJSON *errors = cJSON_GetObjectItemCaseSensitive(error_modelJSON, "errors");
    if (errors) { 
    cJSON *errors_local_nonprimitive = NULL;
    if(!cJSON_IsArray(errors)){
        goto end; //nonprimitive container
    }

    errorsList = list_createList();

    cJSON_ArrayForEach(errors_local_nonprimitive,errors )
    {
        if(!cJSON_IsObject(errors_local_nonprimitive)){
            goto end;
        }
        error_detail_t *errorsItem = error_detail_parseFromJSON(errors_local_nonprimitive);

        list_addElement(errorsList, errorsItem);
    }
    }

    // error_model->instance
    cJSON *instance = cJSON_GetObjectItemCaseSensitive(error_modelJSON, "instance");
    if (instance) { 
    if(!cJSON_IsString(instance) && !cJSON_IsNull(instance))
    {
    goto end; //String
    }
    }

    // error_model->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(error_modelJSON, "status");
    if (status) { 
    if(!cJSON_IsNumber(status))
    {
    goto end; //Numeric
    }
    }

    // error_model->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(error_modelJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // error_model->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(error_modelJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }


    error_model_local_var = error_model_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        detail && !cJSON_IsNull(detail) ? strdup(detail->valuestring) : NULL,
        errors ? errorsList : NULL,
        instance && !cJSON_IsNull(instance) ? strdup(instance->valuestring) : NULL,
        status ? status->valuedouble : 0,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL
        );

    return error_model_local_var;
end:
    if (errorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, errorsList) {
            error_detail_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(errorsList);
        errorsList = NULL;
    }
    return NULL;

}
