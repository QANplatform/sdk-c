/*
 * sync_status.h
 *
 * 
 */

#ifndef _sync_status_H_
#define _sync_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sync_status_t sync_status_t;




typedef struct sync_status_t {
    char *current_block; // string
    char *highest_block; // string
    char *starting_block; // string

} sync_status_t;

sync_status_t *sync_status_create(
    char *current_block,
    char *highest_block,
    char *starting_block
);

void sync_status_free(sync_status_t *sync_status);

sync_status_t *sync_status_parseFromJSON(cJSON *sync_statusJSON);

cJSON *sync_status_convertToJSON(sync_status_t *sync_status);

#endif /* _sync_status_H_ */

