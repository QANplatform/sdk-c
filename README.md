# QAN C SDK

This repository is guaranteed up-to-date with the upstream QAN API definitions, and leverages OpenAPI technology to stay consistent.

Versioning is based on SEMVER, meaning:

- Stable releases guarantee backwards compatibility for the same major versions.
- Minor releases will not contain breaking changes.
- Patch releases only focus on fixing issues.

## Documentation for API Endpoints

All URIs are relative to *https://rpc-testnet.qanplatform.com*

Category | Method | HTTP request | Description
------------ | ------------- | ------------- | -------------
*QANAPI* | [**QANAPI_qanBlockNumber**](docs/QANAPI.md#QANAPI_qanBlockNumber) | **GET** /blockNumber/ | Returns the latest block number of the blockchain.
*QANAPI* | [**QANAPI_qanCall**](docs/QANAPI.md#QANAPI_qanCall) | **POST** /call/ | Executes a new message call immediately without creating a transaction on the block chain.
*QANAPI* | [**QANAPI_qanChainId**](docs/QANAPI.md#QANAPI_qanChainId) | **GET** /chainId/ | Returns the current network/chain ID, used to sign replay-protected transaction introduced in EIP-155.
*QANAPI* | [**QANAPI_qanEstimateGas**](docs/QANAPI.md#QANAPI_qanEstimateGas) | **POST** /estimateGas/ | Returns an estimation of gas for a given transaction.
*QANAPI* | [**QANAPI_qanFeeHistory**](docs/QANAPI.md#QANAPI_qanFeeHistory) | **POST** /feeHistory/ | Returns the collection of historical gas information.
*QANAPI* | [**QANAPI_qanGasPrice**](docs/QANAPI.md#QANAPI_qanGasPrice) | **GET** /gasPrice/ | Returns the current gas price on the network in wei.
*QANAPI* | [**QANAPI_qanGetBalance**](docs/QANAPI.md#QANAPI_qanGetBalance) | **GET** /getBalance/{Address}/ | Returns the balance of the account of given address.
*QANAPI* | [**QANAPI_qanGetBlockByHash**](docs/QANAPI.md#QANAPI_qanGetBlockByHash) | **GET** /getBlockByHash/{Hash}/{TransactionDetailFlag}/ | Returns information of the block matching the given block hash.
*QANAPI* | [**QANAPI_qanGetBlockByNumber**](docs/QANAPI.md#QANAPI_qanGetBlockByNumber) | **GET** /getBlockByNumber/{BlockNumber}/{TransactionDetailFlag}/ | Returns information of the block matching the given block number.
*QANAPI* | [**QANAPI_qanGetBlockReceipts**](docs/QANAPI.md#QANAPI_qanGetBlockReceipts) | **GET** /getBlockReceipts/{BlockNumber}/ | Returns all transaction receipts for a given block.
*QANAPI* | [**QANAPI_qanGetBlockTransactionCountByHash**](docs/QANAPI.md#QANAPI_qanGetBlockTransactionCountByHash) | **GET** /getBlockTransactionCountByHash/{Hash}/ | Returns the number of transactions for the block matching the given block hash.
*QANAPI* | [**QANAPI_qanGetBlockTransactionCountByNumber**](docs/QANAPI.md#QANAPI_qanGetBlockTransactionCountByNumber) | **GET** /getBlockTransactionCountByNumber/{BlockNumber}/ | Returns the number of transactions for the block matching the given block number.
*QANAPI* | [**QANAPI_qanGetCode**](docs/QANAPI.md#QANAPI_qanGetCode) | **GET** /getCode/{Address}/ | Returns the compiled bytecode of a smart contract.
*QANAPI* | [**QANAPI_qanGetFilterChanges**](docs/QANAPI.md#QANAPI_qanGetFilterChanges) | **GET** /getFilterChanges/{FilterId}/ | Polling method for a filter, which returns an array of events that have occurred since the last poll.
*QANAPI* | [**QANAPI_qanGetFilterLogs**](docs/QANAPI.md#QANAPI_qanGetFilterLogs) | **GET** /getFilterLogs/{Id}/ | Returns an array of all logs matching filter with given id.
*QANAPI* | [**QANAPI_qanGetLogs**](docs/QANAPI.md#QANAPI_qanGetLogs) | **POST** /getLogs/ | Returns an array of all logs matching a given filter object.
*QANAPI* | [**QANAPI_qanGetProof**](docs/QANAPI.md#QANAPI_qanGetProof) | **POST** /getProof/ | Returns the account and storage values of the specified account including the Merkle-proof.
*QANAPI* | [**QANAPI_qanGetStorageAt**](docs/QANAPI.md#QANAPI_qanGetStorageAt) | **POST** /getStorageAt/ | Returns the value from a storage position at a given address.
*QANAPI* | [**QANAPI_qanGetTransactionByBlockHashAndIndex**](docs/QANAPI.md#QANAPI_qanGetTransactionByBlockHashAndIndex) | **GET** /getTransactionByBlockHashAndIndex/{blockHash}/{index}/ | Returns information about a transaction given a blockhash and transaction index position.
*QANAPI* | [**QANAPI_qanGetTransactionByBlockNumberAndIndex**](docs/QANAPI.md#QANAPI_qanGetTransactionByBlockNumberAndIndex) | **GET** /getTransactionByBlockNumberAndIndex/{blockNumber}/{index}/ | Returns information about a transaction given a block number and transaction index position.
*QANAPI* | [**QANAPI_qanGetTransactionByHash**](docs/QANAPI.md#QANAPI_qanGetTransactionByHash) | **GET** /getTransactionByHash/{hash}/ | Returns the information about a transaction from a transaction hash.
*QANAPI* | [**QANAPI_qanGetTransactionCount**](docs/QANAPI.md#QANAPI_qanGetTransactionCount) | **GET** /getTransactionCount/{Address}/{BlockNumber}/ | Returns the number of transactions sent from an address.
*QANAPI* | [**QANAPI_qanGetTransactionReceipt**](docs/QANAPI.md#QANAPI_qanGetTransactionReceipt) | **GET** /getTransactionReceipt/{Hash}/ | Returns the receipt of a transaction by transaction hash.
*QANAPI* | [**QANAPI_qanMaxPriorityFeePerGas**](docs/QANAPI.md#QANAPI_qanMaxPriorityFeePerGas) | **GET** /maxPriorityFeePerGas/ | Get the priority fee needed to be included in a block.
*QANAPI* | [**QANAPI_qanNewBlockFilter**](docs/QANAPI.md#QANAPI_qanNewBlockFilter) | **GET** /newBlockFilter/ | Creates a filter in the node, to notify when a new block arrives.
*QANAPI* | [**QANAPI_qanNewFilter**](docs/QANAPI.md#QANAPI_qanNewFilter) | **POST** /newFilter/ | Creates a filter object, based on filter options, to notify when the state changes (logs).
*QANAPI* | [**QANAPI_qanNewPendingTransactionFilter**](docs/QANAPI.md#QANAPI_qanNewPendingTransactionFilter) | **GET** /newPendingTransactionFilter/ | Creates a filter in the node to notify when new pending transactions arrive.
*QANAPI* | [**QANAPI_qanSendRawTransaction**](docs/QANAPI.md#QANAPI_qanSendRawTransaction) | **POST** /sendRawTransaction/ | Creates new message call transaction or a contract creation for signed transactions.
*QANAPI* | [**QANAPI_qanSyncing**](docs/QANAPI.md#QANAPI_qanSyncing) | **GET** /syncing/ | Returns an object with the sync status of the node if the node is out-of-sync and is syncing. Returns null when the node is already in sync.
*QANAPI* | [**QANAPI_qanUninstallFilter**](docs/QANAPI.md#QANAPI_qanUninstallFilter) | **GET** /uninstallFilter/{FilterId}/ | Uninstalls a filter with the given filter id.
*QANAPI* | [**QANAPI_qanXlinkValid**](docs/QANAPI.md#QANAPI_qanXlinkValid) | **GET** /xlinkValid/{Address}/ | Returns the xlink validity time of the account of given address.


## Documentation for Models

 - [error_detail_t](docs/error_detail.md)
 - [error_model_t](docs/error_model.md)
 - [estimate_gas_object_t](docs/estimate_gas_object.md)
 - [filter_object_t](docs/filter_object.md)
 - [input_call_t](docs/input_call.md)
 - [input_estimate_gas_t](docs/input_estimate_gas.md)
 - [input_fee_history_t](docs/input_fee_history.md)
 - [input_get_logs_t](docs/input_get_logs.md)
 - [input_get_proof_t](docs/input_get_proof.md)
 - [input_get_storage_at_t](docs/input_get_storage_at.md)
 - [input_new_filter_t](docs/input_new_filter.md)
 - [input_send_raw_transaction_t](docs/input_send_raw_transaction.md)
 - [output_block_number_t](docs/output_block_number.md)
 - [output_call_t](docs/output_call.md)
 - [output_chain_id_t](docs/output_chain_id.md)
 - [output_estimate_gas_t](docs/output_estimate_gas.md)
 - [output_fee_history_t](docs/output_fee_history.md)
 - [output_gas_price_t](docs/output_gas_price.md)
 - [output_get_balance_t](docs/output_get_balance.md)
 - [output_get_block_by_hash_t](docs/output_get_block_by_hash.md)
 - [output_get_block_by_number_t](docs/output_get_block_by_number.md)
 - [output_get_block_receipts_t](docs/output_get_block_receipts.md)
 - [output_get_block_transaction_count_by_hash_t](docs/output_get_block_transaction_count_by_hash.md)
 - [output_get_block_transaction_count_by_number_t](docs/output_get_block_transaction_count_by_number.md)
 - [output_get_code_t](docs/output_get_code.md)
 - [output_get_filter_changes_t](docs/output_get_filter_changes.md)
 - [output_get_filter_logs_t](docs/output_get_filter_logs.md)
 - [output_get_logs_t](docs/output_get_logs.md)
 - [output_get_proof_t](docs/output_get_proof.md)
 - [output_get_storage_at_t](docs/output_get_storage_at.md)
 - [output_get_transaction_by_block_hash_and_index_t](docs/output_get_transaction_by_block_hash_and_index.md)
 - [output_get_transaction_by_block_number_and_index_t](docs/output_get_transaction_by_block_number_and_index.md)
 - [output_get_transaction_by_hash_t](docs/output_get_transaction_by_hash.md)
 - [output_get_transaction_count_t](docs/output_get_transaction_count.md)
 - [output_get_transaction_receipt_t](docs/output_get_transaction_receipt.md)
 - [output_max_priority_fee_per_gas_t](docs/output_max_priority_fee_per_gas.md)
 - [output_new_block_filter_t](docs/output_new_block_filter.md)
 - [output_new_filter_t](docs/output_new_filter.md)
 - [output_new_pending_transaction_filter_t](docs/output_new_pending_transaction_filter.md)
 - [output_send_raw_transaction_t](docs/output_send_raw_transaction.md)
 - [output_syncing_t](docs/output_syncing.md)
 - [output_uninstall_filter_t](docs/output_uninstall_filter.md)
 - [output_xlink_valid_t](docs/output_xlink_valid.md)
 - [params_transaction_t](docs/params_transaction.md)
 - [response_block_t](docs/response_block.md)
 - [response_log_t](docs/response_log.md)
 - [response_storage_entry_t](docs/response_storage_entry.md)
 - [response_transaction_t](docs/response_transaction.md)
 - [response_transaction_receipt_t](docs/response_transaction_receipt.md)
 - [response_withdrawals_t](docs/response_withdrawals.md)
 - [sync_status_t](docs/sync_status.md)

## Acknowledgements

We would like to thank Smartbear and OpenAPITools tech for making building declarative APIs possible.
A huge benefit for the whole industry!
