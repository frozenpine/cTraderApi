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

#ifdef _WIN32
#include <Windows.h>
#include <direct.h>
#define SLEEP(ms) Sleep((ms))
#define MKDIR(path) _mkdir((path))
#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define SLEEP(ms) usleep((ms)*1000)
#define MKDIR(path) mkdir((path), S_IRUSR|S_IWUSR|S_IRGRP)
#endif

#define NORMAL_PRICE(price) (price) == DBL_MAX? 0.0 : (price)

char* ltrim(char* s);

char* rtrim(char* s);

char* trim(char* s);

char** split(const char* input, int& outCount, char delim = ',');

long long get_ms_ts();

#endif
