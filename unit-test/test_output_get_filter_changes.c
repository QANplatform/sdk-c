#ifndef output_get_filter_changes_TEST
#define output_get_filter_changes_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_get_filter_changes_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_get_filter_changes.h"
output_get_filter_changes_t* instantiate_output_get_filter_changes(int include_optional);



output_get_filter_changes_t* instantiate_output_get_filter_changes(int include_optional) {
  output_get_filter_changes_t* output_get_filter_changes = NULL;
  if (include_optional) {
    output_get_filter_changes = output_get_filter_changes_create(
      "0",
      null
    );
  } else {
    output_get_filter_changes = output_get_filter_changes_create(
      "0",
      null
    );
  }

  return output_get_filter_changes;
}


#ifdef output_get_filter_changes_MAIN

void test_output_get_filter_changes(int include_optional) {
    output_get_filter_changes_t* output_get_filter_changes_1 = instantiate_output_get_filter_changes(include_optional);

	cJSON* jsonoutput_get_filter_changes_1 = output_get_filter_changes_convertToJSON(output_get_filter_changes_1);
	printf("output_get_filter_changes :\n%s\n", cJSON_Print(jsonoutput_get_filter_changes_1));
	output_get_filter_changes_t* output_get_filter_changes_2 = output_get_filter_changes_parseFromJSON(jsonoutput_get_filter_changes_1);
	cJSON* jsonoutput_get_filter_changes_2 = output_get_filter_changes_convertToJSON(output_get_filter_changes_2);
	printf("repeating output_get_filter_changes:\n%s\n", cJSON_Print(jsonoutput_get_filter_changes_2));
}

int main() {
  test_output_get_filter_changes(1);
  test_output_get_filter_changes(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_get_filter_changes_MAIN
#endif // output_get_filter_changes_TEST
