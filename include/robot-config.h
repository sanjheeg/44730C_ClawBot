using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern bumper liftBumper;
extern motor center;
extern motor rightLift;
extern motor claw;
extern motor rightFront;
extern motor rightBack;
extern motor leftBack;
extern motor leftFront;
extern motor leftLift;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
