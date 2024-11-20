/*
 * output_new_block_filter.h
 *
 * 
 */

#ifndef _output_new_block_filter_H_
#define _output_new_block_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_new_block_filter_t output_new_block_filter_t;




typedef struct output_new_block_filter_t {
    char *schema; // string
    char *filter_id; // string

} output_new_block_filter_t;

output_new_block_filter_t *output_new_block_filter_create(
    char *schema,
    char *filter_id
);

void output_new_block_filter_free(output_new_block_filter_t *output_new_block_filter);

output_new_block_filter_t *output_new_block_filter_parseFromJSON(cJSON *output_new_block_filterJSON);

cJSON *output_new_block_filter_convertToJSON(output_new_block_filter_t *output_new_block_filter);

#endif /* _output_new_block_filter_H_ */

