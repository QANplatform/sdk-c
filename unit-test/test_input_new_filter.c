#ifndef input_new_filter_TEST
#define input_new_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_new_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_new_filter.h"
input_new_filter_t* instantiate_input_new_filter(int include_optional);

#include "test_filter_object.c"


input_new_filter_t* instantiate_input_new_filter(int include_optional) {
  input_new_filter_t* input_new_filter = NULL;
  if (include_optional) {
    input_new_filter = input_new_filter_create(
      "0",
       // false, not to have infinite recursion
      instantiate_filter_object(0)
    );
  } else {
    input_new_filter = input_new_filter_create(
      "0",
      NULL
    );
  }

  return input_new_filter;
}


#ifdef input_new_filter_MAIN

void test_input_new_filter(int include_optional) {
    input_new_filter_t* input_new_filter_1 = instantiate_input_new_filter(include_optional);

	cJSON* jsoninput_new_filter_1 = input_new_filter_convertToJSON(input_new_filter_1);
	printf("input_new_filter :\n%s\n", cJSON_Print(jsoninput_new_filter_1));
	input_new_filter_t* input_new_filter_2 = input_new_filter_parseFromJSON(jsoninput_new_filter_1);
	cJSON* jsoninput_new_filter_2 = input_new_filter_convertToJSON(input_new_filter_2);
	printf("repeating input_new_filter:\n%s\n", cJSON_Print(jsoninput_new_filter_2));
}

int main() {
  test_input_new_filter(1);
  test_input_new_filter(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_new_filter_MAIN
#endif // input_new_filter_TEST
