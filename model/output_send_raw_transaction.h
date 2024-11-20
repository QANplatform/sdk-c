/*
 * output_send_raw_transaction.h
 *
 * 
 */

#ifndef _output_send_raw_transaction_H_
#define _output_send_raw_transaction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_send_raw_transaction_t output_send_raw_transaction_t;




typedef struct output_send_raw_transaction_t {
    char *schema; // string
    char *transaction_hash; // string

} output_send_raw_transaction_t;

output_send_raw_transaction_t *output_send_raw_transaction_create(
    char *schema,
    char *transaction_hash
);

void output_send_raw_transaction_free(output_send_raw_transaction_t *output_send_raw_transaction);

output_send_raw_transaction_t *output_send_raw_transaction_parseFromJSON(cJSON *output_send_raw_transactionJSON);

cJSON *output_send_raw_transaction_convertToJSON(output_send_raw_transaction_t *output_send_raw_transaction);

#endif /* _output_send_raw_transaction_H_ */

