#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_call.h"



input_call_t *input_call_create(
    char *schema,
    char *block_number,
    params_transaction_t *transaction
    ) {
    input_call_t *input_call_local_var = malloc(sizeof(input_call_t));
    if (!input_call_local_var) {
        return NULL;
    }
    input_call_local_var->schema = schema;
    input_call_local_var->block_number = block_number;
    input_call_local_var->transaction = transaction;

    return input_call_local_var;
}


void input_call_free(input_call_t *input_call) {
    if(NULL == input_call){
        return ;
    }
    listEntry_t *listEntry;
    if (input_call->schema) {
        free(input_call->schema);
        input_call->schema = NULL;
    }
    if (input_call->block_number) {
        free(input_call->block_number);
        input_call->block_number = NULL;
    }
    if (input_call->transaction) {
        params_transaction_free(input_call->transaction);
        input_call->transaction = NULL;
    }
    free(input_call);
}

cJSON *input_call_convertToJSON(input_call_t *input_call) {
    cJSON *item = cJSON_CreateObject();

    // input_call->schema
    if(input_call->schema) {
    if(cJSON_AddStringToObject(item, "$schema", input_call->schema) == NULL) {
    goto fail; //String
    }
    }


    // input_call->block_number
    if (!input_call->block_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "BlockNumber", input_call->block_number) == NULL) {
    goto fail; //String
    }


    // input_call->transaction
    if (!input_call->transaction) {
        goto fail;
    }
    cJSON *transaction_local_JSON = params_transaction_convertToJSON(input_call->transaction);
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

input_call_t *input_call_parseFromJSON(cJSON *input_callJSON){

    input_call_t *input_call_local_var = NULL;

    // define the local variable for input_call->transaction
    params_transaction_t *transaction_local_nonprim = NULL;

    // input_call->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(input_callJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // input_call->block_number
    cJSON *block_number = cJSON_GetObjectItemCaseSensitive(input_callJSON, "BlockNumber");
    if (!block_number) {
        goto end;
    }

    
    if(!cJSON_IsString(block_number))
    {
    goto end; //String
    }

    // input_call->transaction
    cJSON *transaction = cJSON_GetObjectItemCaseSensitive(input_callJSON, "Transaction");
    if (!transaction) {
        goto end;
    }

    
    transaction_local_nonprim = params_transaction_parseFromJSON(transaction); //nonprimitive


    input_call_local_var = input_call_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(block_number->valuestring),
        transaction_local_nonprim
        );

    return input_call_local_var;
end:
    if (transaction_local_nonprim) {
        params_transaction_free(transaction_local_nonprim);
        transaction_local_nonprim = NULL;
    }
    return NULL;

}
