#include "tesla.h"

Napi::Object Tesla::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func =
      DefineClass(env,
                 "Tesla",
                 {InstanceMethod("CarCountry", &Tesla::CarCountry),
                 InstanceMethod("CarName", &Tesla::CarName)});

  Napi::FunctionReference* constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  env.SetInstanceData(constructor);

  exports.Set("Tesla", func);
  return exports;
}

Tesla::Tesla(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Tesla>(info) {
}

Napi::Value Tesla::CarName(const Napi::CallbackInfo& info) {
  return Napi::String::New(info.Env(), Name());
}

Napi::Value Tesla::CarCountry(const Napi::CallbackInfo& info) {
  return Napi::String::New(info.Env(), Country());
}

std::string Tesla::Name() {
  return "Tesla";
}

std::string Tesla::Country() {
  return "USA";
}