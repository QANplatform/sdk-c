#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sync_status.h"



sync_status_t *sync_status_create(
    char *current_block,
    char *highest_block,
    char *starting_block
    ) {
    sync_status_t *sync_status_local_var = malloc(sizeof(sync_status_t));
    if (!sync_status_local_var) {
        return NULL;
    }
    sync_status_local_var->current_block = current_block;
    sync_status_local_var->highest_block = highest_block;
    sync_status_local_var->starting_block = starting_block;

    return sync_status_local_var;
}


void sync_status_free(sync_status_t *sync_status) {
    if(NULL == sync_status){
        return ;
    }
    listEntry_t *listEntry;
    if (sync_status->current_block) {
        free(sync_status->current_block);
        sync_status->current_block = NULL;
    }
    if (sync_status->highest_block) {
        free(sync_status->highest_block);
        sync_status->highest_block = NULL;
    }
    if (sync_status->starting_block) {
        free(sync_status->starting_block);
        sync_status->starting_block = NULL;
    }
    free(sync_status);
}

cJSON *sync_status_convertToJSON(sync_status_t *sync_status) {
    cJSON *item = cJSON_CreateObject();

    // sync_status->current_block
    if (!sync_status->current_block) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "CurrentBlock", sync_status->current_block) == NULL) {
    goto fail; //String
    }


    // sync_status->highest_block
    if (!sync_status->highest_block) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "HighestBlock", sync_status->highest_block) == NULL) {
    goto fail; //String
    }


    // sync_status->starting_block
    if (!sync_status->starting_block) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "StartingBlock", sync_status->starting_block) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

sync_status_t *sync_status_parseFromJSON(cJSON *sync_statusJSON){

    sync_status_t *sync_status_local_var = NULL;

    // sync_status->current_block
    cJSON *current_block = cJSON_GetObjectItemCaseSensitive(sync_statusJSON, "CurrentBlock");
    if (!current_block) {
        goto end;
    }

    
    if(!cJSON_IsString(current_block))
    {
    goto end; //String
    }

    // sync_status->highest_block
    cJSON *highest_block = cJSON_GetObjectItemCaseSensitive(sync_statusJSON, "HighestBlock");
    if (!highest_block) {
        goto end;
    }

    
    if(!cJSON_IsString(highest_block))
    {
    goto end; //String
    }

    // sync_status->starting_block
    cJSON *starting_block = cJSON_GetObjectItemCaseSensitive(sync_statusJSON, "StartingBlock");
    if (!starting_block) {
        goto end;
    }

    
    if(!cJSON_IsString(starting_block))
    {
    goto end; //String
    }


    sync_status_local_var = sync_status_create (
        strdup(current_block->valuestring),
        strdup(highest_block->valuestring),
        strdup(starting_block->valuestring)
        );

    return sync_status_local_var;
end:
    return NULL;

}
