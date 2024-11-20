#ifndef input_get_storage_at_TEST
#define input_get_storage_at_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_get_storage_at_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_get_storage_at.h"
input_get_storage_at_t* instantiate_input_get_storage_at(int include_optional);



input_get_storage_at_t* instantiate_input_get_storage_at(int include_optional) {
  input_get_storage_at_t* input_get_storage_at = NULL;
  if (include_optional) {
    input_get_storage_at = input_get_storage_at_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    input_get_storage_at = input_get_storage_at_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return input_get_storage_at;
}


#ifdef input_get_storage_at_MAIN

void test_input_get_storage_at(int include_optional) {
    input_get_storage_at_t* input_get_storage_at_1 = instantiate_input_get_storage_at(include_optional);

	cJSON* jsoninput_get_storage_at_1 = input_get_storage_at_convertToJSON(input_get_storage_at_1);
	printf("input_get_storage_at :\n%s\n", cJSON_Print(jsoninput_get_storage_at_1));
	input_get_storage_at_t* input_get_storage_at_2 = input_get_storage_at_parseFromJSON(jsoninput_get_storage_at_1);
	cJSON* jsoninput_get_storage_at_2 = input_get_storage_at_convertToJSON(input_get_storage_at_2);
	printf("repeating input_get_storage_at:\n%s\n", cJSON_Print(jsoninput_get_storage_at_2));
}

int main() {
  test_input_get_storage_at(1);
  test_input_get_storage_at(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_get_storage_at_MAIN
#endif // input_get_storage_at_TEST
