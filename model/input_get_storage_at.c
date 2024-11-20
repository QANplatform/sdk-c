#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_get_storage_at.h"



input_get_storage_at_t *input_get_storage_at_create(
    char *schema,
    char *address,
    char *block_number,
    char *position
    ) {
    input_get_storage_at_t *input_get_storage_at_local_var = malloc(sizeof(input_get_storage_at_t));
    if (!input_get_storage_at_local_var) {
        return NULL;
    }
    input_get_storage_at_local_var->schema = schema;
    input_get_storage_at_local_var->address = address;
    input_get_storage_at_local_var->block_number = block_number;
    input_get_storage_at_local_var->position = position;

    return input_get_storage_at_local_var;
}


void input_get_storage_at_free(input_get_storage_at_t *input_get_storage_at) {
    if(NULL == input_get_storage_at){
        return ;
    }
    listEntry_t *listEntry;
    if (input_get_storage_at->schema) {
        free(input_get_storage_at->schema);
        input_get_storage_at->schema = NULL;
    }
    if (input_get_storage_at->address) {
        free(input_get_storage_at->address);
        input_get_storage_at->address = NULL;
    }
    if (input_get_storage_at->block_number) {
        free(input_get_storage_at->block_number);
        input_get_storage_at->block_number = NULL;
    }
    if (input_get_storage_at->position) {
        free(input_get_storage_at->position);
        input_get_storage_at->position = NULL;
    }
    free(input_get_storage_at);
}

cJSON *input_get_storage_at_convertToJSON(input_get_storage_at_t *input_get_storage_at) {
    cJSON *item = cJSON_CreateObject();

    // input_get_storage_at->schema
    if(input_get_storage_at->schema) {
    if(cJSON_AddStringToObject(item, "$schema", input_get_storage_at->schema) == NULL) {
    goto fail; //String
    }
    }


    // input_get_storage_at->address
    if (!input_get_storage_at->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Address", input_get_storage_at->address) == NULL) {
    goto fail; //String
    }


    // input_get_storage_at->block_number
    if (!input_get_storage_at->block_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "BlockNumber", input_get_storage_at->block_number) == NULL) {
    goto fail; //String
    }


    // input_get_storage_at->position
    if (!input_get_storage_at->position) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Position", input_get_storage_at->position) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

input_get_storage_at_t *input_get_storage_at_parseFromJSON(cJSON *input_get_storage_atJSON){

    input_get_storage_at_t *input_get_storage_at_local_var = NULL;

    // input_get_storage_at->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(input_get_storage_atJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // input_get_storage_at->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(input_get_storage_atJSON, "Address");
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // input_get_storage_at->block_number
    cJSON *block_number = cJSON_GetObjectItemCaseSensitive(input_get_storage_atJSON, "BlockNumber");
    if (!block_number) {
        goto end;
    }

    
    if(!cJSON_IsString(block_number))
    {
    goto end; //String
    }

    // input_get_storage_at->position
    cJSON *position = cJSON_GetObjectItemCaseSensitive(input_get_storage_atJSON, "Position");
    if (!position) {
        goto end;
    }

    
    if(!cJSON_IsString(position))
    {
    goto end; //String
    }


    input_get_storage_at_local_var = input_get_storage_at_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(address->valuestring),
        strdup(block_number->valuestring),
        strdup(position->valuestring)
        );

    return input_get_storage_at_local_var;
end:
    return NULL;

}
