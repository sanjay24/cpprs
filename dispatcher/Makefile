CXX=g++
CC=gcc

CXXFLAGS=-I /usr/local/include -I include  -I . -I ../ -I ../controllers -std=c++11 
LDFLAGS = -L /usr/local/lib

DEBUGFLAGS = -g 
DEPS = $(shell echo *.h)
SOURCES = $(shell echo *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

TARGET = libdispatcher.a



%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	ar rcs $@ $^



clean:
	rm -rf $(OBJECTS) $(TARGET)


