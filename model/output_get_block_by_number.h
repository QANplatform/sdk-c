/*
 * output_get_block_by_number.h
 *
 * 
 */

#ifndef _output_get_block_by_number_H_
#define _output_get_block_by_number_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_get_block_by_number_t output_get_block_by_number_t;

#include "response_block.h"



typedef struct output_get_block_by_number_t {
    char *schema; // string
    struct response_block_t *block; //model

} output_get_block_by_number_t;

output_get_block_by_number_t *output_get_block_by_number_create(
    char *schema,
    response_block_t *block
);

void output_get_block_by_number_free(output_get_block_by_number_t *output_get_block_by_number);

output_get_block_by_number_t *output_get_block_by_number_parseFromJSON(cJSON *output_get_block_by_numberJSON);

cJSON *output_get_block_by_number_convertToJSON(output_get_block_by_number_t *output_get_block_by_number);

#endif /* _output_get_block_by_number_H_ */

