#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "response_storage_entry.h"



response_storage_entry_t *response_storage_entry_create(
    char *key,
    char *proof,
    char *value
    ) {
    response_storage_entry_t *response_storage_entry_local_var = malloc(sizeof(response_storage_entry_t));
    if (!response_storage_entry_local_var) {
        return NULL;
    }
    response_storage_entry_local_var->key = key;
    response_storage_entry_local_var->proof = proof;
    response_storage_entry_local_var->value = value;

    return response_storage_entry_local_var;
}


void response_storage_entry_free(response_storage_entry_t *response_storage_entry) {
    if(NULL == response_storage_entry){
        return ;
    }
    listEntry_t *listEntry;
    if (response_storage_entry->key) {
        free(response_storage_entry->key);
        response_storage_entry->key = NULL;
    }
    if (response_storage_entry->proof) {
        free(response_storage_entry->proof);
        response_storage_entry->proof = NULL;
    }
    if (response_storage_entry->value) {
        free(response_storage_entry->value);
        response_storage_entry->value = NULL;
    }
    free(response_storage_entry);
}

cJSON *response_storage_entry_convertToJSON(response_storage_entry_t *response_storage_entry) {
    cJSON *item = cJSON_CreateObject();

    // response_storage_entry->key
    if (!response_storage_entry->key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Key", response_storage_entry->key) == NULL) {
    goto fail; //String
    }


    // response_storage_entry->proof
    if (!response_storage_entry->proof) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Proof", response_storage_entry->proof) == NULL) {
    goto fail; //String
    }


    // response_storage_entry->value
    if (!response_storage_entry->value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Value", response_storage_entry->value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

response_storage_entry_t *response_storage_entry_parseFromJSON(cJSON *response_storage_entryJSON){

    response_storage_entry_t *response_storage_entry_local_var = NULL;

    // response_storage_entry->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(response_storage_entryJSON, "Key");
    if (!key) {
        goto end;
    }

    
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }

    // response_storage_entry->proof
    cJSON *proof = cJSON_GetObjectItemCaseSensitive(response_storage_entryJSON, "Proof");
    if (!proof) {
        goto end;
    }

    
    if(!cJSON_IsString(proof))
    {
    goto end; //String
    }

    // response_storage_entry->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(response_storage_entryJSON, "Value");
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }


    response_storage_entry_local_var = response_storage_entry_create (
        strdup(key->valuestring),
        strdup(proof->valuestring),
        strdup(value->valuestring)
        );

    return response_storage_entry_local_var;
end:
    return NULL;

}
