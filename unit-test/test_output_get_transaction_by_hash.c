#ifndef output_get_transaction_by_hash_TEST
#define output_get_transaction_by_hash_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_get_transaction_by_hash_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_get_transaction_by_hash.h"
output_get_transaction_by_hash_t* instantiate_output_get_transaction_by_hash(int include_optional);

#include "test_response_transaction.c"


output_get_transaction_by_hash_t* instantiate_output_get_transaction_by_hash(int include_optional) {
  output_get_transaction_by_hash_t* output_get_transaction_by_hash = NULL;
  if (include_optional) {
    output_get_transaction_by_hash = output_get_transaction_by_hash_create(
      "0",
       // false, not to have infinite recursion
      instantiate_response_transaction(0)
    );
  } else {
    output_get_transaction_by_hash = output_get_transaction_by_hash_create(
      "0",
      NULL
    );
  }

  return output_get_transaction_by_hash;
}


#ifdef output_get_transaction_by_hash_MAIN

void test_output_get_transaction_by_hash(int include_optional) {
    output_get_transaction_by_hash_t* output_get_transaction_by_hash_1 = instantiate_output_get_transaction_by_hash(include_optional);

	cJSON* jsonoutput_get_transaction_by_hash_1 = output_get_transaction_by_hash_convertToJSON(output_get_transaction_by_hash_1);
	printf("output_get_transaction_by_hash :\n%s\n", cJSON_Print(jsonoutput_get_transaction_by_hash_1));
	output_get_transaction_by_hash_t* output_get_transaction_by_hash_2 = output_get_transaction_by_hash_parseFromJSON(jsonoutput_get_transaction_by_hash_1);
	cJSON* jsonoutput_get_transaction_by_hash_2 = output_get_transaction_by_hash_convertToJSON(output_get_transaction_by_hash_2);
	printf("repeating output_get_transaction_by_hash:\n%s\n", cJSON_Print(jsonoutput_get_transaction_by_hash_2));
}

int main() {
  test_output_get_transaction_by_hash(1);
  test_output_get_transaction_by_hash(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_get_transaction_by_hash_MAIN
#endif // output_get_transaction_by_hash_TEST
