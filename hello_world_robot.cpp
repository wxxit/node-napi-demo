#include "hello_world_robot.h"

HelloWorldRobot::HelloWorldRobot(const Napi::CallbackInfo& info) : Napi::ObjectWrap<HelloWorldRobot>(info) {
}

Napi::Object HelloWorldRobot::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func =
      DefineClass(env,
                 "HelloWorldRobot",
                 {InstanceMethod("Say", &HelloWorldRobot::Say)});

  Napi::FunctionReference* constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  env.SetInstanceData(constructor);

  exports.Set("HelloWorldRobot", func);
  return exports;
}

void HelloWorldRobot::Say(const Napi::CallbackInfo& info) {
  Napi::Function cb = info[0].As<Napi::Function>();
  cb.Call(info.Env().Global(), {Napi::String::New(info.Env(), "hello world")});
}