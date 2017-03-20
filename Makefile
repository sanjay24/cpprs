CXX=g++
CC=gcc
MAKE = make
ECHO = echo

CXXFLAGS=-I /usr/local/include -I include  -I . -std=c++11 
LDFLAGS = -L /usr/local/lib 

SUBDIRS=util routes dispatcher
ALLDIRS=$(SUBDIRS:%=make-%)
CLEANDIRS = $(SUBDIRS:%=clean-%)
.PHONY: subdirs $(SUBDIRS)
.PHONY: clean
.PHONY: subdirs $(CLEANDIRS)
.PHONY: all

OBJLIBS = util/libutil.a \
	dispatcher/libdispatcher.a \
	routes/libroute.a \
        controllers/libctrl.a

LIBS = -levent 

DEPS = $(shell echo *.h)
SOURCES = $(shell echo *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)


$(ALLDIRS):
	$(MAKE) -C $(@:make-%=%)

%.o: $(DEPS) 
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(CFLAGS)


all: $(ALLDIRS)
	$(MAKE) 

clean: $(CLEANDIRS)
	rm -f $(OBJECTS) 

$(CLEANDIRS):
	$(MAKE) clean -C $(@:clean-%=%)


force_look:
	true

