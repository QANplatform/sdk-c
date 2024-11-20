/*
 * params_transaction.h
 *
 * 
 */

#ifndef _params_transaction_H_
#define _params_transaction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct params_transaction_t params_transaction_t;




typedef struct params_transaction_t {
    char *data; // string
    char *from; // string
    char *gas; // string
    char *gas_price; // string
    char *to; // string
    char *value; // string

} params_transaction_t;

params_transaction_t *params_transaction_create(
    char *data,
    char *from,
    char *gas,
    char *gas_price,
    char *to,
    char *value
);

void params_transaction_free(params_transaction_t *params_transaction);

params_transaction_t *params_transaction_parseFromJSON(cJSON *params_transactionJSON);

cJSON *params_transaction_convertToJSON(params_transaction_t *params_transaction);

#endif /* _params_transaction_H_ */

