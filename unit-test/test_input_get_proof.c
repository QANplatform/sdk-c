#ifndef input_get_proof_TEST
#define input_get_proof_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_get_proof_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_get_proof.h"
input_get_proof_t* instantiate_input_get_proof(int include_optional);



input_get_proof_t* instantiate_input_get_proof(int include_optional) {
  input_get_proof_t* input_get_proof = NULL;
  if (include_optional) {
    input_get_proof = input_get_proof_create(
      "0",
      "0",
      "latest",
      list_createList()
    );
  } else {
    input_get_proof = input_get_proof_create(
      "0",
      "0",
      "latest",
      list_createList()
    );
  }

  return input_get_proof;
}


#ifdef input_get_proof_MAIN

void test_input_get_proof(int include_optional) {
    input_get_proof_t* input_get_proof_1 = instantiate_input_get_proof(include_optional);

	cJSON* jsoninput_get_proof_1 = input_get_proof_convertToJSON(input_get_proof_1);
	printf("input_get_proof :\n%s\n", cJSON_Print(jsoninput_get_proof_1));
	input_get_proof_t* input_get_proof_2 = input_get_proof_parseFromJSON(jsoninput_get_proof_1);
	cJSON* jsoninput_get_proof_2 = input_get_proof_convertToJSON(input_get_proof_2);
	printf("repeating input_get_proof:\n%s\n", cJSON_Print(jsoninput_get_proof_2));
}

int main() {
  test_input_get_proof(1);
  test_input_get_proof(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_get_proof_MAIN
#endif // input_get_proof_TEST
