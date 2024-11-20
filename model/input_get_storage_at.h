/*
 * input_get_storage_at.h
 *
 * 
 */

#ifndef _input_get_storage_at_H_
#define _input_get_storage_at_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_get_storage_at_t input_get_storage_at_t;




typedef struct input_get_storage_at_t {
    char *schema; // string
    char *address; // string
    char *block_number; // string
    char *position; // string

} input_get_storage_at_t;

input_get_storage_at_t *input_get_storage_at_create(
    char *schema,
    char *address,
    char *block_number,
    char *position
);

void input_get_storage_at_free(input_get_storage_at_t *input_get_storage_at);

input_get_storage_at_t *input_get_storage_at_parseFromJSON(cJSON *input_get_storage_atJSON);

cJSON *input_get_storage_at_convertToJSON(input_get_storage_at_t *input_get_storage_at);

#endif /* _input_get_storage_at_H_ */

