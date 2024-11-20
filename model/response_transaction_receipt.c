#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "response_transaction_receipt.h"



response_transaction_receipt_t *response_transaction_receipt_create(
    char *block_hash,
    char *block_number,
    char *contract_address,
    char *cumulative_gas_used,
    char *effective_gas_price,
    char *from,
    char *gas_used,
    list_t *logs,
    char *logs_bloom,
    char *status,
    char *to,
    char *transaction_hash,
    char *transaction_index,
    char *type
    ) {
    response_transaction_receipt_t *response_transaction_receipt_local_var = malloc(sizeof(response_transaction_receipt_t));
    if (!response_transaction_receipt_local_var) {
        return NULL;
    }
    response_transaction_receipt_local_var->block_hash = block_hash;
    response_transaction_receipt_local_var->block_number = block_number;
    response_transaction_receipt_local_var->contract_address = contract_address;
    response_transaction_receipt_local_var->cumulative_gas_used = cumulative_gas_used;
    response_transaction_receipt_local_var->effective_gas_price = effective_gas_price;
    response_transaction_receipt_local_var->from = from;
    response_transaction_receipt_local_var->gas_used = gas_used;
    response_transaction_receipt_local_var->logs = logs;
    response_transaction_receipt_local_var->logs_bloom = logs_bloom;
    response_transaction_receipt_local_var->status = status;
    response_transaction_receipt_local_var->to = to;
    response_transaction_receipt_local_var->transaction_hash = transaction_hash;
    response_transaction_receipt_local_var->transaction_index = transaction_index;
    response_transaction_receipt_local_var->type = type;

    return response_transaction_receipt_local_var;
}


void response_transaction_receipt_free(response_transaction_receipt_t *response_transaction_receipt) {
    if(NULL == response_transaction_receipt){
        return ;
    }
    listEntry_t *listEntry;
    if (response_transaction_receipt->block_hash) {
        free(response_transaction_receipt->block_hash);
        response_transaction_receipt->block_hash = NULL;
    }
    if (response_transaction_receipt->block_number) {
        free(response_transaction_receipt->block_number);
        response_transaction_receipt->block_number = NULL;
    }
    if (response_transaction_receipt->contract_address) {
        free(response_transaction_receipt->contract_address);
        response_transaction_receipt->contract_address = NULL;
    }
    if (response_transaction_receipt->cumulative_gas_used) {
        free(response_transaction_receipt->cumulative_gas_used);
        response_transaction_receipt->cumulative_gas_used = NULL;
    }
    if (response_transaction_receipt->effective_gas_price) {
        free(response_transaction_receipt->effective_gas_price);
        response_transaction_receipt->effective_gas_price = NULL;
    }
    if (response_transaction_receipt->from) {
        free(response_transaction_receipt->from);
        response_transaction_receipt->from = NULL;
    }
    if (response_transaction_receipt->gas_used) {
        free(response_transaction_receipt->gas_used);
        response_transaction_receipt->gas_used = NULL;
    }
    if (response_transaction_receipt->logs) {
        list_ForEach(listEntry, response_transaction_receipt->logs) {
            response_log_free(listEntry->data);
        }
        list_freeList(response_transaction_receipt->logs);
        response_transaction_receipt->logs = NULL;
    }
    if (response_transaction_receipt->logs_bloom) {
        free(response_transaction_receipt->logs_bloom);
        response_transaction_receipt->logs_bloom = NULL;
    }
    if (response_transaction_receipt->status) {
        free(response_transaction_receipt->status);
        response_transaction_receipt->status = NULL;
    }
    if (response_transaction_receipt->to) {
        free(response_transaction_receipt->to);
        response_transaction_receipt->to = NULL;
    }
    if (response_transaction_receipt->transaction_hash) {
        free(response_transaction_receipt->transaction_hash);
        response_transaction_receipt->transaction_hash = NULL;
    }
    if (response_transaction_receipt->transaction_index) {
        free(response_transaction_receipt->transaction_index);
        response_transaction_receipt->transaction_index = NULL;
    }
    if (response_transaction_receipt->type) {
        free(response_transaction_receipt->type);
        response_transaction_receipt->type = NULL;
    }
    free(response_transaction_receipt);
}

cJSON *response_transaction_receipt_convertToJSON(response_transaction_receipt_t *response_transaction_receipt) {
    cJSON *item = cJSON_CreateObject();

    // response_transaction_receipt->block_hash
    if(response_transaction_receipt->block_hash) {
    if(cJSON_AddStringToObject(item, "BlockHash", response_transaction_receipt->block_hash) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction_receipt->block_number
    if(response_transaction_receipt->block_number) {
    if(cJSON_AddStringToObject(item, "BlockNumber", response_transaction_receipt->block_number) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction_receipt->contract_address
    if(response_transaction_receipt->contract_address) {
    if(cJSON_AddStringToObject(item, "ContractAddress", response_transaction_receipt->contract_address) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction_receipt->cumulative_gas_used
    if(response_transaction_receipt->cumulative_gas_used) {
    if(cJSON_AddStringToObject(item, "CumulativeGasUsed", response_transaction_receipt->cumulative_gas_used) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction_receipt->effective_gas_price
    if(response_transaction_receipt->effective_gas_price) {
    if(cJSON_AddStringToObject(item, "EffectiveGasPrice", response_transaction_receipt->effective_gas_price) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction_receipt->from
    if(response_transaction_receipt->from) {
    if(cJSON_AddStringToObject(item, "From", response_transaction_receipt->from) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction_receipt->gas_used
    if(response_transaction_receipt->gas_used) {
    if(cJSON_AddStringToObject(item, "GasUsed", response_transaction_receipt->gas_used) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction_receipt->logs
    if(response_transaction_receipt->logs) {
    cJSON *logs = cJSON_AddArrayToObject(item, "Logs");
    if(logs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *logsListEntry;
    if (response_transaction_receipt->logs) {
    list_ForEach(logsListEntry, response_transaction_receipt->logs) {
    cJSON *itemLocal = response_log_convertToJSON(logsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(logs, itemLocal);
    }
    }
    }


    // response_transaction_receipt->logs_bloom
    if(response_transaction_receipt->logs_bloom) {
    if(cJSON_AddStringToObject(item, "LogsBloom", response_transaction_receipt->logs_bloom) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction_receipt->status
    if(response_transaction_receipt->status) {
    if(cJSON_AddStringToObject(item, "Status", response_transaction_receipt->status) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction_receipt->to
    if(response_transaction_receipt->to) {
    if(cJSON_AddStringToObject(item, "To", response_transaction_receipt->to) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction_receipt->transaction_hash
    if(response_transaction_receipt->transaction_hash) {
    if(cJSON_AddStringToObject(item, "TransactionHash", response_transaction_receipt->transaction_hash) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction_receipt->transaction_index
    if(response_transaction_receipt->transaction_index) {
    if(cJSON_AddStringToObject(item, "TransactionIndex", response_transaction_receipt->transaction_index) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction_receipt->type
    if(response_transaction_receipt->type) {
    if(cJSON_AddStringToObject(item, "Type", response_transaction_receipt->type) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

response_transaction_receipt_t *response_transaction_receipt_parseFromJSON(cJSON *response_transaction_receiptJSON){

    response_transaction_receipt_t *response_transaction_receipt_local_var = NULL;

    // define the local list for response_transaction_receipt->logs
    list_t *logsList = NULL;

    // response_transaction_receipt->block_hash
    cJSON *block_hash = cJSON_GetObjectItemCaseSensitive(response_transaction_receiptJSON, "BlockHash");
    if (block_hash) { 
    if(!cJSON_IsString(block_hash) && !cJSON_IsNull(block_hash))
    {
    goto end; //String
    }
    }

    // response_transaction_receipt->block_number
    cJSON *block_number = cJSON_GetObjectItemCaseSensitive(response_transaction_receiptJSON, "BlockNumber");
    if (block_number) { 
    if(!cJSON_IsString(block_number) && !cJSON_IsNull(block_number))
    {
    goto end; //String
    }
    }

    // response_transaction_receipt->contract_address
    cJSON *contract_address = cJSON_GetObjectItemCaseSensitive(response_transaction_receiptJSON, "ContractAddress");
    if (contract_address) { 
    if(!cJSON_IsString(contract_address) && !cJSON_IsNull(contract_address))
    {
    goto end; //String
    }
    }

    // response_transaction_receipt->cumulative_gas_used
    cJSON *cumulative_gas_used = cJSON_GetObjectItemCaseSensitive(response_transaction_receiptJSON, "CumulativeGasUsed");
    if (cumulative_gas_used) { 
    if(!cJSON_IsString(cumulative_gas_used) && !cJSON_IsNull(cumulative_gas_used))
    {
    goto end; //String
    }
    }

    // response_transaction_receipt->effective_gas_price
    cJSON *effective_gas_price = cJSON_GetObjectItemCaseSensitive(response_transaction_receiptJSON, "EffectiveGasPrice");
    if (effective_gas_price) { 
    if(!cJSON_IsString(effective_gas_price) && !cJSON_IsNull(effective_gas_price))
    {
    goto end; //String
    }
    }

    // response_transaction_receipt->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(response_transaction_receiptJSON, "From");
    if (from) { 
    if(!cJSON_IsString(from) && !cJSON_IsNull(from))
    {
    goto end; //String
    }
    }

    // response_transaction_receipt->gas_used
    cJSON *gas_used = cJSON_GetObjectItemCaseSensitive(response_transaction_receiptJSON, "GasUsed");
    if (gas_used) { 
    if(!cJSON_IsString(gas_used) && !cJSON_IsNull(gas_used))
    {
    goto end; //String
    }
    }

    // response_transaction_receipt->logs
    cJSON *logs = cJSON_GetObjectItemCaseSensitive(response_transaction_receiptJSON, "Logs");
    if (logs) { 
    cJSON *logs_local_nonprimitive = NULL;
    if(!cJSON_IsArray(logs)){
        goto end; //nonprimitive container
    }

    logsList = list_createList();

    cJSON_ArrayForEach(logs_local_nonprimitive,logs )
    {
        if(!cJSON_IsObject(logs_local_nonprimitive)){
            goto end;
        }
        response_log_t *logsItem = response_log_parseFromJSON(logs_local_nonprimitive);

        list_addElement(logsList, logsItem);
    }
    }

    // response_transaction_receipt->logs_bloom
    cJSON *logs_bloom = cJSON_GetObjectItemCaseSensitive(response_transaction_receiptJSON, "LogsBloom");
    if (logs_bloom) { 
    if(!cJSON_IsString(logs_bloom) && !cJSON_IsNull(logs_bloom))
    {
    goto end; //String
    }
    }

    // response_transaction_receipt->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(response_transaction_receiptJSON, "Status");
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // response_transaction_receipt->to
    cJSON *to = cJSON_GetObjectItemCaseSensitive(response_transaction_receiptJSON, "To");
    if (to) { 
    if(!cJSON_IsString(to) && !cJSON_IsNull(to))
    {
    goto end; //String
    }
    }

    // response_transaction_receipt->transaction_hash
    cJSON *transaction_hash = cJSON_GetObjectItemCaseSensitive(response_transaction_receiptJSON, "TransactionHash");
    if (transaction_hash) { 
    if(!cJSON_IsString(transaction_hash) && !cJSON_IsNull(transaction_hash))
    {
    goto end; //String
    }
    }

    // response_transaction_receipt->transaction_index
    cJSON *transaction_index = cJSON_GetObjectItemCaseSensitive(response_transaction_receiptJSON, "TransactionIndex");
    if (transaction_index) { 
    if(!cJSON_IsString(transaction_index) && !cJSON_IsNull(transaction_index))
    {
    goto end; //String
    }
    }

    // response_transaction_receipt->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(response_transaction_receiptJSON, "Type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }


    response_transaction_receipt_local_var = response_transaction_receipt_create (
        block_hash && !cJSON_IsNull(block_hash) ? strdup(block_hash->valuestring) : NULL,
        block_number && !cJSON_IsNull(block_number) ? strdup(block_number->valuestring) : NULL,
        contract_address && !cJSON_IsNull(contract_address) ? strdup(contract_address->valuestring) : NULL,
        cumulative_gas_used && !cJSON_IsNull(cumulative_gas_used) ? strdup(cumulative_gas_used->valuestring) : NULL,
        effective_gas_price && !cJSON_IsNull(effective_gas_price) ? strdup(effective_gas_price->valuestring) : NULL,
        from && !cJSON_IsNull(from) ? strdup(from->valuestring) : NULL,
        gas_used && !cJSON_IsNull(gas_used) ? strdup(gas_used->valuestring) : NULL,
        logs ? logsList : NULL,
        logs_bloom && !cJSON_IsNull(logs_bloom) ? strdup(logs_bloom->valuestring) : NULL,
        status && !cJSON_IsNull(status) ? strdup(status->valuestring) : NULL,
        to && !cJSON_IsNull(to) ? strdup(to->valuestring) : NULL,
        transaction_hash && !cJSON_IsNull(transaction_hash) ? strdup(transaction_hash->valuestring) : NULL,
        transaction_index && !cJSON_IsNull(transaction_index) ? strdup(transaction_index->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL
        );

    return response_transaction_receipt_local_var;
end:
    if (logsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, logsList) {
            response_log_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(logsList);
        logsList = NULL;
    }
    return NULL;

}
