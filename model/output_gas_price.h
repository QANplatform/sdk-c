/*
 * output_gas_price.h
 *
 * 
 */

#ifndef _output_gas_price_H_
#define _output_gas_price_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_gas_price_t output_gas_price_t;




typedef struct output_gas_price_t {
    char *schema; // string
    char *gas_price; // string

} output_gas_price_t;

output_gas_price_t *output_gas_price_create(
    char *schema,
    char *gas_price
);

void output_gas_price_free(output_gas_price_t *output_gas_price);

output_gas_price_t *output_gas_price_parseFromJSON(cJSON *output_gas_priceJSON);

cJSON *output_gas_price_convertToJSON(output_gas_price_t *output_gas_price);

#endif /* _output_gas_price_H_ */

