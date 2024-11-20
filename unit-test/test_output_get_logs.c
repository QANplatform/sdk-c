#ifndef output_get_logs_TEST
#define output_get_logs_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_get_logs_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_get_logs.h"
output_get_logs_t* instantiate_output_get_logs(int include_optional);



output_get_logs_t* instantiate_output_get_logs(int include_optional) {
  output_get_logs_t* output_get_logs = NULL;
  if (include_optional) {
    output_get_logs = output_get_logs_create(
      "0",
      list_createList()
    );
  } else {
    output_get_logs = output_get_logs_create(
      "0",
      list_createList()
    );
  }

  return output_get_logs;
}


#ifdef output_get_logs_MAIN

void test_output_get_logs(int include_optional) {
    output_get_logs_t* output_get_logs_1 = instantiate_output_get_logs(include_optional);

	cJSON* jsonoutput_get_logs_1 = output_get_logs_convertToJSON(output_get_logs_1);
	printf("output_get_logs :\n%s\n", cJSON_Print(jsonoutput_get_logs_1));
	output_get_logs_t* output_get_logs_2 = output_get_logs_parseFromJSON(jsonoutput_get_logs_1);
	cJSON* jsonoutput_get_logs_2 = output_get_logs_convertToJSON(output_get_logs_2);
	printf("repeating output_get_logs:\n%s\n", cJSON_Print(jsonoutput_get_logs_2));
}

int main() {
  test_output_get_logs(1);
  test_output_get_logs(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_get_logs_MAIN
#endif // output_get_logs_TEST
