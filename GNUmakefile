CFLAGS+=-O -g -Wall -Wextra
BIN_FLAGS=-Wl,-rpath,.
DSO_FLAGS=-fPIC -shared -Wl,--image-base,0x30000000

ALL=test libtest.so
all:	$(ALL)

test:	test.c
	$(CC) $(CFLAGS) $(BIN_FLAGS) -o test test.c

libtest.so:	libtest.c
	$(CC) $(CFLAGS) $(DSO_FLAGS) -o libtest.so libtest.c

clean:
	rm -f $(ALL) *.core
