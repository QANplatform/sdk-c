#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_fee_history.h"



input_fee_history_t *input_fee_history_create(
    char *schema,
    int block_count,
    char *newest_block,
    list_t *reward_percentiles
    ) {
    input_fee_history_t *input_fee_history_local_var = malloc(sizeof(input_fee_history_t));
    if (!input_fee_history_local_var) {
        return NULL;
    }
    input_fee_history_local_var->schema = schema;
    input_fee_history_local_var->block_count = block_count;
    input_fee_history_local_var->newest_block = newest_block;
    input_fee_history_local_var->reward_percentiles = reward_percentiles;

    return input_fee_history_local_var;
}


void input_fee_history_free(input_fee_history_t *input_fee_history) {
    if(NULL == input_fee_history){
        return ;
    }
    listEntry_t *listEntry;
    if (input_fee_history->schema) {
        free(input_fee_history->schema);
        input_fee_history->schema = NULL;
    }
    if (input_fee_history->newest_block) {
        free(input_fee_history->newest_block);
        input_fee_history->newest_block = NULL;
    }
    if (input_fee_history->reward_percentiles) {
        list_ForEach(listEntry, input_fee_history->reward_percentiles) {
            free(listEntry->data);
        }
        list_freeList(input_fee_history->reward_percentiles);
        input_fee_history->reward_percentiles = NULL;
    }
    free(input_fee_history);
}

cJSON *input_fee_history_convertToJSON(input_fee_history_t *input_fee_history) {
    cJSON *item = cJSON_CreateObject();

    // input_fee_history->schema
    if(input_fee_history->schema) {
    if(cJSON_AddStringToObject(item, "$schema", input_fee_history->schema) == NULL) {
    goto fail; //String
    }
    }


    // input_fee_history->block_count
    if (!input_fee_history->block_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "BlockCount", input_fee_history->block_count) == NULL) {
    goto fail; //Numeric
    }


    // input_fee_history->newest_block
    if (!input_fee_history->newest_block) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "NewestBlock", input_fee_history->newest_block) == NULL) {
    goto fail; //String
    }


    // input_fee_history->reward_percentiles
    if (!input_fee_history->reward_percentiles) {
        goto fail;
    }
    cJSON *reward_percentiles = cJSON_AddArrayToObject(item, "RewardPercentiles");
    if(reward_percentiles == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *reward_percentilesListEntry;
    list_ForEach(reward_percentilesListEntry, input_fee_history->reward_percentiles) {
    if(cJSON_AddNumberToObject(reward_percentiles, "", *(double *)reward_percentilesListEntry->data) == NULL)
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

input_fee_history_t *input_fee_history_parseFromJSON(cJSON *input_fee_historyJSON){

    input_fee_history_t *input_fee_history_local_var = NULL;

    // define the local list for input_fee_history->reward_percentiles
    list_t *reward_percentilesList = NULL;

    // input_fee_history->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(input_fee_historyJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // input_fee_history->block_count
    cJSON *block_count = cJSON_GetObjectItemCaseSensitive(input_fee_historyJSON, "BlockCount");
    if (!block_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(block_count))
    {
    goto end; //Numeric
    }

    // input_fee_history->newest_block
    cJSON *newest_block = cJSON_GetObjectItemCaseSensitive(input_fee_historyJSON, "NewestBlock");
    if (!newest_block) {
        goto end;
    }

    
    if(!cJSON_IsString(newest_block))
    {
    goto end; //String
    }

    // input_fee_history->reward_percentiles
    cJSON *reward_percentiles = cJSON_GetObjectItemCaseSensitive(input_fee_historyJSON, "RewardPercentiles");
    if (!reward_percentiles) {
        goto end;
    }

    
    cJSON *reward_percentiles_local = NULL;
    if(!cJSON_IsArray(reward_percentiles)) {
        goto end;//primitive container
    }
    reward_percentilesList = list_createList();

    cJSON_ArrayForEach(reward_percentiles_local, reward_percentiles)
    {
        if(!cJSON_IsNumber(reward_percentiles_local))
        {
            goto end;
        }
        double *reward_percentiles_local_value = (double *)calloc(1, sizeof(double));
        if(!reward_percentiles_local_value)
        {
            goto end;
        }
        *reward_percentiles_local_value = reward_percentiles_local->valuedouble;
        list_addElement(reward_percentilesList , reward_percentiles_local_value);
    }


    input_fee_history_local_var = input_fee_history_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        block_count->valuedouble,
        strdup(newest_block->valuestring),
        reward_percentilesList
        );

    return input_fee_history_local_var;
end:
    if (reward_percentilesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, reward_percentilesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(reward_percentilesList);
        reward_percentilesList = NULL;
    }
    return NULL;

}
