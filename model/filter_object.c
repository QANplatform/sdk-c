#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "filter_object.h"



filter_object_t *filter_object_create(
    char *address,
    char *from_block,
    char *to_block,
    list_t *topics
    ) {
    filter_object_t *filter_object_local_var = malloc(sizeof(filter_object_t));
    if (!filter_object_local_var) {
        return NULL;
    }
    filter_object_local_var->address = address;
    filter_object_local_var->from_block = from_block;
    filter_object_local_var->to_block = to_block;
    filter_object_local_var->topics = topics;

    return filter_object_local_var;
}


void filter_object_free(filter_object_t *filter_object) {
    if(NULL == filter_object){
        return ;
    }
    listEntry_t *listEntry;
    if (filter_object->address) {
        free(filter_object->address);
        filter_object->address = NULL;
    }
    if (filter_object->from_block) {
        free(filter_object->from_block);
        filter_object->from_block = NULL;
    }
    if (filter_object->to_block) {
        free(filter_object->to_block);
        filter_object->to_block = NULL;
    }
    if (filter_object->topics) {
        list_ForEach(listEntry, filter_object->topics) {
            free(listEntry->data);
        }
        list_freeList(filter_object->topics);
        filter_object->topics = NULL;
    }
    free(filter_object);
}

cJSON *filter_object_convertToJSON(filter_object_t *filter_object) {
    cJSON *item = cJSON_CreateObject();

    // filter_object->address
    if (!filter_object->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Address", filter_object->address) == NULL) {
    goto fail; //String
    }


    // filter_object->from_block
    if (!filter_object->from_block) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "FromBlock", filter_object->from_block) == NULL) {
    goto fail; //String
    }


    // filter_object->to_block
    if (!filter_object->to_block) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ToBlock", filter_object->to_block) == NULL) {
    goto fail; //String
    }


    // filter_object->topics
    if (!filter_object->topics) {
        goto fail;
    }
    cJSON *topics = cJSON_AddArrayToObject(item, "Topics");
    if(topics == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *topicsListEntry;
    list_ForEach(topicsListEntry, filter_object->topics) {
    if(cJSON_AddStringToObject(topics, "", (char*)topicsListEntry->data) == NULL)
    {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

filter_object_t *filter_object_parseFromJSON(cJSON *filter_objectJSON){

    filter_object_t *filter_object_local_var = NULL;

    // define the local list for filter_object->topics
    list_t *topicsList = NULL;

    // filter_object->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(filter_objectJSON, "Address");
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // filter_object->from_block
    cJSON *from_block = cJSON_GetObjectItemCaseSensitive(filter_objectJSON, "FromBlock");
    if (!from_block) {
        goto end;
    }

    
    if(!cJSON_IsString(from_block))
    {
    goto end; //String
    }

    // filter_object->to_block
    cJSON *to_block = cJSON_GetObjectItemCaseSensitive(filter_objectJSON, "ToBlock");
    if (!to_block) {
        goto end;
    }

    
    if(!cJSON_IsString(to_block))
    {
    goto end; //String
    }

    // filter_object->topics
    cJSON *topics = cJSON_GetObjectItemCaseSensitive(filter_objectJSON, "Topics");
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


    filter_object_local_var = filter_object_create (
        strdup(address->valuestring),
        strdup(from_block->valuestring),
        strdup(to_block->valuestring),
        topicsList
        );

    return filter_object_local_var;
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
