/*
 * response_transaction.h
 *
 * 
 */

#ifndef _response_transaction_H_
#define _response_transaction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct response_transaction_t response_transaction_t;




typedef struct response_transaction_t {
    char *access_list; // string
    char *block_hash; // string
    char *block_number; // string
    char *chain_id; // string
    char *from; // string
    char *gas; // string
    char *gas_price; // string
    char *hash; // string
    char *input; // string
    char *max_fee_per_gas; // string
    char *max_priority_fee_per_gas; // string
    char *nonce; // string
    char *r; // string
    char *s; // string
    char *to; // string
    char *transaction_index; // string
    char *type; // string
    char *v; // string
    char *value; // string

} response_transaction_t;

response_transaction_t *response_transaction_create(
    char *access_list,
    char *block_hash,
    char *block_number,
    char *chain_id,
    char *from,
    char *gas,
    char *gas_price,
    char *hash,
    char *input,
    char *max_fee_per_gas,
    char *max_priority_fee_per_gas,
    char *nonce,
    char *r,
    char *s,
    char *to,
    char *transaction_index,
    char *type,
    char *v,
    char *value
);

void response_transaction_free(response_transaction_t *response_transaction);

response_transaction_t *response_transaction_parseFromJSON(cJSON *response_transactionJSON);

cJSON *response_transaction_convertToJSON(response_transaction_t *response_transaction);

#endif /* _response_transaction_H_ */

