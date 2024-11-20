#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_get_proof.h"



output_get_proof_t *output_get_proof_create(
    char *schema,
    char *account_proof,
    char *address,
    char *balance,
    char *code_hash,
    char *nonce,
    char *storage_hash,
    list_t *storage_proof
    ) {
    output_get_proof_t *output_get_proof_local_var = malloc(sizeof(output_get_proof_t));
    if (!output_get_proof_local_var) {
        return NULL;
    }
    output_get_proof_local_var->schema = schema;
    output_get_proof_local_var->account_proof = account_proof;
    output_get_proof_local_var->address = address;
    output_get_proof_local_var->balance = balance;
    output_get_proof_local_var->code_hash = code_hash;
    output_get_proof_local_var->nonce = nonce;
    output_get_proof_local_var->storage_hash = storage_hash;
    output_get_proof_local_var->storage_proof = storage_proof;

    return output_get_proof_local_var;
}


void output_get_proof_free(output_get_proof_t *output_get_proof) {
    if(NULL == output_get_proof){
        return ;
    }
    listEntry_t *listEntry;
    if (output_get_proof->schema) {
        free(output_get_proof->schema);
        output_get_proof->schema = NULL;
    }
    if (output_get_proof->account_proof) {
        free(output_get_proof->account_proof);
        output_get_proof->account_proof = NULL;
    }
    if (output_get_proof->address) {
        free(output_get_proof->address);
        output_get_proof->address = NULL;
    }
    if (output_get_proof->balance) {
        free(output_get_proof->balance);
        output_get_proof->balance = NULL;
    }
    if (output_get_proof->code_hash) {
        free(output_get_proof->code_hash);
        output_get_proof->code_hash = NULL;
    }
    if (output_get_proof->nonce) {
        free(output_get_proof->nonce);
        output_get_proof->nonce = NULL;
    }
    if (output_get_proof->storage_hash) {
        free(output_get_proof->storage_hash);
        output_get_proof->storage_hash = NULL;
    }
    if (output_get_proof->storage_proof) {
        list_ForEach(listEntry, output_get_proof->storage_proof) {
            response_storage_entry_free(listEntry->data);
        }
        list_freeList(output_get_proof->storage_proof);
        output_get_proof->storage_proof = NULL;
    }
    free(output_get_proof);
}

cJSON *output_get_proof_convertToJSON(output_get_proof_t *output_get_proof) {
    cJSON *item = cJSON_CreateObject();

    // output_get_proof->schema
    if(output_get_proof->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_get_proof->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_get_proof->account_proof
    if (!output_get_proof->account_proof) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "AccountProof", output_get_proof->account_proof) == NULL) {
    goto fail; //String
    }


    // output_get_proof->address
    if (!output_get_proof->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Address", output_get_proof->address) == NULL) {
    goto fail; //String
    }


    // output_get_proof->balance
    if (!output_get_proof->balance) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Balance", output_get_proof->balance) == NULL) {
    goto fail; //String
    }


    // output_get_proof->code_hash
    if (!output_get_proof->code_hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "CodeHash", output_get_proof->code_hash) == NULL) {
    goto fail; //String
    }


    // output_get_proof->nonce
    if (!output_get_proof->nonce) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Nonce", output_get_proof->nonce) == NULL) {
    goto fail; //String
    }


    // output_get_proof->storage_hash
    if (!output_get_proof->storage_hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "StorageHash", output_get_proof->storage_hash) == NULL) {
    goto fail; //String
    }


    // output_get_proof->storage_proof
    if (!output_get_proof->storage_proof) {
        goto fail;
    }
    cJSON *storage_proof = cJSON_AddArrayToObject(item, "StorageProof");
    if(storage_proof == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *storage_proofListEntry;
    if (output_get_proof->storage_proof) {
    list_ForEach(storage_proofListEntry, output_get_proof->storage_proof) {
    cJSON *itemLocal = response_storage_entry_convertToJSON(storage_proofListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(storage_proof, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_get_proof_t *output_get_proof_parseFromJSON(cJSON *output_get_proofJSON){

    output_get_proof_t *output_get_proof_local_var = NULL;

    // define the local list for output_get_proof->storage_proof
    list_t *storage_proofList = NULL;

    // output_get_proof->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_get_proofJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_get_proof->account_proof
    cJSON *account_proof = cJSON_GetObjectItemCaseSensitive(output_get_proofJSON, "AccountProof");
    if (!account_proof) {
        goto end;
    }

    
    if(!cJSON_IsString(account_proof))
    {
    goto end; //String
    }

    // output_get_proof->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(output_get_proofJSON, "Address");
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // output_get_proof->balance
    cJSON *balance = cJSON_GetObjectItemCaseSensitive(output_get_proofJSON, "Balance");
    if (!balance) {
        goto end;
    }

    
    if(!cJSON_IsString(balance))
    {
    goto end; //String
    }

    // output_get_proof->code_hash
    cJSON *code_hash = cJSON_GetObjectItemCaseSensitive(output_get_proofJSON, "CodeHash");
    if (!code_hash) {
        goto end;
    }

    
    if(!cJSON_IsString(code_hash))
    {
    goto end; //String
    }

    // output_get_proof->nonce
    cJSON *nonce = cJSON_GetObjectItemCaseSensitive(output_get_proofJSON, "Nonce");
    if (!nonce) {
        goto end;
    }

    
    if(!cJSON_IsString(nonce))
    {
    goto end; //String
    }

    // output_get_proof->storage_hash
    cJSON *storage_hash = cJSON_GetObjectItemCaseSensitive(output_get_proofJSON, "StorageHash");
    if (!storage_hash) {
        goto end;
    }

    
    if(!cJSON_IsString(storage_hash))
    {
    goto end; //String
    }

    // output_get_proof->storage_proof
    cJSON *storage_proof = cJSON_GetObjectItemCaseSensitive(output_get_proofJSON, "StorageProof");
    if (!storage_proof) {
        goto end;
    }

    
    cJSON *storage_proof_local_nonprimitive = NULL;
    if(!cJSON_IsArray(storage_proof)){
        goto end; //nonprimitive container
    }

    storage_proofList = list_createList();

    cJSON_ArrayForEach(storage_proof_local_nonprimitive,storage_proof )
    {
        if(!cJSON_IsObject(storage_proof_local_nonprimitive)){
            goto end;
        }
        response_storage_entry_t *storage_proofItem = response_storage_entry_parseFromJSON(storage_proof_local_nonprimitive);

        list_addElement(storage_proofList, storage_proofItem);
    }


    output_get_proof_local_var = output_get_proof_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(account_proof->valuestring),
        strdup(address->valuestring),
        strdup(balance->valuestring),
        strdup(code_hash->valuestring),
        strdup(nonce->valuestring),
        strdup(storage_hash->valuestring),
        storage_proofList
        );

    return output_get_proof_local_var;
end:
    if (storage_proofList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, storage_proofList) {
            response_storage_entry_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(storage_proofList);
        storage_proofList = NULL;
    }
    return NULL;

}
