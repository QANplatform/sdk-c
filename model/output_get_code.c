#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_get_code.h"



output_get_code_t *output_get_code_create(
    char *schema,
    char *bytecode
    ) {
    output_get_code_t *output_get_code_local_var = malloc(sizeof(output_get_code_t));
    if (!output_get_code_local_var) {
        return NULL;
    }
    output_get_code_local_var->schema = schema;
    output_get_code_local_var->bytecode = bytecode;

    return output_get_code_local_var;
}


void output_get_code_free(output_get_code_t *output_get_code) {
    if(NULL == output_get_code){
        return ;
    }
    listEntry_t *listEntry;
    if (output_get_code->schema) {
        free(output_get_code->schema);
        output_get_code->schema = NULL;
    }
    if (output_get_code->bytecode) {
        free(output_get_code->bytecode);
        output_get_code->bytecode = NULL;
    }
    free(output_get_code);
}

cJSON *output_get_code_convertToJSON(output_get_code_t *output_get_code) {
    cJSON *item = cJSON_CreateObject();

    // output_get_code->schema
    if(output_get_code->schema) {
    if(cJSON_AddStringToObject(item, "$schema", output_get_code->schema) == NULL) {
    goto fail; //String
    }
    }


    // output_get_code->bytecode
    if (!output_get_code->bytecode) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Bytecode", output_get_code->bytecode) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

output_get_code_t *output_get_code_parseFromJSON(cJSON *output_get_codeJSON){

    output_get_code_t *output_get_code_local_var = NULL;

    // output_get_code->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(output_get_codeJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // output_get_code->bytecode
    cJSON *bytecode = cJSON_GetObjectItemCaseSensitive(output_get_codeJSON, "Bytecode");
    if (!bytecode) {
        goto end;
    }

    
    if(!cJSON_IsString(bytecode))
    {
    goto end; //String
    }


    output_get_code_local_var = output_get_code_create (
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        strdup(bytecode->valuestring)
        );

    return output_get_code_local_var;
end:
    return NULL;

}
