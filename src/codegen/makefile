CC = gcc
CFLAGS= -O4 -Wall -Iinc -I../
DEST = bin
LDFLAGS = -Llib
LIBS = -lm
OBJS = codegen.o file.o strmgr.o parser.o
PROGRAM = codegen

all:		$(PROGRAM)

$(PROGRAM):	$(OBJS)
		$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

clean:
		rm -f *.o *~ *.stackdump $(PROGRAM)

install:	$(PROGRAM)
		install -s $(PROGRAM) $(DEST)
