#include <iostream>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

#include <com/example/fibonacciservice/IFibonacciService.h>

using namespace android;
using namespace com::example::fibonacciservice;

int main(int argc, char *argv[]) {
  std::cout << "fibonacci client started" << std::endl;
  sp<IServiceManager> sm = defaultServiceManager();
  sp<IBinder> binder = sm->getService(String16("com.example.fibonacciservice.FibonacciService"));
  sp<IFibonacciService> service = interface_cast<IFibonacciService>(binder);

  // Call the fibonacci service to calculate Fibonacci number.
  int32_t result;
  service->fibR(5, &result);
  std::cout << "Result of fibR(5): " << result << std::endl;
  service->fibR(10, &result);
  std::cout << "Result of fibR(10): " << result << std::endl;

  service->fibL(5, &result);
  std::cout << "Result of fibL(5): " << result << std::endl;
  service->fibL(16, &result);
  std::cout << "Result of fibL(16): " << result << std::endl;

  // Clean up resources and exit.
  IPCThreadState::self()->flushCommands();
  return 0;
}
