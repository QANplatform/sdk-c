#ifndef input_fee_history_TEST
#define input_fee_history_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_fee_history_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_fee_history.h"
input_fee_history_t* instantiate_input_fee_history(int include_optional);



input_fee_history_t* instantiate_input_fee_history(int include_optional) {
  input_fee_history_t* input_fee_history = NULL;
  if (include_optional) {
    input_fee_history = input_fee_history_create(
      "0",
      56,
      "latest",
      list_createList()
    );
  } else {
    input_fee_history = input_fee_history_create(
      "0",
      56,
      "latest",
      list_createList()
    );
  }

  return input_fee_history;
}


#ifdef input_fee_history_MAIN

void test_input_fee_history(int include_optional) {
    input_fee_history_t* input_fee_history_1 = instantiate_input_fee_history(include_optional);

	cJSON* jsoninput_fee_history_1 = input_fee_history_convertToJSON(input_fee_history_1);
	printf("input_fee_history :\n%s\n", cJSON_Print(jsoninput_fee_history_1));
	input_fee_history_t* input_fee_history_2 = input_fee_history_parseFromJSON(jsoninput_fee_history_1);
	cJSON* jsoninput_fee_history_2 = input_fee_history_convertToJSON(input_fee_history_2);
	printf("repeating input_fee_history:\n%s\n", cJSON_Print(jsoninput_fee_history_2));
}

int main() {
  test_input_fee_history(1);
  test_input_fee_history(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_fee_history_MAIN
#endif // input_fee_history_TEST
