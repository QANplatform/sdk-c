/*
 * output_get_filter_changes.h
 *
 * 
 */

#ifndef _output_get_filter_changes_H_
#define _output_get_filter_changes_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_get_filter_changes_t output_get_filter_changes_t;

#include "any_type.h"



typedef struct output_get_filter_changes_t {
    char *schema; // string
    any_type_t *result; // custom

} output_get_filter_changes_t;

output_get_filter_changes_t *output_get_filter_changes_create(
    char *schema,
    any_type_t *result
);

void output_get_filter_changes_free(output_get_filter_changes_t *output_get_filter_changes);

output_get_filter_changes_t *output_get_filter_changes_parseFromJSON(cJSON *output_get_filter_changesJSON);

cJSON *output_get_filter_changes_convertToJSON(output_get_filter_changes_t *output_get_filter_changes);

#endif /* _output_get_filter_changes_H_ */

