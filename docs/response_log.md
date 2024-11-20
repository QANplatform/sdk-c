# response_log_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**address** | **char \*** | An address from which this log originated | 
**block_hash** | **char \*** | The hash of the block where this log was in. null when its a pending log | 
**block_number** | **char \*** | The block number where this log was in. null when its a pending log | 
**data** | **char \*** | It contains one or more 32 Bytes non-indexed arguments of the log | 
**log_index** | **char \*** | The integer of the log index position in the block. null when its a pending log | 
**removed** | **int** | It is true when the log was removed due to a chain reorganization, and false if it&#39;s a valid log | 
**topics** | **list_t \*** | An array of zero to four 32 Bytes DATA of indexed log arguments. In Solidity, the first topic is the hash of the signature of the event (e.g. Deposit(address, bytes32, uint256)), except you declare the event with the anonymous specifier | 
**transaction_hash** | **char \*** | The hash of the transactions this log was created from. null when its a pending log | 
**transaction_index** | **char \*** | The integer of the transaction&#39;s index position that the log was created from. null when it&#39;s a pending log | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


