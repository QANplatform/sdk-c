# output_get_proof_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**schema** | **char \*** | A URL to the JSON Schema for this object. | [optional] [readonly] 
**account_proof** | **char \*** | An array of rlp-serialized MerkleTree-Nodes which starts with the stateRoot-Node and follows the path of the SHA3 address as key | 
**address** | **char \*** | The address associated with the account | 
**balance** | **char \*** | The current balance of the account in wei | 
**code_hash** | **char \*** | A 32 byte hash of the code of the account | 
**nonce** | **char \*** | The hash of the generated proof-of-work. Null if pending | 
**storage_hash** | **char \*** | A 32 byte SHA3 of the storageRoot. All storage will deliver a MerkleProof starting with this rootHash | 
**storage_proof** | [**list_t**](response_storage_entry.md) \* | An array of storage-entries as requested. Each entry is an object with the following fields: | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


