#include "../gen-cpp/Calculator.h"
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <iostream>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

int main() {
    ::std::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
    ::std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    ::std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

    tutorial::CalculatorClient client(protocol);
    transport->open();

    int32_t sum = client.add(10, 20);
    std::cout << "Result of add: " << sum << std::endl;

    int32_t diff = client.subtract(30, 15);
    std::cout << "Result of subtract: " << diff << std::endl;

    transport->close();

    return 0;
}
