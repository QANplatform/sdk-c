#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/error_model.h"
#include "../model/input_call.h"
#include "../model/input_estimate_gas.h"
#include "../model/input_fee_history.h"
#include "../model/input_get_logs.h"
#include "../model/input_get_proof.h"
#include "../model/input_get_storage_at.h"
#include "../model/input_new_filter.h"
#include "../model/input_send_raw_transaction.h"
#include "../model/output_block_number.h"
#include "../model/output_call.h"
#include "../model/output_chain_id.h"
#include "../model/output_estimate_gas.h"
#include "../model/output_fee_history.h"
#include "../model/output_gas_price.h"
#include "../model/output_get_balance.h"
#include "../model/output_get_block_by_hash.h"
#include "../model/output_get_block_by_number.h"
#include "../model/output_get_block_receipts.h"
#include "../model/output_get_block_transaction_count_by_hash.h"
#include "../model/output_get_block_transaction_count_by_number.h"
#include "../model/output_get_code.h"
#include "../model/output_get_filter_changes.h"
#include "../model/output_get_filter_logs.h"
#include "../model/output_get_logs.h"
#include "../model/output_get_proof.h"
#include "../model/output_get_storage_at.h"
#include "../model/output_get_transaction_by_block_hash_and_index.h"
#include "../model/output_get_transaction_by_block_number_and_index.h"
#include "../model/output_get_transaction_by_hash.h"
#include "../model/output_get_transaction_count.h"
#include "../model/output_get_transaction_receipt.h"
#include "../model/output_max_priority_fee_per_gas.h"
#include "../model/output_new_block_filter.h"
#include "../model/output_new_filter.h"
#include "../model/output_new_pending_transaction_filter.h"
#include "../model/output_send_raw_transaction.h"
#include "../model/output_syncing.h"
#include "../model/output_uninstall_filter.h"
#include "../model/output_xlink_valid.h"


// Returns the latest block number of the blockchain.
//
output_block_number_t*
QANAPI_qanBlockNumber(apiClient_t *apiClient);


// Executes a new message call immediately without creating a transaction on the block chain.
//
output_call_t*
QANAPI_qanCall(apiClient_t *apiClient, input_call_t *input_call);


// Returns the current network/chain ID, used to sign replay-protected transaction introduced in EIP-155.
//
output_chain_id_t*
QANAPI_qanChainId(apiClient_t *apiClient);


// Returns an estimation of gas for a given transaction.
//
output_estimate_gas_t*
QANAPI_qanEstimateGas(apiClient_t *apiClient, input_estimate_gas_t *input_estimate_gas);


// Returns the collection of historical gas information.
//
output_fee_history_t*
QANAPI_qanFeeHistory(apiClient_t *apiClient, input_fee_history_t *input_fee_history);


// Returns the current gas price on the network in wei.
//
output_gas_price_t*
QANAPI_qanGasPrice(apiClient_t *apiClient);


// Returns the balance of the account of given address.
//
output_get_balance_t*
QANAPI_qanGetBalance(apiClient_t *apiClient, char *Address, char *BlockNumber);


// Returns information of the block matching the given block hash.
//
output_get_block_by_hash_t*
QANAPI_qanGetBlockByHash(apiClient_t *apiClient, char *Hash, int *TransactionDetailFlag);


// Returns information of the block matching the given block number.
//
output_get_block_by_number_t*
QANAPI_qanGetBlockByNumber(apiClient_t *apiClient, char *BlockNumber, int *TransactionDetailFlag);


// Returns all transaction receipts for a given block.
//
output_get_block_receipts_t*
QANAPI_qanGetBlockReceipts(apiClient_t *apiClient, char *BlockNumber);


// Returns the number of transactions for the block matching the given block hash.
//
output_get_block_transaction_count_by_hash_t*
QANAPI_qanGetBlockTransactionCountByHash(apiClient_t *apiClient, char *Hash);


// Returns the number of transactions for the block matching the given block number.
//
output_get_block_transaction_count_by_number_t*
QANAPI_qanGetBlockTransactionCountByNumber(apiClient_t *apiClient, char *BlockNumber);


// Returns the compiled bytecode of a smart contract.
//
output_get_code_t*
QANAPI_qanGetCode(apiClient_t *apiClient, char *Address, char *BlockNumber);


// Polling method for a filter, which returns an array of events that have occurred since the last poll.
//
output_get_filter_changes_t*
QANAPI_qanGetFilterChanges(apiClient_t *apiClient, char *FilterId);


// Returns an array of all logs matching filter with given id.
//
output_get_filter_logs_t*
QANAPI_qanGetFilterLogs(apiClient_t *apiClient, char *Id);


// Returns an array of all logs matching a given filter object.
//
output_get_logs_t*
QANAPI_qanGetLogs(apiClient_t *apiClient, input_get_logs_t *input_get_logs);


// Returns the account and storage values of the specified account including the Merkle-proof.
//
output_get_proof_t*
QANAPI_qanGetProof(apiClient_t *apiClient, input_get_proof_t *input_get_proof);


// Returns the value from a storage position at a given address.
//
output_get_storage_at_t*
QANAPI_qanGetStorageAt(apiClient_t *apiClient, input_get_storage_at_t *input_get_storage_at);


// Returns information about a transaction given a blockhash and transaction index position.
//
output_get_transaction_by_block_hash_and_index_t*
QANAPI_qanGetTransactionByBlockHashAndIndex(apiClient_t *apiClient, char *blockHash, char *index);


// Returns information about a transaction given a block number and transaction index position.
//
output_get_transaction_by_block_number_and_index_t*
QANAPI_qanGetTransactionByBlockNumberAndIndex(apiClient_t *apiClient, char *blockNumber, char *index);


// Returns the information about a transaction from a transaction hash.
//
output_get_transaction_by_hash_t*
QANAPI_qanGetTransactionByHash(apiClient_t *apiClient, char *hash);


// Returns the number of transactions sent from an address.
//
output_get_transaction_count_t*
QANAPI_qanGetTransactionCount(apiClient_t *apiClient, char *Address, char *BlockNumber);


// Returns the receipt of a transaction by transaction hash.
//
output_get_transaction_receipt_t*
QANAPI_qanGetTransactionReceipt(apiClient_t *apiClient, char *Hash);


// Get the priority fee needed to be included in a block.
//
output_max_priority_fee_per_gas_t*
QANAPI_qanMaxPriorityFeePerGas(apiClient_t *apiClient);


// Creates a filter in the node, to notify when a new block arrives.
//
output_new_block_filter_t*
QANAPI_qanNewBlockFilter(apiClient_t *apiClient);


// Creates a filter object, based on filter options, to notify when the state changes (logs).
//
output_new_filter_t*
QANAPI_qanNewFilter(apiClient_t *apiClient, input_new_filter_t *input_new_filter);


// Creates a filter in the node to notify when new pending transactions arrive.
//
output_new_pending_transaction_filter_t*
QANAPI_qanNewPendingTransactionFilter(apiClient_t *apiClient);


// Creates new message call transaction or a contract creation for signed transactions.
//
output_send_raw_transaction_t*
QANAPI_qanSendRawTransaction(apiClient_t *apiClient, input_send_raw_transaction_t *input_send_raw_transaction);


// Returns an object with the sync status of the node if the node is out-of-sync and is syncing. Returns null when the node is already in sync.
//
output_syncing_t*
QANAPI_qanSyncing(apiClient_t *apiClient);


// Uninstalls a filter with the given filter id.
//
output_uninstall_filter_t*
QANAPI_qanUninstallFilter(apiClient_t *apiClient, char *FilterId);


// Returns the xlink validity time of the account of given address.
//
output_xlink_valid_t*
QANAPI_qanXlinkValid(apiClient_t *apiClient, char *Address);


