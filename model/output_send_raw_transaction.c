#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_send_raw_transaction.h"



output_send_raw_transaction_t *output_send_raw_transaction_create(
    char *schema,
    char *transaction_hash
    ) {
    output_send_raw_transaction_t *output_send_raw_transaction_local_var = malloc(sizeof(output_send_raw_transaction_t));
    if (!output_send_raw_transaction_local_var) {
        return NULL;
    }
    output_send_raw_transaction_local_var->schema = schema;
    output_send_raw_transaction_local_var->transaction_hash = transaction_hash;

    return output_send_raw_transaction_local_var;
}


void output_send_raw_transaction_free(output_send_raw_transaction_t *output_send_raw_transaction) {
    if(NULL == output_send_raw_transaction){
        return ;
    }
    listEntry_t *listEntry;
    if (output_send_raw_transaction->schema) {
        free(output_send_raw_transaction->schema);
        output_send_raw_transaction->schema = NULL;
    }
    if (output_send_raw_transaction->transaction_hash) {
        free(output_send_raw_transaction->transaction_hash);
        output_send_raw_transaction->transaction_hash = NULL;
    }
    free(output_send_raw_transaction);
}

cJSON *output_send_raw_transaction_convertToJSON(output_send_raw_transaction_t *output_send_raw_transaction) {
    cJSON *item = cJSON_CreateObject();

    // output_send_raw_transaction->schema
    if(output_send_raw_transaction->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_send_raw_transaction->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_send_raw_transaction->transaction_hash
    if (!output_send_raw_transaction->transaction_hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "TransactionHash", output_send_raw_transaction->transaction_hash) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_send_raw_transaction_t *output_send_raw_transaction_parseFromJSON(cJSON *output_send_raw_transactionJSON){

    output_send_raw_transaction_t *output_send_raw_transaction_local_var = NULL;

    // output_send_raw_transaction->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_send_raw_transactionJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_send_raw_transaction->transaction_hash
    cJSON *transaction_hash = cJSON_GetObjectItemCaseSensitive(output_send_raw_transactionJSON, "TransactionHash");
    if (!transaction_hash) {
        goto end;
    }

    
    if(!cJSON_IsString(transaction_hash))
    {
    goto end; //String
    }


    output_send_raw_transaction_local_var = output_send_raw_transaction_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(transaction_hash->valuestring)
        );

    return output_send_raw_transaction_local_var;
end:
    return NULL;

}
