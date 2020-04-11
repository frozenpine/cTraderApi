NAME=cthosttraderapi
BUILD=`date +%FT%T%z`

CC=g++
CFLAGS=-shared -fPIC -DCTRADER_API -DCTRADERAPI_EXPORTS

ifeq ($(OS), Windows_NT)
	BINARY=$(NAME).dll
else
	BINARY=lib$(NAME).so
endif

default:
	$(CC) $(CFLAGS) cThostTraderApi.cpp -o libs/x64/$(BINARY) -I./ -Llibs/x64 -lthosttraderapi

.PHONY: clean
clean:
	-rm -f libs/x64/$(BINARY)
