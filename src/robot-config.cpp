#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor DT_FrontLeft = motor(PORT2, ratio18_1, false);
motor DT_FrontRight = motor(PORT3, ratio18_1, true);
motor DT_BackLeft = motor(PORT4, ratio18_1, false);
motor DT_BackRight = motor(PORT5, ratio18_1, true);
motor ConvB = motor(PORT16, ratio18_1, false);
inertial Inertial_Sens = inertial(PORT20);
motor ForkLiftMotorA = motor(PORT9, ratio36_1, true);
motor ForkLiftMotorB = motor(PORT10, ratio36_1, false);
motor_group ForkLift = motor_group(ForkLiftMotorA, ForkLiftMotorB);
controller Controller1 = controller(primary);
digital_out FrontPistonB = digital_out(Brain.ThreeWirePort.B);
motor DT_FrontRight2 = motor(PORT18, ratio18_1, false);
motor DT_FrontLeft2 = motor(PORT19, ratio18_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1LeftShoulderControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // check the ButtonL1/ButtonL2 status to control ForkLift
      if (Controller1.ButtonL1.pressing()) {
        ForkLift.spin(forward);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        ForkLift.spin(reverse);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1LeftShoulderControlMotorsStopped) {
        ForkLift.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1LeftShoulderControlMotorsStopped = true;
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}