#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "error_detail.h"



error_detail_t *error_detail_create(
    char *location,
    char *message,
    any_type_t *value
    ) {
    error_detail_t *error_detail_local_var = malloc(sizeof(error_detail_t));
    if (!error_detail_local_var) {
        return NULL;
    }
    error_detail_local_var->location = location;
    error_detail_local_var->message = message;
    error_detail_local_var->value = value;

    return error_detail_local_var;
}


void error_detail_free(error_detail_t *error_detail) {
    if(NULL == error_detail){
        return ;
    }
    listEntry_t *listEntry;
    if (error_detail->location) {
        free(error_detail->location);
        error_detail->location = NULL;
    }
    if (error_detail->message) {
        free(error_detail->message);
        error_detail->message = NULL;
    }
    if (error_detail->value) {
        _free(error_detail->value);
        error_detail->value = NULL;
    }
    free(error_detail);
}

cJSON *error_detail_convertToJSON(error_detail_t *error_detail) {
    cJSON *item = cJSON_CreateObject();

    // error_detail->location
    if(error_detail->location) {
    if(cJSON_AddStringToObject(item, "location", error_detail->location) == NULL) {
    goto fail; //String
    }
    }


    // error_detail->message
    if(error_detail->message) {
    if(cJSON_AddStringToObject(item, "message", error_detail->message) == NULL) {
    goto fail; //String
    }
    }


    // error_detail->value
    if(error_detail->value) {
    cJSON *value_local_JSON = _convertToJSON(error_detail->value);
    if(value_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "value", value_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

error_detail_t *error_detail_parseFromJSON(cJSON *error_detailJSON){

    error_detail_t *error_detail_local_var = NULL;

    // define the local variable for error_detail->value
    _t *value_local_nonprim = NULL;

    // error_detail->location
    cJSON *location = cJSON_GetObjectItemCaseSensitive(error_detailJSON, "location");
    if (location) { 
    if(!cJSON_IsString(location) && !cJSON_IsNull(location))
    {
    goto end; //String
    }
    }

    // error_detail->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(error_detailJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // error_detail->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(error_detailJSON, "value");
    if (value) { 
    value_local_nonprim = _parseFromJSON(value); //custom
    }


    error_detail_local_var = error_detail_create (
        location && !cJSON_IsNull(location) ? strdup(location->valuestring) : NULL,
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        value ? value_local_nonprim : NULL
        );

    return error_detail_local_var;
end:
    if (value_local_nonprim) {
        _free(value_local_nonprim);
        value_local_nonprim = NULL;
    }
    return NULL;

}
