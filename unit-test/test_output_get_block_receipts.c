#ifndef output_get_block_receipts_TEST
#define output_get_block_receipts_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_get_block_receipts_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_get_block_receipts.h"
output_get_block_receipts_t* instantiate_output_get_block_receipts(int include_optional);



output_get_block_receipts_t* instantiate_output_get_block_receipts(int include_optional) {
  output_get_block_receipts_t* output_get_block_receipts = NULL;
  if (include_optional) {
    output_get_block_receipts = output_get_block_receipts_create(
      "0",
      list_createList()
    );
  } else {
    output_get_block_receipts = output_get_block_receipts_create(
      "0",
      list_createList()
    );
  }

  return output_get_block_receipts;
}


#ifdef output_get_block_receipts_MAIN

void test_output_get_block_receipts(int include_optional) {
    output_get_block_receipts_t* output_get_block_receipts_1 = instantiate_output_get_block_receipts(include_optional);

	cJSON* jsonoutput_get_block_receipts_1 = output_get_block_receipts_convertToJSON(output_get_block_receipts_1);
	printf("output_get_block_receipts :\n%s\n", cJSON_Print(jsonoutput_get_block_receipts_1));
	output_get_block_receipts_t* output_get_block_receipts_2 = output_get_block_receipts_parseFromJSON(jsonoutput_get_block_receipts_1);
	cJSON* jsonoutput_get_block_receipts_2 = output_get_block_receipts_convertToJSON(output_get_block_receipts_2);
	printf("repeating output_get_block_receipts:\n%s\n", cJSON_Print(jsonoutput_get_block_receipts_2));
}

int main() {
  test_output_get_block_receipts(1);
  test_output_get_block_receipts(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_get_block_receipts_MAIN
#endif // output_get_block_receipts_TEST
