#pragma once
#ifndef TOOLS_H
#define TOOLS_H

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include <float.h>

#ifdef _WIN32
#define STRDUP _strdup
#else
#define STRDUP strdup
#endif

#define NORMAL_PRICE(price) (price) == DBL_MAX? 0.0 : (price)

char* ltrim(char* s);

char* rtrim(char* s);

char* trim(char* s);

char** split(const char* input, int& outCount, char delim = ',');

#endif
