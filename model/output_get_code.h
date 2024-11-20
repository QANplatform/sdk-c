/*
 * output_get_code.h
 *
 * 
 */

#ifndef _output_get_code_H_
#define _output_get_code_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_get_code_t output_get_code_t;




typedef struct output_get_code_t {
    char *schema; // string
    char *bytecode; // string

} output_get_code_t;

output_get_code_t *output_get_code_create(
    char *schema,
    char *bytecode
);

void output_get_code_free(output_get_code_t *output_get_code);

output_get_code_t *output_get_code_parseFromJSON(cJSON *output_get_codeJSON);

cJSON *output_get_code_convertToJSON(output_get_code_t *output_get_code);

#endif /* _output_get_code_H_ */

