#ifndef output_uninstall_filter_TEST
#define output_uninstall_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_uninstall_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_uninstall_filter.h"
output_uninstall_filter_t* instantiate_output_uninstall_filter(int include_optional);



output_uninstall_filter_t* instantiate_output_uninstall_filter(int include_optional) {
  output_uninstall_filter_t* output_uninstall_filter = NULL;
  if (include_optional) {
    output_uninstall_filter = output_uninstall_filter_create(
      "0",
      1
    );
  } else {
    output_uninstall_filter = output_uninstall_filter_create(
      "0",
      1
    );
  }

  return output_uninstall_filter;
}


#ifdef output_uninstall_filter_MAIN

void test_output_uninstall_filter(int include_optional) {
    output_uninstall_filter_t* output_uninstall_filter_1 = instantiate_output_uninstall_filter(include_optional);

	cJSON* jsonoutput_uninstall_filter_1 = output_uninstall_filter_convertToJSON(output_uninstall_filter_1);
	printf("output_uninstall_filter :\n%s\n", cJSON_Print(jsonoutput_uninstall_filter_1));
	output_uninstall_filter_t* output_uninstall_filter_2 = output_uninstall_filter_parseFromJSON(jsonoutput_uninstall_filter_1);
	cJSON* jsonoutput_uninstall_filter_2 = output_uninstall_filter_convertToJSON(output_uninstall_filter_2);
	printf("repeating output_uninstall_filter:\n%s\n", cJSON_Print(jsonoutput_uninstall_filter_2));
}

int main() {
  test_output_uninstall_filter(1);
  test_output_uninstall_filter(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_uninstall_filter_MAIN
#endif // output_uninstall_filter_TEST
