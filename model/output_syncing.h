/*
 * output_syncing.h
 *
 * 
 */

#ifndef _output_syncing_H_
#define _output_syncing_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_syncing_t output_syncing_t;

#include "sync_status.h"



typedef struct output_syncing_t {
    char *schema; // string
    struct sync_status_t *sync_status; //model

} output_syncing_t;

output_syncing_t *output_syncing_create(
    char *schema,
    sync_status_t *sync_status
);

void output_syncing_free(output_syncing_t *output_syncing);

output_syncing_t *output_syncing_parseFromJSON(cJSON *output_syncingJSON);

cJSON *output_syncing_convertToJSON(output_syncing_t *output_syncing);

#endif /* _output_syncing_H_ */

