CXX = g++
CXXFLAGS = -g -std=c++0x -I views

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: main

MAP_OBJECTS = terrain_generator.o main.o raffle.o cave_generator.o arg_html.o tile.o
main: $(MAP_OBJECTS)
	$(CXX) -o $@ $(MAP_OBJECTS)

clean: 
	$(RM) *.o main
