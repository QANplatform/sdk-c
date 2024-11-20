/*
 * output_estimate_gas.h
 *
 * 
 */

#ifndef _output_estimate_gas_H_
#define _output_estimate_gas_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_estimate_gas_t output_estimate_gas_t;




typedef struct output_estimate_gas_t {
    char *schema; // string
    char *estimated_gas; // string

} output_estimate_gas_t;

output_estimate_gas_t *output_estimate_gas_create(
    char *schema,
    char *estimated_gas
);

void output_estimate_gas_free(output_estimate_gas_t *output_estimate_gas);

output_estimate_gas_t *output_estimate_gas_parseFromJSON(cJSON *output_estimate_gasJSON);

cJSON *output_estimate_gas_convertToJSON(output_estimate_gas_t *output_estimate_gas);

#endif /* _output_estimate_gas_H_ */

