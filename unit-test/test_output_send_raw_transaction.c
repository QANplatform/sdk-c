#ifndef output_send_raw_transaction_TEST
#define output_send_raw_transaction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_send_raw_transaction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_send_raw_transaction.h"
output_send_raw_transaction_t* instantiate_output_send_raw_transaction(int include_optional);



output_send_raw_transaction_t* instantiate_output_send_raw_transaction(int include_optional) {
  output_send_raw_transaction_t* output_send_raw_transaction = NULL;
  if (include_optional) {
    output_send_raw_transaction = output_send_raw_transaction_create(
      "0",
      "0"
    );
  } else {
    output_send_raw_transaction = output_send_raw_transaction_create(
      "0",
      "0"
    );
  }

  return output_send_raw_transaction;
}


#ifdef output_send_raw_transaction_MAIN

void test_output_send_raw_transaction(int include_optional) {
    output_send_raw_transaction_t* output_send_raw_transaction_1 = instantiate_output_send_raw_transaction(include_optional);

	cJSON* jsonoutput_send_raw_transaction_1 = output_send_raw_transaction_convertToJSON(output_send_raw_transaction_1);
	printf("output_send_raw_transaction :\n%s\n", cJSON_Print(jsonoutput_send_raw_transaction_1));
	output_send_raw_transaction_t* output_send_raw_transaction_2 = output_send_raw_transaction_parseFromJSON(jsonoutput_send_raw_transaction_1);
	cJSON* jsonoutput_send_raw_transaction_2 = output_send_raw_transaction_convertToJSON(output_send_raw_transaction_2);
	printf("repeating output_send_raw_transaction:\n%s\n", cJSON_Print(jsonoutput_send_raw_transaction_2));
}

int main() {
  test_output_send_raw_transaction(1);
  test_output_send_raw_transaction(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_send_raw_transaction_MAIN
#endif // output_send_raw_transaction_TEST
