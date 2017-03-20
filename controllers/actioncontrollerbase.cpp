#include "actioncontrollerbase.h"
#include <iostream>

using namespace std;

namespace blink {
  ActionControllerBase::ActionControllerBase() {
  }

  ActionControllerBase::ActionControllerBase(struct evhttp_request* req, void* arg): 
    mRequest(req), mRequestArg(arg) {
  }

  ActionControllerBase::~ActionControllerBase() {
  }

  void ActionControllerBase::operator()() {
    cout<<"Inside the ActionControllerBase"<<endl;
  }
}
