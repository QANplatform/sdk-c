#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_get_block_transaction_count_by_number.h"



output_get_block_transaction_count_by_number_t *output_get_block_transaction_count_by_number_create(
    char *schema,
    char *transaction_count
    ) {
    output_get_block_transaction_count_by_number_t *output_get_block_transaction_count_by_number_local_var = malloc(sizeof(output_get_block_transaction_count_by_number_t));
    if (!output_get_block_transaction_count_by_number_local_var) {
        return NULL;
    }
    output_get_block_transaction_count_by_number_local_var->schema = schema;
    output_get_block_transaction_count_by_number_local_var->transaction_count = transaction_count;

    return output_get_block_transaction_count_by_number_local_var;
}


void output_get_block_transaction_count_by_number_free(output_get_block_transaction_count_by_number_t *output_get_block_transaction_count_by_number) {
    if(NULL == output_get_block_transaction_count_by_number){
        return ;
    }
    listEntry_t *listEntry;
    if (output_get_block_transaction_count_by_number->schema) {
        free(output_get_block_transaction_count_by_number->schema);
        output_get_block_transaction_count_by_number->schema = NULL;
    }
    if (output_get_block_transaction_count_by_number->transaction_count) {
        free(output_get_block_transaction_count_by_number->transaction_count);
        output_get_block_transaction_count_by_number->transaction_count = NULL;
    }
    free(output_get_block_transaction_count_by_number);
}

cJSON *output_get_block_transaction_count_by_number_convertToJSON(output_get_block_transaction_count_by_number_t *output_get_block_transaction_count_by_number) {
    cJSON *item = cJSON_CreateObject();

    // output_get_block_transaction_count_by_number->schema
    if(output_get_block_transaction_count_by_number->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_get_block_transaction_count_by_number->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_get_block_transaction_count_by_number->transaction_count
    if (!output_get_block_transaction_count_by_number->transaction_count) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "TransactionCount", output_get_block_transaction_count_by_number->transaction_count) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_get_block_transaction_count_by_number_t *output_get_block_transaction_count_by_number_parseFromJSON(cJSON *output_get_block_transaction_count_by_numberJSON){

    output_get_block_transaction_count_by_number_t *output_get_block_transaction_count_by_number_local_var = NULL;

    // output_get_block_transaction_count_by_number->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_get_block_transaction_count_by_numberJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_get_block_transaction_count_by_number->transaction_count
    cJSON *transaction_count = cJSON_GetObjectItemCaseSensitive(output_get_block_transaction_count_by_numberJSON, "TransactionCount");
    if (!transaction_count) {
        goto end;
    }

    
    if(!cJSON_IsString(transaction_count))
    {
    goto end; //String
    }


    output_get_block_transaction_count_by_number_local_var = output_get_block_transaction_count_by_number_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(transaction_count->valuestring)
        );

    return output_get_block_transaction_count_by_number_local_var;
end:
    return NULL;

}
