/*
 * response_storage_entry.h
 *
 * 
 */

#ifndef _response_storage_entry_H_
#define _response_storage_entry_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct response_storage_entry_t response_storage_entry_t;




typedef struct response_storage_entry_t {
    char *key; // string
    char *proof; // string
    char *value; // string

} response_storage_entry_t;

response_storage_entry_t *response_storage_entry_create(
    char *key,
    char *proof,
    char *value
);

void response_storage_entry_free(response_storage_entry_t *response_storage_entry);

response_storage_entry_t *response_storage_entry_parseFromJSON(cJSON *response_storage_entryJSON);

cJSON *response_storage_entry_convertToJSON(response_storage_entry_t *response_storage_entry);

#endif /* _response_storage_entry_H_ */

