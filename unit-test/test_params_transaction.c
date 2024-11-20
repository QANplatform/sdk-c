#ifndef params_transaction_TEST
#define params_transaction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define params_transaction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/params_transaction.h"
params_transaction_t* instantiate_params_transaction(int include_optional);



params_transaction_t* instantiate_params_transaction(int include_optional) {
  params_transaction_t* params_transaction = NULL;
  if (include_optional) {
    params_transaction = params_transaction_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    params_transaction = params_transaction_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return params_transaction;
}


#ifdef params_transaction_MAIN

void test_params_transaction(int include_optional) {
    params_transaction_t* params_transaction_1 = instantiate_params_transaction(include_optional);

	cJSON* jsonparams_transaction_1 = params_transaction_convertToJSON(params_transaction_1);
	printf("params_transaction :\n%s\n", cJSON_Print(jsonparams_transaction_1));
	params_transaction_t* params_transaction_2 = params_transaction_parseFromJSON(jsonparams_transaction_1);
	cJSON* jsonparams_transaction_2 = params_transaction_convertToJSON(params_transaction_2);
	printf("repeating params_transaction:\n%s\n", cJSON_Print(jsonparams_transaction_2));
}

int main() {
  test_params_transaction(1);
  test_params_transaction(0);

  printf("Hello world \n");
  return 0;
}

#endif // params_transaction_MAIN
#endif // params_transaction_TEST
