#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_gas_price.h"



output_gas_price_t *output_gas_price_create(
    char *schema,
    char *gas_price
    ) {
    output_gas_price_t *output_gas_price_local_var = malloc(sizeof(output_gas_price_t));
    if (!output_gas_price_local_var) {
        return NULL;
    }
    output_gas_price_local_var->schema = schema;
    output_gas_price_local_var->gas_price = gas_price;

    return output_gas_price_local_var;
}


void output_gas_price_free(output_gas_price_t *output_gas_price) {
    if(NULL == output_gas_price){
        return ;
    }
    listEntry_t *listEntry;
    if (output_gas_price->schema) {
        free(output_gas_price->schema);
        output_gas_price->schema = NULL;
    }
    if (output_gas_price->gas_price) {
        free(output_gas_price->gas_price);
        output_gas_price->gas_price = NULL;
    }
    free(output_gas_price);
}

cJSON *output_gas_price_convertToJSON(output_gas_price_t *output_gas_price) {
    cJSON *item = cJSON_CreateObject();

    // output_gas_price->schema
    if(output_gas_price->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_gas_price->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_gas_price->gas_price
    if (!output_gas_price->gas_price) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "GasPrice", output_gas_price->gas_price) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_gas_price_t *output_gas_price_parseFromJSON(cJSON *output_gas_priceJSON){

    output_gas_price_t *output_gas_price_local_var = NULL;

    // output_gas_price->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_gas_priceJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_gas_price->gas_price
    cJSON *gas_price = cJSON_GetObjectItemCaseSensitive(output_gas_priceJSON, "GasPrice");
    if (!gas_price) {
        goto end;
    }

    
    if(!cJSON_IsString(gas_price))
    {
    goto end; //String
    }


    output_gas_price_local_var = output_gas_price_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(gas_price->valuestring)
        );

    return output_gas_price_local_var;
end:
    return NULL;

}
