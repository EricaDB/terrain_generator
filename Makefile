CXX = g++
CXXFLAGS = -g -std=c++0x

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: main

TERRAIN_OBJECTS = terrain_generator.o main.o raffle.o
main: $(TERRAIN_OBJECTS)
	$(CXX) -o $@ $(TERRAIN_OBJECTS)

clean: 
	$(RM) *.o main
