#ifndef __GENERIC_CONTROLLER__
#define __GENERIC_CONTROLLER__

#include "actioncontrollerbase.h"

namespace blink {
  class GenericActionController: public ActionControllerBase {

    public:
      GenericActionController();
      GenericActionController(struct evhttp_request *req, void* arg);
      virtual ~GenericActionController();
      virtual void operator()();
  };
}


#endif

