#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "response_block.h"



response_block_t *response_block_create(
    char *base_fee_per_gas,
    char *difficulty,
    char *extra_data,
    char *gas_limit,
    char *gas_used,
    char *hash,
    char *logs_bloom,
    char *miner,
    char *mix_hash,
    char *nonce,
    char *number,
    char *parent_hash,
    char *receipts_root,
    char *sha3_uncles,
    char *size,
    char *state_root,
    char *timestamp,
    char *total_difficulty,
    list_t *transactions,
    char *transactions_root,
    list_t *uncles,
    response_withdrawals_t *withdrawals,
    char *withdrawals_root
    ) {
    response_block_t *response_block_local_var = malloc(sizeof(response_block_t));
    if (!response_block_local_var) {
        return NULL;
    }
    response_block_local_var->base_fee_per_gas = base_fee_per_gas;
    response_block_local_var->difficulty = difficulty;
    response_block_local_var->extra_data = extra_data;
    response_block_local_var->gas_limit = gas_limit;
    response_block_local_var->gas_used = gas_used;
    response_block_local_var->hash = hash;
    response_block_local_var->logs_bloom = logs_bloom;
    response_block_local_var->miner = miner;
    response_block_local_var->mix_hash = mix_hash;
    response_block_local_var->nonce = nonce;
    response_block_local_var->number = number;
    response_block_local_var->parent_hash = parent_hash;
    response_block_local_var->receipts_root = receipts_root;
    response_block_local_var->sha3_uncles = sha3_uncles;
    response_block_local_var->size = size;
    response_block_local_var->state_root = state_root;
    response_block_local_var->timestamp = timestamp;
    response_block_local_var->total_difficulty = total_difficulty;
    response_block_local_var->transactions = transactions;
    response_block_local_var->transactions_root = transactions_root;
    response_block_local_var->uncles = uncles;
    response_block_local_var->withdrawals = withdrawals;
    response_block_local_var->withdrawals_root = withdrawals_root;

    return response_block_local_var;
}


void response_block_free(response_block_t *response_block) {
    if(NULL == response_block){
        return ;
    }
    listEntry_t *listEntry;
    if (response_block->base_fee_per_gas) {
        free(response_block->base_fee_per_gas);
        response_block->base_fee_per_gas = NULL;
    }
    if (response_block->difficulty) {
        free(response_block->difficulty);
        response_block->difficulty = NULL;
    }
    if (response_block->extra_data) {
        free(response_block->extra_data);
        response_block->extra_data = NULL;
    }
    if (response_block->gas_limit) {
        free(response_block->gas_limit);
        response_block->gas_limit = NULL;
    }
    if (response_block->gas_used) {
        free(response_block->gas_used);
        response_block->gas_used = NULL;
    }
    if (response_block->hash) {
        free(response_block->hash);
        response_block->hash = NULL;
    }
    if (response_block->logs_bloom) {
        free(response_block->logs_bloom);
        response_block->logs_bloom = NULL;
    }
    if (response_block->miner) {
        free(response_block->miner);
        response_block->miner = NULL;
    }
    if (response_block->mix_hash) {
        free(response_block->mix_hash);
        response_block->mix_hash = NULL;
    }
    if (response_block->nonce) {
        free(response_block->nonce);
        response_block->nonce = NULL;
    }
    if (response_block->number) {
        free(response_block->number);
        response_block->number = NULL;
    }
    if (response_block->parent_hash) {
        free(response_block->parent_hash);
        response_block->parent_hash = NULL;
    }
    if (response_block->receipts_root) {
        free(response_block->receipts_root);
        response_block->receipts_root = NULL;
    }
    if (response_block->sha3_uncles) {
        free(response_block->sha3_uncles);
        response_block->sha3_uncles = NULL;
    }
    if (response_block->size) {
        free(response_block->size);
        response_block->size = NULL;
    }
    if (response_block->state_root) {
        free(response_block->state_root);
        response_block->state_root = NULL;
    }
    if (response_block->timestamp) {
        free(response_block->timestamp);
        response_block->timestamp = NULL;
    }
    if (response_block->total_difficulty) {
        free(response_block->total_difficulty);
        response_block->total_difficulty = NULL;
    }
    if (response_block->transactions) {
        list_ForEach(listEntry, response_block->transactions) {
            response_transaction_free(listEntry->data);
        }
        list_freeList(response_block->transactions);
        response_block->transactions = NULL;
    }
    if (response_block->transactions_root) {
        free(response_block->transactions_root);
        response_block->transactions_root = NULL;
    }
    if (response_block->uncles) {
        list_ForEach(listEntry, response_block->uncles) {
            free(listEntry->data);
        }
        list_freeList(response_block->uncles);
        response_block->uncles = NULL;
    }
    if (response_block->withdrawals) {
        response_withdrawals_free(response_block->withdrawals);
        response_block->withdrawals = NULL;
    }
    if (response_block->withdrawals_root) {
        free(response_block->withdrawals_root);
        response_block->withdrawals_root = NULL;
    }
    free(response_block);
}

cJSON *response_block_convertToJSON(response_block_t *response_block) {
    cJSON *item = cJSON_CreateObject();

    // response_block->base_fee_per_gas
    if (!response_block->base_fee_per_gas) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "BaseFeePerGas", response_block->base_fee_per_gas) == NULL) {
    goto fail; //String
    }


    // response_block->difficulty
    if (!response_block->difficulty) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Difficulty", response_block->difficulty) == NULL) {
    goto fail; //String
    }


    // response_block->extra_data
    if (!response_block->extra_data) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ExtraData", response_block->extra_data) == NULL) {
    goto fail; //String
    }


    // response_block->gas_limit
    if (!response_block->gas_limit) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "GasLimit", response_block->gas_limit) == NULL) {
    goto fail; //String
    }


    // response_block->gas_used
    if (!response_block->gas_used) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "GasUsed", response_block->gas_used) == NULL) {
    goto fail; //String
    }


    // response_block->hash
    if (!response_block->hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Hash", response_block->hash) == NULL) {
    goto fail; //String
    }


    // response_block->logs_bloom
    if (!response_block->logs_bloom) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "LogsBloom", response_block->logs_bloom) == NULL) {
    goto fail; //String
    }


    // response_block->miner
    if (!response_block->miner) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Miner", response_block->miner) == NULL) {
    goto fail; //String
    }


    // response_block->mix_hash
    if (!response_block->mix_hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "MixHash", response_block->mix_hash) == NULL) {
    goto fail; //String
    }


    // response_block->nonce
    if (!response_block->nonce) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Nonce", response_block->nonce) == NULL) {
    goto fail; //String
    }


    // response_block->number
    if (!response_block->number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Number", response_block->number) == NULL) {
    goto fail; //String
    }


    // response_block->parent_hash
    if (!response_block->parent_hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ParentHash", response_block->parent_hash) == NULL) {
    goto fail; //String
    }


    // response_block->receipts_root
    if (!response_block->receipts_root) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ReceiptsRoot", response_block->receipts_root) == NULL) {
    goto fail; //String
    }


    // response_block->sha3_uncles
    if (!response_block->sha3_uncles) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Sha3Uncles", response_block->sha3_uncles) == NULL) {
    goto fail; //String
    }


    // response_block->size
    if (!response_block->size) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Size", response_block->size) == NULL) {
    goto fail; //String
    }


    // response_block->state_root
    if (!response_block->state_root) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "StateRoot", response_block->state_root) == NULL) {
    goto fail; //String
    }


    // response_block->timestamp
    if (!response_block->timestamp) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Timestamp", response_block->timestamp) == NULL) {
    goto fail; //String
    }


    // response_block->total_difficulty
    if (!response_block->total_difficulty) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "TotalDifficulty", response_block->total_difficulty) == NULL) {
    goto fail; //String
    }


    // response_block->transactions
    if (!response_block->transactions) {
        goto fail;
    }
    cJSON *transactions = cJSON_AddArrayToObject(item, "Transactions");
    if(transactions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *transactionsListEntry;
    if (response_block->transactions) {
    list_ForEach(transactionsListEntry, response_block->transactions) {
    cJSON *itemLocal = response_transaction_convertToJSON(transactionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(transactions, itemLocal);
    }
    }


    // response_block->transactions_root
    if (!response_block->transactions_root) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "TransactionsRoot", response_block->transactions_root) == NULL) {
    goto fail; //String
    }


    // response_block->uncles
    if (!response_block->uncles) {
        goto fail;
    }
    cJSON *uncles = cJSON_AddArrayToObject(item, "Uncles");
    if(uncles == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *unclesListEntry;
    list_ForEach(unclesListEntry, response_block->uncles) {
    if(cJSON_AddStringToObject(uncles, "", (char*)unclesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // response_block->withdrawals
    if (!response_block->withdrawals) {
        goto fail;
    }
    cJSON *withdrawals_local_JSON = response_withdrawals_convertToJSON(response_block->withdrawals);
    if(withdrawals_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "Withdrawals", withdrawals_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // response_block->withdrawals_root
    if (!response_block->withdrawals_root) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "WithdrawalsRoot", response_block->withdrawals_root) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

response_block_t *response_block_parseFromJSON(cJSON *response_blockJSON){

    response_block_t *response_block_local_var = NULL;

    // define the local list for response_block->transactions
    list_t *transactionsList = NULL;

    // define the local list for response_block->uncles
    list_t *unclesList = NULL;

    // define the local variable for response_block->withdrawals
    response_withdrawals_t *withdrawals_local_nonprim = NULL;

    // response_block->base_fee_per_gas
    cJSON *base_fee_per_gas = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "BaseFeePerGas");
    if (!base_fee_per_gas) {
        goto end;
    }

    
    if(!cJSON_IsString(base_fee_per_gas))
    {
    goto end; //String
    }

    // response_block->difficulty
    cJSON *difficulty = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "Difficulty");
    if (!difficulty) {
        goto end;
    }

    
    if(!cJSON_IsString(difficulty))
    {
    goto end; //String
    }

    // response_block->extra_data
    cJSON *extra_data = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "ExtraData");
    if (!extra_data) {
        goto end;
    }

    
    if(!cJSON_IsString(extra_data))
    {
    goto end; //String
    }

    // response_block->gas_limit
    cJSON *gas_limit = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "GasLimit");
    if (!gas_limit) {
        goto end;
    }

    
    if(!cJSON_IsString(gas_limit))
    {
    goto end; //String
    }

    // response_block->gas_used
    cJSON *gas_used = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "GasUsed");
    if (!gas_used) {
        goto end;
    }

    
    if(!cJSON_IsString(gas_used))
    {
    goto end; //String
    }

    // response_block->hash
    cJSON *hash = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "Hash");
    if (!hash) {
        goto end;
    }

    
    if(!cJSON_IsString(hash))
    {
    goto end; //String
    }

    // response_block->logs_bloom
    cJSON *logs_bloom = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "LogsBloom");
    if (!logs_bloom) {
        goto end;
    }

    
    if(!cJSON_IsString(logs_bloom))
    {
    goto end; //String
    }

    // response_block->miner
    cJSON *miner = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "Miner");
    if (!miner) {
        goto end;
    }

    
    if(!cJSON_IsString(miner))
    {
    goto end; //String
    }

    // response_block->mix_hash
    cJSON *mix_hash = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "MixHash");
    if (!mix_hash) {
        goto end;
    }

    
    if(!cJSON_IsString(mix_hash))
    {
    goto end; //String
    }

    // response_block->nonce
    cJSON *nonce = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "Nonce");
    if (!nonce) {
        goto end;
    }

    
    if(!cJSON_IsString(nonce))
    {
    goto end; //String
    }

    // response_block->number
    cJSON *number = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "Number");
    if (!number) {
        goto end;
    }

    
    if(!cJSON_IsString(number))
    {
    goto end; //String
    }

    // response_block->parent_hash
    cJSON *parent_hash = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "ParentHash");
    if (!parent_hash) {
        goto end;
    }

    
    if(!cJSON_IsString(parent_hash))
    {
    goto end; //String
    }

    // response_block->receipts_root
    cJSON *receipts_root = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "ReceiptsRoot");
    if (!receipts_root) {
        goto end;
    }

    
    if(!cJSON_IsString(receipts_root))
    {
    goto end; //String
    }

    // response_block->sha3_uncles
    cJSON *sha3_uncles = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "Sha3Uncles");
    if (!sha3_uncles) {
        goto end;
    }

    
    if(!cJSON_IsString(sha3_uncles))
    {
    goto end; //String
    }

    // response_block->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "Size");
    if (!size) {
        goto end;
    }

    
    if(!cJSON_IsString(size))
    {
    goto end; //String
    }

    // response_block->state_root
    cJSON *state_root = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "StateRoot");
    if (!state_root) {
        goto end;
    }

    
    if(!cJSON_IsString(state_root))
    {
    goto end; //String
    }

    // response_block->timestamp
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "Timestamp");
    if (!timestamp) {
        goto end;
    }

    
    if(!cJSON_IsString(timestamp))
    {
    goto end; //String
    }

    // response_block->total_difficulty
    cJSON *total_difficulty = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "TotalDifficulty");
    if (!total_difficulty) {
        goto end;
    }

    
    if(!cJSON_IsString(total_difficulty))
    {
    goto end; //String
    }

    // response_block->transactions
    cJSON *transactions = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "Transactions");
    if (!transactions) {
        goto end;
    }

    
    cJSON *transactions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(transactions)){
        goto end; //nonprimitive container
    }

    transactionsList = list_createList();

    cJSON_ArrayForEach(transactions_local_nonprimitive,transactions )
    {
        if(!cJSON_IsObject(transactions_local_nonprimitive)){
            goto end;
        }
        response_transaction_t *transactionsItem = response_transaction_parseFromJSON(transactions_local_nonprimitive);

        list_addElement(transactionsList, transactionsItem);
    }

    // response_block->transactions_root
    cJSON *transactions_root = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "TransactionsRoot");
    if (!transactions_root) {
        goto end;
    }

    
    if(!cJSON_IsString(transactions_root))
    {
    goto end; //String
    }

    // response_block->uncles
    cJSON *uncles = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "Uncles");
    if (!uncles) {
        goto end;
    }

    
    cJSON *uncles_local = NULL;
    if(!cJSON_IsArray(uncles)) {
        goto end;//primitive container
    }
    unclesList = list_createList();

    cJSON_ArrayForEach(uncles_local, uncles)
    {
        if(!cJSON_IsString(uncles_local))
        {
            goto end;
        }
        list_addElement(unclesList , strdup(uncles_local->valuestring));
    }

    // response_block->withdrawals
    cJSON *withdrawals = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "Withdrawals");
    if (!withdrawals) {
        goto end;
    }

    
    withdrawals_local_nonprim = response_withdrawals_parseFromJSON(withdrawals); //nonprimitive

    // response_block->withdrawals_root
    cJSON *withdrawals_root = cJSON_GetObjectItemCaseSensitive(response_blockJSON, "WithdrawalsRoot");
    if (!withdrawals_root) {
        goto end;
    }

    
    if(!cJSON_IsString(withdrawals_root))
    {
    goto end; //String
    }


    response_block_local_var = response_block_create (
        strdup(base_fee_per_gas->valuestring),
        strdup(difficulty->valuestring),
        strdup(extra_data->valuestring),
        strdup(gas_limit->valuestring),
        strdup(gas_used->valuestring),
        strdup(hash->valuestring),
        strdup(logs_bloom->valuestring),
        strdup(miner->valuestring),
        strdup(mix_hash->valuestring),
        strdup(nonce->valuestring),
        strdup(number->valuestring),
        strdup(parent_hash->valuestring),
        strdup(receipts_root->valuestring),
        strdup(sha3_uncles->valuestring),
        strdup(size->valuestring),
        strdup(state_root->valuestring),
        strdup(timestamp->valuestring),
        strdup(total_difficulty->valuestring),
        transactionsList,
        strdup(transactions_root->valuestring),
        unclesList,
        withdrawals_local_nonprim,
        strdup(withdrawals_root->valuestring)
        );

    return response_block_local_var;
end:
    if (transactionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, transactionsList) {
            response_transaction_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(transactionsList);
        transactionsList = NULL;
    }
    if (unclesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, unclesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(unclesList);
        unclesList = NULL;
    }
    if (withdrawals_local_nonprim) {
        response_withdrawals_free(withdrawals_local_nonprim);
        withdrawals_local_nonprim = NULL;
    }
    return NULL;

}
