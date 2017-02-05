#include <string>
#include "route.h"

namespace blink {
  Route::Route() { }
  
  Route::Route(const HttpMethod& method, const std::string& url, const std::string& ctrl) :
    mMethod(method), mUrlPath(url), mControllerId(ctrl) {
  }
}
