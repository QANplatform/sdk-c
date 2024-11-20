#ifndef response_withdrawals_TEST
#define response_withdrawals_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define response_withdrawals_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/response_withdrawals.h"
response_withdrawals_t* instantiate_response_withdrawals(int include_optional);



response_withdrawals_t* instantiate_response_withdrawals(int include_optional) {
  response_withdrawals_t* response_withdrawals = NULL;
  if (include_optional) {
    response_withdrawals = response_withdrawals_create(
      "0",
      "0",
      56,
      56
    );
  } else {
    response_withdrawals = response_withdrawals_create(
      "0",
      "0",
      56,
      56
    );
  }

  return response_withdrawals;
}


#ifdef response_withdrawals_MAIN

void test_response_withdrawals(int include_optional) {
    response_withdrawals_t* response_withdrawals_1 = instantiate_response_withdrawals(include_optional);

	cJSON* jsonresponse_withdrawals_1 = response_withdrawals_convertToJSON(response_withdrawals_1);
	printf("response_withdrawals :\n%s\n", cJSON_Print(jsonresponse_withdrawals_1));
	response_withdrawals_t* response_withdrawals_2 = response_withdrawals_parseFromJSON(jsonresponse_withdrawals_1);
	cJSON* jsonresponse_withdrawals_2 = response_withdrawals_convertToJSON(response_withdrawals_2);
	printf("repeating response_withdrawals:\n%s\n", cJSON_Print(jsonresponse_withdrawals_2));
}

int main() {
  test_response_withdrawals(1);
  test_response_withdrawals(0);

  printf("Hello world \n");
  return 0;
}

#endif // response_withdrawals_MAIN
#endif // response_withdrawals_TEST
