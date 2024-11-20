/*
 * response_log.h
 *
 * 
 */

#ifndef _response_log_H_
#define _response_log_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct response_log_t response_log_t;




typedef struct response_log_t {
    char *address; // string
    char *block_hash; // string
    char *block_number; // string
    char *data; // string
    char *log_index; // string
    int removed; //boolean
    list_t *topics; //primitive container
    char *transaction_hash; // string
    char *transaction_index; // string

} response_log_t;

response_log_t *response_log_create(
    char *address,
    char *block_hash,
    char *block_number,
    char *data,
    char *log_index,
    int removed,
    list_t *topics,
    char *transaction_hash,
    char *transaction_index
);

void response_log_free(response_log_t *response_log);

response_log_t *response_log_parseFromJSON(cJSON *response_logJSON);

cJSON *response_log_convertToJSON(response_log_t *response_log);

#endif /* _response_log_H_ */

