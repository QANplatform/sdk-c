# QANAPI

All URIs are relative to *https://rpc-testnet.qanplatform.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**QANAPI_qanBlockNumber**](QANAPI.md#QANAPI_qanBlockNumber) | **GET** /blockNumber/ | Returns the latest block number of the blockchain.
[**QANAPI_qanCall**](QANAPI.md#QANAPI_qanCall) | **POST** /call/ | Executes a new message call immediately without creating a transaction on the block chain.
[**QANAPI_qanChainId**](QANAPI.md#QANAPI_qanChainId) | **GET** /chainId/ | Returns the current network/chain ID, used to sign replay-protected transaction introduced in EIP-155.
[**QANAPI_qanEstimateGas**](QANAPI.md#QANAPI_qanEstimateGas) | **POST** /estimateGas/ | Returns an estimation of gas for a given transaction.
[**QANAPI_qanFeeHistory**](QANAPI.md#QANAPI_qanFeeHistory) | **POST** /feeHistory/ | Returns the collection of historical gas information.
[**QANAPI_qanGasPrice**](QANAPI.md#QANAPI_qanGasPrice) | **GET** /gasPrice/ | Returns the current gas price on the network in wei.
[**QANAPI_qanGetBalance**](QANAPI.md#QANAPI_qanGetBalance) | **GET** /getBalance/{Address}/ | Returns the balance of the account of given address.
[**QANAPI_qanGetBlockByHash**](QANAPI.md#QANAPI_qanGetBlockByHash) | **GET** /getBlockByHash/{Hash}/{TransactionDetailFlag}/ | Returns information of the block matching the given block hash.
[**QANAPI_qanGetBlockByNumber**](QANAPI.md#QANAPI_qanGetBlockByNumber) | **GET** /getBlockByNumber/{BlockNumber}/{TransactionDetailFlag}/ | Returns information of the block matching the given block number.
[**QANAPI_qanGetBlockReceipts**](QANAPI.md#QANAPI_qanGetBlockReceipts) | **GET** /getBlockReceipts/{BlockNumber}/ | Returns all transaction receipts for a given block.
[**QANAPI_qanGetBlockTransactionCountByHash**](QANAPI.md#QANAPI_qanGetBlockTransactionCountByHash) | **GET** /getBlockTransactionCountByHash/{Hash}/ | Returns the number of transactions for the block matching the given block hash.
[**QANAPI_qanGetBlockTransactionCountByNumber**](QANAPI.md#QANAPI_qanGetBlockTransactionCountByNumber) | **GET** /getBlockTransactionCountByNumber/{BlockNumber}/ | Returns the number of transactions for the block matching the given block number.
[**QANAPI_qanGetCode**](QANAPI.md#QANAPI_qanGetCode) | **GET** /getCode/{Address}/ | Returns the compiled bytecode of a smart contract.
[**QANAPI_qanGetFilterChanges**](QANAPI.md#QANAPI_qanGetFilterChanges) | **GET** /getFilterChanges/{FilterId}/ | Polling method for a filter, which returns an array of events that have occurred since the last poll.
[**QANAPI_qanGetFilterLogs**](QANAPI.md#QANAPI_qanGetFilterLogs) | **GET** /getFilterLogs/{Id}/ | Returns an array of all logs matching filter with given id.
[**QANAPI_qanGetLogs**](QANAPI.md#QANAPI_qanGetLogs) | **POST** /getLogs/ | Returns an array of all logs matching a given filter object.
[**QANAPI_qanGetProof**](QANAPI.md#QANAPI_qanGetProof) | **POST** /getProof/ | Returns the account and storage values of the specified account including the Merkle-proof.
[**QANAPI_qanGetStorageAt**](QANAPI.md#QANAPI_qanGetStorageAt) | **POST** /getStorageAt/ | Returns the value from a storage position at a given address.
[**QANAPI_qanGetTransactionByBlockHashAndIndex**](QANAPI.md#QANAPI_qanGetTransactionByBlockHashAndIndex) | **GET** /getTransactionByBlockHashAndIndex/{blockHash}/{index}/ | Returns information about a transaction given a blockhash and transaction index position.
[**QANAPI_qanGetTransactionByBlockNumberAndIndex**](QANAPI.md#QANAPI_qanGetTransactionByBlockNumberAndIndex) | **GET** /getTransactionByBlockNumberAndIndex/{blockNumber}/{index}/ | Returns information about a transaction given a block number and transaction index position.
[**QANAPI_qanGetTransactionByHash**](QANAPI.md#QANAPI_qanGetTransactionByHash) | **GET** /getTransactionByHash/{hash}/ | Returns the information about a transaction from a transaction hash.
[**QANAPI_qanGetTransactionCount**](QANAPI.md#QANAPI_qanGetTransactionCount) | **GET** /getTransactionCount/{Address}/{BlockNumber}/ | Returns the number of transactions sent from an address.
[**QANAPI_qanGetTransactionReceipt**](QANAPI.md#QANAPI_qanGetTransactionReceipt) | **GET** /getTransactionReceipt/{Hash}/ | Returns the receipt of a transaction by transaction hash.
[**QANAPI_qanMaxPriorityFeePerGas**](QANAPI.md#QANAPI_qanMaxPriorityFeePerGas) | **GET** /maxPriorityFeePerGas/ | Get the priority fee needed to be included in a block.
[**QANAPI_qanNewBlockFilter**](QANAPI.md#QANAPI_qanNewBlockFilter) | **GET** /newBlockFilter/ | Creates a filter in the node, to notify when a new block arrives.
[**QANAPI_qanNewFilter**](QANAPI.md#QANAPI_qanNewFilter) | **POST** /newFilter/ | Creates a filter object, based on filter options, to notify when the state changes (logs).
[**QANAPI_qanNewPendingTransactionFilter**](QANAPI.md#QANAPI_qanNewPendingTransactionFilter) | **GET** /newPendingTransactionFilter/ | Creates a filter in the node to notify when new pending transactions arrive.
[**QANAPI_qanSendRawTransaction**](QANAPI.md#QANAPI_qanSendRawTransaction) | **POST** /sendRawTransaction/ | Creates new message call transaction or a contract creation for signed transactions.
[**QANAPI_qanSyncing**](QANAPI.md#QANAPI_qanSyncing) | **GET** /syncing/ | Returns an object with the sync status of the node if the node is out-of-sync and is syncing. Returns null when the node is already in sync.
[**QANAPI_qanUninstallFilter**](QANAPI.md#QANAPI_qanUninstallFilter) | **GET** /uninstallFilter/{FilterId}/ | Uninstalls a filter with the given filter id.
[**QANAPI_qanXlinkValid**](QANAPI.md#QANAPI_qanXlinkValid) | **GET** /xlinkValid/{Address}/ | Returns the xlink validity time of the account of given address.


# **QANAPI_qanBlockNumber**
```c
// Returns the latest block number of the blockchain.
//
output_block_number_t* QANAPI_qanBlockNumber(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[output_block_number_t](output_block_number.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanCall**
```c
// Executes a new message call immediately without creating a transaction on the block chain.
//
output_call_t* QANAPI_qanCall(apiClient_t *apiClient, input_call_t *input_call);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**input_call** | **[input_call_t](input_call.md) \*** |  | 

### Return type

[output_call_t](output_call.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanChainId**
```c
// Returns the current network/chain ID, used to sign replay-protected transaction introduced in EIP-155.
//
output_chain_id_t* QANAPI_qanChainId(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[output_chain_id_t](output_chain_id.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanEstimateGas**
```c
// Returns an estimation of gas for a given transaction.
//
output_estimate_gas_t* QANAPI_qanEstimateGas(apiClient_t *apiClient, input_estimate_gas_t *input_estimate_gas);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**input_estimate_gas** | **[input_estimate_gas_t](input_estimate_gas.md) \*** |  | 

### Return type

[output_estimate_gas_t](output_estimate_gas.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanFeeHistory**
```c
// Returns the collection of historical gas information.
//
output_fee_history_t* QANAPI_qanFeeHistory(apiClient_t *apiClient, input_fee_history_t *input_fee_history);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**input_fee_history** | **[input_fee_history_t](input_fee_history.md) \*** |  | 

### Return type

[output_fee_history_t](output_fee_history.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGasPrice**
```c
// Returns the current gas price on the network in wei.
//
output_gas_price_t* QANAPI_qanGasPrice(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[output_gas_price_t](output_gas_price.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetBalance**
```c
// Returns the balance of the account of given address.
//
output_get_balance_t* QANAPI_qanGetBalance(apiClient_t *apiClient, char *Address, char *BlockNumber);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**Address** | **char \*** | A 20 bytes long hexadecimal value representing an address | 
**BlockNumber** | **char \*** | The block number in hexadecimal or decimal format or the string latest, earliest, pending | [optional] [default to &#39;latest&#39;]

### Return type

[output_get_balance_t](output_get_balance.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetBlockByHash**
```c
// Returns information of the block matching the given block hash.
//
output_get_block_by_hash_t* QANAPI_qanGetBlockByHash(apiClient_t *apiClient, char *Hash, int *TransactionDetailFlag);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**Hash** | **char \*** | The hash (32 bytes) of the block | 
**TransactionDetailFlag** | **int \*** | The method returns the full transaction objects when this value is true otherwise, it returns only the hashes of the transactions | [default to false]

### Return type

[output_get_block_by_hash_t](output_get_block_by_hash.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetBlockByNumber**
```c
// Returns information of the block matching the given block number.
//
output_get_block_by_number_t* QANAPI_qanGetBlockByNumber(apiClient_t *apiClient, char *BlockNumber, int *TransactionDetailFlag);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**BlockNumber** | **char \*** | The block number in hexadecimal or decimal format or the string latest, earliest, pending | [default to &#39;latest&#39;]
**TransactionDetailFlag** | **int \*** | The method returns the full transaction objects when this value is true otherwise, it returns only the hashes of the transactions | [default to false]

### Return type

[output_get_block_by_number_t](output_get_block_by_number.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetBlockReceipts**
```c
// Returns all transaction receipts for a given block.
//
output_get_block_receipts_t* QANAPI_qanGetBlockReceipts(apiClient_t *apiClient, char *BlockNumber);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**BlockNumber** | **char \*** | The block number in hexadecimal or decimal format or the string latest, earliest, pending | [default to &#39;latest&#39;]

### Return type

[output_get_block_receipts_t](output_get_block_receipts.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetBlockTransactionCountByHash**
```c
// Returns the number of transactions for the block matching the given block hash.
//
output_get_block_transaction_count_by_hash_t* QANAPI_qanGetBlockTransactionCountByHash(apiClient_t *apiClient, char *Hash);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**Hash** | **char \*** | The hash of the block | 

### Return type

[output_get_block_transaction_count_by_hash_t](output_get_block_transaction_count_by_hash.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetBlockTransactionCountByNumber**
```c
// Returns the number of transactions for the block matching the given block number.
//
output_get_block_transaction_count_by_number_t* QANAPI_qanGetBlockTransactionCountByNumber(apiClient_t *apiClient, char *BlockNumber);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**BlockNumber** | **char \*** | The block number in hexadecimal or decimal format or the string latest, earliest, pending | 

### Return type

[output_get_block_transaction_count_by_number_t](output_get_block_transaction_count_by_number.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetCode**
```c
// Returns the compiled bytecode of a smart contract.
//
output_get_code_t* QANAPI_qanGetCode(apiClient_t *apiClient, char *Address, char *BlockNumber);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**Address** | **char \*** | The address of the smart contract from which the bytecode will be obtained | 
**BlockNumber** | **char \*** | The block number in hexadecimal or decimal format or the string latest, earliest, pending | [optional] [default to &#39;latest&#39;]

### Return type

[output_get_code_t](output_get_code.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetFilterChanges**
```c
// Polling method for a filter, which returns an array of events that have occurred since the last poll.
//
output_get_filter_changes_t* QANAPI_qanGetFilterChanges(apiClient_t *apiClient, char *FilterId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**FilterId** | **char \*** | The filter id that is returned from getFilterChangesnewFilter, getFilterChangesnewBlockFilter or getFilterChangesnewPendingTransactionFilter | 

### Return type

[output_get_filter_changes_t](output_get_filter_changes.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetFilterLogs**
```c
// Returns an array of all logs matching filter with given id.
//
output_get_filter_logs_t* QANAPI_qanGetFilterLogs(apiClient_t *apiClient, char *Id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**Id** | **char \*** | The filter ID | 

### Return type

[output_get_filter_logs_t](output_get_filter_logs.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetLogs**
```c
// Returns an array of all logs matching a given filter object.
//
output_get_logs_t* QANAPI_qanGetLogs(apiClient_t *apiClient, input_get_logs_t *input_get_logs);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**input_get_logs** | **[input_get_logs_t](input_get_logs.md) \*** |  | 

### Return type

[output_get_logs_t](output_get_logs.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetProof**
```c
// Returns the account and storage values of the specified account including the Merkle-proof.
//
output_get_proof_t* QANAPI_qanGetProof(apiClient_t *apiClient, input_get_proof_t *input_get_proof);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**input_get_proof** | **[input_get_proof_t](input_get_proof.md) \*** |  | 

### Return type

[output_get_proof_t](output_get_proof.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetStorageAt**
```c
// Returns the value from a storage position at a given address.
//
output_get_storage_at_t* QANAPI_qanGetStorageAt(apiClient_t *apiClient, input_get_storage_at_t *input_get_storage_at);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**input_get_storage_at** | **[input_get_storage_at_t](input_get_storage_at.md) \*** |  | 

### Return type

[output_get_storage_at_t](output_get_storage_at.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetTransactionByBlockHashAndIndex**
```c
// Returns information about a transaction given a blockhash and transaction index position.
//
output_get_transaction_by_block_hash_and_index_t* QANAPI_qanGetTransactionByBlockHashAndIndex(apiClient_t *apiClient, char *blockHash, char *index);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**blockHash** | **char \*** |  | 
**index** | **char \*** | An integer of the transaction index position | 

### Return type

[output_get_transaction_by_block_hash_and_index_t](output_get_transaction_by_block_hash_and_index.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetTransactionByBlockNumberAndIndex**
```c
// Returns information about a transaction given a block number and transaction index position.
//
output_get_transaction_by_block_number_and_index_t* QANAPI_qanGetTransactionByBlockNumberAndIndex(apiClient_t *apiClient, char *blockNumber, char *index);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**blockNumber** | **char \*** | The block number in hexadecimal or decimal format or the string latest, earliest, pending | 
**index** | **char \*** | An integer of the transaction index position | 

### Return type

[output_get_transaction_by_block_number_and_index_t](output_get_transaction_by_block_number_and_index.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetTransactionByHash**
```c
// Returns the information about a transaction from a transaction hash.
//
output_get_transaction_by_hash_t* QANAPI_qanGetTransactionByHash(apiClient_t *apiClient, char *hash);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**hash** | **char \*** | The hash of a transaction | 

### Return type

[output_get_transaction_by_hash_t](output_get_transaction_by_hash.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetTransactionCount**
```c
// Returns the number of transactions sent from an address.
//
output_get_transaction_count_t* QANAPI_qanGetTransactionCount(apiClient_t *apiClient, char *Address, char *BlockNumber);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**Address** | **char \*** | The address from which the transaction count to be checked | 
**BlockNumber** | **char \*** | The block number in hexadecimal or decimal format or the string latest, earliest, pending | 

### Return type

[output_get_transaction_count_t](output_get_transaction_count.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanGetTransactionReceipt**
```c
// Returns the receipt of a transaction by transaction hash.
//
output_get_transaction_receipt_t* QANAPI_qanGetTransactionReceipt(apiClient_t *apiClient, char *Hash);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**Hash** | **char \*** | The hash of a transaction | 

### Return type

[output_get_transaction_receipt_t](output_get_transaction_receipt.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanMaxPriorityFeePerGas**
```c
// Get the priority fee needed to be included in a block.
//
output_max_priority_fee_per_gas_t* QANAPI_qanMaxPriorityFeePerGas(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[output_max_priority_fee_per_gas_t](output_max_priority_fee_per_gas.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanNewBlockFilter**
```c
// Creates a filter in the node, to notify when a new block arrives.
//
output_new_block_filter_t* QANAPI_qanNewBlockFilter(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[output_new_block_filter_t](output_new_block_filter.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanNewFilter**
```c
// Creates a filter object, based on filter options, to notify when the state changes (logs).
//
output_new_filter_t* QANAPI_qanNewFilter(apiClient_t *apiClient, input_new_filter_t *input_new_filter);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**input_new_filter** | **[input_new_filter_t](input_new_filter.md) \*** |  | 

### Return type

[output_new_filter_t](output_new_filter.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanNewPendingTransactionFilter**
```c
// Creates a filter in the node to notify when new pending transactions arrive.
//
output_new_pending_transaction_filter_t* QANAPI_qanNewPendingTransactionFilter(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[output_new_pending_transaction_filter_t](output_new_pending_transaction_filter.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanSendRawTransaction**
```c
// Creates new message call transaction or a contract creation for signed transactions.
//
output_send_raw_transaction_t* QANAPI_qanSendRawTransaction(apiClient_t *apiClient, input_send_raw_transaction_t *input_send_raw_transaction);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**input_send_raw_transaction** | **[input_send_raw_transaction_t](input_send_raw_transaction.md) \*** |  | 

### Return type

[output_send_raw_transaction_t](output_send_raw_transaction.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanSyncing**
```c
// Returns an object with the sync status of the node if the node is out-of-sync and is syncing. Returns null when the node is already in sync.
//
output_syncing_t* QANAPI_qanSyncing(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[output_syncing_t](output_syncing.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanUninstallFilter**
```c
// Uninstalls a filter with the given filter id.
//
output_uninstall_filter_t* QANAPI_qanUninstallFilter(apiClient_t *apiClient, char *FilterId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**FilterId** | **char \*** | The filter ID that needs to be uninstalled. It should always be called when watch is no longer needed. Additionally, Filters timeout when they aren&#39;t requested with getFilterChanges for a period of time | 

### Return type

[output_uninstall_filter_t](output_uninstall_filter.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QANAPI_qanXlinkValid**
```c
// Returns the xlink validity time of the account of given address.
//
output_xlink_valid_t* QANAPI_qanXlinkValid(apiClient_t *apiClient, char *Address);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**Address** | **char \*** |  | 

### Return type

[output_xlink_valid_t](output_xlink_valid.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

