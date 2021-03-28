#include "vex.h"

using namespace vex;

competition Competition;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}

void autonomous(void) {
  
}

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {

    wait(20, msec); 
  }
}


  // move forward
  void forward() {
    LeftFront.spin(directionType::fwd, 100, pct);
    LeftBack.spin(directionType::fwd, 100, pct);
    RightFront.spin(directionType::fwd, 100, pct);
    RightBack.spin(directionType::fwd, 100, pct);
  }

  // move reverse
  void reverse() {
    LeftFront.spin(directionType::rev, 100, pct);
    LeftBack.spin(directionType::rev, 100, pct);
    RightFront.spin(directionType::rev, 100, pct);
    LeftBack.spin(directionType::rev, 100, pct);
  }
  
  // move right
  void right() {
  Center.spin(directionType::rev, 100, pct);
  }

  // move left
  void left() {  
    Center.spin(directionType::fwd, 100, pct);
  }


int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  
  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
