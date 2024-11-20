#ifndef response_block_TEST
#define response_block_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define response_block_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/response_block.h"
response_block_t* instantiate_response_block(int include_optional);

#include "test_response_withdrawals.c"


response_block_t* instantiate_response_block(int include_optional) {
  response_block_t* response_block = NULL;
  if (include_optional) {
    response_block = response_block_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      list_createList(),
       // false, not to have infinite recursion
      instantiate_response_withdrawals(0),
      "0"
    );
  } else {
    response_block = response_block_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      list_createList(),
      NULL,
      "0"
    );
  }

  return response_block;
}


#ifdef response_block_MAIN

void test_response_block(int include_optional) {
    response_block_t* response_block_1 = instantiate_response_block(include_optional);

	cJSON* jsonresponse_block_1 = response_block_convertToJSON(response_block_1);
	printf("response_block :\n%s\n", cJSON_Print(jsonresponse_block_1));
	response_block_t* response_block_2 = response_block_parseFromJSON(jsonresponse_block_1);
	cJSON* jsonresponse_block_2 = response_block_convertToJSON(response_block_2);
	printf("repeating response_block:\n%s\n", cJSON_Print(jsonresponse_block_2));
}

int main() {
  test_response_block(1);
  test_response_block(0);

  printf("Hello world \n");
  return 0;
}

#endif // response_block_MAIN
#endif // response_block_TEST
