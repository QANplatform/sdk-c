/*
 * input_new_filter.h
 *
 * 
 */

#ifndef _input_new_filter_H_
#define _input_new_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_new_filter_t input_new_filter_t;

#include "filter_object.h"



typedef struct input_new_filter_t {
    char *schema; // string
    struct filter_object_t *filter_object; //model

} input_new_filter_t;

input_new_filter_t *input_new_filter_create(
    char *schema,
    filter_object_t *filter_object
);

void input_new_filter_free(input_new_filter_t *input_new_filter);

input_new_filter_t *input_new_filter_parseFromJSON(cJSON *input_new_filterJSON);

cJSON *input_new_filter_convertToJSON(input_new_filter_t *input_new_filter);

#endif /* _input_new_filter_H_ */

