#ifndef error_model_TEST
#define error_model_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define error_model_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/error_model.h"
error_model_t* instantiate_error_model(int include_optional);



error_model_t* instantiate_error_model(int include_optional) {
  error_model_t* error_model = NULL;
  if (include_optional) {
    error_model = error_model_create(
      "0",
      "0",
      list_createList(),
      "0",
      56,
      "0",
      "about:blank"
    );
  } else {
    error_model = error_model_create(
      "0",
      "0",
      list_createList(),
      "0",
      56,
      "0",
      "about:blank"
    );
  }

  return error_model;
}


#ifdef error_model_MAIN

void test_error_model(int include_optional) {
    error_model_t* error_model_1 = instantiate_error_model(include_optional);

	cJSON* jsonerror_model_1 = error_model_convertToJSON(error_model_1);
	printf("error_model :\n%s\n", cJSON_Print(jsonerror_model_1));
	error_model_t* error_model_2 = error_model_parseFromJSON(jsonerror_model_1);
	cJSON* jsonerror_model_2 = error_model_convertToJSON(error_model_2);
	printf("repeating error_model:\n%s\n", cJSON_Print(jsonerror_model_2));
}

int main() {
  test_error_model(1);
  test_error_model(0);

  printf("Hello world \n");
  return 0;
}

#endif // error_model_MAIN
#endif // error_model_TEST
