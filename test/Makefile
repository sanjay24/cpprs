CXX = g++
CXXFLAGS = -g -std=c++11 -L/usr/local/lib 
GTEST_LIBS = /usr/local/lib/libgtest.a -lpthread
INCS = -I./ -I../routes  -I../include -I/usr/local/include
OBJS = ../routes/route.o ../routes/routeparser.o routerparser_test.o

testAll: $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCS) -o testAll  main_testall.cpp $(OBJS) $(GTEST_LIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
	rm testAll *.o 
