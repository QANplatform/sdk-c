/*
 * output_get_transaction_by_block_number_and_index.h
 *
 * 
 */

#ifndef _output_get_transaction_by_block_number_and_index_H_
#define _output_get_transaction_by_block_number_and_index_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_get_transaction_by_block_number_and_index_t output_get_transaction_by_block_number_and_index_t;

#include "response_transaction.h"



typedef struct output_get_transaction_by_block_number_and_index_t {
    char *schema; // string
    struct response_transaction_t *transaction; //model

} output_get_transaction_by_block_number_and_index_t;

output_get_transaction_by_block_number_and_index_t *output_get_transaction_by_block_number_and_index_create(
    char *schema,
    response_transaction_t *transaction
);

void output_get_transaction_by_block_number_and_index_free(output_get_transaction_by_block_number_and_index_t *output_get_transaction_by_block_number_and_index);

output_get_transaction_by_block_number_and_index_t *output_get_transaction_by_block_number_and_index_parseFromJSON(cJSON *output_get_transaction_by_block_number_and_indexJSON);

cJSON *output_get_transaction_by_block_number_and_index_convertToJSON(output_get_transaction_by_block_number_and_index_t *output_get_transaction_by_block_number_and_index);

#endif /* _output_get_transaction_by_block_number_and_index_H_ */

