/*
 * output_fee_history.h
 *
 * 
 */

#ifndef _output_fee_history_H_
#define _output_fee_history_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_fee_history_t output_fee_history_t;




typedef struct output_fee_history_t {
    char *schema; // string
    list_t *base_fee_per_gas; //primitive container
    list_t *gas_used_ratio; //primitive container
    char *oldest_block; // string
    list_t *reward; //primitive container

} output_fee_history_t;

output_fee_history_t *output_fee_history_create(
    char *schema,
    list_t *base_fee_per_gas,
    list_t *gas_used_ratio,
    char *oldest_block,
    list_t *reward
);

void output_fee_history_free(output_fee_history_t *output_fee_history);

output_fee_history_t *output_fee_history_parseFromJSON(cJSON *output_fee_historyJSON);

cJSON *output_fee_history_convertToJSON(output_fee_history_t *output_fee_history);

#endif /* _output_fee_history_H_ */

