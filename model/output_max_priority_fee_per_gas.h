/*
 * output_max_priority_fee_per_gas.h
 *
 * 
 */

#ifndef _output_max_priority_fee_per_gas_H_
#define _output_max_priority_fee_per_gas_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_max_priority_fee_per_gas_t output_max_priority_fee_per_gas_t;




typedef struct output_max_priority_fee_per_gas_t {
    char *schema; // string
    char *max_priority_fee_per_gas; // string

} output_max_priority_fee_per_gas_t;

output_max_priority_fee_per_gas_t *output_max_priority_fee_per_gas_create(
    char *schema,
    char *max_priority_fee_per_gas
);

void output_max_priority_fee_per_gas_free(output_max_priority_fee_per_gas_t *output_max_priority_fee_per_gas);

output_max_priority_fee_per_gas_t *output_max_priority_fee_per_gas_parseFromJSON(cJSON *output_max_priority_fee_per_gasJSON);

cJSON *output_max_priority_fee_per_gas_convertToJSON(output_max_priority_fee_per_gas_t *output_max_priority_fee_per_gas);

#endif /* _output_max_priority_fee_per_gas_H_ */

