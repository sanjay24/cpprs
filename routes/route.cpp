#include <string>
#include "route.h"

namespace blink {
  Route::Route() { }
  
  Route::Route(const HttpMethod& method, const std::string& ctrl) :
    mMethod(method), mControllerId(ctrl) {
  }
}
