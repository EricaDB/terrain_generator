CXX = g++
CXXFLAGS = -g -std=c++0x

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: viewTest arg_view_test

HTML_OBJECTS = viewTest.o html.o
viewTest: $(HTML_OBJECTS)
	$(CXX) -o $@ $(HTML_OBJECTS)

ARGHTML_OBJECTS = arg_view_test.o arg_html.o
arg_view_test: $(ARGHTML_OBJECTS)
	$(CXX) -o $@ $(ARGHTML_OBJECTS)

clean: 
	$(RM) *.o viewTest arg_view_test
