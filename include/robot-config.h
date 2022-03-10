using namespace vex;

extern brain Brain;

using signature = vision::signature;

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
extern digital_out BackPistonA;
extern signature Vsens__SIG_1;
extern signature Vsens__SIG_2;
extern signature Vsens__SIG_3;
extern signature Vsens__SIG_4;
extern signature Vsens__SIG_5;
extern signature Vsens__SIG_6;
extern signature Vsens__SIG_7;
extern vision Vsens;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
