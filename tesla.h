#pragma once

#include <napi.h>
#include "car.h"

class Tesla : public Car, public Napi::ObjectWrap<Tesla> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  Tesla(const Napi::CallbackInfo& info);
  Napi::Value CarName(const Napi::CallbackInfo& info);
  Napi::Value CarCountry(const Napi::CallbackInfo& info);

 private:
  std::string Name() override;
  std::string Country() override;
};