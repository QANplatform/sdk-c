#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_get_transaction_receipt.h"



output_get_transaction_receipt_t *output_get_transaction_receipt_create(
    char *schema,
    response_transaction_receipt_t *transaction_receipt
    ) {
    output_get_transaction_receipt_t *output_get_transaction_receipt_local_var = malloc(sizeof(output_get_transaction_receipt_t));
    if (!output_get_transaction_receipt_local_var) {
        return NULL;
    }
    output_get_transaction_receipt_local_var->schema = schema;
    output_get_transaction_receipt_local_var->transaction_receipt = transaction_receipt;

    return output_get_transaction_receipt_local_var;
}


void output_get_transaction_receipt_free(output_get_transaction_receipt_t *output_get_transaction_receipt) {
    if(NULL == output_get_transaction_receipt){
        return ;
    }
    listEntry_t *listEntry;
    if (output_get_transaction_receipt->schema) {
        free(output_get_transaction_receipt->schema);
        output_get_transaction_receipt->schema = NULL;
    }
    if (output_get_transaction_receipt->transaction_receipt) {
        response_transaction_receipt_free(output_get_transaction_receipt->transaction_receipt);
        output_get_transaction_receipt->transaction_receipt = NULL;
    }
    free(output_get_transaction_receipt);
}

cJSON *output_get_transaction_receipt_convertToJSON(output_get_transaction_receipt_t *output_get_transaction_receipt) {
    cJSON *item = cJSON_CreateObject();

    // output_get_transaction_receipt->schema
    if(output_get_transaction_receipt->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_get_transaction_receipt->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_get_transaction_receipt->transaction_receipt
    if (!output_get_transaction_receipt->transaction_receipt) {
        goto fail;
    }
    cJSON *transaction_receipt_local_JSON = response_transaction_receipt_convertToJSON(output_get_transaction_receipt->transaction_receipt);
    if(transaction_receipt_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "TransactionReceipt", transaction_receipt_local_JSON);
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

output_get_transaction_receipt_t *output_get_transaction_receipt_parseFromJSON(cJSON *output_get_transaction_receiptJSON){

    output_get_transaction_receipt_t *output_get_transaction_receipt_local_var = NULL;

    // define the local variable for output_get_transaction_receipt->transaction_receipt
    response_transaction_receipt_t *transaction_receipt_local_nonprim = NULL;

    // output_get_transaction_receipt->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_get_transaction_receiptJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_get_transaction_receipt->transaction_receipt
    cJSON *transaction_receipt = cJSON_GetObjectItemCaseSensitive(output_get_transaction_receiptJSON, "TransactionReceipt");
    if (!transaction_receipt) {
        goto end;
    }

    
    transaction_receipt_local_nonprim = response_transaction_receipt_parseFromJSON(transaction_receipt); //nonprimitive


    output_get_transaction_receipt_local_var = output_get_transaction_receipt_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        transaction_receipt_local_nonprim
        );

    return output_get_transaction_receipt_local_var;
end:
    if (transaction_receipt_local_nonprim) {
        response_transaction_receipt_free(transaction_receipt_local_nonprim);
        transaction_receipt_local_nonprim = NULL;
    }
    return NULL;

}
