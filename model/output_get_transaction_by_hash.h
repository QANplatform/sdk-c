/*
 * output_get_transaction_by_hash.h
 *
 * 
 */

#ifndef _output_get_transaction_by_hash_H_
#define _output_get_transaction_by_hash_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_get_transaction_by_hash_t output_get_transaction_by_hash_t;

#include "response_transaction.h"



typedef struct output_get_transaction_by_hash_t {
    char *schema; // string
    struct response_transaction_t *transaction; //model

} output_get_transaction_by_hash_t;

output_get_transaction_by_hash_t *output_get_transaction_by_hash_create(
    char *schema,
    response_transaction_t *transaction
);

void output_get_transaction_by_hash_free(output_get_transaction_by_hash_t *output_get_transaction_by_hash);

output_get_transaction_by_hash_t *output_get_transaction_by_hash_parseFromJSON(cJSON *output_get_transaction_by_hashJSON);

cJSON *output_get_transaction_by_hash_convertToJSON(output_get_transaction_by_hash_t *output_get_transaction_by_hash);

#endif /* _output_get_transaction_by_hash_H_ */

