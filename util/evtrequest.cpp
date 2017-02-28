#include "evtrequest.h"

#include <iostream>

namespace blink {
  namespace util {

    std::string EventRequest::getUriPath() {

      std::string thePath;

      const char *uri = evhttp_request_get_uri(mEventReq);
      auto decoded = evhttp_uri_parse(uri);

      if (!decoded) {
        std::cerr << "BAD REQUESTED URI, SENDING BAD REQUEST CODE\n";
        evhttp_send_error(mEventReq, HTTP_BADREQUEST, 0); 
        return thePath;
      } else {
        /* Let's see what path the user asked for. */
        thePath = evhttp_uri_get_path(decoded);
        std::cout << "PATH IDENTIFIED IS = "<<thePath<<std::endl;
        if (thePath.empty()) thePath = "/";
      }

      return thePath;
    }
  }

}
