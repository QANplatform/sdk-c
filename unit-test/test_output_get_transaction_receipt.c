#ifndef output_get_transaction_receipt_TEST
#define output_get_transaction_receipt_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_get_transaction_receipt_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_get_transaction_receipt.h"
output_get_transaction_receipt_t* instantiate_output_get_transaction_receipt(int include_optional);

#include "test_response_transaction_receipt.c"


output_get_transaction_receipt_t* instantiate_output_get_transaction_receipt(int include_optional) {
  output_get_transaction_receipt_t* output_get_transaction_receipt = NULL;
  if (include_optional) {
    output_get_transaction_receipt = output_get_transaction_receipt_create(
      "0",
       // false, not to have infinite recursion
      instantiate_response_transaction_receipt(0)
    );
  } else {
    output_get_transaction_receipt = output_get_transaction_receipt_create(
      "0",
      NULL
    );
  }

  return output_get_transaction_receipt;
}


#ifdef output_get_transaction_receipt_MAIN

void test_output_get_transaction_receipt(int include_optional) {
    output_get_transaction_receipt_t* output_get_transaction_receipt_1 = instantiate_output_get_transaction_receipt(include_optional);

	cJSON* jsonoutput_get_transaction_receipt_1 = output_get_transaction_receipt_convertToJSON(output_get_transaction_receipt_1);
	printf("output_get_transaction_receipt :\n%s\n", cJSON_Print(jsonoutput_get_transaction_receipt_1));
	output_get_transaction_receipt_t* output_get_transaction_receipt_2 = output_get_transaction_receipt_parseFromJSON(jsonoutput_get_transaction_receipt_1);
	cJSON* jsonoutput_get_transaction_receipt_2 = output_get_transaction_receipt_convertToJSON(output_get_transaction_receipt_2);
	printf("repeating output_get_transaction_receipt:\n%s\n", cJSON_Print(jsonoutput_get_transaction_receipt_2));
}

int main() {
  test_output_get_transaction_receipt(1);
  test_output_get_transaction_receipt(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_get_transaction_receipt_MAIN
#endif // output_get_transaction_receipt_TEST
