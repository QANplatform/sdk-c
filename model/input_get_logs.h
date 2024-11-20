/*
 * input_get_logs.h
 *
 * 
 */

#ifndef _input_get_logs_H_
#define _input_get_logs_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_get_logs_t input_get_logs_t;




typedef struct input_get_logs_t {
    char *schema; // string
    char *address; // string
    char *block_hash; // string
    char *from_block; // string
    char *to_block; // string
    list_t *topics; //primitive container

} input_get_logs_t;

input_get_logs_t *input_get_logs_create(
    char *schema,
    char *address,
    char *block_hash,
    char *from_block,
    char *to_block,
    list_t *topics
);

void input_get_logs_free(input_get_logs_t *input_get_logs);

input_get_logs_t *input_get_logs_parseFromJSON(cJSON *input_get_logsJSON);

cJSON *input_get_logs_convertToJSON(input_get_logs_t *input_get_logs);

#endif /* _input_get_logs_H_ */

