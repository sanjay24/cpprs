#ifndef __BINK__DISPATCHER__
#define __BINK__DISPATCHER__

#include "util/evtrequest.h"
#include "util/singleton.h"

// CRTP
namespace blink {
  namespace nw {
    class Dispatcher: public blink::util::Singleton<Dispatcher> {
      public: 
	// Dispatch the incoming request to the appropriate
	// action controller
	bool execute(blink::util::EventRequest& eq);
    };
  }
}

#endif
