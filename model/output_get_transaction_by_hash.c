#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_get_transaction_by_hash.h"



output_get_transaction_by_hash_t *output_get_transaction_by_hash_create(
    char *schema,
    response_transaction_t *transaction
    ) {
    output_get_transaction_by_hash_t *output_get_transaction_by_hash_local_var = malloc(sizeof(output_get_transaction_by_hash_t));
    if (!output_get_transaction_by_hash_local_var) {
        return NULL;
    }
    output_get_transaction_by_hash_local_var->schema = schema;
    output_get_transaction_by_hash_local_var->transaction = transaction;

    return output_get_transaction_by_hash_local_var;
}


void output_get_transaction_by_hash_free(output_get_transaction_by_hash_t *output_get_transaction_by_hash) {
    if(NULL == output_get_transaction_by_hash){
        return ;
    }
    listEntry_t *listEntry;
    if (output_get_transaction_by_hash->schema) {
        free(output_get_transaction_by_hash->schema);
        output_get_transaction_by_hash->schema = NULL;
    }
    if (output_get_transaction_by_hash->transaction) {
        response_transaction_free(output_get_transaction_by_hash->transaction);
        output_get_transaction_by_hash->transaction = NULL;
    }
    free(output_get_transaction_by_hash);
}

cJSON *output_get_transaction_by_hash_convertToJSON(output_get_transaction_by_hash_t *output_get_transaction_by_hash) {
    cJSON *item = cJSON_CreateObject();

    // output_get_transaction_by_hash->schema
    if(output_get_transaction_by_hash->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_get_transaction_by_hash->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_get_transaction_by_hash->transaction
    if (!output_get_transaction_by_hash->transaction) {
        goto fail;
    }
    cJSON *transaction_local_JSON = response_transaction_convertToJSON(output_get_transaction_by_hash->transaction);
    if(transaction_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "Transaction", transaction_local_JSON);
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

output_get_transaction_by_hash_t *output_get_transaction_by_hash_parseFromJSON(cJSON *output_get_transaction_by_hashJSON){

    output_get_transaction_by_hash_t *output_get_transaction_by_hash_local_var = NULL;

    // define the local variable for output_get_transaction_by_hash->transaction
    response_transaction_t *transaction_local_nonprim = NULL;

    // output_get_transaction_by_hash->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_get_transaction_by_hashJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_get_transaction_by_hash->transaction
    cJSON *transaction = cJSON_GetObjectItemCaseSensitive(output_get_transaction_by_hashJSON, "Transaction");
    if (!transaction) {
        goto end;
    }

    
    transaction_local_nonprim = response_transaction_parseFromJSON(transaction); //nonprimitive


    output_get_transaction_by_hash_local_var = output_get_transaction_by_hash_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        transaction_local_nonprim
        );

    return output_get_transaction_by_hash_local_var;
end:
    if (transaction_local_nonprim) {
        response_transaction_free(transaction_local_nonprim);
        transaction_local_nonprim = NULL;
    }
    return NULL;

}
