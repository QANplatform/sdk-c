#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_call.h"



output_call_t *output_call_create(
    char *schema,
    char *data
    ) {
    output_call_t *output_call_local_var = malloc(sizeof(output_call_t));
    if (!output_call_local_var) {
        return NULL;
    }
    output_call_local_var->schema = schema;
    output_call_local_var->data = data;

    return output_call_local_var;
}


void output_call_free(output_call_t *output_call) {
    if(NULL == output_call){
        return ;
    }
    listEntry_t *listEntry;
    if (output_call->schema) {
        free(output_call->schema);
        output_call->schema = NULL;
    }
    if (output_call->data) {
        free(output_call->data);
        output_call->data = NULL;
    }
    free(output_call);
}

cJSON *output_call_convertToJSON(output_call_t *output_call) {
    cJSON *item = cJSON_CreateObject();

    // output_call->schema
    if(output_call->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_call->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_call->data
    if (!output_call->data) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Data", output_call->data) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_call_t *output_call_parseFromJSON(cJSON *output_callJSON){

    output_call_t *output_call_local_var = NULL;

    // output_call->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_callJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_call->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(output_callJSON, "Data");
    if (!data) {
        goto end;
    }

    
    if(!cJSON_IsString(data))
    {
    goto end; //String
    }


    output_call_local_var = output_call_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(data->valuestring)
        );

    return output_call_local_var;
end:
    return NULL;

}
