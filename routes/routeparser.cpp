#include "routeparser.h"
#include <fstream>
#include <assert.h>
#include <iostream>
#include "util.h"

using namespace std;

namespace blink {
  RouteParser::RouteParser() {}

  RouteParser::RouteParser(const std::string& fname): mFileName(fname) {
  } 

  std::vector<std::unique_ptr<Route>> RouteParser::getAllRoutes() {
    return parse();
  }

  std::vector<std::unique_ptr<Route>> RouteParser::parse() {

    std::ifstream routeFile(mFileName.c_str());

    cout<<"trying to open "<<mFileName<<endl;

    assert(routeFile.is_open());

    cout<<"Testing the parser method"<<endl;
    std::string line;

    std::vector<std::unique_ptr<Route>> routeVec;;

    while (std::getline(routeFile, line)) {
      cout<<line<<endl;
      
    }

    return std::vector<std::unique_ptr<Route>>(); 
  } 
}

main() {
  blink::RouteParser r("test.txt");
  auto rdata = r.getAllRoutes();
  cout<<"size of rdata = "<<rdata.size()<<endl;
}
