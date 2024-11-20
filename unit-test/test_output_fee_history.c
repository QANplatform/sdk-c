#ifndef output_fee_history_TEST
#define output_fee_history_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_fee_history_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_fee_history.h"
output_fee_history_t* instantiate_output_fee_history(int include_optional);



output_fee_history_t* instantiate_output_fee_history(int include_optional) {
  output_fee_history_t* output_fee_history = NULL;
  if (include_optional) {
    output_fee_history = output_fee_history_create(
      "0",
      list_createList(),
      list_createList(),
      "0",
      list_createList()
    );
  } else {
    output_fee_history = output_fee_history_create(
      "0",
      list_createList(),
      list_createList(),
      "0",
      list_createList()
    );
  }

  return output_fee_history;
}


#ifdef output_fee_history_MAIN

void test_output_fee_history(int include_optional) {
    output_fee_history_t* output_fee_history_1 = instantiate_output_fee_history(include_optional);

	cJSON* jsonoutput_fee_history_1 = output_fee_history_convertToJSON(output_fee_history_1);
	printf("output_fee_history :\n%s\n", cJSON_Print(jsonoutput_fee_history_1));
	output_fee_history_t* output_fee_history_2 = output_fee_history_parseFromJSON(jsonoutput_fee_history_1);
	cJSON* jsonoutput_fee_history_2 = output_fee_history_convertToJSON(output_fee_history_2);
	printf("repeating output_fee_history:\n%s\n", cJSON_Print(jsonoutput_fee_history_2));
}

int main() {
  test_output_fee_history(1);
  test_output_fee_history(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_fee_history_MAIN
#endif // output_fee_history_TEST
