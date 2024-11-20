#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_get_balance.h"



output_get_balance_t *output_get_balance_create(
    char *schema,
    char *balance
    ) {
    output_get_balance_t *output_get_balance_local_var = malloc(sizeof(output_get_balance_t));
    if (!output_get_balance_local_var) {
        return NULL;
    }
    output_get_balance_local_var->schema = schema;
    output_get_balance_local_var->balance = balance;

    return output_get_balance_local_var;
}


void output_get_balance_free(output_get_balance_t *output_get_balance) {
    if(NULL == output_get_balance){
        return ;
    }
    listEntry_t *listEntry;
    if (output_get_balance->schema) {
        free(output_get_balance->schema);
        output_get_balance->schema = NULL;
    }
    if (output_get_balance->balance) {
        free(output_get_balance->balance);
        output_get_balance->balance = NULL;
    }
    free(output_get_balance);
}

cJSON *output_get_balance_convertToJSON(output_get_balance_t *output_get_balance) {
    cJSON *item = cJSON_CreateObject();

    // output_get_balance->schema
    if(output_get_balance->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_get_balance->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_get_balance->balance
    if (!output_get_balance->balance) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Balance", output_get_balance->balance) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_get_balance_t *output_get_balance_parseFromJSON(cJSON *output_get_balanceJSON){

    output_get_balance_t *output_get_balance_local_var = NULL;

    // output_get_balance->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_get_balanceJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_get_balance->balance
    cJSON *balance = cJSON_GetObjectItemCaseSensitive(output_get_balanceJSON, "Balance");
    if (!balance) {
        goto end;
    }

    
    if(!cJSON_IsString(balance))
    {
    goto end; //String
    }


    output_get_balance_local_var = output_get_balance_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(balance->valuestring)
        );

    return output_get_balance_local_var;
end:
    return NULL;

}
