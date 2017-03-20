#ifndef __BINK__DISPATCHER__
#define __BINK__DISPATCHER__

#include "util/evtrequest.h"
#include "util/singleton.h"
#include "controllers/genericactioncontroller.h"

#include <map>

// CRTP
namespace blink {
  namespace nw {
    class Dispatcher: public blink::util::Singleton<Dispatcher> {
      public: 
	// Dispatch the incoming request to the appropriate
	// action controller
	bool execute(blink::util::EventRequest& eq);

        void initialize();

        Dispatcher();

       protected:
         std::map<std::string, blink::ActionControllerBase*> mRouteMap;
    };
  }
}

#endif
