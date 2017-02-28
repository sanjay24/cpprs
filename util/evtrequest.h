#ifndef __BLINK__EVTREQPARSER__
#define __BLINK__EVTREQPARSER__

#include <event2/event.h>
#include <event2/http.h>
#include <event2/buffer.h>
#include <event2/util.h>
#include <event2/keyvalq_struct.h>
#include <string>

  
namespace blink { 
  namespace util {

    // This class is just a wrapper over event_request and doesn't 
    // own the memory pointed to by it.
    
    class EventRequest {
      public:
        EventRequest() {}
        EventRequest(struct evhttp_request* req): mEventReq(req) {}
  
        std::string getUriPath();

	void setEventRequest(struct evhttp_request* req) { 
          mEventReq = req;
	}

	struct evhttp_request* getEventRequest() { 
          return mEventReq;
	}

      private:
        struct evhttp_request* mEventReq;
    };
  }
}
#endif
