#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_get_logs.h"



output_get_logs_t *output_get_logs_create(
    char *schema,
    list_t *logs
    ) {
    output_get_logs_t *output_get_logs_local_var = malloc(sizeof(output_get_logs_t));
    if (!output_get_logs_local_var) {
        return NULL;
    }
    output_get_logs_local_var->schema = schema;
    output_get_logs_local_var->logs = logs;

    return output_get_logs_local_var;
}


void output_get_logs_free(output_get_logs_t *output_get_logs) {
    if(NULL == output_get_logs){
        return ;
    }
    listEntry_t *listEntry;
    if (output_get_logs->schema) {
        free(output_get_logs->schema);
        output_get_logs->schema = NULL;
    }
    if (output_get_logs->logs) {
        list_ForEach(listEntry, output_get_logs->logs) {
            response_log_free(listEntry->data);
        }
        list_freeList(output_get_logs->logs);
        output_get_logs->logs = NULL;
    }
    free(output_get_logs);
}

cJSON *output_get_logs_convertToJSON(output_get_logs_t *output_get_logs) {
    cJSON *item = cJSON_CreateObject();

    // output_get_logs->schema
    if(output_get_logs->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_get_logs->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_get_logs->logs
    if (!output_get_logs->logs) {
        goto fail;
    }
    cJSON *logs = cJSON_AddArrayToObject(item, "Logs");
    if(logs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *logsListEntry;
    if (output_get_logs->logs) {
    list_ForEach(logsListEntry, output_get_logs->logs) {
    cJSON *itemLocal = response_log_convertToJSON(logsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(logs, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_get_logs_t *output_get_logs_parseFromJSON(cJSON *output_get_logsJSON){

    output_get_logs_t *output_get_logs_local_var = NULL;

    // define the local list for output_get_logs->logs
    list_t *logsList = NULL;

    // output_get_logs->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_get_logsJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_get_logs->logs
    cJSON *logs = cJSON_GetObjectItemCaseSensitive(output_get_logsJSON, "Logs");
    if (!logs) {
        goto end;
    }

    
    cJSON *logs_local_nonprimitive = NULL;
    if(!cJSON_IsArray(logs)){
        goto end; //nonprimitive container
    }

    logsList = list_createList();

    cJSON_ArrayForEach(logs_local_nonprimitive,logs )
    {
        if(!cJSON_IsObject(logs_local_nonprimitive)){
            goto end;
        }
        response_log_t *logsItem = response_log_parseFromJSON(logs_local_nonprimitive);

        list_addElement(logsList, logsItem);
    }


    output_get_logs_local_var = output_get_logs_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        logsList
        );

    return output_get_logs_local_var;
end:
    if (logsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, logsList) {
            response_log_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(logsList);
        logsList = NULL;
    }
    return NULL;

}
