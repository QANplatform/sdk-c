/*
 * response_withdrawals.h
 *
 * 
 */

#ifndef _response_withdrawals_H_
#define _response_withdrawals_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct response_withdrawals_t response_withdrawals_t;




typedef struct response_withdrawals_t {
    char *address; // string
    char *amount; // string
    int index; //numeric
    int validator_index; //numeric

} response_withdrawals_t;

response_withdrawals_t *response_withdrawals_create(
    char *address,
    char *amount,
    int index,
    int validator_index
);

void response_withdrawals_free(response_withdrawals_t *response_withdrawals);

response_withdrawals_t *response_withdrawals_parseFromJSON(cJSON *response_withdrawalsJSON);

cJSON *response_withdrawals_convertToJSON(response_withdrawals_t *response_withdrawals);

#endif /* _response_withdrawals_H_ */

