/*
 * estimate_gas_object.h
 *
 * 
 */

#ifndef _estimate_gas_object_H_
#define _estimate_gas_object_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct estimate_gas_object_t estimate_gas_object_t;




typedef struct estimate_gas_object_t {
    char *balance; // string
    int code; //numeric
    char *nonce; // string
    char *state; // string
    char *state_diff; // string

} estimate_gas_object_t;

estimate_gas_object_t *estimate_gas_object_create(
    char *balance,
    int code,
    char *nonce,
    char *state,
    char *state_diff
);

void estimate_gas_object_free(estimate_gas_object_t *estimate_gas_object);

estimate_gas_object_t *estimate_gas_object_parseFromJSON(cJSON *estimate_gas_objectJSON);

cJSON *estimate_gas_object_convertToJSON(estimate_gas_object_t *estimate_gas_object);

#endif /* _estimate_gas_object_H_ */

