#include "routeparser.h"
#include <fstream>
#include <assert.h>
#include <iostream>
#include "util.h"
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <cstring>

using namespace std;

namespace blink {
  RouteParser::RouteParser() {}

  RouteParser::RouteParser(const std::string& fname): mFileName(fname) {
  } 

  std::vector<std::unique_ptr<Route>> RouteParser::getAllRoutes() {
    return parse();
  }

  std::vector<std::unique_ptr<Route>> RouteParser::parse() {

    typedef boost::tokenizer<boost::char_separator<char>> tokenizer_t;
    
    std::ifstream routeFile(mFileName.c_str());
    assert(routeFile.is_open());
    std::string line;
    std::vector<std::unique_ptr<Route>> routeVec;;

    boost::char_separator<char> deli{" "};
    while (std::getline(routeFile, line)) {
     
      tokenizer_t tok{line, deli};
      int numTokens = std::distance(tok.begin(), tok.end());

      auto itr = tok.begin();

      if (!numTokens) {
        continue; //empty line
      } else {
        const string& el = *itr;
        if ( !el.empty() && el[0] == '#' ) {
          continue;
        }
      }

      assert(std::distance(tok.begin(), tok.end()) == 3); // we expect METHOD url ctrl triplet
      HttpMethod method;
 

      if (strcasecmp((*itr).c_str(), "GET") == 0) {
        method = HttpMethod::GET;  
      } else if (strcasecmp((*itr).c_str(), "POST") == 0) {
        method = HttpMethod::POST;  
      } else if (strcasecmp((*itr).c_str(), "PUT") == 0) {
        method = HttpMethod::PUT;  
      } else if (strcasecmp((*itr).c_str(), "DELETE") == 0) {
        method = HttpMethod::DELETE;  
      } else if (strcasecmp((*itr).c_str(), "MODIFY") == 0) {
        method = HttpMethod::MODIFY;  
      } else if (strcasecmp((*itr).c_str(), "PUBLISH") == 0) {
        method = HttpMethod::PUBLISH;  
      }

      itr++; // second token is url
      std::string url = *itr;

      itr++; // 3rd token is action controller
      std::string ctrl = *itr;

      routeVec.push_back(std::unique_ptr<Route>(new Route(method, url, ctrl)));
    }

    return routeVec;
  } 
}

/*
main() {
  blink::RouteParser r("test.txt");
  auto rdata = r.getAllRoutes();
  for(auto& r: rdata) {
    cout<<r->toString()<<endl;
  }
  cout<<"size of rdata = "<<rdata.size()<<endl;
}
*/
