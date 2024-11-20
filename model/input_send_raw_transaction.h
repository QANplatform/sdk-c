/*
 * input_send_raw_transaction.h
 *
 * 
 */

#ifndef _input_send_raw_transaction_H_
#define _input_send_raw_transaction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_send_raw_transaction_t input_send_raw_transaction_t;




typedef struct input_send_raw_transaction_t {
    char *schema; // string
    char *data; // string

} input_send_raw_transaction_t;

input_send_raw_transaction_t *input_send_raw_transaction_create(
    char *schema,
    char *data
);

void input_send_raw_transaction_free(input_send_raw_transaction_t *input_send_raw_transaction);

input_send_raw_transaction_t *input_send_raw_transaction_parseFromJSON(cJSON *input_send_raw_transactionJSON);

cJSON *input_send_raw_transaction_convertToJSON(input_send_raw_transaction_t *input_send_raw_transaction);

#endif /* _input_send_raw_transaction_H_ */

