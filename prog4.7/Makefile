COMM_HFILE = include/comm.h include/error.h
H_PATHALLOC = include/pathalloc.h

out:	out.o error.o pathalloc.o
	gcc -o out out.o error.o pathalloc.o

out.o:	out.c $(COMM_HFILE) $(H_PATHALLOC)
	@gcc -c out.c

# the header file could remove, like:
# error.o	error.c
#	gcc -c error.c
# that is fine too.

error.o:	error.c $(COMM_HFILE)
	@gcc -c error.c

pathalloc.o:	pathalloc.c $(COMM_HFILE) $(H_PATHALLOC) 
	@gcc -c pathalloc.c

clean:
	rm error.o out.o pathalloc.o
