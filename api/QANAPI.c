#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "QANAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// Returns the latest block number of the blockchain.
//
output_block_number_t*
QANAPI_qanBlockNumber(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/blockNumber/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/blockNumber/");



    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_block_number_t *elementToReturn = output_block_number_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Executes a new message call immediately without creating a transaction on the block chain.
//
output_call_t*
QANAPI_qanCall(apiClient_t *apiClient, input_call_t *input_call)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/call/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/call/");




    // Body Param
    cJSON *localVarSingleItemJSON_input_call = NULL;
    if (input_call != NULL)
    {
        //string
        localVarSingleItemJSON_input_call = input_call_convertToJSON(input_call);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_input_call);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_call_t *elementToReturn = output_call_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_input_call) {
        cJSON_Delete(localVarSingleItemJSON_input_call);
        localVarSingleItemJSON_input_call = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns the current network/chain ID, used to sign replay-protected transaction introduced in EIP-155.
//
output_chain_id_t*
QANAPI_qanChainId(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/chainId/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/chainId/");



    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_chain_id_t *elementToReturn = output_chain_id_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns an estimation of gas for a given transaction.
//
output_estimate_gas_t*
QANAPI_qanEstimateGas(apiClient_t *apiClient, input_estimate_gas_t *input_estimate_gas)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/estimateGas/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/estimateGas/");




    // Body Param
    cJSON *localVarSingleItemJSON_input_estimate_gas = NULL;
    if (input_estimate_gas != NULL)
    {
        //string
        localVarSingleItemJSON_input_estimate_gas = input_estimate_gas_convertToJSON(input_estimate_gas);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_input_estimate_gas);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_estimate_gas_t *elementToReturn = output_estimate_gas_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_input_estimate_gas) {
        cJSON_Delete(localVarSingleItemJSON_input_estimate_gas);
        localVarSingleItemJSON_input_estimate_gas = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns the collection of historical gas information.
//
output_fee_history_t*
QANAPI_qanFeeHistory(apiClient_t *apiClient, input_fee_history_t *input_fee_history)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/feeHistory/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/feeHistory/");




    // Body Param
    cJSON *localVarSingleItemJSON_input_fee_history = NULL;
    if (input_fee_history != NULL)
    {
        //string
        localVarSingleItemJSON_input_fee_history = input_fee_history_convertToJSON(input_fee_history);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_input_fee_history);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_fee_history_t *elementToReturn = output_fee_history_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_input_fee_history) {
        cJSON_Delete(localVarSingleItemJSON_input_fee_history);
        localVarSingleItemJSON_input_fee_history = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns the current gas price on the network in wei.
//
output_gas_price_t*
QANAPI_qanGasPrice(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/gasPrice/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/gasPrice/");



    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_gas_price_t *elementToReturn = output_gas_price_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns the balance of the account of given address.
//
output_get_balance_t*
QANAPI_qanGetBalance(apiClient_t *apiClient, char *Address, char *BlockNumber)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getBalance/{Address}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getBalance/{Address}/");


    // Path Params
    long sizeOfPathParams_Address = strlen(Address)+3 + strlen("{ Address }");
    if(Address == NULL) {
        goto end;
    }
    char* localVarToReplace_Address = malloc(sizeOfPathParams_Address);
    sprintf(localVarToReplace_Address, "{%s}", "Address");

    localVarPath = strReplace(localVarPath, localVarToReplace_Address, Address);



    // query parameters
    char *keyQuery_BlockNumber = NULL;
    char * valueQuery_BlockNumber = NULL;
    keyValuePair_t *keyPairQuery_BlockNumber = 0;
    if (BlockNumber)
    {
        keyQuery_BlockNumber = strdup("BlockNumber");
        valueQuery_BlockNumber = strdup((BlockNumber));
        keyPairQuery_BlockNumber = keyValuePair_create(keyQuery_BlockNumber, valueQuery_BlockNumber);
        list_addElement(localVarQueryParameters,keyPairQuery_BlockNumber);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_balance_t *elementToReturn = output_get_balance_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_Address);
    if(keyQuery_BlockNumber){
        free(keyQuery_BlockNumber);
        keyQuery_BlockNumber = NULL;
    }
    if(valueQuery_BlockNumber){
        free(valueQuery_BlockNumber);
        valueQuery_BlockNumber = NULL;
    }
    if(keyPairQuery_BlockNumber){
        keyValuePair_free(keyPairQuery_BlockNumber);
        keyPairQuery_BlockNumber = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns information of the block matching the given block hash.
//
output_get_block_by_hash_t*
QANAPI_qanGetBlockByHash(apiClient_t *apiClient, char *Hash, int *TransactionDetailFlag)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getBlockByHash/{Hash}/{TransactionDetailFlag}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getBlockByHash/{Hash}/{TransactionDetailFlag}/");


    // Path Params
    long sizeOfPathParams_Hash = strlen(Hash)+3 +  + strlen("{ Hash }");
    if(Hash == NULL) {
        goto end;
    }
    char* localVarToReplace_Hash = malloc(sizeOfPathParams_Hash);
    sprintf(localVarToReplace_Hash, "{%s}", "Hash");

    localVarPath = strReplace(localVarPath, localVarToReplace_Hash, Hash);

    // Path Params
    long sizeOfPathParams_TransactionDetailFlag = strlen(Hash)+3 +  + strlen("{ TransactionDetailFlag }");


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_block_by_hash_t *elementToReturn = output_get_block_by_hash_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_Hash);
    free(localVarToReplace_TransactionDetailFlag);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns information of the block matching the given block number.
//
output_get_block_by_number_t*
QANAPI_qanGetBlockByNumber(apiClient_t *apiClient, char *BlockNumber, int *TransactionDetailFlag)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getBlockByNumber/{BlockNumber}/{TransactionDetailFlag}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getBlockByNumber/{BlockNumber}/{TransactionDetailFlag}/");


    // Path Params
    long sizeOfPathParams_BlockNumber = strlen(BlockNumber)+3 +  + strlen("{ BlockNumber }");
    if(BlockNumber == NULL) {
        goto end;
    }
    char* localVarToReplace_BlockNumber = malloc(sizeOfPathParams_BlockNumber);
    sprintf(localVarToReplace_BlockNumber, "{%s}", "BlockNumber");

    localVarPath = strReplace(localVarPath, localVarToReplace_BlockNumber, BlockNumber);

    // Path Params
    long sizeOfPathParams_TransactionDetailFlag = strlen(BlockNumber)+3 +  + strlen("{ TransactionDetailFlag }");


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_block_by_number_t *elementToReturn = output_get_block_by_number_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_BlockNumber);
    free(localVarToReplace_TransactionDetailFlag);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns all transaction receipts for a given block.
//
output_get_block_receipts_t*
QANAPI_qanGetBlockReceipts(apiClient_t *apiClient, char *BlockNumber)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getBlockReceipts/{BlockNumber}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getBlockReceipts/{BlockNumber}/");


    // Path Params
    long sizeOfPathParams_BlockNumber = strlen(BlockNumber)+3 + strlen("{ BlockNumber }");
    if(BlockNumber == NULL) {
        goto end;
    }
    char* localVarToReplace_BlockNumber = malloc(sizeOfPathParams_BlockNumber);
    sprintf(localVarToReplace_BlockNumber, "{%s}", "BlockNumber");

    localVarPath = strReplace(localVarPath, localVarToReplace_BlockNumber, BlockNumber);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_block_receipts_t *elementToReturn = output_get_block_receipts_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_BlockNumber);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns the number of transactions for the block matching the given block hash.
//
output_get_block_transaction_count_by_hash_t*
QANAPI_qanGetBlockTransactionCountByHash(apiClient_t *apiClient, char *Hash)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getBlockTransactionCountByHash/{Hash}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getBlockTransactionCountByHash/{Hash}/");


    // Path Params
    long sizeOfPathParams_Hash = strlen(Hash)+3 + strlen("{ Hash }");
    if(Hash == NULL) {
        goto end;
    }
    char* localVarToReplace_Hash = malloc(sizeOfPathParams_Hash);
    sprintf(localVarToReplace_Hash, "{%s}", "Hash");

    localVarPath = strReplace(localVarPath, localVarToReplace_Hash, Hash);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_block_transaction_count_by_hash_t *elementToReturn = output_get_block_transaction_count_by_hash_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_Hash);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns the number of transactions for the block matching the given block number.
//
output_get_block_transaction_count_by_number_t*
QANAPI_qanGetBlockTransactionCountByNumber(apiClient_t *apiClient, char *BlockNumber)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getBlockTransactionCountByNumber/{BlockNumber}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getBlockTransactionCountByNumber/{BlockNumber}/");


    // Path Params
    long sizeOfPathParams_BlockNumber = strlen(BlockNumber)+3 + strlen("{ BlockNumber }");
    if(BlockNumber == NULL) {
        goto end;
    }
    char* localVarToReplace_BlockNumber = malloc(sizeOfPathParams_BlockNumber);
    sprintf(localVarToReplace_BlockNumber, "{%s}", "BlockNumber");

    localVarPath = strReplace(localVarPath, localVarToReplace_BlockNumber, BlockNumber);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_block_transaction_count_by_number_t *elementToReturn = output_get_block_transaction_count_by_number_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_BlockNumber);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns the compiled bytecode of a smart contract.
//
output_get_code_t*
QANAPI_qanGetCode(apiClient_t *apiClient, char *Address, char *BlockNumber)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getCode/{Address}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getCode/{Address}/");


    // Path Params
    long sizeOfPathParams_Address = strlen(Address)+3 + strlen("{ Address }");
    if(Address == NULL) {
        goto end;
    }
    char* localVarToReplace_Address = malloc(sizeOfPathParams_Address);
    sprintf(localVarToReplace_Address, "{%s}", "Address");

    localVarPath = strReplace(localVarPath, localVarToReplace_Address, Address);



    // query parameters
    char *keyQuery_BlockNumber = NULL;
    char * valueQuery_BlockNumber = NULL;
    keyValuePair_t *keyPairQuery_BlockNumber = 0;
    if (BlockNumber)
    {
        keyQuery_BlockNumber = strdup("BlockNumber");
        valueQuery_BlockNumber = strdup((BlockNumber));
        keyPairQuery_BlockNumber = keyValuePair_create(keyQuery_BlockNumber, valueQuery_BlockNumber);
        list_addElement(localVarQueryParameters,keyPairQuery_BlockNumber);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_code_t *elementToReturn = output_get_code_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_Address);
    if(keyQuery_BlockNumber){
        free(keyQuery_BlockNumber);
        keyQuery_BlockNumber = NULL;
    }
    if(valueQuery_BlockNumber){
        free(valueQuery_BlockNumber);
        valueQuery_BlockNumber = NULL;
    }
    if(keyPairQuery_BlockNumber){
        keyValuePair_free(keyPairQuery_BlockNumber);
        keyPairQuery_BlockNumber = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Polling method for a filter, which returns an array of events that have occurred since the last poll.
//
output_get_filter_changes_t*
QANAPI_qanGetFilterChanges(apiClient_t *apiClient, char *FilterId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getFilterChanges/{FilterId}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getFilterChanges/{FilterId}/");


    // Path Params
    long sizeOfPathParams_FilterId = strlen(FilterId)+3 + strlen("{ FilterId }");
    if(FilterId == NULL) {
        goto end;
    }
    char* localVarToReplace_FilterId = malloc(sizeOfPathParams_FilterId);
    sprintf(localVarToReplace_FilterId, "{%s}", "FilterId");

    localVarPath = strReplace(localVarPath, localVarToReplace_FilterId, FilterId);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_filter_changes_t *elementToReturn = output_get_filter_changes_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_FilterId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns an array of all logs matching filter with given id.
//
output_get_filter_logs_t*
QANAPI_qanGetFilterLogs(apiClient_t *apiClient, char *Id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getFilterLogs/{Id}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getFilterLogs/{Id}/");


    // Path Params
    long sizeOfPathParams_Id = strlen(Id)+3 + strlen("{ Id }");
    if(Id == NULL) {
        goto end;
    }
    char* localVarToReplace_Id = malloc(sizeOfPathParams_Id);
    sprintf(localVarToReplace_Id, "{%s}", "Id");

    localVarPath = strReplace(localVarPath, localVarToReplace_Id, Id);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_filter_logs_t *elementToReturn = output_get_filter_logs_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_Id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns an array of all logs matching a given filter object.
//
output_get_logs_t*
QANAPI_qanGetLogs(apiClient_t *apiClient, input_get_logs_t *input_get_logs)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getLogs/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getLogs/");




    // Body Param
    cJSON *localVarSingleItemJSON_input_get_logs = NULL;
    if (input_get_logs != NULL)
    {
        //string
        localVarSingleItemJSON_input_get_logs = input_get_logs_convertToJSON(input_get_logs);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_input_get_logs);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_logs_t *elementToReturn = output_get_logs_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_input_get_logs) {
        cJSON_Delete(localVarSingleItemJSON_input_get_logs);
        localVarSingleItemJSON_input_get_logs = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns the account and storage values of the specified account including the Merkle-proof.
//
output_get_proof_t*
QANAPI_qanGetProof(apiClient_t *apiClient, input_get_proof_t *input_get_proof)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getProof/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getProof/");




    // Body Param
    cJSON *localVarSingleItemJSON_input_get_proof = NULL;
    if (input_get_proof != NULL)
    {
        //string
        localVarSingleItemJSON_input_get_proof = input_get_proof_convertToJSON(input_get_proof);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_input_get_proof);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_proof_t *elementToReturn = output_get_proof_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_input_get_proof) {
        cJSON_Delete(localVarSingleItemJSON_input_get_proof);
        localVarSingleItemJSON_input_get_proof = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns the value from a storage position at a given address.
//
output_get_storage_at_t*
QANAPI_qanGetStorageAt(apiClient_t *apiClient, input_get_storage_at_t *input_get_storage_at)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getStorageAt/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getStorageAt/");




    // Body Param
    cJSON *localVarSingleItemJSON_input_get_storage_at = NULL;
    if (input_get_storage_at != NULL)
    {
        //string
        localVarSingleItemJSON_input_get_storage_at = input_get_storage_at_convertToJSON(input_get_storage_at);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_input_get_storage_at);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_storage_at_t *elementToReturn = output_get_storage_at_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_input_get_storage_at) {
        cJSON_Delete(localVarSingleItemJSON_input_get_storage_at);
        localVarSingleItemJSON_input_get_storage_at = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns information about a transaction given a blockhash and transaction index position.
//
output_get_transaction_by_block_hash_and_index_t*
QANAPI_qanGetTransactionByBlockHashAndIndex(apiClient_t *apiClient, char *blockHash, char *index)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getTransactionByBlockHashAndIndex/{blockHash}/{index}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getTransactionByBlockHashAndIndex/{blockHash}/{index}/");


    // Path Params
    long sizeOfPathParams_blockHash = strlen(blockHash)+3 + strlen(index)+3 + strlen("{ blockHash }");
    if(blockHash == NULL) {
        goto end;
    }
    char* localVarToReplace_blockHash = malloc(sizeOfPathParams_blockHash);
    sprintf(localVarToReplace_blockHash, "{%s}", "blockHash");

    localVarPath = strReplace(localVarPath, localVarToReplace_blockHash, blockHash);

    // Path Params
    long sizeOfPathParams_index = strlen(blockHash)+3 + strlen(index)+3 + strlen("{ index }");
    if(index == NULL) {
        goto end;
    }
    char* localVarToReplace_index = malloc(sizeOfPathParams_index);
    sprintf(localVarToReplace_index, "{%s}", "index");

    localVarPath = strReplace(localVarPath, localVarToReplace_index, index);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_transaction_by_block_hash_and_index_t *elementToReturn = output_get_transaction_by_block_hash_and_index_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_blockHash);
    free(localVarToReplace_index);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns information about a transaction given a block number and transaction index position.
//
output_get_transaction_by_block_number_and_index_t*
QANAPI_qanGetTransactionByBlockNumberAndIndex(apiClient_t *apiClient, char *blockNumber, char *index)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getTransactionByBlockNumberAndIndex/{blockNumber}/{index}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getTransactionByBlockNumberAndIndex/{blockNumber}/{index}/");


    // Path Params
    long sizeOfPathParams_blockNumber = strlen(blockNumber)+3 + strlen(index)+3 + strlen("{ blockNumber }");
    if(blockNumber == NULL) {
        goto end;
    }
    char* localVarToReplace_blockNumber = malloc(sizeOfPathParams_blockNumber);
    sprintf(localVarToReplace_blockNumber, "{%s}", "blockNumber");

    localVarPath = strReplace(localVarPath, localVarToReplace_blockNumber, blockNumber);

    // Path Params
    long sizeOfPathParams_index = strlen(blockNumber)+3 + strlen(index)+3 + strlen("{ index }");
    if(index == NULL) {
        goto end;
    }
    char* localVarToReplace_index = malloc(sizeOfPathParams_index);
    sprintf(localVarToReplace_index, "{%s}", "index");

    localVarPath = strReplace(localVarPath, localVarToReplace_index, index);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_transaction_by_block_number_and_index_t *elementToReturn = output_get_transaction_by_block_number_and_index_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_blockNumber);
    free(localVarToReplace_index);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns the information about a transaction from a transaction hash.
//
output_get_transaction_by_hash_t*
QANAPI_qanGetTransactionByHash(apiClient_t *apiClient, char *hash)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getTransactionByHash/{hash}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getTransactionByHash/{hash}/");


    // Path Params
    long sizeOfPathParams_hash = strlen(hash)+3 + strlen("{ hash }");
    if(hash == NULL) {
        goto end;
    }
    char* localVarToReplace_hash = malloc(sizeOfPathParams_hash);
    sprintf(localVarToReplace_hash, "{%s}", "hash");

    localVarPath = strReplace(localVarPath, localVarToReplace_hash, hash);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_transaction_by_hash_t *elementToReturn = output_get_transaction_by_hash_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_hash);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns the number of transactions sent from an address.
//
output_get_transaction_count_t*
QANAPI_qanGetTransactionCount(apiClient_t *apiClient, char *Address, char *BlockNumber)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getTransactionCount/{Address}/{BlockNumber}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getTransactionCount/{Address}/{BlockNumber}/");


    // Path Params
    long sizeOfPathParams_Address = strlen(Address)+3 + strlen(BlockNumber)+3 + strlen("{ Address }");
    if(Address == NULL) {
        goto end;
    }
    char* localVarToReplace_Address = malloc(sizeOfPathParams_Address);
    sprintf(localVarToReplace_Address, "{%s}", "Address");

    localVarPath = strReplace(localVarPath, localVarToReplace_Address, Address);

    // Path Params
    long sizeOfPathParams_BlockNumber = strlen(Address)+3 + strlen(BlockNumber)+3 + strlen("{ BlockNumber }");
    if(BlockNumber == NULL) {
        goto end;
    }
    char* localVarToReplace_BlockNumber = malloc(sizeOfPathParams_BlockNumber);
    sprintf(localVarToReplace_BlockNumber, "{%s}", "BlockNumber");

    localVarPath = strReplace(localVarPath, localVarToReplace_BlockNumber, BlockNumber);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_transaction_count_t *elementToReturn = output_get_transaction_count_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_Address);
    free(localVarToReplace_BlockNumber);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns the receipt of a transaction by transaction hash.
//
output_get_transaction_receipt_t*
QANAPI_qanGetTransactionReceipt(apiClient_t *apiClient, char *Hash)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/getTransactionReceipt/{Hash}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/getTransactionReceipt/{Hash}/");


    // Path Params
    long sizeOfPathParams_Hash = strlen(Hash)+3 + strlen("{ Hash }");
    if(Hash == NULL) {
        goto end;
    }
    char* localVarToReplace_Hash = malloc(sizeOfPathParams_Hash);
    sprintf(localVarToReplace_Hash, "{%s}", "Hash");

    localVarPath = strReplace(localVarPath, localVarToReplace_Hash, Hash);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_get_transaction_receipt_t *elementToReturn = output_get_transaction_receipt_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_Hash);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get the priority fee needed to be included in a block.
//
output_max_priority_fee_per_gas_t*
QANAPI_qanMaxPriorityFeePerGas(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/maxPriorityFeePerGas/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/maxPriorityFeePerGas/");



    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_max_priority_fee_per_gas_t *elementToReturn = output_max_priority_fee_per_gas_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Creates a filter in the node, to notify when a new block arrives.
//
output_new_block_filter_t*
QANAPI_qanNewBlockFilter(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/newBlockFilter/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/newBlockFilter/");



    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_new_block_filter_t *elementToReturn = output_new_block_filter_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Creates a filter object, based on filter options, to notify when the state changes (logs).
//
output_new_filter_t*
QANAPI_qanNewFilter(apiClient_t *apiClient, input_new_filter_t *input_new_filter)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/newFilter/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/newFilter/");




    // Body Param
    cJSON *localVarSingleItemJSON_input_new_filter = NULL;
    if (input_new_filter != NULL)
    {
        //string
        localVarSingleItemJSON_input_new_filter = input_new_filter_convertToJSON(input_new_filter);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_input_new_filter);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_new_filter_t *elementToReturn = output_new_filter_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_input_new_filter) {
        cJSON_Delete(localVarSingleItemJSON_input_new_filter);
        localVarSingleItemJSON_input_new_filter = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Creates a filter in the node to notify when new pending transactions arrive.
//
output_new_pending_transaction_filter_t*
QANAPI_qanNewPendingTransactionFilter(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/newPendingTransactionFilter/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/newPendingTransactionFilter/");



    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_new_pending_transaction_filter_t *elementToReturn = output_new_pending_transaction_filter_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Creates new message call transaction or a contract creation for signed transactions.
//
output_send_raw_transaction_t*
QANAPI_qanSendRawTransaction(apiClient_t *apiClient, input_send_raw_transaction_t *input_send_raw_transaction)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/sendRawTransaction/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/sendRawTransaction/");




    // Body Param
    cJSON *localVarSingleItemJSON_input_send_raw_transaction = NULL;
    if (input_send_raw_transaction != NULL)
    {
        //string
        localVarSingleItemJSON_input_send_raw_transaction = input_send_raw_transaction_convertToJSON(input_send_raw_transaction);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_input_send_raw_transaction);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_send_raw_transaction_t *elementToReturn = output_send_raw_transaction_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_input_send_raw_transaction) {
        cJSON_Delete(localVarSingleItemJSON_input_send_raw_transaction);
        localVarSingleItemJSON_input_send_raw_transaction = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns an object with the sync status of the node if the node is out-of-sync and is syncing. Returns null when the node is already in sync.
//
output_syncing_t*
QANAPI_qanSyncing(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/syncing/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/syncing/");



    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_syncing_t *elementToReturn = output_syncing_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Uninstalls a filter with the given filter id.
//
output_uninstall_filter_t*
QANAPI_qanUninstallFilter(apiClient_t *apiClient, char *FilterId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/uninstallFilter/{FilterId}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/uninstallFilter/{FilterId}/");


    // Path Params
    long sizeOfPathParams_FilterId = strlen(FilterId)+3 + strlen("{ FilterId }");
    if(FilterId == NULL) {
        goto end;
    }
    char* localVarToReplace_FilterId = malloc(sizeOfPathParams_FilterId);
    sprintf(localVarToReplace_FilterId, "{%s}", "FilterId");

    localVarPath = strReplace(localVarPath, localVarToReplace_FilterId, FilterId);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_uninstall_filter_t *elementToReturn = output_uninstall_filter_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_FilterId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns the xlink validity time of the account of given address.
//
output_xlink_valid_t*
QANAPI_qanXlinkValid(apiClient_t *apiClient, char *Address)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/xlinkValid/{Address}/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/xlinkValid/{Address}/");


    // Path Params
    long sizeOfPathParams_Address = strlen(Address)+3 + strlen("{ Address }");
    if(Address == NULL) {
        goto end;
    }
    char* localVarToReplace_Address = malloc(sizeOfPathParams_Address);
    sprintf(localVarToReplace_Address, "{%s}", "Address");

    localVarPath = strReplace(localVarPath, localVarToReplace_Address, Address);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    cJSON *QANAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    output_xlink_valid_t *elementToReturn = output_xlink_valid_parseFromJSON(QANAPIlocalVarJSON);
    cJSON_Delete(QANAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_Address);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

