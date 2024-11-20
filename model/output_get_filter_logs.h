/*
 * output_get_filter_logs.h
 *
 * 
 */

#ifndef _output_get_filter_logs_H_
#define _output_get_filter_logs_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_get_filter_logs_t output_get_filter_logs_t;

#include "response_log.h"



typedef struct output_get_filter_logs_t {
    char *schema; // string
    list_t *logs; //nonprimitive container

} output_get_filter_logs_t;

output_get_filter_logs_t *output_get_filter_logs_create(
    char *schema,
    list_t *logs
);

void output_get_filter_logs_free(output_get_filter_logs_t *output_get_filter_logs);

output_get_filter_logs_t *output_get_filter_logs_parseFromJSON(cJSON *output_get_filter_logsJSON);

cJSON *output_get_filter_logs_convertToJSON(output_get_filter_logs_t *output_get_filter_logs);

#endif /* _output_get_filter_logs_H_ */

