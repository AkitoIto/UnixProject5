EXEC := dealer hand
SRC  := dealer.c hand.c
#options
CC := gcc
INC := -I/home/013/a/ax/axi171130//src/include
LIB := -L/home/013/a/ax/axi171130/src/lib
#Rules
$(EXEC): 
	$(CC) -o $@ $@.c
	$(CC) -o hand $(INC) hand.c -lgsl -lgslcblas $(LIB)

clean:
	rm -f $(EXEC)
