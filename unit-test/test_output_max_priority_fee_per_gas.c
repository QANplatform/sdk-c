#ifndef output_max_priority_fee_per_gas_TEST
#define output_max_priority_fee_per_gas_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_max_priority_fee_per_gas_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_max_priority_fee_per_gas.h"
output_max_priority_fee_per_gas_t* instantiate_output_max_priority_fee_per_gas(int include_optional);



output_max_priority_fee_per_gas_t* instantiate_output_max_priority_fee_per_gas(int include_optional) {
  output_max_priority_fee_per_gas_t* output_max_priority_fee_per_gas = NULL;
  if (include_optional) {
    output_max_priority_fee_per_gas = output_max_priority_fee_per_gas_create(
      "0",
      "0"
    );
  } else {
    output_max_priority_fee_per_gas = output_max_priority_fee_per_gas_create(
      "0",
      "0"
    );
  }

  return output_max_priority_fee_per_gas;
}


#ifdef output_max_priority_fee_per_gas_MAIN

void test_output_max_priority_fee_per_gas(int include_optional) {
    output_max_priority_fee_per_gas_t* output_max_priority_fee_per_gas_1 = instantiate_output_max_priority_fee_per_gas(include_optional);

	cJSON* jsonoutput_max_priority_fee_per_gas_1 = output_max_priority_fee_per_gas_convertToJSON(output_max_priority_fee_per_gas_1);
	printf("output_max_priority_fee_per_gas :\n%s\n", cJSON_Print(jsonoutput_max_priority_fee_per_gas_1));
	output_max_priority_fee_per_gas_t* output_max_priority_fee_per_gas_2 = output_max_priority_fee_per_gas_parseFromJSON(jsonoutput_max_priority_fee_per_gas_1);
	cJSON* jsonoutput_max_priority_fee_per_gas_2 = output_max_priority_fee_per_gas_convertToJSON(output_max_priority_fee_per_gas_2);
	printf("repeating output_max_priority_fee_per_gas:\n%s\n", cJSON_Print(jsonoutput_max_priority_fee_per_gas_2));
}

int main() {
  test_output_max_priority_fee_per_gas(1);
  test_output_max_priority_fee_per_gas(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_max_priority_fee_per_gas_MAIN
#endif // output_max_priority_fee_per_gas_TEST
