#ifndef output_get_code_TEST
#define output_get_code_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_get_code_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_get_code.h"
output_get_code_t* instantiate_output_get_code(int include_optional);



output_get_code_t* instantiate_output_get_code(int include_optional) {
  output_get_code_t* output_get_code = NULL;
  if (include_optional) {
    output_get_code = output_get_code_create(
      "0",
      "0"
    );
  } else {
    output_get_code = output_get_code_create(
      "0",
      "0"
    );
  }

  return output_get_code;
}


#ifdef output_get_code_MAIN

void test_output_get_code(int include_optional) {
    output_get_code_t* output_get_code_1 = instantiate_output_get_code(include_optional);

	cJSON* jsonoutput_get_code_1 = output_get_code_convertToJSON(output_get_code_1);
	printf("output_get_code :\n%s\n", cJSON_Print(jsonoutput_get_code_1));
	output_get_code_t* output_get_code_2 = output_get_code_parseFromJSON(jsonoutput_get_code_1);
	cJSON* jsonoutput_get_code_2 = output_get_code_convertToJSON(output_get_code_2);
	printf("repeating output_get_code:\n%s\n", cJSON_Print(jsonoutput_get_code_2));
}

int main() {
  test_output_get_code(1);
  test_output_get_code(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_get_code_MAIN
#endif // output_get_code_TEST
