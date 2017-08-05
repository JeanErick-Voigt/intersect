CFLAGS=-Wall -Wextra -Wpedantic -Wwrite-strings -Wstack-usage=1024 -Wfloat-equal -Waggregate-return -Winline

all: intersect

intersect: intersect.c
	gcc $(CFLAGS) intersect.c -o intersect

debug: CFLAGS += -g
debug: all

profile: CFLAGS += -pg
profile: all

clean:
	rm -f  intersect
