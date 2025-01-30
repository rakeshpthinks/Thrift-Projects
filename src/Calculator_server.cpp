#include "./../gen-cpp/Calculator.h"
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <iostream>


using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

class CalculatorHandler : public tutorial::CalculatorIf {
public:
    int32_t add(int32_t num1, int32_t num2) override {
        std::cout << "Adding: " << num1 << " + " << num2 << std::endl;
        return num1 + num2;
    }

    int32_t subtract(int32_t num1, int32_t num2) override {
        std::cout << "Subtracting: " << num1 << " - " << num2 << std::endl;
        return num1 - num2;
    }
};


int main() {
    int port = 9090;
    ::std::shared_ptr<CalculatorHandler> handler(new CalculatorHandler());
    ::std::shared_ptr<TProcessor> processor(new tutorial::CalculatorProcessor(handler));
    ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    std::cout << "Starting the server on port " << port << "..." << std::endl;
    server.serve();

    return 0;
}
