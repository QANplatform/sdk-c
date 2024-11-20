/*
 * output_uninstall_filter.h
 *
 * 
 */

#ifndef _output_uninstall_filter_H_
#define _output_uninstall_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_uninstall_filter_t output_uninstall_filter_t;




typedef struct output_uninstall_filter_t {
    char *schema; // string
    int result; //boolean

} output_uninstall_filter_t;

output_uninstall_filter_t *output_uninstall_filter_create(
    char *schema,
    int result
);

void output_uninstall_filter_free(output_uninstall_filter_t *output_uninstall_filter);

output_uninstall_filter_t *output_uninstall_filter_parseFromJSON(cJSON *output_uninstall_filterJSON);

cJSON *output_uninstall_filter_convertToJSON(output_uninstall_filter_t *output_uninstall_filter);

#endif /* _output_uninstall_filter_H_ */

