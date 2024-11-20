#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_get_block_transaction_count_by_hash.h"



output_get_block_transaction_count_by_hash_t *output_get_block_transaction_count_by_hash_create(
    char *schema,
    char *transaction_count
    ) {
    output_get_block_transaction_count_by_hash_t *output_get_block_transaction_count_by_hash_local_var = malloc(sizeof(output_get_block_transaction_count_by_hash_t));
    if (!output_get_block_transaction_count_by_hash_local_var) {
        return NULL;
    }
    output_get_block_transaction_count_by_hash_local_var->schema = schema;
    output_get_block_transaction_count_by_hash_local_var->transaction_count = transaction_count;

    return output_get_block_transaction_count_by_hash_local_var;
}


void output_get_block_transaction_count_by_hash_free(output_get_block_transaction_count_by_hash_t *output_get_block_transaction_count_by_hash) {
    if(NULL == output_get_block_transaction_count_by_hash){
        return ;
    }
    listEntry_t *listEntry;
    if (output_get_block_transaction_count_by_hash->schema) {
        free(output_get_block_transaction_count_by_hash->schema);
        output_get_block_transaction_count_by_hash->schema = NULL;
    }
    if (output_get_block_transaction_count_by_hash->transaction_count) {
        free(output_get_block_transaction_count_by_hash->transaction_count);
        output_get_block_transaction_count_by_hash->transaction_count = NULL;
    }
    free(output_get_block_transaction_count_by_hash);
}

cJSON *output_get_block_transaction_count_by_hash_convertToJSON(output_get_block_transaction_count_by_hash_t *output_get_block_transaction_count_by_hash) {
    cJSON *item = cJSON_CreateObject();

    // output_get_block_transaction_count_by_hash->schema
    if(output_get_block_transaction_count_by_hash->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_get_block_transaction_count_by_hash->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_get_block_transaction_count_by_hash->transaction_count
    if (!output_get_block_transaction_count_by_hash->transaction_count) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "TransactionCount", output_get_block_transaction_count_by_hash->transaction_count) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_get_block_transaction_count_by_hash_t *output_get_block_transaction_count_by_hash_parseFromJSON(cJSON *output_get_block_transaction_count_by_hashJSON){

    output_get_block_transaction_count_by_hash_t *output_get_block_transaction_count_by_hash_local_var = NULL;

    // output_get_block_transaction_count_by_hash->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_get_block_transaction_count_by_hashJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_get_block_transaction_count_by_hash->transaction_count
    cJSON *transaction_count = cJSON_GetObjectItemCaseSensitive(output_get_block_transaction_count_by_hashJSON, "TransactionCount");
    if (!transaction_count) {
        goto end;
    }

    
    if(!cJSON_IsString(transaction_count))
    {
    goto end; //String
    }


    output_get_block_transaction_count_by_hash_local_var = output_get_block_transaction_count_by_hash_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(transaction_count->valuestring)
        );

    return output_get_block_transaction_count_by_hash_local_var;
end:
    return NULL;

}
