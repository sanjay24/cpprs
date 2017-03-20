#include "dispatcher.h"
#include "routes/routeparser.h"
#include <iostream>

namespace blink {
  namespace nw {

    Dispatcher::Dispatcher() {
      initialize();
    }

    bool Dispatcher::execute(blink::util::EventRequest& ereq) {
      std::string route = ereq.getUriPath();
      std::cout<<"Got request for the uri ["<< ereq.getUriPath()<<std::endl;

      auto itr = mRouteMap.find(route);
      if (itr != mRouteMap.end()) {
        std::cout<<"Found the route, dispatching to the right controller"<<std::endl;
      } else {
        throw std::string("Invalid Route Specified");
      }
    }


    void Dispatcher::initialize() {
      blink::RouteParser routeParser("test/testdata/routes.txt");
      auto allRoutes = routeParser.getAllRoutes(); 

      std::cout<<"Got a total of "<<allRoutes.size()<<" Routes"<<std::endl;
      for(auto& r: allRoutes) {
        std::cout<<r->toString()<<std::endl;
        mRouteMap[r->toString()] = new GenericActionController();
      }
    }
  }
}
