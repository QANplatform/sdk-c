#ifndef output_get_block_by_number_TEST
#define output_get_block_by_number_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_get_block_by_number_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_get_block_by_number.h"
output_get_block_by_number_t* instantiate_output_get_block_by_number(int include_optional);

#include "test_response_block.c"


output_get_block_by_number_t* instantiate_output_get_block_by_number(int include_optional) {
  output_get_block_by_number_t* output_get_block_by_number = NULL;
  if (include_optional) {
    output_get_block_by_number = output_get_block_by_number_create(
      "0",
       // false, not to have infinite recursion
      instantiate_response_block(0)
    );
  } else {
    output_get_block_by_number = output_get_block_by_number_create(
      "0",
      NULL
    );
  }

  return output_get_block_by_number;
}


#ifdef output_get_block_by_number_MAIN

void test_output_get_block_by_number(int include_optional) {
    output_get_block_by_number_t* output_get_block_by_number_1 = instantiate_output_get_block_by_number(include_optional);

	cJSON* jsonoutput_get_block_by_number_1 = output_get_block_by_number_convertToJSON(output_get_block_by_number_1);
	printf("output_get_block_by_number :\n%s\n", cJSON_Print(jsonoutput_get_block_by_number_1));
	output_get_block_by_number_t* output_get_block_by_number_2 = output_get_block_by_number_parseFromJSON(jsonoutput_get_block_by_number_1);
	cJSON* jsonoutput_get_block_by_number_2 = output_get_block_by_number_convertToJSON(output_get_block_by_number_2);
	printf("repeating output_get_block_by_number:\n%s\n", cJSON_Print(jsonoutput_get_block_by_number_2));
}

int main() {
  test_output_get_block_by_number(1);
  test_output_get_block_by_number(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_get_block_by_number_MAIN
#endif // output_get_block_by_number_TEST
