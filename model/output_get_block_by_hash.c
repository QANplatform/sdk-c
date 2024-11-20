#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_get_block_by_hash.h"



output_get_block_by_hash_t *output_get_block_by_hash_create(
    char *schema,
    response_block_t *block
    ) {
    output_get_block_by_hash_t *output_get_block_by_hash_local_var = malloc(sizeof(output_get_block_by_hash_t));
    if (!output_get_block_by_hash_local_var) {
        return NULL;
    }
    output_get_block_by_hash_local_var->schema = schema;
    output_get_block_by_hash_local_var->block = block;

    return output_get_block_by_hash_local_var;
}


void output_get_block_by_hash_free(output_get_block_by_hash_t *output_get_block_by_hash) {
    if(NULL == output_get_block_by_hash){
        return ;
    }
    listEntry_t *listEntry;
    if (output_get_block_by_hash->schema) {
        free(output_get_block_by_hash->schema);
        output_get_block_by_hash->schema = NULL;
    }
    if (output_get_block_by_hash->block) {
        response_block_free(output_get_block_by_hash->block);
        output_get_block_by_hash->block = NULL;
    }
    free(output_get_block_by_hash);
}

cJSON *output_get_block_by_hash_convertToJSON(output_get_block_by_hash_t *output_get_block_by_hash) {
    cJSON *item = cJSON_CreateObject();

    // output_get_block_by_hash->schema
    if(output_get_block_by_hash->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_get_block_by_hash->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_get_block_by_hash->block
    if (!output_get_block_by_hash->block) {
        goto fail;
    }
    cJSON *block_local_JSON = response_block_convertToJSON(output_get_block_by_hash->block);
    if(block_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "Block", block_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_get_block_by_hash_t *output_get_block_by_hash_parseFromJSON(cJSON *output_get_block_by_hashJSON){

    output_get_block_by_hash_t *output_get_block_by_hash_local_var = NULL;

    // define the local variable for output_get_block_by_hash->block
    response_block_t *block_local_nonprim = NULL;

    // output_get_block_by_hash->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_get_block_by_hashJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_get_block_by_hash->block
    cJSON *block = cJSON_GetObjectItemCaseSensitive(output_get_block_by_hashJSON, "Block");
    if (!block) {
        goto end;
    }

    
    block_local_nonprim = response_block_parseFromJSON(block); //nonprimitive


    output_get_block_by_hash_local_var = output_get_block_by_hash_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        block_local_nonprim
        );

    return output_get_block_by_hash_local_var;
end:
    if (block_local_nonprim) {
        response_block_free(block_local_nonprim);
        block_local_nonprim = NULL;
    }
    return NULL;

}
