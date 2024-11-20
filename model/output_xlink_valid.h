/*
 * output_xlink_valid.h
 *
 * 
 */

#ifndef _output_xlink_valid_H_
#define _output_xlink_valid_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_xlink_valid_t output_xlink_valid_t;




typedef struct output_xlink_valid_t {
    char *schema; // string
    char *validity; // string

} output_xlink_valid_t;

output_xlink_valid_t *output_xlink_valid_create(
    char *schema,
    char *validity
);

void output_xlink_valid_free(output_xlink_valid_t *output_xlink_valid);

output_xlink_valid_t *output_xlink_valid_parseFromJSON(cJSON *output_xlink_validJSON);

cJSON *output_xlink_valid_convertToJSON(output_xlink_valid_t *output_xlink_valid);

#endif /* _output_xlink_valid_H_ */

