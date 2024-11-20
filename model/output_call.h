/*
 * output_call.h
 *
 * 
 */

#ifndef _output_call_H_
#define _output_call_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_call_t output_call_t;




typedef struct output_call_t {
    char *schema; // string
    char *data; // string

} output_call_t;

output_call_t *output_call_create(
    char *schema,
    char *data
);

void output_call_free(output_call_t *output_call);

output_call_t *output_call_parseFromJSON(cJSON *output_callJSON);

cJSON *output_call_convertToJSON(output_call_t *output_call);

#endif /* _output_call_H_ */

