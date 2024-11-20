/*
 * response_transaction_receipt.h
 *
 * 
 */

#ifndef _response_transaction_receipt_H_
#define _response_transaction_receipt_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct response_transaction_receipt_t response_transaction_receipt_t;

#include "response_log.h"



typedef struct response_transaction_receipt_t {
    char *block_hash; // string
    char *block_number; // string
    char *contract_address; // string
    char *cumulative_gas_used; // string
    char *effective_gas_price; // string
    char *from; // string
    char *gas_used; // string
    list_t *logs; //nonprimitive container
    char *logs_bloom; // string
    char *status; // string
    char *to; // string
    char *transaction_hash; // string
    char *transaction_index; // string
    char *type; // string

} response_transaction_receipt_t;

response_transaction_receipt_t *response_transaction_receipt_create(
    char *block_hash,
    char *block_number,
    char *contract_address,
    char *cumulative_gas_used,
    char *effective_gas_price,
    char *from,
    char *gas_used,
    list_t *logs,
    char *logs_bloom,
    char *status,
    char *to,
    char *transaction_hash,
    char *transaction_index,
    char *type
);

void response_transaction_receipt_free(response_transaction_receipt_t *response_transaction_receipt);

response_transaction_receipt_t *response_transaction_receipt_parseFromJSON(cJSON *response_transaction_receiptJSON);

cJSON *response_transaction_receipt_convertToJSON(response_transaction_receipt_t *response_transaction_receipt);

#endif /* _response_transaction_receipt_H_ */

