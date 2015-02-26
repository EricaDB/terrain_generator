CXX = g++
CXXFLAGS = -g -std=c++0x

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: viewTest 

HTML_OBJECTS = viewTest.o html.o
viewTest: $(HTML_OBJECTS)
	$(CXX) -o $@ $(HTML_OBJECTS)

clean: 
	$(RM) *.o viewTest
