/*
 * filter_object.h
 *
 * 
 */

#ifndef _filter_object_H_
#define _filter_object_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct filter_object_t filter_object_t;




typedef struct filter_object_t {
    char *address; // string
    char *from_block; // string
    char *to_block; // string
    list_t *topics; //primitive container

} filter_object_t;

filter_object_t *filter_object_create(
    char *address,
    char *from_block,
    char *to_block,
    list_t *topics
);

void filter_object_free(filter_object_t *filter_object);

filter_object_t *filter_object_parseFromJSON(cJSON *filter_objectJSON);

cJSON *filter_object_convertToJSON(filter_object_t *filter_object);

#endif /* _filter_object_H_ */

