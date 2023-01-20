#pragma once

#include <binder/IInterface.h>
#include "IFibonacciService.h"


namespace com {

namespace example {

namespace fibonacciservice {


class BnFibonacciService : public ::android::BnInterface<IFibonacciService> {
public:
  static constexpr uint32_t TRANSACTION_fibR = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_fibL = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnFibonacciService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnFibonacciService

}  // namespace fibonacciservice

}  // namespace example

}  // namespace com
