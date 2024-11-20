#ifndef output_xlink_valid_TEST
#define output_xlink_valid_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_xlink_valid_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_xlink_valid.h"
output_xlink_valid_t* instantiate_output_xlink_valid(int include_optional);



output_xlink_valid_t* instantiate_output_xlink_valid(int include_optional) {
  output_xlink_valid_t* output_xlink_valid = NULL;
  if (include_optional) {
    output_xlink_valid = output_xlink_valid_create(
      "0",
      "0"
    );
  } else {
    output_xlink_valid = output_xlink_valid_create(
      "0",
      "0"
    );
  }

  return output_xlink_valid;
}


#ifdef output_xlink_valid_MAIN

void test_output_xlink_valid(int include_optional) {
    output_xlink_valid_t* output_xlink_valid_1 = instantiate_output_xlink_valid(include_optional);

	cJSON* jsonoutput_xlink_valid_1 = output_xlink_valid_convertToJSON(output_xlink_valid_1);
	printf("output_xlink_valid :\n%s\n", cJSON_Print(jsonoutput_xlink_valid_1));
	output_xlink_valid_t* output_xlink_valid_2 = output_xlink_valid_parseFromJSON(jsonoutput_xlink_valid_1);
	cJSON* jsonoutput_xlink_valid_2 = output_xlink_valid_convertToJSON(output_xlink_valid_2);
	printf("repeating output_xlink_valid:\n%s\n", cJSON_Print(jsonoutput_xlink_valid_2));
}

int main() {
  test_output_xlink_valid(1);
  test_output_xlink_valid(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_xlink_valid_MAIN
#endif // output_xlink_valid_TEST
