/*
 * output_get_transaction_receipt.h
 *
 * 
 */

#ifndef _output_get_transaction_receipt_H_
#define _output_get_transaction_receipt_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_get_transaction_receipt_t output_get_transaction_receipt_t;

#include "response_transaction_receipt.h"



typedef struct output_get_transaction_receipt_t {
    char *schema; // string
    struct response_transaction_receipt_t *transaction_receipt; //model

} output_get_transaction_receipt_t;

output_get_transaction_receipt_t *output_get_transaction_receipt_create(
    char *schema,
    response_transaction_receipt_t *transaction_receipt
);

void output_get_transaction_receipt_free(output_get_transaction_receipt_t *output_get_transaction_receipt);

output_get_transaction_receipt_t *output_get_transaction_receipt_parseFromJSON(cJSON *output_get_transaction_receiptJSON);

cJSON *output_get_transaction_receipt_convertToJSON(output_get_transaction_receipt_t *output_get_transaction_receipt);

#endif /* _output_get_transaction_receipt_H_ */

