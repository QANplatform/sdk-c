#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_estimate_gas.h"



input_estimate_gas_t *input_estimate_gas_create(
    char *schema,
    estimate_gas_object_t *object,
    params_transaction_t *transaction
    ) {
    input_estimate_gas_t *input_estimate_gas_local_var = malloc(sizeof(input_estimate_gas_t));
    if (!input_estimate_gas_local_var) {
        return NULL;
    }
    input_estimate_gas_local_var->schema = schema;
    input_estimate_gas_local_var->object = object;
    input_estimate_gas_local_var->transaction = transaction;

    return input_estimate_gas_local_var;
}


void input_estimate_gas_free(input_estimate_gas_t *input_estimate_gas) {
    if(NULL == input_estimate_gas){
        return ;
    }
    listEntry_t *listEntry;
    if (input_estimate_gas->schema) {
        free(input_estimate_gas->schema);
        input_estimate_gas->schema = NULL;
    }
    if (input_estimate_gas->object) {
        estimate_gas_object_free(input_estimate_gas->object);
        input_estimate_gas->object = NULL;
    }
    if (input_estimate_gas->transaction) {
        params_transaction_free(input_estimate_gas->transaction);
        input_estimate_gas->transaction = NULL;
    }
    free(input_estimate_gas);
}

cJSON *input_estimate_gas_convertToJSON(input_estimate_gas_t *input_estimate_gas) {
    cJSON *item = cJSON_CreateObject();

    // input_estimate_gas->schema
    if(input_estimate_gas->schema) {
    if(cJSON_AddStringToObject(item, "$schema", input_estimate_gas->schema) == NULL) {
    goto fail; //String
    }
    }


    // input_estimate_gas->object
    if(input_estimate_gas->object) {
    cJSON *object_local_JSON = estimate_gas_object_convertToJSON(input_estimate_gas->object);
    if(object_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "Object", object_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_estimate_gas->transaction
    if (!input_estimate_gas->transaction) {
        goto fail;
    }
    cJSON *transaction_local_JSON = params_transaction_convertToJSON(input_estimate_gas->transaction);
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

input_estimate_gas_t *input_estimate_gas_parseFromJSON(cJSON *input_estimate_gasJSON){

    input_estimate_gas_t *input_estimate_gas_local_var = NULL;

    // define the local variable for input_estimate_gas->object
    estimate_gas_object_t *object_local_nonprim = NULL;

    // define the local variable for input_estimate_gas->transaction
    params_transaction_t *transaction_local_nonprim = NULL;

    // input_estimate_gas->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(input_estimate_gasJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // input_estimate_gas->object
    cJSON *object = cJSON_GetObjectItemCaseSensitive(input_estimate_gasJSON, "Object");
    if (object) { 
    object_local_nonprim = estimate_gas_object_parseFromJSON(object); //nonprimitive
    }

    // input_estimate_gas->transaction
    cJSON *transaction = cJSON_GetObjectItemCaseSensitive(input_estimate_gasJSON, "Transaction");
    if (!transaction) {
        goto end;
    }

    
    transaction_local_nonprim = params_transaction_parseFromJSON(transaction); //nonprimitive


    input_estimate_gas_local_var = input_estimate_gas_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        object ? object_local_nonprim : NULL,
        transaction_local_nonprim
        );

    return input_estimate_gas_local_var;
end:
    if (object_local_nonprim) {
        estimate_gas_object_free(object_local_nonprim);
        object_local_nonprim = NULL;
    }
    if (transaction_local_nonprim) {
        params_transaction_free(transaction_local_nonprim);
        transaction_local_nonprim = NULL;
    }
    return NULL;

}
