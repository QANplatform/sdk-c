#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_get_logs.h"



input_get_logs_t *input_get_logs_create(
    char *schema,
    char *address,
    char *block_hash,
    char *from_block,
    char *to_block,
    list_t *topics
    ) {
    input_get_logs_t *input_get_logs_local_var = malloc(sizeof(input_get_logs_t));
    if (!input_get_logs_local_var) {
        return NULL;
    }
    input_get_logs_local_var->schema = schema;
    input_get_logs_local_var->address = address;
    input_get_logs_local_var->block_hash = block_hash;
    input_get_logs_local_var->from_block = from_block;
    input_get_logs_local_var->to_block = to_block;
    input_get_logs_local_var->topics = topics;

    return input_get_logs_local_var;
}


void input_get_logs_free(input_get_logs_t *input_get_logs) {
    if(NULL == input_get_logs){
        return ;
    }
    listEntry_t *listEntry;
    if (input_get_logs->schema) {
        free(input_get_logs->schema);
        input_get_logs->schema = NULL;
    }
    if (input_get_logs->address) {
        free(input_get_logs->address);
        input_get_logs->address = NULL;
    }
    if (input_get_logs->block_hash) {
        free(input_get_logs->block_hash);
        input_get_logs->block_hash = NULL;
    }
    if (input_get_logs->from_block) {
        free(input_get_logs->from_block);
        input_get_logs->from_block = NULL;
    }
    if (input_get_logs->to_block) {
        free(input_get_logs->to_block);
        input_get_logs->to_block = NULL;
    }
    if (input_get_logs->topics) {
        list_ForEach(listEntry, input_get_logs->topics) {
            free(listEntry->data);
        }
        list_freeList(input_get_logs->topics);
        input_get_logs->topics = NULL;
    }
    free(input_get_logs);
}

cJSON *input_get_logs_convertToJSON(input_get_logs_t *input_get_logs) {
    cJSON *item = cJSON_CreateObject();

    // input_get_logs->schema
    if(input_get_logs->schema) {
    if(cJSON_AddStringToObject(item, "$schema", input_get_logs->schema) == NULL) {
    goto fail; //String
    }
    }


    // input_get_logs->address
    if(input_get_logs->address) {
    if(cJSON_AddStringToObject(item, "Address", input_get_logs->address) == NULL) {
    goto fail; //String
    }
    }


    // input_get_logs->block_hash
    if(input_get_logs->block_hash) {
    if(cJSON_AddStringToObject(item, "BlockHash", input_get_logs->block_hash) == NULL) {
    goto fail; //String
    }
    }


    // input_get_logs->from_block
    if(input_get_logs->from_block) {
    if(cJSON_AddStringToObject(item, "FromBlock", input_get_logs->from_block) == NULL) {
    goto fail; //String
    }
    }


    // input_get_logs->to_block
    if(input_get_logs->to_block) {
    if(cJSON_AddStringToObject(item, "ToBlock", input_get_logs->to_block) == NULL) {
    goto fail; //String
    }
    }


    // input_get_logs->topics
    if(input_get_logs->topics) {
    cJSON *topics = cJSON_AddArrayToObject(item, "Topics");
    if(topics == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *topicsListEntry;
    list_ForEach(topicsListEntry, input_get_logs->topics) {
    if(cJSON_AddStringToObject(topics, "", (char*)topicsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

input_get_logs_t *input_get_logs_parseFromJSON(cJSON *input_get_logsJSON){

    input_get_logs_t *input_get_logs_local_var = NULL;

    // define the local list for input_get_logs->topics
    list_t *topicsList = NULL;

    // input_get_logs->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(input_get_logsJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // input_get_logs->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(input_get_logsJSON, "Address");
    if (address) { 
    if(!cJSON_IsString(address) && !cJSON_IsNull(address))
    {
    goto end; //String
    }
    }

    // input_get_logs->block_hash
    cJSON *block_hash = cJSON_GetObjectItemCaseSensitive(input_get_logsJSON, "BlockHash");
    if (block_hash) { 
    if(!cJSON_IsString(block_hash) && !cJSON_IsNull(block_hash))
    {
    goto end; //String
    }
    }

    // input_get_logs->from_block
    cJSON *from_block = cJSON_GetObjectItemCaseSensitive(input_get_logsJSON, "FromBlock");
    if (from_block) { 
    if(!cJSON_IsString(from_block) && !cJSON_IsNull(from_block))
    {
    goto end; //String
    }
    }

    // input_get_logs->to_block
    cJSON *to_block = cJSON_GetObjectItemCaseSensitive(input_get_logsJSON, "ToBlock");
    if (to_block) { 
    if(!cJSON_IsString(to_block) && !cJSON_IsNull(to_block))
    {
    goto end; //String
    }
    }

    // input_get_logs->topics
    cJSON *topics = cJSON_GetObjectItemCaseSensitive(input_get_logsJSON, "Topics");
    if (topics) { 
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
    }


    input_get_logs_local_var = input_get_logs_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        address && !cJSON_IsNull(address) ? strdup(address->valuestring) : NULL,
        block_hash && !cJSON_IsNull(block_hash) ? strdup(block_hash->valuestring) : NULL,
        from_block && !cJSON_IsNull(from_block) ? strdup(from_block->valuestring) : NULL,
        to_block && !cJSON_IsNull(to_block) ? strdup(to_block->valuestring) : NULL,
        topics ? topicsList : NULL
        );

    return input_get_logs_local_var;
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
