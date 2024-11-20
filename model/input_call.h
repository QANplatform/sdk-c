/*
 * input_call.h
 *
 * 
 */

#ifndef _input_call_H_
#define _input_call_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_call_t input_call_t;

#include "params_transaction.h"



typedef struct input_call_t {
    char *schema; // string
    char *block_number; // string
    struct params_transaction_t *transaction; //model

} input_call_t;

input_call_t *input_call_create(
    char *schema,
    char *block_number,
    params_transaction_t *transaction
);

void input_call_free(input_call_t *input_call);

input_call_t *input_call_parseFromJSON(cJSON *input_callJSON);

cJSON *input_call_convertToJSON(input_call_t *input_call);

#endif /* _input_call_H_ */

