#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_fee_history.h"



output_fee_history_t *output_fee_history_create(
    char *schema,
    list_t *base_fee_per_gas,
    list_t *gas_used_ratio,
    char *oldest_block,
    list_t *reward
    ) {
    output_fee_history_t *output_fee_history_local_var = malloc(sizeof(output_fee_history_t));
    if (!output_fee_history_local_var) {
        return NULL;
    }
    output_fee_history_local_var->schema = schema;
    output_fee_history_local_var->base_fee_per_gas = base_fee_per_gas;
    output_fee_history_local_var->gas_used_ratio = gas_used_ratio;
    output_fee_history_local_var->oldest_block = oldest_block;
    output_fee_history_local_var->reward = reward;

    return output_fee_history_local_var;
}


void output_fee_history_free(output_fee_history_t *output_fee_history) {
    if(NULL == output_fee_history){
        return ;
    }
    listEntry_t *listEntry;
    if (output_fee_history->schema) {
        free(output_fee_history->schema);
        output_fee_history->schema = NULL;
    }
    if (output_fee_history->base_fee_per_gas) {
        list_ForEach(listEntry, output_fee_history->base_fee_per_gas) {
            free(listEntry->data);
        }
        list_freeList(output_fee_history->base_fee_per_gas);
        output_fee_history->base_fee_per_gas = NULL;
    }
    if (output_fee_history->gas_used_ratio) {
        list_ForEach(listEntry, output_fee_history->gas_used_ratio) {
            free(listEntry->data);
        }
        list_freeList(output_fee_history->gas_used_ratio);
        output_fee_history->gas_used_ratio = NULL;
    }
    if (output_fee_history->oldest_block) {
        free(output_fee_history->oldest_block);
        output_fee_history->oldest_block = NULL;
    }
    if (output_fee_history->reward) {
        list_ForEach(listEntry, output_fee_history->reward) {
            free(listEntry->data);
        }
        list_freeList(output_fee_history->reward);
        output_fee_history->reward = NULL;
    }
    free(output_fee_history);
}

cJSON *output_fee_history_convertToJSON(output_fee_history_t *output_fee_history) {
    cJSON *item = cJSON_CreateObject();

    // output_fee_history->schema
    if(output_fee_history->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_fee_history->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_fee_history->base_fee_per_gas
    if (!output_fee_history->base_fee_per_gas) {
        goto fail;
    }
    cJSON *base_fee_per_gas = cJSON_AddArrayToObject(item, "BaseFeePerGas");
    if(base_fee_per_gas == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *base_fee_per_gasListEntry;
    list_ForEach(base_fee_per_gasListEntry, output_fee_history->base_fee_per_gas) {
    if(cJSON_AddStringToObject(base_fee_per_gas, "", (char*)base_fee_per_gasListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // output_fee_history->gas_used_ratio
    if (!output_fee_history->gas_used_ratio) {
        goto fail;
    }
    cJSON *gas_used_ratio = cJSON_AddArrayToObject(item, "GasUsedRatio");
    if(gas_used_ratio == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *gas_used_ratioListEntry;
    list_ForEach(gas_used_ratioListEntry, output_fee_history->gas_used_ratio) {
    if(cJSON_AddNumberToObject(gas_used_ratio, "", *(double *)gas_used_ratioListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // output_fee_history->oldest_block
    if (!output_fee_history->oldest_block) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "OldestBlock", output_fee_history->oldest_block) == NULL) {
    goto fail; //String
    }


    // output_fee_history->reward
    if (!output_fee_history->reward) {
        goto fail;
    }
    cJSON *reward = cJSON_AddArrayToObject(item, "Reward");
    if(reward == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *rewardListEntry;
    list_ForEach(rewardListEntry, output_fee_history->reward) {
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_fee_history_t *output_fee_history_parseFromJSON(cJSON *output_fee_historyJSON){

    output_fee_history_t *output_fee_history_local_var = NULL;

    // define the local list for output_fee_history->base_fee_per_gas
    list_t *base_fee_per_gasList = NULL;

    // define the local list for output_fee_history->gas_used_ratio
    list_t *gas_used_ratioList = NULL;

    // define the local list for output_fee_history->reward
    list_t *rewardList = NULL;

    // output_fee_history->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_fee_historyJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_fee_history->base_fee_per_gas
    cJSON *base_fee_per_gas = cJSON_GetObjectItemCaseSensitive(output_fee_historyJSON, "BaseFeePerGas");
    if (!base_fee_per_gas) {
        goto end;
    }

    
    cJSON *base_fee_per_gas_local = NULL;
    if(!cJSON_IsArray(base_fee_per_gas)) {
        goto end;//primitive container
    }
    base_fee_per_gasList = list_createList();

    cJSON_ArrayForEach(base_fee_per_gas_local, base_fee_per_gas)
    {
        if(!cJSON_IsString(base_fee_per_gas_local))
        {
            goto end;
        }
        list_addElement(base_fee_per_gasList , strdup(base_fee_per_gas_local->valuestring));
    }

    // output_fee_history->gas_used_ratio
    cJSON *gas_used_ratio = cJSON_GetObjectItemCaseSensitive(output_fee_historyJSON, "GasUsedRatio");
    if (!gas_used_ratio) {
        goto end;
    }

    
    cJSON *gas_used_ratio_local = NULL;
    if(!cJSON_IsArray(gas_used_ratio)) {
        goto end;//primitive container
    }
    gas_used_ratioList = list_createList();

    cJSON_ArrayForEach(gas_used_ratio_local, gas_used_ratio)
    {
        if(!cJSON_IsNumber(gas_used_ratio_local))
        {
            goto end;
        }
        double *gas_used_ratio_local_value = (double *)calloc(1, sizeof(double));
        if(!gas_used_ratio_local_value)
        {
            goto end;
        }
        *gas_used_ratio_local_value = gas_used_ratio_local->valuedouble;
        list_addElement(gas_used_ratioList , gas_used_ratio_local_value);
    }

    // output_fee_history->oldest_block
    cJSON *oldest_block = cJSON_GetObjectItemCaseSensitive(output_fee_historyJSON, "OldestBlock");
    if (!oldest_block) {
        goto end;
    }

    
    if(!cJSON_IsString(oldest_block))
    {
    goto end; //String
    }

    // output_fee_history->reward
    cJSON *reward = cJSON_GetObjectItemCaseSensitive(output_fee_historyJSON, "Reward");
    if (!reward) {
        goto end;
    }

    
    cJSON *reward_local = NULL;
    if(!cJSON_IsArray(reward)) {
        goto end;//primitive container
    }
    rewardList = list_createList();

    cJSON_ArrayForEach(reward_local, reward)
    {
    }


    output_fee_history_local_var = output_fee_history_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        base_fee_per_gasList,
        gas_used_ratioList,
        strdup(oldest_block->valuestring),
        rewardList
        );

    return output_fee_history_local_var;
end:
    if (base_fee_per_gasList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, base_fee_per_gasList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(base_fee_per_gasList);
        base_fee_per_gasList = NULL;
    }
    if (gas_used_ratioList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, gas_used_ratioList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(gas_used_ratioList);
        gas_used_ratioList = NULL;
    }
    if (rewardList) {
        list_freeList(rewardList);
        rewardList = NULL;
    }
    return NULL;

}
