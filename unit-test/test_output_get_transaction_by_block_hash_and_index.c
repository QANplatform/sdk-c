#ifndef output_get_transaction_by_block_hash_and_index_TEST
#define output_get_transaction_by_block_hash_and_index_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_get_transaction_by_block_hash_and_index_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_get_transaction_by_block_hash_and_index.h"
output_get_transaction_by_block_hash_and_index_t* instantiate_output_get_transaction_by_block_hash_and_index(int include_optional);

#include "test_response_transaction.c"


output_get_transaction_by_block_hash_and_index_t* instantiate_output_get_transaction_by_block_hash_and_index(int include_optional) {
  output_get_transaction_by_block_hash_and_index_t* output_get_transaction_by_block_hash_and_index = NULL;
  if (include_optional) {
    output_get_transaction_by_block_hash_and_index = output_get_transaction_by_block_hash_and_index_create(
      "0",
       // false, not to have infinite recursion
      instantiate_response_transaction(0)
    );
  } else {
    output_get_transaction_by_block_hash_and_index = output_get_transaction_by_block_hash_and_index_create(
      "0",
      NULL
    );
  }

  return output_get_transaction_by_block_hash_and_index;
}


#ifdef output_get_transaction_by_block_hash_and_index_MAIN

void test_output_get_transaction_by_block_hash_and_index(int include_optional) {
    output_get_transaction_by_block_hash_and_index_t* output_get_transaction_by_block_hash_and_index_1 = instantiate_output_get_transaction_by_block_hash_and_index(include_optional);

	cJSON* jsonoutput_get_transaction_by_block_hash_and_index_1 = output_get_transaction_by_block_hash_and_index_convertToJSON(output_get_transaction_by_block_hash_and_index_1);
	printf("output_get_transaction_by_block_hash_and_index :\n%s\n", cJSON_Print(jsonoutput_get_transaction_by_block_hash_and_index_1));
	output_get_transaction_by_block_hash_and_index_t* output_get_transaction_by_block_hash_and_index_2 = output_get_transaction_by_block_hash_and_index_parseFromJSON(jsonoutput_get_transaction_by_block_hash_and_index_1);
	cJSON* jsonoutput_get_transaction_by_block_hash_and_index_2 = output_get_transaction_by_block_hash_and_index_convertToJSON(output_get_transaction_by_block_hash_and_index_2);
	printf("repeating output_get_transaction_by_block_hash_and_index:\n%s\n", cJSON_Print(jsonoutput_get_transaction_by_block_hash_and_index_2));
}

int main() {
  test_output_get_transaction_by_block_hash_and_index(1);
  test_output_get_transaction_by_block_hash_and_index(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_get_transaction_by_block_hash_and_index_MAIN
#endif // output_get_transaction_by_block_hash_and_index_TEST
