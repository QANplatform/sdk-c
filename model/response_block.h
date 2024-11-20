/*
 * response_block.h
 *
 * 
 */

#ifndef _response_block_H_
#define _response_block_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct response_block_t response_block_t;

#include "response_transaction.h"
#include "response_withdrawals.h"



typedef struct response_block_t {
    char *base_fee_per_gas; // string
    char *difficulty; // string
    char *extra_data; // string
    char *gas_limit; // string
    char *gas_used; // string
    char *hash; // string
    char *logs_bloom; // string
    char *miner; // string
    char *mix_hash; // string
    char *nonce; // string
    char *number; // string
    char *parent_hash; // string
    char *receipts_root; // string
    char *sha3_uncles; // string
    char *size; // string
    char *state_root; // string
    char *timestamp; // string
    char *total_difficulty; // string
    list_t *transactions; //nonprimitive container
    char *transactions_root; // string
    list_t *uncles; //primitive container
    struct response_withdrawals_t *withdrawals; //model
    char *withdrawals_root; // string

} response_block_t;

response_block_t *response_block_create(
    char *base_fee_per_gas,
    char *difficulty,
    char *extra_data,
    char *gas_limit,
    char *gas_used,
    char *hash,
    char *logs_bloom,
    char *miner,
    char *mix_hash,
    char *nonce,
    char *number,
    char *parent_hash,
    char *receipts_root,
    char *sha3_uncles,
    char *size,
    char *state_root,
    char *timestamp,
    char *total_difficulty,
    list_t *transactions,
    char *transactions_root,
    list_t *uncles,
    response_withdrawals_t *withdrawals,
    char *withdrawals_root
);

void response_block_free(response_block_t *response_block);

response_block_t *response_block_parseFromJSON(cJSON *response_blockJSON);

cJSON *response_block_convertToJSON(response_block_t *response_block);

#endif /* _response_block_H_ */

