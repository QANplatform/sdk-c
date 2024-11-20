/*
 * output_get_block_transaction_count_by_number.h
 *
 * 
 */

#ifndef _output_get_block_transaction_count_by_number_H_
#define _output_get_block_transaction_count_by_number_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_get_block_transaction_count_by_number_t output_get_block_transaction_count_by_number_t;




typedef struct output_get_block_transaction_count_by_number_t {
    char *schema; // string
    char *transaction_count; // string

} output_get_block_transaction_count_by_number_t;

output_get_block_transaction_count_by_number_t *output_get_block_transaction_count_by_number_create(
    char *schema,
    char *transaction_count
);

void output_get_block_transaction_count_by_number_free(output_get_block_transaction_count_by_number_t *output_get_block_transaction_count_by_number);

output_get_block_transaction_count_by_number_t *output_get_block_transaction_count_by_number_parseFromJSON(cJSON *output_get_block_transaction_count_by_numberJSON);

cJSON *output_get_block_transaction_count_by_number_convertToJSON(output_get_block_transaction_count_by_number_t *output_get_block_transaction_count_by_number);

#endif /* _output_get_block_transaction_count_by_number_H_ */

