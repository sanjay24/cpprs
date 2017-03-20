CXX = g++
CXXFLAGS = -g -std=c++11 -L/usr/local/lib 
GTEST_LIBS = /usr/local/lib/libgtest.a -lpthread
INCS = -I./ -I..  -I../include -I/usr/local/include 
OBJS = ../routes/route.o ../routes/routeparser.o routerparser_test.o

LIBS = -levent

gtest: $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCS) -o testAll  main_testall.cpp $(OBJS) $(GTEST_LIBS)


HTTPOBJS = myhttpserver.cpp
OBJLIBS = ../util/libutil.a \
	../dispatcher/libdispatcher.a \
        ../controllers/libctrl.a \
	../routes/libroute.a

LDFLAGS = -L /usr/local/lib 
httpserv: $(HTTPOBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o httpserv $(INCS) $(OBJECTS) $(HTTPOBJS) $(OBJLIBS) $(LIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
	rm -rf testAll *.o httpserv
