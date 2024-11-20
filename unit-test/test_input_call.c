#ifndef input_call_TEST
#define input_call_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_call_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_call.h"
input_call_t* instantiate_input_call(int include_optional);

#include "test_params_transaction.c"


input_call_t* instantiate_input_call(int include_optional) {
  input_call_t* input_call = NULL;
  if (include_optional) {
    input_call = input_call_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_params_transaction(0)
    );
  } else {
    input_call = input_call_create(
      "0",
      "0",
      NULL
    );
  }

  return input_call;
}


#ifdef input_call_MAIN

void test_input_call(int include_optional) {
    input_call_t* input_call_1 = instantiate_input_call(include_optional);

	cJSON* jsoninput_call_1 = input_call_convertToJSON(input_call_1);
	printf("input_call :\n%s\n", cJSON_Print(jsoninput_call_1));
	input_call_t* input_call_2 = input_call_parseFromJSON(jsoninput_call_1);
	cJSON* jsoninput_call_2 = input_call_convertToJSON(input_call_2);
	printf("repeating input_call:\n%s\n", cJSON_Print(jsoninput_call_2));
}

int main() {
  test_input_call(1);
  test_input_call(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_call_MAIN
#endif // input_call_TEST
