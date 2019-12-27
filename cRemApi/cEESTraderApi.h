#include <stdint.h>
#include <stdbool.h>

#include "EesTraderDefine.h"
#include "EesTraderErr.h"

#ifdef __GNUC__
#ifdef CTRADERAPI_EXPORTS
#define C_API __attribute__((dllexport))
#else
#define C_API __attribute__((dllimport))
#endif
#else
#ifdef CTRADERAPI_EXPORTS
#define C_API __declspec(dllexport)
#else
#define C_API __declspec(dllimport)
#endif
#endif

#ifndef _WIN32
#define __stdcall
#endif
#define APPWINAPI __stdcall

#ifdef __cplusplus
#define NULL 0
extern "C"
{
#else
#define NULL ((void *)0)
#endif

	// C API instance id
	typedef uintptr_t InstanceID;



#ifdef __cplusplus
}
#endif // __cplusplus
