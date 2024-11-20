#ifndef output_block_number_TEST
#define output_block_number_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_block_number_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_block_number.h"
output_block_number_t* instantiate_output_block_number(int include_optional);



output_block_number_t* instantiate_output_block_number(int include_optional) {
  output_block_number_t* output_block_number = NULL;
  if (include_optional) {
    output_block_number = output_block_number_create(
      "0",
      "0"
    );
  } else {
    output_block_number = output_block_number_create(
      "0",
      "0"
    );
  }

  return output_block_number;
}


#ifdef output_block_number_MAIN

void test_output_block_number(int include_optional) {
    output_block_number_t* output_block_number_1 = instantiate_output_block_number(include_optional);

	cJSON* jsonoutput_block_number_1 = output_block_number_convertToJSON(output_block_number_1);
	printf("output_block_number :\n%s\n", cJSON_Print(jsonoutput_block_number_1));
	output_block_number_t* output_block_number_2 = output_block_number_parseFromJSON(jsonoutput_block_number_1);
	cJSON* jsonoutput_block_number_2 = output_block_number_convertToJSON(output_block_number_2);
	printf("repeating output_block_number:\n%s\n", cJSON_Print(jsonoutput_block_number_2));
}

int main() {
  test_output_block_number(1);
  test_output_block_number(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_block_number_MAIN
#endif // output_block_number_TEST
