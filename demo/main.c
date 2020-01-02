#include <stdio.h>

#include "cThostTraderApi.h"

#ifdef _WIN32
#include <direct.h>
#define MKDIR(path) _mkdir((path))
#else
#include <sys/types.h>
#include <sys/stat.h>
#define MKDIR(path) mkdir((path), S_IRUSR|S_IWUSR|S_IRGRP)
#endif

const char *front = "tcp://172.30.1.221:31803";
const char *flowPath = "flow/";

void onFrontConnected(InstanceID id)
{
	printf("Front connected: %s", front);
	Release(id);
}


int main() {
	printf("API Version: %s", GetApiVersion());

	MKDIR(flowPath);

	InstanceID id = CreateThostTraderApi(flowPath);

	SetCallbackOnFrontConnected(id, onFrontConnected);

	RegisterFront(id, front);

	SubscribePrivateTopic(id, THOST_TERT_QUICK);
	SubscribePublicTopic(id, THOST_TERT_QUICK);

	Init(id, false);

	Join(id);

	printf("Exit.");

	return 0;
}