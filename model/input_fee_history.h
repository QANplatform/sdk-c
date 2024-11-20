/*
 * input_fee_history.h
 *
 * 
 */

#ifndef _input_fee_history_H_
#define _input_fee_history_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_fee_history_t input_fee_history_t;




typedef struct input_fee_history_t {
    char *schema; // string
    int block_count; //numeric
    char *newest_block; // string
    list_t *reward_percentiles; //primitive container

} input_fee_history_t;

input_fee_history_t *input_fee_history_create(
    char *schema,
    int block_count,
    char *newest_block,
    list_t *reward_percentiles
);

void input_fee_history_free(input_fee_history_t *input_fee_history);

input_fee_history_t *input_fee_history_parseFromJSON(cJSON *input_fee_historyJSON);

cJSON *input_fee_history_convertToJSON(input_fee_history_t *input_fee_history);

#endif /* _input_fee_history_H_ */

