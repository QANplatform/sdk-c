/*
 * output_get_block_receipts.h
 *
 * 
 */

#ifndef _output_get_block_receipts_H_
#define _output_get_block_receipts_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_get_block_receipts_t output_get_block_receipts_t;

#include "response_transaction_receipt.h"



typedef struct output_get_block_receipts_t {
    char *schema; // string
    list_t *transaction_receipts; //nonprimitive container

} output_get_block_receipts_t;

output_get_block_receipts_t *output_get_block_receipts_create(
    char *schema,
    list_t *transaction_receipts
);

void output_get_block_receipts_free(output_get_block_receipts_t *output_get_block_receipts);

output_get_block_receipts_t *output_get_block_receipts_parseFromJSON(cJSON *output_get_block_receiptsJSON);

cJSON *output_get_block_receipts_convertToJSON(output_get_block_receipts_t *output_get_block_receipts);

#endif /* _output_get_block_receipts_H_ */

