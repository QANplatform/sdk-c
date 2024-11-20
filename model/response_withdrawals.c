#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "response_withdrawals.h"



response_withdrawals_t *response_withdrawals_create(
    char *address,
    char *amount,
    int index,
    int validator_index
    ) {
    response_withdrawals_t *response_withdrawals_local_var = malloc(sizeof(response_withdrawals_t));
    if (!response_withdrawals_local_var) {
        return NULL;
    }
    response_withdrawals_local_var->address = address;
    response_withdrawals_local_var->amount = amount;
    response_withdrawals_local_var->index = index;
    response_withdrawals_local_var->validator_index = validator_index;

    return response_withdrawals_local_var;
}


void response_withdrawals_free(response_withdrawals_t *response_withdrawals) {
    if(NULL == response_withdrawals){
        return ;
    }
    listEntry_t *listEntry;
    if (response_withdrawals->address) {
        free(response_withdrawals->address);
        response_withdrawals->address = NULL;
    }
    if (response_withdrawals->amount) {
        free(response_withdrawals->amount);
        response_withdrawals->amount = NULL;
    }
    free(response_withdrawals);
}

cJSON *response_withdrawals_convertToJSON(response_withdrawals_t *response_withdrawals) {
    cJSON *item = cJSON_CreateObject();

    // response_withdrawals->address
    if (!response_withdrawals->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Address", response_withdrawals->address) == NULL) {
    goto fail; //String
    }


    // response_withdrawals->amount
    if (!response_withdrawals->amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Amount", response_withdrawals->amount) == NULL) {
    goto fail; //String
    }


    // response_withdrawals->index
    if (!response_withdrawals->index) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "Index", response_withdrawals->index) == NULL) {
    goto fail; //Numeric
    }


    // response_withdrawals->validator_index
    if (!response_withdrawals->validator_index) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "ValidatorIndex", response_withdrawals->validator_index) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

response_withdrawals_t *response_withdrawals_parseFromJSON(cJSON *response_withdrawalsJSON){

    response_withdrawals_t *response_withdrawals_local_var = NULL;

    // response_withdrawals->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(response_withdrawalsJSON, "Address");
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // response_withdrawals->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(response_withdrawalsJSON, "Amount");
    if (!amount) {
        goto end;
    }

    
    if(!cJSON_IsString(amount))
    {
    goto end; //String
    }

    // response_withdrawals->index
    cJSON *index = cJSON_GetObjectItemCaseSensitive(response_withdrawalsJSON, "Index");
    if (!index) {
        goto end;
    }

    
    if(!cJSON_IsNumber(index))
    {
    goto end; //Numeric
    }

    // response_withdrawals->validator_index
    cJSON *validator_index = cJSON_GetObjectItemCaseSensitive(response_withdrawalsJSON, "ValidatorIndex");
    if (!validator_index) {
        goto end;
    }

    
    if(!cJSON_IsNumber(validator_index))
    {
    goto end; //Numeric
    }


    response_withdrawals_local_var = response_withdrawals_create (
        strdup(address->valuestring),
        strdup(amount->valuestring),
        index->valuedouble,
        validator_index->valuedouble
        );

    return response_withdrawals_local_var;
end:
    return NULL;

}
