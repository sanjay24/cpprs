#ifndef __BLINK_ROUTE__
#define __BLINK_ROUTE__

#include <string>
#include "constants.h"

namespace blink {
  class Route {
    public:
      Route();
      Route(const HttpMethod& method, const std::string& ctrl);

      HttpMethod method() const {
        return mMethod;
      }

      HttpMethod& method() {
        return mMethod;
      }

      std::string controller() const {
        return mControllerId;
      }

      std::string& controller() {
        return mControllerId;
      }

      std::string urlPath() const {
        return mUrlPath;
      }

      std::string& urlPath() {
        return mUrlPath;
      }

    protected:
      HttpMethod mMethod;
      std::string mUrlPath;
      std::string mControllerId; 

  };
}
#endif
