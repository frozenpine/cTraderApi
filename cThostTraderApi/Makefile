NAME=cthosttraderapi
BUILD=`date +%FT%T%z`

CC=g++
CFLAGS=-shared -fPIC -DCTRADER_API -DCTRADERAPI_EXPORTS -fvisibility=default

ifeq ($(OS), Windows_NT)
	BINARY=$(NAME).dll
else
	BINARY=lib$(NAME).so
endif

default:
	$(CC) $(CFLAGS) cThostTraderApi.cpp -o $(BINARY) -I./ -Llibs/x64 -lthosttraderapi

.PHONY: clean
clean:
	-rm -f $(BINARY)
