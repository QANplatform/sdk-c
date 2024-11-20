/*
 * output_get_transaction_count.h
 *
 * 
 */

#ifndef _output_get_transaction_count_H_
#define _output_get_transaction_count_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_get_transaction_count_t output_get_transaction_count_t;




typedef struct output_get_transaction_count_t {
    char *schema; // string
    char *transaction_count; // string

} output_get_transaction_count_t;

output_get_transaction_count_t *output_get_transaction_count_create(
    char *schema,
    char *transaction_count
);

void output_get_transaction_count_free(output_get_transaction_count_t *output_get_transaction_count);

output_get_transaction_count_t *output_get_transaction_count_parseFromJSON(cJSON *output_get_transaction_countJSON);

cJSON *output_get_transaction_count_convertToJSON(output_get_transaction_count_t *output_get_transaction_count);

#endif /* _output_get_transaction_count_H_ */

