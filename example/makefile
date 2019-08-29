CC = gcc
CFLAGS= -O4 -Wall -Iinc
DEST = bin
LDFLAGS = -Llib
LIBS = -lm
OBJS = main.o idle.o hsm_lib.o
PROGRAM = test

all:		$(PROGRAM)

$(PROGRAM):	$(OBJS)
		$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

clean:
		rm -f *.o *~ $(PROGRAM)

install:	$(PROGRAM)
		install -s $(PROGRAM) $(DEST)
