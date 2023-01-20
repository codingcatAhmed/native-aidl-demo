#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace com {

namespace example {

namespace fibonacciservice {

class IFibonacciService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(FibonacciService)
  virtual ::android::binder::Status fibR(int32_t n, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status fibL(int32_t n, int32_t* _aidl_return) = 0;
};  // class IFibonacciService

class IFibonacciServiceDefault : public IFibonacciService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status fibR(int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fibL(int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IFibonacciServiceDefault

}  // namespace fibonacciservice

}  // namespace example

}  // namespace com
