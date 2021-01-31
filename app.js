const addon = require('./build/Release/node_napi_demo.node');
const Tesla = addon.Tesla;
const HelloWorldRobot = addon.HelloWorldRobot;

const TeslaCar = new Tesla();
console.log(TeslaCar.CarName());
console.log(TeslaCar.CarCountry());

const HelloWorldRobotInstance = new HelloWorldRobot();


HelloWorldRobotInstance.Say((msg)=>{
  console.log(msg);
});
