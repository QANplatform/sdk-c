/*
 * input_get_proof.h
 *
 * 
 */

#ifndef _input_get_proof_H_
#define _input_get_proof_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_get_proof_t input_get_proof_t;




typedef struct input_get_proof_t {
    char *schema; // string
    char *address; // string
    char *block_number; // string
    list_t *storage_keys; //primitive container

} input_get_proof_t;

input_get_proof_t *input_get_proof_create(
    char *schema,
    char *address,
    char *block_number,
    list_t *storage_keys
);

void input_get_proof_free(input_get_proof_t *input_get_proof);

input_get_proof_t *input_get_proof_parseFromJSON(cJSON *input_get_proofJSON);

cJSON *input_get_proof_convertToJSON(input_get_proof_t *input_get_proof);

#endif /* _input_get_proof_H_ */

