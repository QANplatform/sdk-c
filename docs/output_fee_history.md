# output_fee_history_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**schema** | **char \*** | A URL to the JSON Schema for this object. | [optional] [readonly] 
**base_fee_per_gas** | **list_t \*** | An array of block base fees per gas. This includes the next block after the newest of the returned range, because this value can be derived from the newest block. Zeroes are returned for pre-EIP-1559 blocks | 
**gas_used_ratio** | **list_t \*** | An array of block gas used ratios. These are calculated as the ratio of gasUsed and gasLimit | 
**oldest_block** | **char \*** | The lowest number block of the returned range encoded in decimal format | 
**reward** | **list_t \*** | An array of effective priority fees per gas data points from a single block. All zeroes are returned if the block is empty | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


