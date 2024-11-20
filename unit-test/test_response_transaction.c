#ifndef response_transaction_TEST
#define response_transaction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define response_transaction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/response_transaction.h"
response_transaction_t* instantiate_response_transaction(int include_optional);



response_transaction_t* instantiate_response_transaction(int include_optional) {
  response_transaction_t* response_transaction = NULL;
  if (include_optional) {
    response_transaction = response_transaction_create(
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
      "0"
    );
  } else {
    response_transaction = response_transaction_create(
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
      "0"
    );
  }

  return response_transaction;
}


#ifdef response_transaction_MAIN

void test_response_transaction(int include_optional) {
    response_transaction_t* response_transaction_1 = instantiate_response_transaction(include_optional);

	cJSON* jsonresponse_transaction_1 = response_transaction_convertToJSON(response_transaction_1);
	printf("response_transaction :\n%s\n", cJSON_Print(jsonresponse_transaction_1));
	response_transaction_t* response_transaction_2 = response_transaction_parseFromJSON(jsonresponse_transaction_1);
	cJSON* jsonresponse_transaction_2 = response_transaction_convertToJSON(response_transaction_2);
	printf("repeating response_transaction:\n%s\n", cJSON_Print(jsonresponse_transaction_2));
}

int main() {
  test_response_transaction(1);
  test_response_transaction(0);

  printf("Hello world \n");
  return 0;
}

#endif // response_transaction_MAIN
#endif // response_transaction_TEST
