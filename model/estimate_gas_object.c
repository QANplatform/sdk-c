#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "estimate_gas_object.h"



estimate_gas_object_t *estimate_gas_object_create(
    char *balance,
    int code,
    char *nonce,
    char *state,
    char *state_diff
    ) {
    estimate_gas_object_t *estimate_gas_object_local_var = malloc(sizeof(estimate_gas_object_t));
    if (!estimate_gas_object_local_var) {
        return NULL;
    }
    estimate_gas_object_local_var->balance = balance;
    estimate_gas_object_local_var->code = code;
    estimate_gas_object_local_var->nonce = nonce;
    estimate_gas_object_local_var->state = state;
    estimate_gas_object_local_var->state_diff = state_diff;

    return estimate_gas_object_local_var;
}


void estimate_gas_object_free(estimate_gas_object_t *estimate_gas_object) {
    if(NULL == estimate_gas_object){
        return ;
    }
    listEntry_t *listEntry;
    if (estimate_gas_object->balance) {
        free(estimate_gas_object->balance);
        estimate_gas_object->balance = NULL;
    }
    if (estimate_gas_object->nonce) {
        free(estimate_gas_object->nonce);
        estimate_gas_object->nonce = NULL;
    }
    if (estimate_gas_object->state) {
        free(estimate_gas_object->state);
        estimate_gas_object->state = NULL;
    }
    if (estimate_gas_object->state_diff) {
        free(estimate_gas_object->state_diff);
        estimate_gas_object->state_diff = NULL;
    }
    free(estimate_gas_object);
}

cJSON *estimate_gas_object_convertToJSON(estimate_gas_object_t *estimate_gas_object) {
    cJSON *item = cJSON_CreateObject();

    // estimate_gas_object->balance
    if(estimate_gas_object->balance) {
    if(cJSON_AddStringToObject(item, "Balance", estimate_gas_object->balance) == NULL) {
    goto fail; //String
    }
    }


    // estimate_gas_object->code
    if(estimate_gas_object->code) {
    if(cJSON_AddNumberToObject(item, "Code", estimate_gas_object->code) == NULL) {
    goto fail; //Numeric
    }
    }


    // estimate_gas_object->nonce
    if(estimate_gas_object->nonce) {
    if(cJSON_AddStringToObject(item, "Nonce", estimate_gas_object->nonce) == NULL) {
    goto fail; //String
    }
    }


    // estimate_gas_object->state
    if(estimate_gas_object->state) {
    if(cJSON_AddStringToObject(item, "State", estimate_gas_object->state) == NULL) {
    goto fail; //String
    }
    }


    // estimate_gas_object->state_diff
    if(estimate_gas_object->state_diff) {
    if(cJSON_AddStringToObject(item, "StateDiff", estimate_gas_object->state_diff) == NULL) {
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

estimate_gas_object_t *estimate_gas_object_parseFromJSON(cJSON *estimate_gas_objectJSON){

    estimate_gas_object_t *estimate_gas_object_local_var = NULL;

    // estimate_gas_object->balance
    cJSON *balance = cJSON_GetObjectItemCaseSensitive(estimate_gas_objectJSON, "Balance");
    if (balance) { 
    if(!cJSON_IsString(balance) && !cJSON_IsNull(balance))
    {
    goto end; //String
    }
    }

    // estimate_gas_object->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(estimate_gas_objectJSON, "Code");
    if (code) { 
    if(!cJSON_IsNumber(code))
    {
    goto end; //Numeric
    }
    }

    // estimate_gas_object->nonce
    cJSON *nonce = cJSON_GetObjectItemCaseSensitive(estimate_gas_objectJSON, "Nonce");
    if (nonce) { 
    if(!cJSON_IsString(nonce) && !cJSON_IsNull(nonce))
    {
    goto end; //String
    }
    }

    // estimate_gas_object->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(estimate_gas_objectJSON, "State");
    if (state) { 
    if(!cJSON_IsString(state) && !cJSON_IsNull(state))
    {
    goto end; //String
    }
    }

    // estimate_gas_object->state_diff
    cJSON *state_diff = cJSON_GetObjectItemCaseSensitive(estimate_gas_objectJSON, "StateDiff");
    if (state_diff) { 
    if(!cJSON_IsString(state_diff) && !cJSON_IsNull(state_diff))
    {
    goto end; //String
    }
    }


    estimate_gas_object_local_var = estimate_gas_object_create (
        balance && !cJSON_IsNull(balance) ? strdup(balance->valuestring) : NULL,
        code ? code->valuedouble : 0,
        nonce && !cJSON_IsNull(nonce) ? strdup(nonce->valuestring) : NULL,
        state && !cJSON_IsNull(state) ? strdup(state->valuestring) : NULL,
        state_diff && !cJSON_IsNull(state_diff) ? strdup(state_diff->valuestring) : NULL
        );

    return estimate_gas_object_local_var;
end:
    return NULL;

}
