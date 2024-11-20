#ifndef output_estimate_gas_TEST
#define output_estimate_gas_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_estimate_gas_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_estimate_gas.h"
output_estimate_gas_t* instantiate_output_estimate_gas(int include_optional);



output_estimate_gas_t* instantiate_output_estimate_gas(int include_optional) {
  output_estimate_gas_t* output_estimate_gas = NULL;
  if (include_optional) {
    output_estimate_gas = output_estimate_gas_create(
      "0",
      "0"
    );
  } else {
    output_estimate_gas = output_estimate_gas_create(
      "0",
      "0"
    );
  }

  return output_estimate_gas;
}


#ifdef output_estimate_gas_MAIN

void test_output_estimate_gas(int include_optional) {
    output_estimate_gas_t* output_estimate_gas_1 = instantiate_output_estimate_gas(include_optional);

	cJSON* jsonoutput_estimate_gas_1 = output_estimate_gas_convertToJSON(output_estimate_gas_1);
	printf("output_estimate_gas :\n%s\n", cJSON_Print(jsonoutput_estimate_gas_1));
	output_estimate_gas_t* output_estimate_gas_2 = output_estimate_gas_parseFromJSON(jsonoutput_estimate_gas_1);
	cJSON* jsonoutput_estimate_gas_2 = output_estimate_gas_convertToJSON(output_estimate_gas_2);
	printf("repeating output_estimate_gas:\n%s\n", cJSON_Print(jsonoutput_estimate_gas_2));
}

int main() {
  test_output_estimate_gas(1);
  test_output_estimate_gas(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_estimate_gas_MAIN
#endif // output_estimate_gas_TEST
