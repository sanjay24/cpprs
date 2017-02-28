#include "dispatcher.h"
#include <iostream>

namespace blink {
  namespace nw {
    bool Dispatcher::execute(blink::util::EventRequest& ereq) {
      std::cout<<"Got request for the uri ["<< ereq.getUriPath()<<std::endl;
    }
  }
}
