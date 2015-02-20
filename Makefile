CXX = g++
CXXFLAGS = -g -std=c++0x

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: main

MAP_OBJECTS = terrain_generator.o main.o cave_generator.o
main: $(MAP_OBJECTS)
	$(CXX) -o $@ $(MAP_OBJECTS)

clean: 
	$(RM) *.o main
