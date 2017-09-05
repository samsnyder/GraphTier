#include <iostream>
#include "rpc_futures.h"

using namespace std;

namespace graphtier {


  void RpcFutures::processOpList(const OpList& op_list) {
    dispatcher.Process(op_list);
  }




}
