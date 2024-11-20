/*
 * error_detail.h
 *
 * 
 */

#ifndef _error_detail_H_
#define _error_detail_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct error_detail_t error_detail_t;

#include "any_type.h"



typedef struct error_detail_t {
    char *location; // string
    char *message; // string
    any_type_t *value; // custom

} error_detail_t;

error_detail_t *error_detail_create(
    char *location,
    char *message,
    any_type_t *value
);

void error_detail_free(error_detail_t *error_detail);

error_detail_t *error_detail_parseFromJSON(cJSON *error_detailJSON);

cJSON *error_detail_convertToJSON(error_detail_t *error_detail);

#endif /* _error_detail_H_ */

