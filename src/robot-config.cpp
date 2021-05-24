#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
bumper liftBumper = bumper(Brain.ThreeWirePort.A);
motor center = motor(PORT2, ratio18_1, false);
motor rightLift = motor(PORT3, ratio36_1, true);
motor claw = motor(PORT16, ratio18_1, false);
motor rightFront = motor(PORT15, ratio18_1, true);
motor rightBack = motor(PORT14, ratio18_1, true);
motor leftBack = motor(PORT13, ratio18_1, false);
motor leftFront = motor(PORT11, ratio18_1, false);
motor leftLift = motor(PORT12, ratio36_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
