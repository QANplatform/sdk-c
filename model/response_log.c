#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "response_log.h"



response_log_t *response_log_create(
    char *address,
    char *block_hash,
    char *block_number,
    char *data,
    char *log_index,
    int removed,
    list_t *topics,
    char *transaction_hash,
    char *transaction_index
    ) {
    response_log_t *response_log_local_var = malloc(sizeof(response_log_t));
    if (!response_log_local_var) {
        return NULL;
    }
    response_log_local_var->address = address;
    response_log_local_var->block_hash = block_hash;
    response_log_local_var->block_number = block_number;
    response_log_local_var->data = data;
    response_log_local_var->log_index = log_index;
    response_log_local_var->removed = removed;
    response_log_local_var->topics = topics;
    response_log_local_var->transaction_hash = transaction_hash;
    response_log_local_var->transaction_index = transaction_index;

    return response_log_local_var;
}


void response_log_free(response_log_t *response_log) {
    if(NULL == response_log){
        return ;
    }
    listEntry_t *listEntry;
    if (response_log->address) {
        free(response_log->address);
        response_log->address = NULL;
    }
    if (response_log->block_hash) {
        free(response_log->block_hash);
        response_log->block_hash = NULL;
    }
    if (response_log->block_number) {
        free(response_log->block_number);
        response_log->block_number = NULL;
    }
    if (response_log->data) {
        free(response_log->data);
        response_log->data = NULL;
    }
    if (response_log->log_index) {
        free(response_log->log_index);
        response_log->log_index = NULL;
    }
    if (response_log->topics) {
        list_ForEach(listEntry, response_log->topics) {
            free(listEntry->data);
        }
        list_freeList(response_log->topics);
        response_log->topics = NULL;
    }
    if (response_log->transaction_hash) {
        free(response_log->transaction_hash);
        response_log->transaction_hash = NULL;
    }
    if (response_log->transaction_index) {
        free(response_log->transaction_index);
        response_log->transaction_index = NULL;
    }
    free(response_log);
}

cJSON *response_log_convertToJSON(response_log_t *response_log) {
    cJSON *item = cJSON_CreateObject();

    // response_log->address
    if (!response_log->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Address", response_log->address) == NULL) {
    goto fail; //String
    }


    // response_log->block_hash
    if (!response_log->block_hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "BlockHash", response_log->block_hash) == NULL) {
    goto fail; //String
    }


    // response_log->block_number
    if (!response_log->block_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "BlockNumber", response_log->block_number) == NULL) {
    goto fail; //String
    }


    // response_log->data
    if (!response_log->data) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Data", response_log->data) == NULL) {
    goto fail; //String
    }


    // response_log->log_index
    if (!response_log->log_index) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "LogIndex", response_log->log_index) == NULL) {
    goto fail; //String
    }


    // response_log->removed
    if (!response_log->removed) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "Removed", response_log->removed) == NULL) {
    goto fail; //Bool
    }


    // response_log->topics
    if (!response_log->topics) {
        goto fail;
    }
    cJSON *topics = cJSON_AddArrayToObject(item, "Topics");
    if(topics == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *topicsListEntry;
    list_ForEach(topicsListEntry, response_log->topics) {
    if(cJSON_AddStringToObject(topics, "", (char*)topicsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // response_log->transaction_hash
    if (!response_log->transaction_hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "TransactionHash", response_log->transaction_hash) == NULL) {
    goto fail; //String
    }


    // response_log->transaction_index
    if (!response_log->transaction_index) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "TransactionIndex", response_log->transaction_index) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

response_log_t *response_log_parseFromJSON(cJSON *response_logJSON){

    response_log_t *response_log_local_var = NULL;

    // define the local list for response_log->topics
    list_t *topicsList = NULL;

    // response_log->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(response_logJSON, "Address");
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // response_log->block_hash
    cJSON *block_hash = cJSON_GetObjectItemCaseSensitive(response_logJSON, "BlockHash");
    if (!block_hash) {
        goto end;
    }

    
    if(!cJSON_IsString(block_hash))
    {
    goto end; //String
    }

    // response_log->block_number
    cJSON *block_number = cJSON_GetObjectItemCaseSensitive(response_logJSON, "BlockNumber");
    if (!block_number) {
        goto end;
    }

    
    if(!cJSON_IsString(block_number))
    {
    goto end; //String
    }

    // response_log->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(response_logJSON, "Data");
    if (!data) {
        goto end;
    }

    
    if(!cJSON_IsString(data))
    {
    goto end; //String
    }

    // response_log->log_index
    cJSON *log_index = cJSON_GetObjectItemCaseSensitive(response_logJSON, "LogIndex");
    if (!log_index) {
        goto end;
    }

    
    if(!cJSON_IsString(log_index))
    {
    goto end; //String
    }

    // response_log->removed
    cJSON *removed = cJSON_GetObjectItemCaseSensitive(response_logJSON, "Removed");
    if (!removed) {
        goto end;
    }

    
    if(!cJSON_IsBool(removed))
    {
    goto end; //Bool
    }

    // response_log->topics
    cJSON *topics = cJSON_GetObjectItemCaseSensitive(response_logJSON, "Topics");
    if (!topics) {
        goto end;
    }

    
    cJSON *topics_local = NULL;
    if(!cJSON_IsArray(topics)) {
        goto end;//primitive container
    }
    topicsList = list_createList();

    cJSON_ArrayForEach(topics_local, topics)
    {
        if(!cJSON_IsString(topics_local))
        {
            goto end;
        }
        list_addElement(topicsList , strdup(topics_local->valuestring));
    }

    // response_log->transaction_hash
    cJSON *transaction_hash = cJSON_GetObjectItemCaseSensitive(response_logJSON, "TransactionHash");
    if (!transaction_hash) {
        goto end;
    }

    
    if(!cJSON_IsString(transaction_hash))
    {
    goto end; //String
    }

    // response_log->transaction_index
    cJSON *transaction_index = cJSON_GetObjectItemCaseSensitive(response_logJSON, "TransactionIndex");
    if (!transaction_index) {
        goto end;
    }

    
    if(!cJSON_IsString(transaction_index))
    {
    goto end; //String
    }


    response_log_local_var = response_log_create (
        strdup(address->valuestring),
        strdup(block_hash->valuestring),
        strdup(block_number->valuestring),
        strdup(data->valuestring),
        strdup(log_index->valuestring),
        removed->valueint,
        topicsList,
        strdup(transaction_hash->valuestring),
        strdup(transaction_index->valuestring)
        );

    return response_log_local_var;
end:
    if (topicsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, topicsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(topicsList);
        topicsList = NULL;
    }
    return NULL;

}
