#ifndef output_get_transaction_count_TEST
#define output_get_transaction_count_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_get_transaction_count_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_get_transaction_count.h"
output_get_transaction_count_t* instantiate_output_get_transaction_count(int include_optional);



output_get_transaction_count_t* instantiate_output_get_transaction_count(int include_optional) {
  output_get_transaction_count_t* output_get_transaction_count = NULL;
  if (include_optional) {
    output_get_transaction_count = output_get_transaction_count_create(
      "0",
      "0"
    );
  } else {
    output_get_transaction_count = output_get_transaction_count_create(
      "0",
      "0"
    );
  }

  return output_get_transaction_count;
}


#ifdef output_get_transaction_count_MAIN

void test_output_get_transaction_count(int include_optional) {
    output_get_transaction_count_t* output_get_transaction_count_1 = instantiate_output_get_transaction_count(include_optional);

	cJSON* jsonoutput_get_transaction_count_1 = output_get_transaction_count_convertToJSON(output_get_transaction_count_1);
	printf("output_get_transaction_count :\n%s\n", cJSON_Print(jsonoutput_get_transaction_count_1));
	output_get_transaction_count_t* output_get_transaction_count_2 = output_get_transaction_count_parseFromJSON(jsonoutput_get_transaction_count_1);
	cJSON* jsonoutput_get_transaction_count_2 = output_get_transaction_count_convertToJSON(output_get_transaction_count_2);
	printf("repeating output_get_transaction_count:\n%s\n", cJSON_Print(jsonoutput_get_transaction_count_2));
}

int main() {
  test_output_get_transaction_count(1);
  test_output_get_transaction_count(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_get_transaction_count_MAIN
#endif // output_get_transaction_count_TEST
