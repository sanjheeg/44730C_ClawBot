/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// liftBumper           bumper        A               
// center               motor         2               
// rightLift            motor         3               
// claw                 motor         16              
// rightFront           motor         15              
// rightBack            motor         14              
// leftBack             motor         13              
// leftFront            motor         11              
// leftLift             motor         12              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

void pre_auton(void) {
  vexcodeInit();
}

//START OF ROBOT CONTROL FUNCTIONS.......................................................................... 
void YMove(){
  //move forward and backward
  rightFront.spin(fwd, (Controller1.Axis3.position()) * 0.75, pct);
  leftFront.spin(fwd, (Controller1.Axis3.position()) * 0.75, pct);
  rightBack.spin(fwd, (Controller1.Axis3.position()) * 0.75, pct);
  leftBack.spin(fwd, (Controller1.Axis3.position()) * 0.75, pct);
}

void XMove(){
  //strafe left and right
  center.spin(fwd, (Controller1.Axis4.position()) * 3, pct);
}

void liftMove(){
  if(liftBumper.pressing()){
    rightLift.stop();
    leftLift.stop();
  } else{ 
    rightLift.spin(fwd, (Controller1.Axis2.position()) * 0.25, pct);
    leftLift.spin(fwd, (Controller1.Axis2.position()) * 0.25, pct);
  }
}

void clawMove(){
  claw.spin(fwd, (Controller1.Axis1.position()) * 0.25, pct);
}


void turnRight(){
  rightFront.stop();
  rightBack.stop();
  leftBack.spin(fwd, 50, pct);
  leftFront.spin(fwd, 50, pct);
}

void turnLeft(){
  leftFront.stop();
  leftBack.stop();
  rightBack.spin(fwd, 50, pct);
  rightFront.spin(fwd, 50, pct);
}

void moveStop(){
  rightFront.stop();
  leftFront.stop();
  rightBack.stop();
  leftBack.stop();
}

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    YMove();
    XMove();
    liftMove();
    clawMove();

    if(Controller1.ButtonA.pressing()){
      turnRight();
    } else if(Controller1.ButtonY.pressing()){
      turnLeft();
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}


int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
