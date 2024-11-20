/*
 * output_chain_id.h
 *
 * 
 */

#ifndef _output_chain_id_H_
#define _output_chain_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_chain_id_t output_chain_id_t;




typedef struct output_chain_id_t {
    char *schema; // string
    char *chain_id; // string

} output_chain_id_t;

output_chain_id_t *output_chain_id_create(
    char *schema,
    char *chain_id
);

void output_chain_id_free(output_chain_id_t *output_chain_id);

output_chain_id_t *output_chain_id_parseFromJSON(cJSON *output_chain_idJSON);

cJSON *output_chain_id_convertToJSON(output_chain_id_t *output_chain_id);

#endif /* _output_chain_id_H_ */

