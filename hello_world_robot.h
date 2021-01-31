#pragma once

#include <napi.h>
#include <thread>

class HelloWorldRobot : public Napi::ObjectWrap<HelloWorldRobot> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  HelloWorldRobot(const Napi::CallbackInfo& info);
  void Say(const Napi::CallbackInfo& info);
 private:
  int say_count_ {10};
};