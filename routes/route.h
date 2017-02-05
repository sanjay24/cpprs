#ifndef __BLINK_ROUTE__
#define __BLINK_ROUTE__

#include <string>
#include <sstream>
#include "constants.h"

namespace blink {
  class Route {
    public:
      Route();
      Route(const HttpMethod& method, const std::string& url, const std::string& ctrl);

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

      std::string toString() {
        std::stringstream ss;
        if (mMethod == HttpMethod::GET) {
          ss<<"GET";
        } else if (mMethod == HttpMethod::POST) {
          ss<<"POST";
        } else if (mMethod == HttpMethod::PUT) {
          ss<<"PUT";
        } else if (mMethod == HttpMethod::MODIFY) {
          ss<<"MODIFY";
        } else if (mMethod == HttpMethod::PUBLISH) {
          ss<<"PUBLISH";
        } else if (mMethod == HttpMethod::DELETE) {
          ss<<"DELETE";
        }

        ss<<"|"<<mUrlPath<<"|"<<mControllerId;
        return ss.str();
      }

    protected:
      HttpMethod mMethod;
      std::string mUrlPath;
      std::string mControllerId; 

  };
}
#endif
