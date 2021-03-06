GCC=g++
CFLAGS=-Wall -c
DFLAGS=-g
OFLAGS=-Wall
EXECUTABLE_NAME=CSV_Transformation

#All Object Files
OBJECTS=CommonFunctions.o	date.o	Input.o	CSV_Transformation.o

all: CSV_Transformation

CSV_Transformation: $(OBJECTS)
	$(GCC) $(OBJECTS) $(DFLAGS) $(OFLAGS) -o $(EXECUTABLE_NAME)

CommonFunctions.o: CommonFunctions.h
	$(GCC) $(CFLAGS) $(DFLAGS) CommonFunctions.cpp

date.o: date.h
	$(GCC) $(CFLAGS) $(DFLAGS) date.cpp

Input.o: Input.h
	$(GCC) $(CFLAGS) $(DFLAGS) Input.cpp

CSV_Transformation.o:
	$(GCC) $(CFLAGS) $(DFLAGS) CSV_Transformation.cpp

clean:
	rm -rf *.o
