# error_model_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**schema** | **char \*** | A URL to the JSON Schema for this object. | [optional] [readonly] 
**detail** | **char \*** | A human-readable explanation specific to this occurrence of the problem. | [optional] 
**errors** | [**list_t**](error_detail.md) \* | Optional list of individual error details | [optional] 
**instance** | **char \*** | A URI reference that identifies the specific occurrence of the problem. | [optional] 
**status** | **long** | HTTP status code | [optional] 
**title** | **char \*** | A short, human-readable summary of the problem type. This value should not change between occurrences of the error. | [optional] 
**type** | **char \*** | A URI reference to human-readable documentation for the error. | [optional] [default to 'about:blank']

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


