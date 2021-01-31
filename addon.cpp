#include <napi.h>
#include "tesla.h"
#include "hello_world_robot.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  Tesla::Init(env, exports);
  HelloWorldRobot::Init(env, exports);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)