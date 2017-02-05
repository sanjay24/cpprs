CXX=g++
#AR=/home/mk7/sanjay/gcc-5.3.0/bin/gcc-ar
AR=ar
CC=gcc

CXXFLAGS=-g -I /usr/local/include -I .  -I ../util -std=c++11
LDFLAGS = -L /usr/local/lib

#LIBS=-levent

DEPS = route.h routeparser.h constant.h util.h


%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(CFLAGS)

route: route.o routeparser.o 
#	$(AR) rvs libroute.a route.o routeparser.o 
	$(CXX) -o routetest route.o routeparser.o




clean:
	rm -f route.o routeparser.o routetest


