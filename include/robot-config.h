using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor DT_FrontLeft;
extern motor DT_FrontRight;
extern motor DT_BackLeft;
extern motor DT_BackRight;
extern motor ConvB;
extern inertial Inertial_Sens;
extern motor_group ForkLift;
extern controller Controller1;
extern digital_out FrontPistonB;
extern motor DT_FrontRight2;
extern motor DT_FrontLeft2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );

// this file is apparently important, me don't know why, but me know that it has a use and me understand that me don't understand.
