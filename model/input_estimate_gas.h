/*
 * input_estimate_gas.h
 *
 * 
 */

#ifndef _input_estimate_gas_H_
#define _input_estimate_gas_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_estimate_gas_t input_estimate_gas_t;

#include "estimate_gas_object.h"
#include "params_transaction.h"



typedef struct input_estimate_gas_t {
    char *schema; // string
    struct estimate_gas_object_t *object; //model
    struct params_transaction_t *transaction; //model

} input_estimate_gas_t;

input_estimate_gas_t *input_estimate_gas_create(
    char *schema,
    estimate_gas_object_t *object,
    params_transaction_t *transaction
);

void input_estimate_gas_free(input_estimate_gas_t *input_estimate_gas);

input_estimate_gas_t *input_estimate_gas_parseFromJSON(cJSON *input_estimate_gasJSON);

cJSON *input_estimate_gas_convertToJSON(input_estimate_gas_t *input_estimate_gas);

#endif /* _input_estimate_gas_H_ */

