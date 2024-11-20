#ifndef input_send_raw_transaction_TEST
#define input_send_raw_transaction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_send_raw_transaction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_send_raw_transaction.h"
input_send_raw_transaction_t* instantiate_input_send_raw_transaction(int include_optional);



input_send_raw_transaction_t* instantiate_input_send_raw_transaction(int include_optional) {
  input_send_raw_transaction_t* input_send_raw_transaction = NULL;
  if (include_optional) {
    input_send_raw_transaction = input_send_raw_transaction_create(
      "0",
      "0"
    );
  } else {
    input_send_raw_transaction = input_send_raw_transaction_create(
      "0",
      "0"
    );
  }

  return input_send_raw_transaction;
}


#ifdef input_send_raw_transaction_MAIN

void test_input_send_raw_transaction(int include_optional) {
    input_send_raw_transaction_t* input_send_raw_transaction_1 = instantiate_input_send_raw_transaction(include_optional);

	cJSON* jsoninput_send_raw_transaction_1 = input_send_raw_transaction_convertToJSON(input_send_raw_transaction_1);
	printf("input_send_raw_transaction :\n%s\n", cJSON_Print(jsoninput_send_raw_transaction_1));
	input_send_raw_transaction_t* input_send_raw_transaction_2 = input_send_raw_transaction_parseFromJSON(jsoninput_send_raw_transaction_1);
	cJSON* jsoninput_send_raw_transaction_2 = input_send_raw_transaction_convertToJSON(input_send_raw_transaction_2);
	printf("repeating input_send_raw_transaction:\n%s\n", cJSON_Print(jsoninput_send_raw_transaction_2));
}

int main() {
  test_input_send_raw_transaction(1);
  test_input_send_raw_transaction(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_send_raw_transaction_MAIN
#endif // input_send_raw_transaction_TEST
