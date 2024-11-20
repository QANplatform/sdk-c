#ifndef output_get_storage_at_TEST
#define output_get_storage_at_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_get_storage_at_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_get_storage_at.h"
output_get_storage_at_t* instantiate_output_get_storage_at(int include_optional);



output_get_storage_at_t* instantiate_output_get_storage_at(int include_optional) {
  output_get_storage_at_t* output_get_storage_at = NULL;
  if (include_optional) {
    output_get_storage_at = output_get_storage_at_create(
      "0",
      "0"
    );
  } else {
    output_get_storage_at = output_get_storage_at_create(
      "0",
      "0"
    );
  }

  return output_get_storage_at;
}


#ifdef output_get_storage_at_MAIN

void test_output_get_storage_at(int include_optional) {
    output_get_storage_at_t* output_get_storage_at_1 = instantiate_output_get_storage_at(include_optional);

	cJSON* jsonoutput_get_storage_at_1 = output_get_storage_at_convertToJSON(output_get_storage_at_1);
	printf("output_get_storage_at :\n%s\n", cJSON_Print(jsonoutput_get_storage_at_1));
	output_get_storage_at_t* output_get_storage_at_2 = output_get_storage_at_parseFromJSON(jsonoutput_get_storage_at_1);
	cJSON* jsonoutput_get_storage_at_2 = output_get_storage_at_convertToJSON(output_get_storage_at_2);
	printf("repeating output_get_storage_at:\n%s\n", cJSON_Print(jsonoutput_get_storage_at_2));
}

int main() {
  test_output_get_storage_at(1);
  test_output_get_storage_at(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_get_storage_at_MAIN
#endif // output_get_storage_at_TEST
