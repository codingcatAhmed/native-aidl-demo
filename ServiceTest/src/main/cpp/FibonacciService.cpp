#include "include/com/example/fibonacciservice/IFibonacciService.h"
#include "include/com/example/fibonacciservice/BnFibonacciService.h"
#include "include/com/example/fibonacciservice/BpFibonacciService.h"
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

using namespace android;
namespace com {
namespace example {
namespace fibonacciservice {

class FibonacciService : public BnFibonacciService {
 public:
  static void instantiate();

  // Implement the method stubs for the AIDL interface.
  ::android::binder::Status fibR(int32_t n, int32_t* _aidl_return) override;
  ::android::binder::Status fibL(int32_t n, int32_t* _aidl_return) override;

 private:
  // Calculate the Fibonacci number using a recursive algorithm.
  int32_t fibRHelper(int32_t n);
  // Calculate the Fibonacci number using a linear algorithm.
  int32_t fibLHelper(int32_t n);
};

}  // namespace fibonacciservice

}  // namespace example

}  // namespace com

using namespace android;
using namespace com::example::fibonacciservice;


void FibonacciService::instantiate() {
  defaultServiceManager()->addService(
      IFibonacciService::descriptor, new FibonacciService());
}

::android::binder::Status FibonacciService::fibR(int32_t n, int32_t* _aidl_return) {
  std::cout << "fibR is called" << std::endl;
  *_aidl_return = fibRHelper(n);
  return ::android::binder::Status::ok();
}

int32_t FibonacciService::fibRHelper(int32_t n) {
  if (n <= 0) return 0;
  if (n == 1) return 1;
  return fibRHelper(n - 1) + fibRHelper(n - 2);
}

::android::binder::Status FibonacciService::fibL(int32_t n, int32_t* _aidl_return) {
  std::cout << "fibR is called" << std::endl;
  *_aidl_return = fibLHelper(n);
  return ::android::binder::Status::ok();
}

int32_t FibonacciService::fibLHelper(int32_t n) {
  if (n <= 0) return 0;
  int32_t a = 0, b = 1;
  for (int32_t i = 1; i < n; ++i) {
    int32_t tmp = a + b;
    a = b;
    b = tmp;
  }
  return b;
}

int main(int argc, char *argv[]) {

    std::cout << "Fibonacci service has started" << std::endl;
    sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm = defaultServiceManager();
    sm->addService(String16("com.example.fibonacciservice.FibonacciService"), new FibonacciService());
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    return 0;
}
