#ifndef filter_object_TEST
#define filter_object_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define filter_object_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/filter_object.h"
filter_object_t* instantiate_filter_object(int include_optional);



filter_object_t* instantiate_filter_object(int include_optional) {
  filter_object_t* filter_object = NULL;
  if (include_optional) {
    filter_object = filter_object_create(
      "0",
      "0",
      "0",
      list_createList()
    );
  } else {
    filter_object = filter_object_create(
      "0",
      "0",
      "0",
      list_createList()
    );
  }

  return filter_object;
}


#ifdef filter_object_MAIN

void test_filter_object(int include_optional) {
    filter_object_t* filter_object_1 = instantiate_filter_object(include_optional);

	cJSON* jsonfilter_object_1 = filter_object_convertToJSON(filter_object_1);
	printf("filter_object :\n%s\n", cJSON_Print(jsonfilter_object_1));
	filter_object_t* filter_object_2 = filter_object_parseFromJSON(jsonfilter_object_1);
	cJSON* jsonfilter_object_2 = filter_object_convertToJSON(filter_object_2);
	printf("repeating filter_object:\n%s\n", cJSON_Print(jsonfilter_object_2));
}

int main() {
  test_filter_object(1);
  test_filter_object(0);

  printf("Hello world \n");
  return 0;
}

#endif // filter_object_MAIN
#endif // filter_object_TEST
