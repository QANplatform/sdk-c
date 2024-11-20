# response_block_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**base_fee_per_gas** | **char \*** | A string of the base fee encoded in decimal format. Please note that this response field will not be included in a block requested before the EIP-1559 upgrade | 
**difficulty** | **char \*** | The integer of the difficulty for this block encoded as a decimal | 
**extra_data** | **char \*** | The “extra data” field of this block | 
**gas_limit** | **char \*** | The maximum gas allowed in this block encoded as a decimal | 
**gas_used** | **char \*** | The total used gas by all transactions in this block encoded as a decimal | 
**hash** | **char \*** | The block hash of the requested block. null if pending | 
**logs_bloom** | **char \*** | The bloom filter for the logs of the block. null if pending | 
**miner** | **char \*** | The address of the beneficiary to whom the mining rewards were given | 
**mix_hash** | **char \*** | A string of a 256-bit hash encoded as a decimal | 
**nonce** | **char \*** | The hash of the generated proof-of-work. null if pending | 
**number** | **char \*** | The block number of the requested block encoded as a decimal. null if pending | 
**parent_hash** | **char \*** | The hash of the parent block | 
**receipts_root** | **char \*** | The root of the receipts trie of the bloc | 
**sha3_uncles** | **char \*** | The SHA3 of the uncles data in the block | 
**size** | **char \*** | The size of this block in bytes as an Integer value encoded as decimal | 
**state_root** | **char \*** | The root of the final state trie of the block | 
**timestamp** | **char \*** | The unix timestamp for when the block was collated | 
**total_difficulty** | **char \*** | The integer of the total difficulty of the chain until this block encoded as a decimal | 
**transactions** | [**list_t**](response_transaction.md) \* | An array of transaction objects - please see getTransactionByHash for exact shape | 
**transactions_root** | **char \*** | The root of the transaction trie of the block | 
**uncles** | **list_t \*** | An array of uncle hashes | 
**withdrawals** | [**response_withdrawals_t**](response_withdrawals.md) \* | A withdrawals object contains information about withdrawals made by validators. Please note that this field will not be included in a block requested before the EIP-4895 upgrade | 
**withdrawals_root** | **char \*** | The Merkle root of withdrawal data. Also, please note that this field will not be included in a block requested before the EIP-4895 upgrade | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


