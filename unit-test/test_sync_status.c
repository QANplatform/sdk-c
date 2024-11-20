#ifndef sync_status_TEST
#define sync_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sync_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sync_status.h"
sync_status_t* instantiate_sync_status(int include_optional);



sync_status_t* instantiate_sync_status(int include_optional) {
  sync_status_t* sync_status = NULL;
  if (include_optional) {
    sync_status = sync_status_create(
      "0",
      "0",
      "0"
    );
  } else {
    sync_status = sync_status_create(
      "0",
      "0",
      "0"
    );
  }

  return sync_status;
}


#ifdef sync_status_MAIN

void test_sync_status(int include_optional) {
    sync_status_t* sync_status_1 = instantiate_sync_status(include_optional);

	cJSON* jsonsync_status_1 = sync_status_convertToJSON(sync_status_1);
	printf("sync_status :\n%s\n", cJSON_Print(jsonsync_status_1));
	sync_status_t* sync_status_2 = sync_status_parseFromJSON(jsonsync_status_1);
	cJSON* jsonsync_status_2 = sync_status_convertToJSON(sync_status_2);
	printf("repeating sync_status:\n%s\n", cJSON_Print(jsonsync_status_2));
}

int main() {
  test_sync_status(1);
  test_sync_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // sync_status_MAIN
#endif // sync_status_TEST
