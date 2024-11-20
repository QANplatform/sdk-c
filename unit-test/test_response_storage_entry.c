#ifndef response_storage_entry_TEST
#define response_storage_entry_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define response_storage_entry_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/response_storage_entry.h"
response_storage_entry_t* instantiate_response_storage_entry(int include_optional);



response_storage_entry_t* instantiate_response_storage_entry(int include_optional) {
  response_storage_entry_t* response_storage_entry = NULL;
  if (include_optional) {
    response_storage_entry = response_storage_entry_create(
      "0",
      "0",
      "0"
    );
  } else {
    response_storage_entry = response_storage_entry_create(
      "0",
      "0",
      "0"
    );
  }

  return response_storage_entry;
}


#ifdef response_storage_entry_MAIN

void test_response_storage_entry(int include_optional) {
    response_storage_entry_t* response_storage_entry_1 = instantiate_response_storage_entry(include_optional);

	cJSON* jsonresponse_storage_entry_1 = response_storage_entry_convertToJSON(response_storage_entry_1);
	printf("response_storage_entry :\n%s\n", cJSON_Print(jsonresponse_storage_entry_1));
	response_storage_entry_t* response_storage_entry_2 = response_storage_entry_parseFromJSON(jsonresponse_storage_entry_1);
	cJSON* jsonresponse_storage_entry_2 = response_storage_entry_convertToJSON(response_storage_entry_2);
	printf("repeating response_storage_entry:\n%s\n", cJSON_Print(jsonresponse_storage_entry_2));
}

int main() {
  test_response_storage_entry(1);
  test_response_storage_entry(0);

  printf("Hello world \n");
  return 0;
}

#endif // response_storage_entry_MAIN
#endif // response_storage_entry_TEST
