#ifndef response_transaction_receipt_TEST
#define response_transaction_receipt_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define response_transaction_receipt_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/response_transaction_receipt.h"
response_transaction_receipt_t* instantiate_response_transaction_receipt(int include_optional);



response_transaction_receipt_t* instantiate_response_transaction_receipt(int include_optional) {
  response_transaction_receipt_t* response_transaction_receipt = NULL;
  if (include_optional) {
    response_transaction_receipt = response_transaction_receipt_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    response_transaction_receipt = response_transaction_receipt_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return response_transaction_receipt;
}


#ifdef response_transaction_receipt_MAIN

void test_response_transaction_receipt(int include_optional) {
    response_transaction_receipt_t* response_transaction_receipt_1 = instantiate_response_transaction_receipt(include_optional);

	cJSON* jsonresponse_transaction_receipt_1 = response_transaction_receipt_convertToJSON(response_transaction_receipt_1);
	printf("response_transaction_receipt :\n%s\n", cJSON_Print(jsonresponse_transaction_receipt_1));
	response_transaction_receipt_t* response_transaction_receipt_2 = response_transaction_receipt_parseFromJSON(jsonresponse_transaction_receipt_1);
	cJSON* jsonresponse_transaction_receipt_2 = response_transaction_receipt_convertToJSON(response_transaction_receipt_2);
	printf("repeating response_transaction_receipt:\n%s\n", cJSON_Print(jsonresponse_transaction_receipt_2));
}

int main() {
  test_response_transaction_receipt(1);
  test_response_transaction_receipt(0);

  printf("Hello world \n");
  return 0;
}

#endif // response_transaction_receipt_MAIN
#endif // response_transaction_receipt_TEST
