/*
 * output_get_proof.h
 *
 * 
 */

#ifndef _output_get_proof_H_
#define _output_get_proof_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct output_get_proof_t output_get_proof_t;

#include "response_storage_entry.h"



typedef struct output_get_proof_t {
    char *schema; // string
    char *account_proof; // string
    char *address; // string
    char *balance; // string
    char *code_hash; // string
    char *nonce; // string
    char *storage_hash; // string
    list_t *storage_proof; //nonprimitive container

} output_get_proof_t;

output_get_proof_t *output_get_proof_create(
    char *schema,
    char *account_proof,
    char *address,
    char *balance,
    char *code_hash,
    char *nonce,
    char *storage_hash,
    list_t *storage_proof
);

void output_get_proof_free(output_get_proof_t *output_get_proof);

output_get_proof_t *output_get_proof_parseFromJSON(cJSON *output_get_proofJSON);

cJSON *output_get_proof_convertToJSON(output_get_proof_t *output_get_proof);

#endif /* _output_get_proof_H_ */

