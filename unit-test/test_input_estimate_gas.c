#ifndef input_estimate_gas_TEST
#define input_estimate_gas_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_estimate_gas_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_estimate_gas.h"
input_estimate_gas_t* instantiate_input_estimate_gas(int include_optional);

#include "test_estimate_gas_object.c"
#include "test_params_transaction.c"


input_estimate_gas_t* instantiate_input_estimate_gas(int include_optional) {
  input_estimate_gas_t* input_estimate_gas = NULL;
  if (include_optional) {
    input_estimate_gas = input_estimate_gas_create(
      "0",
       // false, not to have infinite recursion
      instantiate_estimate_gas_object(0),
       // false, not to have infinite recursion
      instantiate_params_transaction(0)
    );
  } else {
    input_estimate_gas = input_estimate_gas_create(
      "0",
      NULL,
      NULL
    );
  }

  return input_estimate_gas;
}


#ifdef input_estimate_gas_MAIN

void test_input_estimate_gas(int include_optional) {
    input_estimate_gas_t* input_estimate_gas_1 = instantiate_input_estimate_gas(include_optional);

	cJSON* jsoninput_estimate_gas_1 = input_estimate_gas_convertToJSON(input_estimate_gas_1);
	printf("input_estimate_gas :\n%s\n", cJSON_Print(jsoninput_estimate_gas_1));
	input_estimate_gas_t* input_estimate_gas_2 = input_estimate_gas_parseFromJSON(jsoninput_estimate_gas_1);
	cJSON* jsoninput_estimate_gas_2 = input_estimate_gas_convertToJSON(input_estimate_gas_2);
	printf("repeating input_estimate_gas:\n%s\n", cJSON_Print(jsoninput_estimate_gas_2));
}

int main() {
  test_input_estimate_gas(1);
  test_input_estimate_gas(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_estimate_gas_MAIN
#endif // input_estimate_gas_TEST
