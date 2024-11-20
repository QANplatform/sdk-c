/*
 * output_get_storage_at.h
 *
 * 
 */

#ifndef _output_get_storage_at_H_
#define _output_get_storage_at_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_get_storage_at_t output_get_storage_at_t;




typedef struct output_get_storage_at_t {
    char *schema; // string
    char *value; // string

} output_get_storage_at_t;

output_get_storage_at_t *output_get_storage_at_create(
    char *schema,
    char *value
);

void output_get_storage_at_free(output_get_storage_at_t *output_get_storage_at);

output_get_storage_at_t *output_get_storage_at_parseFromJSON(cJSON *output_get_storage_atJSON);

cJSON *output_get_storage_at_convertToJSON(output_get_storage_at_t *output_get_storage_at);

#endif /* _output_get_storage_at_H_ */

