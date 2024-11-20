#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "params_transaction.h"



params_transaction_t *params_transaction_create(
    char *data,
    char *from,
    char *gas,
    char *gas_price,
    char *to,
    char *value
    ) {
    params_transaction_t *params_transaction_local_var = malloc(sizeof(params_transaction_t));
    if (!params_transaction_local_var) {
        return NULL;
    }
    params_transaction_local_var->data = data;
    params_transaction_local_var->from = from;
    params_transaction_local_var->gas = gas;
    params_transaction_local_var->gas_price = gas_price;
    params_transaction_local_var->to = to;
    params_transaction_local_var->value = value;

    return params_transaction_local_var;
}


void params_transaction_free(params_transaction_t *params_transaction) {
    if(NULL == params_transaction){
        return ;
    }
    listEntry_t *listEntry;
    if (params_transaction->data) {
        free(params_transaction->data);
        params_transaction->data = NULL;
    }
    if (params_transaction->from) {
        free(params_transaction->from);
        params_transaction->from = NULL;
    }
    if (params_transaction->gas) {
        free(params_transaction->gas);
        params_transaction->gas = NULL;
    }
    if (params_transaction->gas_price) {
        free(params_transaction->gas_price);
        params_transaction->gas_price = NULL;
    }
    if (params_transaction->to) {
        free(params_transaction->to);
        params_transaction->to = NULL;
    }
    if (params_transaction->value) {
        free(params_transaction->value);
        params_transaction->value = NULL;
    }
    free(params_transaction);
}

cJSON *params_transaction_convertToJSON(params_transaction_t *params_transaction) {
    cJSON *item = cJSON_CreateObject();

    // params_transaction->data
    if(params_transaction->data) {
    if(cJSON_AddStringToObject(item, "Data", params_transaction->data) == NULL) {
    goto fail; //String
    }
    }


    // params_transaction->from
    if(params_transaction->from) {
    if(cJSON_AddStringToObject(item, "From", params_transaction->from) == NULL) {
    goto fail; //String
    }
    }


    // params_transaction->gas
    if(params_transaction->gas) {
    if(cJSON_AddStringToObject(item, "Gas", params_transaction->gas) == NULL) {
    goto fail; //String
    }
    }


    // params_transaction->gas_price
    if(params_transaction->gas_price) {
    if(cJSON_AddStringToObject(item, "GasPrice", params_transaction->gas_price) == NULL) {
    goto fail; //String
    }
    }


    // params_transaction->to
    if (!params_transaction->to) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "To", params_transaction->to) == NULL) {
    goto fail; //String
    }


    // params_transaction->value
    if(params_transaction->value) {
    if(cJSON_AddStringToObject(item, "Value", params_transaction->value) == NULL) {
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

params_transaction_t *params_transaction_parseFromJSON(cJSON *params_transactionJSON){

    params_transaction_t *params_transaction_local_var = NULL;

    // params_transaction->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(params_transactionJSON, "Data");
    if (data) { 
    if(!cJSON_IsString(data) && !cJSON_IsNull(data))
    {
    goto end; //String
    }
    }

    // params_transaction->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(params_transactionJSON, "From");
    if (from) { 
    if(!cJSON_IsString(from) && !cJSON_IsNull(from))
    {
    goto end; //String
    }
    }

    // params_transaction->gas
    cJSON *gas = cJSON_GetObjectItemCaseSensitive(params_transactionJSON, "Gas");
    if (gas) { 
    if(!cJSON_IsString(gas) && !cJSON_IsNull(gas))
    {
    goto end; //String
    }
    }

    // params_transaction->gas_price
    cJSON *gas_price = cJSON_GetObjectItemCaseSensitive(params_transactionJSON, "GasPrice");
    if (gas_price) { 
    if(!cJSON_IsString(gas_price) && !cJSON_IsNull(gas_price))
    {
    goto end; //String
    }
    }

    // params_transaction->to
    cJSON *to = cJSON_GetObjectItemCaseSensitive(params_transactionJSON, "To");
    if (!to) {
        goto end;
    }

    
    if(!cJSON_IsString(to))
    {
    goto end; //String
    }

    // params_transaction->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(params_transactionJSON, "Value");
    if (value) { 
    if(!cJSON_IsString(value) && !cJSON_IsNull(value))
    {
    goto end; //String
    }
    }


    params_transaction_local_var = params_transaction_create (
        data && !cJSON_IsNull(data) ? strdup(data->valuestring) : NULL,
        from && !cJSON_IsNull(from) ? strdup(from->valuestring) : NULL,
        gas && !cJSON_IsNull(gas) ? strdup(gas->valuestring) : NULL,
        gas_price && !cJSON_IsNull(gas_price) ? strdup(gas_price->valuestring) : NULL,
        strdup(to->valuestring),
        value && !cJSON_IsNull(value) ? strdup(value->valuestring) : NULL
        );

    return params_transaction_local_var;
end:
    return NULL;

}
