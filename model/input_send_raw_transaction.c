#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_send_raw_transaction.h"



input_send_raw_transaction_t *input_send_raw_transaction_create(
    char *schema,
    char *data
    ) {
    input_send_raw_transaction_t *input_send_raw_transaction_local_var = malloc(sizeof(input_send_raw_transaction_t));
    if (!input_send_raw_transaction_local_var) {
        return NULL;
    }
    input_send_raw_transaction_local_var->schema = schema;
    input_send_raw_transaction_local_var->data = data;

    return input_send_raw_transaction_local_var;
}


void input_send_raw_transaction_free(input_send_raw_transaction_t *input_send_raw_transaction) {
    if(NULL == input_send_raw_transaction){
        return ;
    }
    listEntry_t *listEntry;
    if (input_send_raw_transaction->schema) {
        free(input_send_raw_transaction->schema);
        input_send_raw_transaction->schema = NULL;
    }
    if (input_send_raw_transaction->data) {
        free(input_send_raw_transaction->data);
        input_send_raw_transaction->data = NULL;
    }
    free(input_send_raw_transaction);
}

cJSON *input_send_raw_transaction_convertToJSON(input_send_raw_transaction_t *input_send_raw_transaction) {
    cJSON *item = cJSON_CreateObject();

    // input_send_raw_transaction->schema
    if(input_send_raw_transaction->schema) {
    if(cJSON_AddStringToObject(item, "$schema", input_send_raw_transaction->schema) == NULL) {
    goto fail; //String
    }
    }


    // input_send_raw_transaction->data
    if (!input_send_raw_transaction->data) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Data", input_send_raw_transaction->data) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

input_send_raw_transaction_t *input_send_raw_transaction_parseFromJSON(cJSON *input_send_raw_transactionJSON){

    input_send_raw_transaction_t *input_send_raw_transaction_local_var = NULL;

    // input_send_raw_transaction->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(input_send_raw_transactionJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // input_send_raw_transaction->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(input_send_raw_transactionJSON, "Data");
    if (!data) {
        goto end;
    }

    
    if(!cJSON_IsString(data))
    {
    goto end; //String
    }


    input_send_raw_transaction_local_var = input_send_raw_transaction_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(data->valuestring)
        );

    return input_send_raw_transaction_local_var;
end:
    return NULL;

}
