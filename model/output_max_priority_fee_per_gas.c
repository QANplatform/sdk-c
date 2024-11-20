#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_max_priority_fee_per_gas.h"



output_max_priority_fee_per_gas_t *output_max_priority_fee_per_gas_create(
    char *schema,
    char *max_priority_fee_per_gas
    ) {
    output_max_priority_fee_per_gas_t *output_max_priority_fee_per_gas_local_var = malloc(sizeof(output_max_priority_fee_per_gas_t));
    if (!output_max_priority_fee_per_gas_local_var) {
        return NULL;
    }
    output_max_priority_fee_per_gas_local_var->schema = schema;
    output_max_priority_fee_per_gas_local_var->max_priority_fee_per_gas = max_priority_fee_per_gas;

    return output_max_priority_fee_per_gas_local_var;
}


void output_max_priority_fee_per_gas_free(output_max_priority_fee_per_gas_t *output_max_priority_fee_per_gas) {
    if(NULL == output_max_priority_fee_per_gas){
        return ;
    }
    listEntry_t *listEntry;
    if (output_max_priority_fee_per_gas->schema) {
        free(output_max_priority_fee_per_gas->schema);
        output_max_priority_fee_per_gas->schema = NULL;
    }
    if (output_max_priority_fee_per_gas->max_priority_fee_per_gas) {
        free(output_max_priority_fee_per_gas->max_priority_fee_per_gas);
        output_max_priority_fee_per_gas->max_priority_fee_per_gas = NULL;
    }
    free(output_max_priority_fee_per_gas);
}

cJSON *output_max_priority_fee_per_gas_convertToJSON(output_max_priority_fee_per_gas_t *output_max_priority_fee_per_gas) {
    cJSON *item = cJSON_CreateObject();

    // output_max_priority_fee_per_gas->schema
    if(output_max_priority_fee_per_gas->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_max_priority_fee_per_gas->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_max_priority_fee_per_gas->max_priority_fee_per_gas
    if (!output_max_priority_fee_per_gas->max_priority_fee_per_gas) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "MaxPriorityFeePerGas", output_max_priority_fee_per_gas->max_priority_fee_per_gas) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_max_priority_fee_per_gas_t *output_max_priority_fee_per_gas_parseFromJSON(cJSON *output_max_priority_fee_per_gasJSON){

    output_max_priority_fee_per_gas_t *output_max_priority_fee_per_gas_local_var = NULL;

    // output_max_priority_fee_per_gas->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_max_priority_fee_per_gasJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_max_priority_fee_per_gas->max_priority_fee_per_gas
    cJSON *max_priority_fee_per_gas = cJSON_GetObjectItemCaseSensitive(output_max_priority_fee_per_gasJSON, "MaxPriorityFeePerGas");
    if (!max_priority_fee_per_gas) {
        goto end;
    }

    
    if(!cJSON_IsString(max_priority_fee_per_gas))
    {
    goto end; //String
    }


    output_max_priority_fee_per_gas_local_var = output_max_priority_fee_per_gas_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(max_priority_fee_per_gas->valuestring)
        );

    return output_max_priority_fee_per_gas_local_var;
end:
    return NULL;

}
