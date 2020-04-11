NAME=cthosttrader
VERSION=1.0.1
BUILD=`date +%FT%T%z`

CC=gcc
CFLAGS=-DNAME=$(NAME) -DVERSION=$(VERSION) -DBUILD=$(BUILD)

ifeq ($(OS), Windows_NT)
	BINARY=$(NAME).exe
else
	BINARY=$(NAME)
endif

default:
	$(CC) $(CFLAGS) -o $(BINARY) cThostTraderDemo.c \
		-I../cThostTraderApi -L../cThostTraderApi/libs/x64 -lcthosttraderapi

.PHONY: clean
clean:
	-rm -f $(BINARY)
