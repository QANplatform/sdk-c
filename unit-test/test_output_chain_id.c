#ifndef output_chain_id_TEST
#define output_chain_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_chain_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_chain_id.h"
output_chain_id_t* instantiate_output_chain_id(int include_optional);



output_chain_id_t* instantiate_output_chain_id(int include_optional) {
  output_chain_id_t* output_chain_id = NULL;
  if (include_optional) {
    output_chain_id = output_chain_id_create(
      "0",
      "0"
    );
  } else {
    output_chain_id = output_chain_id_create(
      "0",
      "0"
    );
  }

  return output_chain_id;
}


#ifdef output_chain_id_MAIN

void test_output_chain_id(int include_optional) {
    output_chain_id_t* output_chain_id_1 = instantiate_output_chain_id(include_optional);

	cJSON* jsonoutput_chain_id_1 = output_chain_id_convertToJSON(output_chain_id_1);
	printf("output_chain_id :\n%s\n", cJSON_Print(jsonoutput_chain_id_1));
	output_chain_id_t* output_chain_id_2 = output_chain_id_parseFromJSON(jsonoutput_chain_id_1);
	cJSON* jsonoutput_chain_id_2 = output_chain_id_convertToJSON(output_chain_id_2);
	printf("repeating output_chain_id:\n%s\n", cJSON_Print(jsonoutput_chain_id_2));
}

int main() {
  test_output_chain_id(1);
  test_output_chain_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // output_chain_id_MAIN
#endif // output_chain_id_TEST
