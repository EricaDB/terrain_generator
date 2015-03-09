CXX = g++
CXXFLAGS = -g -std=c++11

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: main

MAP_OBJECTS = main.o tile.o terrain_generator.o maze_generator.o cave_generator.o terrain_view.o maze_view.o cave_view.o
main: $(MAP_OBJECTS)
	$(CXX) -o $@ $(MAP_OBJECTS)

clean: 
	$(RM) *.o main
