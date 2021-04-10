using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftFront;
extern motor RightFront;
extern motor LeftBack;
extern motor RightBack;
extern motor Center;
extern motor LeftLift;
extern motor RightLift;
extern controller Controller1;
extern motor Claw;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );