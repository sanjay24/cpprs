#include "genericactioncontroller.h"
#include <event2/keyvalq_struct.h>
#include <event2/buffer.h>

#include <iostream>

using namespace std;

namespace blink {
  GenericActionController::GenericActionController() {
  }

  GenericActionController::GenericActionController(struct evhttp_request* req, void* arg): ActionControllerBase(req, arg) {
  }

  GenericActionController::~GenericActionController() {
  }

  void GenericActionController::operator()() {
    cout<<"Inside the GenericActionController ======================"<<endl;
    const char *cmdtype;
    struct evkeyvalq *headers;
    struct evkeyval *header;
    struct evbuffer *buf;

    switch (evhttp_request_get_command(mRequest)) {
      case EVHTTP_REQ_GET: cmdtype = "GET"; break;
      case EVHTTP_REQ_POST: cmdtype = "POST"; break;
      case EVHTTP_REQ_HEAD: cmdtype = "HEAD"; break;
      case EVHTTP_REQ_PUT: cmdtype = "PUT"; break;
      case EVHTTP_REQ_DELETE: cmdtype = "DELETE"; break;
      case EVHTTP_REQ_OPTIONS: cmdtype = "OPTIONS"; break;
      case EVHTTP_REQ_TRACE: cmdtype = "TRACE"; break;
      case EVHTTP_REQ_CONNECT: cmdtype = "CONNECT"; break;
      case EVHTTP_REQ_PATCH: cmdtype = "PATCH"; break;
      default: cmdtype = "unknown"; break;
    }   

    cout<<"Received type => "<<cmdtype<<endl;
    cout<<"Headers       => "<<evhttp_request_get_uri(mRequest)<<endl;
    cout<<"=========================================================="<<endl;
   
    headers = evhttp_request_get_input_headers(mRequest);

    for (header = headers->tqh_first; header;
      header = header->next.tqe_next) {
      cout<<header->key<<header->value<<endl;
    }

    buf = evhttp_request_get_input_buffer(mRequest);
    puts("Input data: <<<");

    while (evbuffer_get_length(buf)) {
      int n;
      char cbuf[128];
      n = evbuffer_remove(buf, cbuf, sizeof(cbuf));
      if (n > 0)
        (void) fwrite(cbuf, 1, n, stdout);
    }
    puts(">>>");

    evhttp_send_reply(mRequest, 200, "OK", NULL);
  }
}
