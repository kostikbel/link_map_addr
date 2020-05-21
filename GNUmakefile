CFLAGS+=-O -g -Wall -Wextra
BIN_FLAGS=-Wl,-rpath,.
DSO_FLAGS=-fPIC -shared -Wl,--image-base,0x30000000
os=$(shell uname -o)
ifeq ($(os), "GNU/Linux")
BIN_FLAGS+=-D_GNU_SOURCE
endif

ALL=test libtest.so
all:	$(ALL)

test:	test.c GNUmakefile
	$(CC) $(CFLAGS) $(BIN_FLAGS) -o test test.c -ldl

libtest.so:	libtest.c GNUmakefile
	$(CC) $(CFLAGS) $(DSO_FLAGS) -o libtest.so libtest.c

clean:
	rm -f $(ALL) *.core
