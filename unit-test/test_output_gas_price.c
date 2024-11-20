#ifndef output_gas_price_TEST
#define output_gas_price_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_gas_price_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_gas_price.h"
output_gas_price_t* instantiate_output_gas_price(int include_optional);



output_gas_price_t* instantiate_output_gas_price(int include_optional) {
  output_gas_price_t* output_gas_price = NULL;
  if (include_optional) {
    output_gas_price = output_gas_price_create(
      "0",
      "0"
    );
  } else {
    output_gas_price = output_gas_price_create(
      "0",
      "0"
    );
  }

  return output_gas_price;
}


#ifdef output_gas_price_MAIN

void test_output_gas_price(int include_optional) {
    output_gas_price_t* output_gas_price_1 = instantiate_output_gas_price(include_optional);

	cJSON* jsonoutput_gas_price_1 = output_gas_price_convertToJSON(output_gas_price_1);
	printf("output_gas_price :\n%s\n", cJSON_Print(jsonoutput_gas_price_1));
	output_gas_price_t* output_gas_price_2 = output_gas_price_parseFromJSON(jsonoutput_gas_price_1);
	cJSON* jsonoutput_gas_price_2 = output_gas_price_convertToJSON(output_gas_price_2);
	printf("repeating output_gas_price:\n%s\n", cJSON_Print(jsonoutput_gas_price_2));
}

int main() {
  test_output_gas_price(1);
  test_output_gas_price(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_gas_price_MAIN
#endif // output_gas_price_TEST
