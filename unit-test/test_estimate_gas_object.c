#ifndef estimate_gas_object_TEST
#define estimate_gas_object_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define estimate_gas_object_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/estimate_gas_object.h"
estimate_gas_object_t* instantiate_estimate_gas_object(int include_optional);



estimate_gas_object_t* instantiate_estimate_gas_object(int include_optional) {
  estimate_gas_object_t* estimate_gas_object = NULL;
  if (include_optional) {
    estimate_gas_object = estimate_gas_object_create(
      "0",
      56,
      "0",
      "0",
      "0"
    );
  } else {
    estimate_gas_object = estimate_gas_object_create(
      "0",
      56,
      "0",
      "0",
      "0"
    );
  }

  return estimate_gas_object;
}


#ifdef estimate_gas_object_MAIN

void test_estimate_gas_object(int include_optional) {
    estimate_gas_object_t* estimate_gas_object_1 = instantiate_estimate_gas_object(include_optional);

	cJSON* jsonestimate_gas_object_1 = estimate_gas_object_convertToJSON(estimate_gas_object_1);
	printf("estimate_gas_object :\n%s\n", cJSON_Print(jsonestimate_gas_object_1));
	estimate_gas_object_t* estimate_gas_object_2 = estimate_gas_object_parseFromJSON(jsonestimate_gas_object_1);
	cJSON* jsonestimate_gas_object_2 = estimate_gas_object_convertToJSON(estimate_gas_object_2);
	printf("repeating estimate_gas_object:\n%s\n", cJSON_Print(jsonestimate_gas_object_2));
}

int main() {
  test_estimate_gas_object(1);
  test_estimate_gas_object(0);

  printf("Hello world \n");
  return 0;
}

#endif // estimate_gas_object_MAIN
#endif // estimate_gas_object_TEST
