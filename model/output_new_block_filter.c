#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_new_block_filter.h"



output_new_block_filter_t *output_new_block_filter_create(
    char *schema,
    char *filter_id
    ) {
    output_new_block_filter_t *output_new_block_filter_local_var = malloc(sizeof(output_new_block_filter_t));
    if (!output_new_block_filter_local_var) {
        return NULL;
    }
    output_new_block_filter_local_var->schema = schema;
    output_new_block_filter_local_var->filter_id = filter_id;

    return output_new_block_filter_local_var;
}


void output_new_block_filter_free(output_new_block_filter_t *output_new_block_filter) {
    if(NULL == output_new_block_filter){
        return ;
    }
    listEntry_t *listEntry;
    if (output_new_block_filter->schema) {
        free(output_new_block_filter->schema);
        output_new_block_filter->schema = NULL;
    }
    if (output_new_block_filter->filter_id) {
        free(output_new_block_filter->filter_id);
        output_new_block_filter->filter_id = NULL;
    }
    free(output_new_block_filter);
}

cJSON *output_new_block_filter_convertToJSON(output_new_block_filter_t *output_new_block_filter) {
    cJSON *item = cJSON_CreateObject();

    // output_new_block_filter->schema
    if(output_new_block_filter->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_new_block_filter->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_new_block_filter->filter_id
    if (!output_new_block_filter->filter_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "FilterId", output_new_block_filter->filter_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_new_block_filter_t *output_new_block_filter_parseFromJSON(cJSON *output_new_block_filterJSON){

    output_new_block_filter_t *output_new_block_filter_local_var = NULL;

    // output_new_block_filter->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_new_block_filterJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_new_block_filter->filter_id
    cJSON *filter_id = cJSON_GetObjectItemCaseSensitive(output_new_block_filterJSON, "FilterId");
    if (!filter_id) {
        goto end;
    }

    
    if(!cJSON_IsString(filter_id))
    {
    goto end; //String
    }


    output_new_block_filter_local_var = output_new_block_filter_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(filter_id->valuestring)
        );

    return output_new_block_filter_local_var;
end:
    return NULL;

}
