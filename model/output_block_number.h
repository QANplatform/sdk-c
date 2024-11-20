/*
 * output_block_number.h
 *
 * 
 */

#ifndef _output_block_number_H_
#define _output_block_number_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_block_number_t output_block_number_t;




typedef struct output_block_number_t {
    char *schema; // string
    char *block_number; // string

} output_block_number_t;

output_block_number_t *output_block_number_create(
    char *schema,
    char *block_number
);

void output_block_number_free(output_block_number_t *output_block_number);

output_block_number_t *output_block_number_parseFromJSON(cJSON *output_block_numberJSON);

cJSON *output_block_number_convertToJSON(output_block_number_t *output_block_number);

#endif /* _output_block_number_H_ */

