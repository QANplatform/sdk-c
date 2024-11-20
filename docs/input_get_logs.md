# input_get_logs_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**schema** | **char \*** | A URL to the JSON Schema for this object. | [optional] [readonly] 
**address** | **char \*** | The contract address or a list of addresses from which logs should originate | [optional] 
**block_hash** | **char \*** | With the addition of EIP-234, blockHash is a new filter option that restricts the logs returned to the block number referenced in the blockHash. Using the blockHash field is equivalent to setting the fromBlock and toBlock to the block number the blockHash references. If blockHash is present in the filter criteria, neither fromBlock nor toBlock is allowed | [optional] 
**from_block** | **char \*** | The block number as a string in decimal format or tags. The supported tag values include earliest for the earliest/genesis block, latest for the latest mined block, pending for the pending state/transactions. | [optional] 
**to_block** | **char \*** | The block number as a string in decimal format or tags. The supported tag values include earliest for the earliest/genesis block, latest for the latest mined block, pending for the pending state/transactions. | [optional] 
**topics** | **list_t \*** | An array of DATA topics and also, the topics are order-dependent. Visit this official page to learn more about topics | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


