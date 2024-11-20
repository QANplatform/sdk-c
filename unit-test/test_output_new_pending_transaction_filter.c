#ifndef output_new_pending_transaction_filter_TEST
#define output_new_pending_transaction_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_new_pending_transaction_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_new_pending_transaction_filter.h"
output_new_pending_transaction_filter_t* instantiate_output_new_pending_transaction_filter(int include_optional);



output_new_pending_transaction_filter_t* instantiate_output_new_pending_transaction_filter(int include_optional) {
  output_new_pending_transaction_filter_t* output_new_pending_transaction_filter = NULL;
  if (include_optional) {
    output_new_pending_transaction_filter = output_new_pending_transaction_filter_create(
      "0",
      "0"
    );
  } else {
    output_new_pending_transaction_filter = output_new_pending_transaction_filter_create(
      "0",
      "0"
    );
  }

  return output_new_pending_transaction_filter;
}


#ifdef output_new_pending_transaction_filter_MAIN

void test_output_new_pending_transaction_filter(int include_optional) {
    output_new_pending_transaction_filter_t* output_new_pending_transaction_filter_1 = instantiate_output_new_pending_transaction_filter(include_optional);

	cJSON* jsonoutput_new_pending_transaction_filter_1 = output_new_pending_transaction_filter_convertToJSON(output_new_pending_transaction_filter_1);
	printf("output_new_pending_transaction_filter :\n%s\n", cJSON_Print(jsonoutput_new_pending_transaction_filter_1));
	output_new_pending_transaction_filter_t* output_new_pending_transaction_filter_2 = output_new_pending_transaction_filter_parseFromJSON(jsonoutput_new_pending_transaction_filter_1);
	cJSON* jsonoutput_new_pending_transaction_filter_2 = output_new_pending_transaction_filter_convertToJSON(output_new_pending_transaction_filter_2);
	printf("repeating output_new_pending_transaction_filter:\n%s\n", cJSON_Print(jsonoutput_new_pending_transaction_filter_2));
}

int main() {
  test_output_new_pending_transaction_filter(1);
  test_output_new_pending_transaction_filter(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_new_pending_transaction_filter_MAIN
#endif // output_new_pending_transaction_filter_TEST
