#ifndef __ACTION_CONTROLLER_BASE___
#define __ACTION_CONTROLLER_BASE___

#include <event2/event.h>
#include <event2/http.h>
#include <event2/util.h>
#include <event2/keyvalq_struct.h>



namespace blink {
  class ActionControllerBase {
    public:
      ActionControllerBase();
      ActionControllerBase(struct evhttp_request *req, void* arg);
      virtual ~ActionControllerBase();
      virtual void operator()();

      void setRequest(struct evhttp_request* req) {
        mRequest = req;
      }

      void setRequestArg(void* arg) {
        mRequestArg = arg;
      }

      struct evhttp_request* getRequest() const {
        return mRequest;
      }

      void* getRequestArg() const {
        return mRequestArg;
      }

    protected:
      struct evhttp_request *mRequest;
      void *mRequestArg;
  };
}
#endif
