# response_transaction_receipt_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**block_hash** | **char \*** | The hash of the block. null when pending | [optional] 
**block_number** | **char \*** |  | [optional] 
**contract_address** | **char \*** | The contract address created if the transaction was a contract creation, otherwise null | [optional] 
**cumulative_gas_used** | **char \*** | The total amount of gas used when this transaction was executed in the block | [optional] 
**effective_gas_price** | **char \*** | The actual value per gas deducted from the sender account | [optional] 
**from** | **char \*** | The address of the sender | [optional] 
**gas_used** | **char \*** | The amount of gas used by this specific transaction alone | [optional] 
**logs** | [**list_t**](response_log.md) \* | An array of log objects that generated this transaction | [optional] 
**logs_bloom** | **char \*** | The bloom filter for light clients to quickly retrieve related logs | [optional] 
**status** | **char \*** | It is either 1 (success) or 0 (failure) encoded as a decimal | [optional] 
**to** | **char \*** | The address of the receiver. null when it&#39;s a contract creation transaction | [optional] 
**transaction_hash** | **char \*** | The hash of the transaction | [optional] 
**transaction_index** | **char \*** | An index of the transaction in the block | [optional] 
**type** | **char \*** | The value type | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


