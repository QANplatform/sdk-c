#ifndef output_get_proof_TEST
#define output_get_proof_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_get_proof_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_get_proof.h"
output_get_proof_t* instantiate_output_get_proof(int include_optional);



output_get_proof_t* instantiate_output_get_proof(int include_optional) {
  output_get_proof_t* output_get_proof = NULL;
  if (include_optional) {
    output_get_proof = output_get_proof_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList()
    );
  } else {
    output_get_proof = output_get_proof_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList()
    );
  }

  return output_get_proof;
}


#ifdef output_get_proof_MAIN

void test_output_get_proof(int include_optional) {
    output_get_proof_t* output_get_proof_1 = instantiate_output_get_proof(include_optional);

	cJSON* jsonoutput_get_proof_1 = output_get_proof_convertToJSON(output_get_proof_1);
	printf("output_get_proof :\n%s\n", cJSON_Print(jsonoutput_get_proof_1));
	output_get_proof_t* output_get_proof_2 = output_get_proof_parseFromJSON(jsonoutput_get_proof_1);
	cJSON* jsonoutput_get_proof_2 = output_get_proof_convertToJSON(output_get_proof_2);
	printf("repeating output_get_proof:\n%s\n", cJSON_Print(jsonoutput_get_proof_2));
}

int main() {
  test_output_get_proof(1);
  test_output_get_proof(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_get_proof_MAIN
#endif // output_get_proof_TEST
