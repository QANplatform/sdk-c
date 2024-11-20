# response_transaction_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**access_list** | **char \*** | A list of addresses and storage keys that the transaction plans to access | [optional] 
**block_hash** | **char \*** | The hash of the block where this transaction was in. Null when it&#39;s a pending transaction | [optional] 
**block_number** | **char \*** | The block number where this transaction was in. Null when it&#39;s a pending transaction | [optional] 
**chain_id** | **char \*** | The chain id of the transaction, if any | [optional] 
**from** | **char \*** | The address of the sender | [optional] 
**gas** | **char \*** | The gas provided by the sender, encoded as decimal | [optional] 
**gas_price** | **char \*** | The gas price provided by the sender in wei encoded as decimal | [optional] 
**hash** | **char \*** | The hash of the transaction | [optional] 
**input** | **char \*** | The data sent along with the transaction | [optional] 
**max_fee_per_gas** | **char \*** | The maximum fee per gas set in the transaction | [optional] 
**max_priority_fee_per_gas** | **char \*** | The maximum priority gas fee set in the transaction | [optional] 
**nonce** | **char \*** | The number of transactions made by the sender prior to this one encoded as decimal | [optional] 
**r** | **char \*** | The R field of the signature | [optional] 
**s** | **char \*** | The S field of the signature | [optional] 
**to** | **char \*** | The address of the receiver. Null when its a contract creation transaction | [optional] 
**transaction_index** | **char \*** | The integer of the transaction&#39;s index position that the log was created from. Null when it&#39;s a pending log | [optional] 
**type** | **char \*** | The transaction type | [optional] 
**v** | **char \*** | The standardized V field of the signature | [optional] 
**value** | **char \*** | The value transferred in wei encoded as decimal | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


