all: add-nbo

main.o: nbo.h main.cpp 

nbo.o: nbo.h nbo.cpp

add-nbo: main.o nbo.o
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@
clean: 
	rm -f add-nbo *.o
