NAME=cthosttraderapi
BUILD=`date +%FT%T%z`

CC=gcc
CFLAGS=-fPIC -shared -DCTRADER_API -DCTRADERAPI_EXPORTS
EXTRALINK=

ifeq ($(OS), Windows_NT)
	BINARY=$(NAME).dll
else
	BINARY=lib$(NAME).so
endif

default:
	$(CC) $(CFLAGS) -o $(BINARY) cThostTraderApi.cpp -I./ -Llibs/x64/ -lthosttraderapi

.PHONY: clean
clean:
	-rm -f $(BINARY)
