#include "gtest/gtest.h"
#include "controllers/actioncontrollerbase.h"
#include "routes/routeparser.h"
#include <iostream>

class RouteParserTest : public ::testing::Test {
  protected:
    virtual void SetUp() {
      mRouteParser.setFilename("testdata/routes.txt");
    }

    virtual void TearDown() {
      // code here will be called immediately after each test
      // right before the destructor
    }
    
    blink::RouteParser mRouteParser;
/*
  auto rdata = r.getAllRoutes();
  for(auto& r: rdata) {
    cout<<r->toString()<<endl;
  }
  cout<<"size of rdata = "<<rdata.size()<<endl;
*/

};


TEST_F(RouteParserTest, parsesRoutes) {
  auto routes = mRouteParser.getAllRoutes();
  EXPECT_EQ(4, routes.size());
}
