#ifndef input_get_logs_TEST
#define input_get_logs_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_get_logs_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_get_logs.h"
input_get_logs_t* instantiate_input_get_logs(int include_optional);



input_get_logs_t* instantiate_input_get_logs(int include_optional) {
  input_get_logs_t* input_get_logs = NULL;
  if (include_optional) {
    input_get_logs = input_get_logs_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList()
    );
  } else {
    input_get_logs = input_get_logs_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList()
    );
  }

  return input_get_logs;
}


#ifdef input_get_logs_MAIN

void test_input_get_logs(int include_optional) {
    input_get_logs_t* input_get_logs_1 = instantiate_input_get_logs(include_optional);

	cJSON* jsoninput_get_logs_1 = input_get_logs_convertToJSON(input_get_logs_1);
	printf("input_get_logs :\n%s\n", cJSON_Print(jsoninput_get_logs_1));
	input_get_logs_t* input_get_logs_2 = input_get_logs_parseFromJSON(jsoninput_get_logs_1);
	cJSON* jsoninput_get_logs_2 = input_get_logs_convertToJSON(input_get_logs_2);
	printf("repeating input_get_logs:\n%s\n", cJSON_Print(jsoninput_get_logs_2));
}

int main() {
  test_input_get_logs(1);
  test_input_get_logs(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_get_logs_MAIN
#endif // input_get_logs_TEST
