/*
 * output_get_block_by_hash.h
 *
 * 
 */

#ifndef _output_get_block_by_hash_H_
#define _output_get_block_by_hash_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_get_block_by_hash_t output_get_block_by_hash_t;

#include "response_block.h"



typedef struct output_get_block_by_hash_t {
    char *schema; // string
    struct response_block_t *block; //model

} output_get_block_by_hash_t;

output_get_block_by_hash_t *output_get_block_by_hash_create(
    char *schema,
    response_block_t *block
);

void output_get_block_by_hash_free(output_get_block_by_hash_t *output_get_block_by_hash);

output_get_block_by_hash_t *output_get_block_by_hash_parseFromJSON(cJSON *output_get_block_by_hashJSON);

cJSON *output_get_block_by_hash_convertToJSON(output_get_block_by_hash_t *output_get_block_by_hash);

#endif /* _output_get_block_by_hash_H_ */

