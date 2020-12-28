#include "tools.h"

char* ltrim(char* s)
{
	while (isspace(*s)) s++;
	return s;
}

char* rtrim(char* s)
{
	char* back = s + strlen(s);
	while (isspace(*--back));
	*(back + 1) = '\0';
	return s;
}

char* trim(char* s)
{
	return rtrim(ltrim(s));
}

char** split(const char* input, int& outCount, char delim)
{
	char** result = 0;

	int count = 0;
	int len = int(strlen(input));
	char* instruments = (char*)malloc(size_t(len) + 1);
	if (!instruments) {
		return NULL;
	}
	instruments[len] = 0;
	memcpy(instruments, input, len);
	char* tmp = instruments;
	char* last_comma = 0;
	char delimer[2] = { 0 };
	delimer[0] = delim;

	while (*tmp) {
		if (delim == *tmp) {
			count++;
			last_comma = tmp;
		}

		tmp++;
	}
	// 如果分隔符不存在或者最后一个字符不是逗号分隔符，则计数加一
	// a,b count = 2
	// a,b, count = 2
	if (!last_comma || last_comma < (instruments + strlen(instruments) - 1)) {
		count++;
	}

	result = (char**)malloc(sizeof(char*) * count);

	if (result) {
		int idx = 0;

		char* token = strtok(instruments, delimer);

		while (token != NULL) {
			*(result + idx++) = STRDUP(trim(token));

			token = strtok(NULL, delimer);
		}

		outCount = count;
	}

	free(instruments);
	return result;
}
