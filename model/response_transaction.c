#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "response_transaction.h"



response_transaction_t *response_transaction_create(
    char *access_list,
    char *block_hash,
    char *block_number,
    char *chain_id,
    char *from,
    char *gas,
    char *gas_price,
    char *hash,
    char *input,
    char *max_fee_per_gas,
    char *max_priority_fee_per_gas,
    char *nonce,
    char *r,
    char *s,
    char *to,
    char *transaction_index,
    char *type,
    char *v,
    char *value
    ) {
    response_transaction_t *response_transaction_local_var = malloc(sizeof(response_transaction_t));
    if (!response_transaction_local_var) {
        return NULL;
    }
    response_transaction_local_var->access_list = access_list;
    response_transaction_local_var->block_hash = block_hash;
    response_transaction_local_var->block_number = block_number;
    response_transaction_local_var->chain_id = chain_id;
    response_transaction_local_var->from = from;
    response_transaction_local_var->gas = gas;
    response_transaction_local_var->gas_price = gas_price;
    response_transaction_local_var->hash = hash;
    response_transaction_local_var->input = input;
    response_transaction_local_var->max_fee_per_gas = max_fee_per_gas;
    response_transaction_local_var->max_priority_fee_per_gas = max_priority_fee_per_gas;
    response_transaction_local_var->nonce = nonce;
    response_transaction_local_var->r = r;
    response_transaction_local_var->s = s;
    response_transaction_local_var->to = to;
    response_transaction_local_var->transaction_index = transaction_index;
    response_transaction_local_var->type = type;
    response_transaction_local_var->v = v;
    response_transaction_local_var->value = value;

    return response_transaction_local_var;
}


void response_transaction_free(response_transaction_t *response_transaction) {
    if(NULL == response_transaction){
        return ;
    }
    listEntry_t *listEntry;
    if (response_transaction->access_list) {
        free(response_transaction->access_list);
        response_transaction->access_list = NULL;
    }
    if (response_transaction->block_hash) {
        free(response_transaction->block_hash);
        response_transaction->block_hash = NULL;
    }
    if (response_transaction->block_number) {
        free(response_transaction->block_number);
        response_transaction->block_number = NULL;
    }
    if (response_transaction->chain_id) {
        free(response_transaction->chain_id);
        response_transaction->chain_id = NULL;
    }
    if (response_transaction->from) {
        free(response_transaction->from);
        response_transaction->from = NULL;
    }
    if (response_transaction->gas) {
        free(response_transaction->gas);
        response_transaction->gas = NULL;
    }
    if (response_transaction->gas_price) {
        free(response_transaction->gas_price);
        response_transaction->gas_price = NULL;
    }
    if (response_transaction->hash) {
        free(response_transaction->hash);
        response_transaction->hash = NULL;
    }
    if (response_transaction->input) {
        free(response_transaction->input);
        response_transaction->input = NULL;
    }
    if (response_transaction->max_fee_per_gas) {
        free(response_transaction->max_fee_per_gas);
        response_transaction->max_fee_per_gas = NULL;
    }
    if (response_transaction->max_priority_fee_per_gas) {
        free(response_transaction->max_priority_fee_per_gas);
        response_transaction->max_priority_fee_per_gas = NULL;
    }
    if (response_transaction->nonce) {
        free(response_transaction->nonce);
        response_transaction->nonce = NULL;
    }
    if (response_transaction->r) {
        free(response_transaction->r);
        response_transaction->r = NULL;
    }
    if (response_transaction->s) {
        free(response_transaction->s);
        response_transaction->s = NULL;
    }
    if (response_transaction->to) {
        free(response_transaction->to);
        response_transaction->to = NULL;
    }
    if (response_transaction->transaction_index) {
        free(response_transaction->transaction_index);
        response_transaction->transaction_index = NULL;
    }
    if (response_transaction->type) {
        free(response_transaction->type);
        response_transaction->type = NULL;
    }
    if (response_transaction->v) {
        free(response_transaction->v);
        response_transaction->v = NULL;
    }
    if (response_transaction->value) {
        free(response_transaction->value);
        response_transaction->value = NULL;
    }
    free(response_transaction);
}

cJSON *response_transaction_convertToJSON(response_transaction_t *response_transaction) {
    cJSON *item = cJSON_CreateObject();

    // response_transaction->access_list
    if(response_transaction->access_list) {
    if(cJSON_AddStringToObject(item, "AccessList", response_transaction->access_list) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->block_hash
    if(response_transaction->block_hash) {
    if(cJSON_AddStringToObject(item, "BlockHash", response_transaction->block_hash) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->block_number
    if(response_transaction->block_number) {
    if(cJSON_AddStringToObject(item, "BlockNumber", response_transaction->block_number) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->chain_id
    if(response_transaction->chain_id) {
    if(cJSON_AddStringToObject(item, "ChainId", response_transaction->chain_id) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->from
    if(response_transaction->from) {
    if(cJSON_AddStringToObject(item, "From", response_transaction->from) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->gas
    if(response_transaction->gas) {
    if(cJSON_AddStringToObject(item, "Gas", response_transaction->gas) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->gas_price
    if(response_transaction->gas_price) {
    if(cJSON_AddStringToObject(item, "GasPrice", response_transaction->gas_price) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->hash
    if(response_transaction->hash) {
    if(cJSON_AddStringToObject(item, "Hash", response_transaction->hash) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->input
    if(response_transaction->input) {
    if(cJSON_AddStringToObject(item, "Input", response_transaction->input) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->max_fee_per_gas
    if(response_transaction->max_fee_per_gas) {
    if(cJSON_AddStringToObject(item, "MaxFeePerGas", response_transaction->max_fee_per_gas) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->max_priority_fee_per_gas
    if(response_transaction->max_priority_fee_per_gas) {
    if(cJSON_AddStringToObject(item, "MaxPriorityFeePerGas", response_transaction->max_priority_fee_per_gas) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->nonce
    if(response_transaction->nonce) {
    if(cJSON_AddStringToObject(item, "Nonce", response_transaction->nonce) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->r
    if(response_transaction->r) {
    if(cJSON_AddStringToObject(item, "R", response_transaction->r) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->s
    if(response_transaction->s) {
    if(cJSON_AddStringToObject(item, "S", response_transaction->s) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->to
    if(response_transaction->to) {
    if(cJSON_AddStringToObject(item, "To", response_transaction->to) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->transaction_index
    if(response_transaction->transaction_index) {
    if(cJSON_AddStringToObject(item, "TransactionIndex", response_transaction->transaction_index) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->type
    if(response_transaction->type) {
    if(cJSON_AddStringToObject(item, "Type", response_transaction->type) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->v
    if(response_transaction->v) {
    if(cJSON_AddStringToObject(item, "V", response_transaction->v) == NULL) {
    goto fail; //String
    }
    }


    // response_transaction->value
    if(response_transaction->value) {
    if(cJSON_AddStringToObject(item, "Value", response_transaction->value) == NULL) {
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

response_transaction_t *response_transaction_parseFromJSON(cJSON *response_transactionJSON){

    response_transaction_t *response_transaction_local_var = NULL;

    // response_transaction->access_list
    cJSON *access_list = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "AccessList");
    if (access_list) { 
    if(!cJSON_IsString(access_list) && !cJSON_IsNull(access_list))
    {
    goto end; //String
    }
    }

    // response_transaction->block_hash
    cJSON *block_hash = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "BlockHash");
    if (block_hash) { 
    if(!cJSON_IsString(block_hash) && !cJSON_IsNull(block_hash))
    {
    goto end; //String
    }
    }

    // response_transaction->block_number
    cJSON *block_number = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "BlockNumber");
    if (block_number) { 
    if(!cJSON_IsString(block_number) && !cJSON_IsNull(block_number))
    {
    goto end; //String
    }
    }

    // response_transaction->chain_id
    cJSON *chain_id = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "ChainId");
    if (chain_id) { 
    if(!cJSON_IsString(chain_id) && !cJSON_IsNull(chain_id))
    {
    goto end; //String
    }
    }

    // response_transaction->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "From");
    if (from) { 
    if(!cJSON_IsString(from) && !cJSON_IsNull(from))
    {
    goto end; //String
    }
    }

    // response_transaction->gas
    cJSON *gas = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "Gas");
    if (gas) { 
    if(!cJSON_IsString(gas) && !cJSON_IsNull(gas))
    {
    goto end; //String
    }
    }

    // response_transaction->gas_price
    cJSON *gas_price = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "GasPrice");
    if (gas_price) { 
    if(!cJSON_IsString(gas_price) && !cJSON_IsNull(gas_price))
    {
    goto end; //String
    }
    }

    // response_transaction->hash
    cJSON *hash = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "Hash");
    if (hash) { 
    if(!cJSON_IsString(hash) && !cJSON_IsNull(hash))
    {
    goto end; //String
    }
    }

    // response_transaction->input
    cJSON *input = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "Input");
    if (input) { 
    if(!cJSON_IsString(input) && !cJSON_IsNull(input))
    {
    goto end; //String
    }
    }

    // response_transaction->max_fee_per_gas
    cJSON *max_fee_per_gas = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "MaxFeePerGas");
    if (max_fee_per_gas) { 
    if(!cJSON_IsString(max_fee_per_gas) && !cJSON_IsNull(max_fee_per_gas))
    {
    goto end; //String
    }
    }

    // response_transaction->max_priority_fee_per_gas
    cJSON *max_priority_fee_per_gas = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "MaxPriorityFeePerGas");
    if (max_priority_fee_per_gas) { 
    if(!cJSON_IsString(max_priority_fee_per_gas) && !cJSON_IsNull(max_priority_fee_per_gas))
    {
    goto end; //String
    }
    }

    // response_transaction->nonce
    cJSON *nonce = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "Nonce");
    if (nonce) { 
    if(!cJSON_IsString(nonce) && !cJSON_IsNull(nonce))
    {
    goto end; //String
    }
    }

    // response_transaction->r
    cJSON *r = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "R");
    if (r) { 
    if(!cJSON_IsString(r) && !cJSON_IsNull(r))
    {
    goto end; //String
    }
    }

    // response_transaction->s
    cJSON *s = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "S");
    if (s) { 
    if(!cJSON_IsString(s) && !cJSON_IsNull(s))
    {
    goto end; //String
    }
    }

    // response_transaction->to
    cJSON *to = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "To");
    if (to) { 
    if(!cJSON_IsString(to) && !cJSON_IsNull(to))
    {
    goto end; //String
    }
    }

    // response_transaction->transaction_index
    cJSON *transaction_index = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "TransactionIndex");
    if (transaction_index) { 
    if(!cJSON_IsString(transaction_index) && !cJSON_IsNull(transaction_index))
    {
    goto end; //String
    }
    }

    // response_transaction->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "Type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // response_transaction->v
    cJSON *v = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "V");
    if (v) { 
    if(!cJSON_IsString(v) && !cJSON_IsNull(v))
    {
    goto end; //String
    }
    }

    // response_transaction->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(response_transactionJSON, "Value");
    if (value) { 
    if(!cJSON_IsString(value) && !cJSON_IsNull(value))
    {
    goto end; //String
    }
    }


    response_transaction_local_var = response_transaction_create (
        access_list && !cJSON_IsNull(access_list) ? strdup(access_list->valuestring) : NULL,
        block_hash && !cJSON_IsNull(block_hash) ? strdup(block_hash->valuestring) : NULL,
        block_number && !cJSON_IsNull(block_number) ? strdup(block_number->valuestring) : NULL,
        chain_id && !cJSON_IsNull(chain_id) ? strdup(chain_id->valuestring) : NULL,
        from && !cJSON_IsNull(from) ? strdup(from->valuestring) : NULL,
        gas && !cJSON_IsNull(gas) ? strdup(gas->valuestring) : NULL,
        gas_price && !cJSON_IsNull(gas_price) ? strdup(gas_price->valuestring) : NULL,
        hash && !cJSON_IsNull(hash) ? strdup(hash->valuestring) : NULL,
        input && !cJSON_IsNull(input) ? strdup(input->valuestring) : NULL,
        max_fee_per_gas && !cJSON_IsNull(max_fee_per_gas) ? strdup(max_fee_per_gas->valuestring) : NULL,
        max_priority_fee_per_gas && !cJSON_IsNull(max_priority_fee_per_gas) ? strdup(max_priority_fee_per_gas->valuestring) : NULL,
        nonce && !cJSON_IsNull(nonce) ? strdup(nonce->valuestring) : NULL,
        r && !cJSON_IsNull(r) ? strdup(r->valuestring) : NULL,
        s && !cJSON_IsNull(s) ? strdup(s->valuestring) : NULL,
        to && !cJSON_IsNull(to) ? strdup(to->valuestring) : NULL,
        transaction_index && !cJSON_IsNull(transaction_index) ? strdup(transaction_index->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        v && !cJSON_IsNull(v) ? strdup(v->valuestring) : NULL,
        value && !cJSON_IsNull(value) ? strdup(value->valuestring) : NULL
        );

    return response_transaction_local_var;
end:
    return NULL;

}
