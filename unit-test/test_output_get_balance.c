#ifndef output_get_balance_TEST
#define output_get_balance_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_get_balance_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_get_balance.h"
output_get_balance_t* instantiate_output_get_balance(int include_optional);



output_get_balance_t* instantiate_output_get_balance(int include_optional) {
  output_get_balance_t* output_get_balance = NULL;
  if (include_optional) {
    output_get_balance = output_get_balance_create(
      "0",
      "0"
    );
  } else {
    output_get_balance = output_get_balance_create(
      "0",
      "0"
    );
  }

  return output_get_balance;
}


#ifdef output_get_balance_MAIN

void test_output_get_balance(int include_optional) {
    output_get_balance_t* output_get_balance_1 = instantiate_output_get_balance(include_optional);

	cJSON* jsonoutput_get_balance_1 = output_get_balance_convertToJSON(output_get_balance_1);
	printf("output_get_balance :\n%s\n", cJSON_Print(jsonoutput_get_balance_1));
	output_get_balance_t* output_get_balance_2 = output_get_balance_parseFromJSON(jsonoutput_get_balance_1);
	cJSON* jsonoutput_get_balance_2 = output_get_balance_convertToJSON(output_get_balance_2);
	printf("repeating output_get_balance:\n%s\n", cJSON_Print(jsonoutput_get_balance_2));
}

int main() {
  test_output_get_balance(1);
  test_output_get_balance(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_get_balance_MAIN
#endif // output_get_balance_TEST
