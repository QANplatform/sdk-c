#ifndef response_log_TEST
#define response_log_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define response_log_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/response_log.h"
response_log_t* instantiate_response_log(int include_optional);



response_log_t* instantiate_response_log(int include_optional) {
  response_log_t* response_log = NULL;
  if (include_optional) {
    response_log = response_log_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      list_createList(),
      "0",
      "0"
    );
  } else {
    response_log = response_log_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      list_createList(),
      "0",
      "0"
    );
  }

  return response_log;
}


#ifdef response_log_MAIN

void test_response_log(int include_optional) {
    response_log_t* response_log_1 = instantiate_response_log(include_optional);

	cJSON* jsonresponse_log_1 = response_log_convertToJSON(response_log_1);
	printf("response_log :\n%s\n", cJSON_Print(jsonresponse_log_1));
	response_log_t* response_log_2 = response_log_parseFromJSON(jsonresponse_log_1);
	cJSON* jsonresponse_log_2 = response_log_convertToJSON(response_log_2);
	printf("repeating response_log:\n%s\n", cJSON_Print(jsonresponse_log_2));
}

int main() {
  test_response_log(1);
  test_response_log(0);

  printf("Hello world \n");
  return 0;
}

#endif // response_log_MAIN
#endif // response_log_TEST
