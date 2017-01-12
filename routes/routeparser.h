#ifndef __BLINK_ROUTE_PARSER__
#define __BLINK_ROUTE_PARSER__

#include <vector>
#include <memory>

#include "route.h"

namespace blink {
  class RouteParser {
    public:
      RouteParser();
      RouteParser(const std::string& fname); 

      std::string getFilename() { return mFileName; }
      void setFilename(std::string fname) { mFileName = fname; }

      std::vector<std::unique_ptr<Route>>  getAllRoutes();

    protected:
      std::vector<std::unique_ptr<Route>> parse();
      std::string mFileName;
  };
}
#endif
