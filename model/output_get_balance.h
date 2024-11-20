/*
 * output_get_balance.h
 *
 * 
 */

#ifndef _output_get_balance_H_
#define _output_get_balance_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_get_balance_t output_get_balance_t;




typedef struct output_get_balance_t {
    char *schema; // string
    char *balance; // string

} output_get_balance_t;

output_get_balance_t *output_get_balance_create(
    char *schema,
    char *balance
);

void output_get_balance_free(output_get_balance_t *output_get_balance);

output_get_balance_t *output_get_balance_parseFromJSON(cJSON *output_get_balanceJSON);

cJSON *output_get_balance_convertToJSON(output_get_balance_t *output_get_balance);

#endif /* _output_get_balance_H_ */

