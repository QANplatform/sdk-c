/*
 * error_model.h
 *
 * 
 */

#ifndef _error_model_H_
#define _error_model_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct error_model_t error_model_t;

#include "error_detail.h"



typedef struct error_model_t {
    char *schema; // string
    char *detail; // string
    list_t *errors; //nonprimitive container
    char *instance; // string
    long status; //numeric
    char *title; // string
    char *type; // string

} error_model_t;

error_model_t *error_model_create(
    char *schema,
    char *detail,
    list_t *errors,
    char *instance,
    long status,
    char *title,
    char *type
);

void error_model_free(error_model_t *error_model);

error_model_t *error_model_parseFromJSON(cJSON *error_modelJSON);

cJSON *error_model_convertToJSON(error_model_t *error_model);

#endif /* _error_model_H_ */

