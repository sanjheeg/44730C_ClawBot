// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftFront            motor         1               
// RightFront           motor         2               
// LeftBack             motor         3               
// RightBack            motor         4               
// Center               motor         5               
// LeftLift             motor         6               
// RightLift            motor         7               
// Controller1          controller                    
// Claw                 motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftFront            motor         1               
// RightFront           motor         2               
// LeftBack             motor         3               
// RightBack            motor         4               
// Center               motor         5               
// LeftLift             motor         6               
// RightLift            motor         7               
// Controller1          controller                    
// Claw                 motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
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
// LeftFront            motor         1               
// RightFront           motor         2               
// LeftBack             motor         3               
// RightBack            motor         4               
// Center               motor         5               
// LeftLift             motor         6               
// RightLift            motor         7               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
//
// Main will set up the competition functions and callbacks.
//

  // move forward

  void moveForward() {

    LeftFront.spin(directionType::fwd, 100, pct);
    LeftBack.spin(directionType::fwd, 100, pct);
    RightFront.spin(directionType::fwd, 100, pct);
    RightBack.spin(directionType::fwd, 100, pct);

  }

  // move reverse


  void moveReverse() {

    LeftFront.spin(directionType::rev, 100, pct);
    LeftBack.spin(directionType::rev, 100, pct);
    RightFront.spin(directionType::rev, 100, pct);
    LeftBack.spin(directionType::rev, 100, pct);

  }
  // move right

  void strafeRight() {

   

  Center.spin(directionType::rev, 100, pct);

  }

  // move left

  void strafeLeft() {

    

    Center.spin(directionType::fwd, 100, pct);
  }
  void turnRight(){
    LeftFront.spin(fwd,100,pct);
    LeftBack.spin(fwd,100,pct);
    RightFront.spin(reverse,100,pct);
    RightBack.spin(reverse,100,pct);
  }
  void turnLeft(){
    LeftFront.spin(reverse,100,pct);
    LeftBack.spin(reverse,100,pct);
    RightFront.spin(fwd,100,pct);
    RightBack.spin(fwd,100,pct);
  }
  void lift() {
    LeftLift.spin(fwd,50,pct);
    RightLift.spin(directionType::rev,50,pct);
  }
  void lower() {
    LeftLift.spin(directionType::rev,50,pct);
    RightLift.spin(directionType::fwd,50,pct);
  }

void openClaw() {
  Claw.spin(fwd, 100, pct);
}

void closeClaw() {
  Claw.spin(directionType::rev, 100, pct);
}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {

    if (Controller1.ButtonA.pressing()){
      openClaw();
    }

    else if (Controller1.ButtonB.pressing()){
      closeClaw();
    }

    else {
      Claw.stop();
    }


    if (Controller1.ButtonX.pressing()){
      lift();
    }
    else if (Controller1.ButtonB.pressing()){
      lower();
    }
    else {
      LeftLift.stop(brakeType::hold);
      RightLift.stop(brakeType::hold);
    }

    if(Controller1.ButtonUp.pressing()){
      moveForward();
    }
    else if(Controller1.ButtonDown.pressing()){
      moveReverse();
    }
    else if(Controller1.ButtonLeft.pressing()){
      turnLeft();
    }
    else if(Controller1.ButtonRight.pressing()){
      turnRight();
    }
    else{
      RightFront.stop();
      RightBack.stop();
      LeftFront.stop();
      LeftBack.stop();
    }
    if(Controller1.ButtonY.pressing()){
      strafeLeft();
    }
    else if(Controller1.ButtonY.pressing()){
      strafeRight();
    }
    else{
      Center.stop();
    }

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}


 
int main() {

  
  


  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
