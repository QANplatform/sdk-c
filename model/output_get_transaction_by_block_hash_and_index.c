#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_get_transaction_by_block_hash_and_index.h"



output_get_transaction_by_block_hash_and_index_t *output_get_transaction_by_block_hash_and_index_create(
    char *schema,
    response_transaction_t *transaction
    ) {
    output_get_transaction_by_block_hash_and_index_t *output_get_transaction_by_block_hash_and_index_local_var = malloc(sizeof(output_get_transaction_by_block_hash_and_index_t));
    if (!output_get_transaction_by_block_hash_and_index_local_var) {
        return NULL;
    }
    output_get_transaction_by_block_hash_and_index_local_var->schema = schema;
    output_get_transaction_by_block_hash_and_index_local_var->transaction = transaction;

    return output_get_transaction_by_block_hash_and_index_local_var;
}


void output_get_transaction_by_block_hash_and_index_free(output_get_transaction_by_block_hash_and_index_t *output_get_transaction_by_block_hash_and_index) {
    if(NULL == output_get_transaction_by_block_hash_and_index){
        return ;
    }
    listEntry_t *listEntry;
    if (output_get_transaction_by_block_hash_and_index->schema) {
        free(output_get_transaction_by_block_hash_and_index->schema);
        output_get_transaction_by_block_hash_and_index->schema = NULL;
    }
    if (output_get_transaction_by_block_hash_and_index->transaction) {
        response_transaction_free(output_get_transaction_by_block_hash_and_index->transaction);
        output_get_transaction_by_block_hash_and_index->transaction = NULL;
    }
    free(output_get_transaction_by_block_hash_and_index);
}

cJSON *output_get_transaction_by_block_hash_and_index_convertToJSON(output_get_transaction_by_block_hash_and_index_t *output_get_transaction_by_block_hash_and_index) {
    cJSON *item = cJSON_CreateObject();

    // output_get_transaction_by_block_hash_and_index->schema
    if(output_get_transaction_by_block_hash_and_index->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_get_transaction_by_block_hash_and_index->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_get_transaction_by_block_hash_and_index->transaction
    if (!output_get_transaction_by_block_hash_and_index->transaction) {
        goto fail;
    }
    cJSON *transaction_local_JSON = response_transaction_convertToJSON(output_get_transaction_by_block_hash_and_index->transaction);
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

output_get_transaction_by_block_hash_and_index_t *output_get_transaction_by_block_hash_and_index_parseFromJSON(cJSON *output_get_transaction_by_block_hash_and_indexJSON){

    output_get_transaction_by_block_hash_and_index_t *output_get_transaction_by_block_hash_and_index_local_var = NULL;

    // define the local variable for output_get_transaction_by_block_hash_and_index->transaction
    response_transaction_t *transaction_local_nonprim = NULL;

    // output_get_transaction_by_block_hash_and_index->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_get_transaction_by_block_hash_and_indexJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_get_transaction_by_block_hash_and_index->transaction
    cJSON *transaction = cJSON_GetObjectItemCaseSensitive(output_get_transaction_by_block_hash_and_indexJSON, "Transaction");
    if (!transaction) {
        goto end;
    }

    
    transaction_local_nonprim = response_transaction_parseFromJSON(transaction); //nonprimitive


    output_get_transaction_by_block_hash_and_index_local_var = output_get_transaction_by_block_hash_and_index_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        transaction_local_nonprim
        );

    return output_get_transaction_by_block_hash_and_index_local_var;
end:
    if (transaction_local_nonprim) {
        response_transaction_free(transaction_local_nonprim);
        transaction_local_nonprim = NULL;
    }
    return NULL;

}
