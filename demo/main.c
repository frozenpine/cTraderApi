#include <stdio.h>

#include "cTraderApi.h"

const char * front = "tcp://172.30.1.221:31803";

void onFrontConnected(InstanceID id)
{
	printf("Front connected: %s", front);
	Release(id);
}


int main() {
	printf("API Version: %s", GetApiVersion());

	InstanceID id = CreateApi("flow/");

	RegisterFront(id, front);

	SubscribePrivateTopic(id, THOST_TERT_QUICK);
	SubscribePublicTopic(id, THOST_TERT_QUICK);

	Init(id, false);

	Join(id);

	return 0;
}