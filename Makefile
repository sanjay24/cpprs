CXX=g++
CC=gcc

CXXFLAGS=-I /usr/local/include -I include  -std=c++11
LDFLAGS = -L /usr/local/lib

LIBS=-levent

DEPS = actioncontrollerbase.h genericactioncontroller.h util.h


%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(CFLAGS)

httpserver: actioncontrollerbase.o genericactioncontroller.o myhttpserver.o
	$(CXX) -o myhttpserver actioncontrollerbase.o myhttpserver.o genericactioncontroller.o $(CFLAGS) $(LDFLAGS) $(LIBS)


clean:
	rm -f myhttpserver myhttpserver.o actioncontrollerbase.o genericactioncontroller.o myhttpserver.o


