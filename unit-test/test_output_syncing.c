#ifndef output_syncing_TEST
#define output_syncing_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_syncing_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_syncing.h"
output_syncing_t* instantiate_output_syncing(int include_optional);

#include "test_sync_status.c"


output_syncing_t* instantiate_output_syncing(int include_optional) {
  output_syncing_t* output_syncing = NULL;
  if (include_optional) {
    output_syncing = output_syncing_create(
      "0",
       // false, not to have infinite recursion
      instantiate_sync_status(0)
    );
  } else {
    output_syncing = output_syncing_create(
      "0",
      NULL
    );
  }

  return output_syncing;
}


#ifdef output_syncing_MAIN

void test_output_syncing(int include_optional) {
    output_syncing_t* output_syncing_1 = instantiate_output_syncing(include_optional);

	cJSON* jsonoutput_syncing_1 = output_syncing_convertToJSON(output_syncing_1);
	printf("output_syncing :\n%s\n", cJSON_Print(jsonoutput_syncing_1));
	output_syncing_t* output_syncing_2 = output_syncing_parseFromJSON(jsonoutput_syncing_1);
	cJSON* jsonoutput_syncing_2 = output_syncing_convertToJSON(output_syncing_2);
	printf("repeating output_syncing:\n%s\n", cJSON_Print(jsonoutput_syncing_2));
}

int main() {
  test_output_syncing(1);
  test_output_syncing(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_syncing_MAIN
#endif // output_syncing_TEST
