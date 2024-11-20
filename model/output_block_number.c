#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_block_number.h"



output_block_number_t *output_block_number_create(
    char *schema,
    char *block_number
    ) {
    output_block_number_t *output_block_number_local_var = malloc(sizeof(output_block_number_t));
    if (!output_block_number_local_var) {
        return NULL;
    }
    output_block_number_local_var->schema = schema;
    output_block_number_local_var->block_number = block_number;

    return output_block_number_local_var;
}


void output_block_number_free(output_block_number_t *output_block_number) {
    if(NULL == output_block_number){
        return ;
    }
    listEntry_t *listEntry;
    if (output_block_number->schema) {
        free(output_block_number->schema);
        output_block_number->schema = NULL;
    }
    if (output_block_number->block_number) {
        free(output_block_number->block_number);
        output_block_number->block_number = NULL;
    }
    free(output_block_number);
}

cJSON *output_block_number_convertToJSON(output_block_number_t *output_block_number) {
    cJSON *item = cJSON_CreateObject();

    // output_block_number->schema
    if(output_block_number->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_block_number->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_block_number->block_number
    if (!output_block_number->block_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "BlockNumber", output_block_number->block_number) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_block_number_t *output_block_number_parseFromJSON(cJSON *output_block_numberJSON){

    output_block_number_t *output_block_number_local_var = NULL;

    // output_block_number->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_block_numberJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_block_number->block_number
    cJSON *block_number = cJSON_GetObjectItemCaseSensitive(output_block_numberJSON, "BlockNumber");
    if (!block_number) {
        goto end;
    }

    
    if(!cJSON_IsString(block_number))
    {
    goto end; //String
    }


    output_block_number_local_var = output_block_number_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(block_number->valuestring)
        );

    return output_block_number_local_var;
end:
    return NULL;

}
