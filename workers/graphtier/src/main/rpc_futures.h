#include "graphtier.h"
#include <future>


using namespace std;

namespace graphtier {

  class RpcFutures {
  public:
    RpcFutures() = default;
    ~RpcFutures() = default;

    template <typename T>
      future<const typename T::Response>
      sendCommandRequest(Connection& connection, EntityId to, const typename T::Request& request,
                         const Option<std::uint32_t>& timeout_millis);


    void processOpList(const OpList& op_list);

  private:
    Dispatcher dispatcher;
  };

  template <typename T>
    future<const typename T::Response>
    RpcFutures::sendCommandRequest(Connection& connection, EntityId to,
                                        const typename T::Request& request,
                                        const Option<std::uint32_t>& timeout_millis) {

    auto p = new promise<const typename T::Response>();
    future<const typename T::Response> f = p->get_future();

    auto requestId = connection.SendCommandRequest<T>(to, request, timeout_millis);

    dispatcher.OnCommandResponse<T>([=](const CommandResponseOp<T>& op) {
        if(op.RequestId == requestId){
          if(op.StatusCode == StatusCode::kSuccess){
            cout << "success" << endl;
            p->set_value(*op.Response);
          }else{
            cout << "command response error" << op.Message << endl;
            try {
              throw std::runtime_error("Hello");
            } catch(const std::exception& e) {
              p->set_exception(std::current_exception());
            }
          }
          delete p;
        }
      });

    return f;
  }

}


