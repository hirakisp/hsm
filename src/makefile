CC = gcc
CFLAGS= -O4 -Wall -Iinc
DEST = bin
LDFLAGS = -Llib
LIBS = -lm
OBJS = main.o libhsm.o state.o sm.o
PROGRAM = hsm

all:		$(PROGRAM)

$(PROGRAM):	$(OBJS)
		$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

clean:
		rm -f *.o *~ *.stackdump $(PROGRAM)

install:	$(PROGRAM)
		install -s $(PROGRAM) $(DEST)
