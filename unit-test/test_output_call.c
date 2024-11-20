#ifndef output_call_TEST
#define output_call_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_call_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_call.h"
output_call_t* instantiate_output_call(int include_optional);



output_call_t* instantiate_output_call(int include_optional) {
  output_call_t* output_call = NULL;
  if (include_optional) {
    output_call = output_call_create(
      "0",
      "0"
    );
  } else {
    output_call = output_call_create(
      "0",
      "0"
    );
  }

  return output_call;
}


#ifdef output_call_MAIN

void test_output_call(int include_optional) {
    output_call_t* output_call_1 = instantiate_output_call(include_optional);

	cJSON* jsonoutput_call_1 = output_call_convertToJSON(output_call_1);
	printf("output_call :\n%s\n", cJSON_Print(jsonoutput_call_1));
	output_call_t* output_call_2 = output_call_parseFromJSON(jsonoutput_call_1);
	cJSON* jsonoutput_call_2 = output_call_convertToJSON(output_call_2);
	printf("repeating output_call:\n%s\n", cJSON_Print(jsonoutput_call_2));
}

int main() {
  test_output_call(1);
  test_output_call(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_call_MAIN
#endif // output_call_TEST
