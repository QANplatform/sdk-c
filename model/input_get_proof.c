#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_get_proof.h"



input_get_proof_t *input_get_proof_create(
    char *schema,
    char *address,
    char *block_number,
    list_t *storage_keys
    ) {
    input_get_proof_t *input_get_proof_local_var = malloc(sizeof(input_get_proof_t));
    if (!input_get_proof_local_var) {
        return NULL;
    }
    input_get_proof_local_var->schema = schema;
    input_get_proof_local_var->address = address;
    input_get_proof_local_var->block_number = block_number;
    input_get_proof_local_var->storage_keys = storage_keys;

    return input_get_proof_local_var;
}


void input_get_proof_free(input_get_proof_t *input_get_proof) {
    if(NULL == input_get_proof){
        return ;
    }
    listEntry_t *listEntry;
    if (input_get_proof->schema) {
        free(input_get_proof->schema);
        input_get_proof->schema = NULL;
    }
    if (input_get_proof->address) {
        free(input_get_proof->address);
        input_get_proof->address = NULL;
    }
    if (input_get_proof->block_number) {
        free(input_get_proof->block_number);
        input_get_proof->block_number = NULL;
    }
    if (input_get_proof->storage_keys) {
        list_ForEach(listEntry, input_get_proof->storage_keys) {
            free(listEntry->data);
        }
        list_freeList(input_get_proof->storage_keys);
        input_get_proof->storage_keys = NULL;
    }
    free(input_get_proof);
}

cJSON *input_get_proof_convertToJSON(input_get_proof_t *input_get_proof) {
    cJSON *item = cJSON_CreateObject();

    // input_get_proof->schema
    if(input_get_proof->schema) {
    if(cJSON_AddStringToObject(item, "$schema", input_get_proof->schema) == NULL) {
    goto fail; //String
    }
    }


    // input_get_proof->address
    if (!input_get_proof->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Address", input_get_proof->address) == NULL) {
    goto fail; //String
    }


    // input_get_proof->block_number
    if(input_get_proof->block_number) {
    if(cJSON_AddStringToObject(item, "BlockNumber", input_get_proof->block_number) == NULL) {
    goto fail; //String
    }
    }


    // input_get_proof->storage_keys
    if (!input_get_proof->storage_keys) {
        goto fail;
    }
    cJSON *storage_keys = cJSON_AddArrayToObject(item, "StorageKeys");
    if(storage_keys == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *storage_keysListEntry;
    list_ForEach(storage_keysListEntry, input_get_proof->storage_keys) {
    if(cJSON_AddStringToObject(storage_keys, "", (char*)storage_keysListEntry->data) == NULL)
    {
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

input_get_proof_t *input_get_proof_parseFromJSON(cJSON *input_get_proofJSON){

    input_get_proof_t *input_get_proof_local_var = NULL;

    // define the local list for input_get_proof->storage_keys
    list_t *storage_keysList = NULL;

    // input_get_proof->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(input_get_proofJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // input_get_proof->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(input_get_proofJSON, "Address");
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // input_get_proof->block_number
    cJSON *block_number = cJSON_GetObjectItemCaseSensitive(input_get_proofJSON, "BlockNumber");
    if (block_number) { 
    if(!cJSON_IsString(block_number) && !cJSON_IsNull(block_number))
    {
    goto end; //String
    }
    }

    // input_get_proof->storage_keys
    cJSON *storage_keys = cJSON_GetObjectItemCaseSensitive(input_get_proofJSON, "StorageKeys");
    if (!storage_keys) {
        goto end;
    }

    
    cJSON *storage_keys_local = NULL;
    if(!cJSON_IsArray(storage_keys)) {
        goto end;//primitive container
    }
    storage_keysList = list_createList();

    cJSON_ArrayForEach(storage_keys_local, storage_keys)
    {
        if(!cJSON_IsString(storage_keys_local))
        {
            goto end;
        }
        list_addElement(storage_keysList , strdup(storage_keys_local->valuestring));
    }


    input_get_proof_local_var = input_get_proof_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(address->valuestring),
        block_number && !cJSON_IsNull(block_number) ? strdup(block_number->valuestring) : NULL,
        storage_keysList
        );

    return input_get_proof_local_var;
end:
    if (storage_keysList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, storage_keysList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(storage_keysList);
        storage_keysList = NULL;
    }
    return NULL;

}
