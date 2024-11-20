#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_get_block_receipts.h"



output_get_block_receipts_t *output_get_block_receipts_create(
    char *schema,
    list_t *transaction_receipts
    ) {
    output_get_block_receipts_t *output_get_block_receipts_local_var = malloc(sizeof(output_get_block_receipts_t));
    if (!output_get_block_receipts_local_var) {
        return NULL;
    }
    output_get_block_receipts_local_var->schema = schema;
    output_get_block_receipts_local_var->transaction_receipts = transaction_receipts;

    return output_get_block_receipts_local_var;
}


void output_get_block_receipts_free(output_get_block_receipts_t *output_get_block_receipts) {
    if(NULL == output_get_block_receipts){
        return ;
    }
    listEntry_t *listEntry;
    if (output_get_block_receipts->schema) {
        free(output_get_block_receipts->schema);
        output_get_block_receipts->schema = NULL;
    }
    if (output_get_block_receipts->transaction_receipts) {
        list_ForEach(listEntry, output_get_block_receipts->transaction_receipts) {
            response_transaction_receipt_free(listEntry->data);
        }
        list_freeList(output_get_block_receipts->transaction_receipts);
        output_get_block_receipts->transaction_receipts = NULL;
    }
    free(output_get_block_receipts);
}

cJSON *output_get_block_receipts_convertToJSON(output_get_block_receipts_t *output_get_block_receipts) {
    cJSON *item = cJSON_CreateObject();

    // output_get_block_receipts->schema
    if(output_get_block_receipts->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_get_block_receipts->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_get_block_receipts->transaction_receipts
    if (!output_get_block_receipts->transaction_receipts) {
        goto fail;
    }
    cJSON *transaction_receipts = cJSON_AddArrayToObject(item, "TransactionReceipts");
    if(transaction_receipts == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *transaction_receiptsListEntry;
    if (output_get_block_receipts->transaction_receipts) {
    list_ForEach(transaction_receiptsListEntry, output_get_block_receipts->transaction_receipts) {
    cJSON *itemLocal = response_transaction_receipt_convertToJSON(transaction_receiptsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(transaction_receipts, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_get_block_receipts_t *output_get_block_receipts_parseFromJSON(cJSON *output_get_block_receiptsJSON){

    output_get_block_receipts_t *output_get_block_receipts_local_var = NULL;

    // define the local list for output_get_block_receipts->transaction_receipts
    list_t *transaction_receiptsList = NULL;

    // output_get_block_receipts->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_get_block_receiptsJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_get_block_receipts->transaction_receipts
    cJSON *transaction_receipts = cJSON_GetObjectItemCaseSensitive(output_get_block_receiptsJSON, "TransactionReceipts");
    if (!transaction_receipts) {
        goto end;
    }

    
    cJSON *transaction_receipts_local_nonprimitive = NULL;
    if(!cJSON_IsArray(transaction_receipts)){
        goto end; //nonprimitive container
    }

    transaction_receiptsList = list_createList();

    cJSON_ArrayForEach(transaction_receipts_local_nonprimitive,transaction_receipts )
    {
        if(!cJSON_IsObject(transaction_receipts_local_nonprimitive)){
            goto end;
        }
        response_transaction_receipt_t *transaction_receiptsItem = response_transaction_receipt_parseFromJSON(transaction_receipts_local_nonprimitive);

        list_addElement(transaction_receiptsList, transaction_receiptsItem);
    }


    output_get_block_receipts_local_var = output_get_block_receipts_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        transaction_receiptsList
        );

    return output_get_block_receipts_local_var;
end:
    if (transaction_receiptsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, transaction_receiptsList) {
            response_transaction_receipt_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(transaction_receiptsList);
        transaction_receiptsList = NULL;
    }
    return NULL;

}
