#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_estimate_gas.h"



output_estimate_gas_t *output_estimate_gas_create(
    char *schema,
    char *estimated_gas
    ) {
    output_estimate_gas_t *output_estimate_gas_local_var = malloc(sizeof(output_estimate_gas_t));
    if (!output_estimate_gas_local_var) {
        return NULL;
    }
    output_estimate_gas_local_var->schema = schema;
    output_estimate_gas_local_var->estimated_gas = estimated_gas;

    return output_estimate_gas_local_var;
}


void output_estimate_gas_free(output_estimate_gas_t *output_estimate_gas) {
    if(NULL == output_estimate_gas){
        return ;
    }
    listEntry_t *listEntry;
    if (output_estimate_gas->schema) {
        free(output_estimate_gas->schema);
        output_estimate_gas->schema = NULL;
    }
    if (output_estimate_gas->estimated_gas) {
        free(output_estimate_gas->estimated_gas);
        output_estimate_gas->estimated_gas = NULL;
    }
    free(output_estimate_gas);
}

cJSON *output_estimate_gas_convertToJSON(output_estimate_gas_t *output_estimate_gas) {
    cJSON *item = cJSON_CreateObject();

    // output_estimate_gas->schema
    if(output_estimate_gas->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_estimate_gas->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_estimate_gas->estimated_gas
    if (!output_estimate_gas->estimated_gas) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "EstimatedGas", output_estimate_gas->estimated_gas) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_estimate_gas_t *output_estimate_gas_parseFromJSON(cJSON *output_estimate_gasJSON){

    output_estimate_gas_t *output_estimate_gas_local_var = NULL;

    // output_estimate_gas->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_estimate_gasJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_estimate_gas->estimated_gas
    cJSON *estimated_gas = cJSON_GetObjectItemCaseSensitive(output_estimate_gasJSON, "EstimatedGas");
    if (!estimated_gas) {
        goto end;
    }

    
    if(!cJSON_IsString(estimated_gas))
    {
    goto end; //String
    }


    output_estimate_gas_local_var = output_estimate_gas_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(estimated_gas->valuestring)
        );

    return output_estimate_gas_local_var;
end:
    return NULL;

}
