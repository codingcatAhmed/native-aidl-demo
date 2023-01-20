#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <com/example/fibonacciservice/IFibonacciService.h>

namespace com {

namespace example {

namespace fibonacciservice {

class BpFibonacciService : public ::android::BpInterface<IFibonacciService> {
public:
  explicit BpFibonacciService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpFibonacciService() = default;
  ::android::binder::Status fibR(int32_t n, int32_t* _aidl_return) override;
  ::android::binder::Status fibL(int32_t n, int32_t* _aidl_return) override;
};  // class BpFibonacciService

}  // namespace fibonacciservice

}  // namespace example

}  // namespace com
