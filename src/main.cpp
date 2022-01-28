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
// DT_FrontLeft         motor         2               
// DT_FrontRight        motor         3               
// DT_BackLeft          motor         4               
// DT_BackRight         motor         5               
// ConvB                motor         16              
// Inertial_Sens        inertial      20              
// ForkLift             motor_group   9, 10           
// Controller1          controller                    
// FrontPistonB         digital_out   B               
// DT_FrontRight2       motor         18              
// DT_FrontLeft2        motor         19              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;
float Ch1;
float Ch2;
float Ch3;
float Ch4;



void drive(int velo, float dist, int delay) {
  DT_FrontLeft.setVelocity(velo, pct);
  DT_FrontLeft.rotateFor(forward, dist, rev, false);
  DT_FrontRight.setVelocity(velo, pct);
  DT_FrontRight.rotateFor(forward, dist, rev, false);
  DT_BackLeft.setVelocity(velo, pct);
  DT_BackLeft.rotateFor(forward, dist, rev, false);
  DT_BackRight.setVelocity(velo, pct);
  DT_BackRight.rotateFor(forward, dist, rev, false);
  DT_FrontLeft2.setVelocity(velo, pct);
  DT_FrontLeft2.rotateFor(forward, dist, rev, false);
  DT_FrontRight2.setVelocity(velo, pct);
  DT_FrontRight2.rotateFor(forward, dist, rev, true);
  wait(delay, msec);
}


void turn(int velo, float dist, int delay) {
  DT_FrontLeft.setVelocity(velo, pct);
  DT_FrontLeft.rotateFor(forward, dist, rev, false);
  DT_FrontRight.setVelocity(velo, pct);
  DT_FrontRight.rotateFor(reverse, dist, rev, false);
  DT_BackLeft.setVelocity(velo, pct);
  DT_BackLeft.rotateFor(forward, dist, rev, false);
  DT_BackRight.setVelocity(velo, pct);
  DT_BackRight.rotateFor(reverse, dist, rev, false);
  DT_FrontLeft2.setVelocity(velo, pct);
  DT_FrontLeft2.rotateFor(forward, dist, rev, false);
  DT_FrontRight2.setVelocity(velo, pct);
  DT_FrontRight2.rotateFor(forward, dist, rev, true);
  wait(delay, msec);
}


/*void strafe(float velo, float dist) {
  DT_FrontLeft.setVelocity(velo, pct);
  DT_FrontLeft.rotateFor(reverse, dist, rev);
  DT_FrontRight.setVelocity(velo, pct);
  DT_FrontRight.rotateFor(forward, dist, rev);
  DT_BackLeft.setVelocity(velo, pct);
  DT_BackLeft.rotateFor(forward, dist, rev);
  DT_BackRight.setVelocity(velo, pct);
  DT_BackRight.rotateFor(reverse, dist, rev);
}*/


void forkie(float velo, float dist) {
  ForkLift.setVelocity(velo, pct);
  ForkLift.rotateFor(forward, dist, rev);
  ForkLift.setVelocity(velo, pct);
  ForkLift.rotateFor(reverse, dist, rev);
}

// 

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

  // Michael slowly realized that the goal doesn't count for autonomous and that the 3 hours spent on 2 lines of code was completely not worth it. 
// drive(80, 2, 300);
// drive(40, 2.8, 750);
// adding separate auton files for skills and general field positions
//drive(70, -6, 0);

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
DT_FrontLeft.setVelocity(100, pct);
DT_BackLeft.setVelocity(100, pct);
DT_FrontRight.setVelocity(100, pct);
DT_BackRight.setVelocity(100, pct);
DT_FrontLeft2.setVelocity(100, pct);
DT_FrontRight2.setVelocity(100, pct);


  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................




Ch1 = Controller1.Axis1.position();
Ch2 = Controller1.Axis2.position();
Ch3 = Controller1.Axis3.position();
Ch4 = Controller1.Axis4.position();


/*DT_FrontLeft.spin(forward, Ch3 + Ch4 + Ch1, percent);
DT_BackLeft.spin(forward, Ch3 + Ch4 - Ch1, percent);
DT_FrontRight.spin(forward, Ch3 - Ch4 - Ch1, percent);
DT_BackRight.spin(forward, Ch3 - Ch4 + Ch1, percent);*/

DT_FrontLeft.spin(forward, Ch3 + Ch4, percent);
DT_BackLeft.spin(forward, Ch3 + Ch4, percent);
DT_FrontRight.spin(forward, Ch3 - Ch4, percent);
DT_BackRight.spin(forward, Ch3 - Ch4, percent);
DT_FrontLeft2.spin(forward, Ch3 + Ch4, percent);
DT_FrontRight2.spin(forward, Ch3 - Ch4, percent);

Brain.Screen.setPenColor(purple);
Brain.Screen.setCursor(1, 1);
Brain.Screen.print("FrontLeft Motor Velocity");
Brain.Screen.setPenColor(green);
Brain.Screen.setCursor(2, 1);
Brain.Screen.print(DT_FrontLeft.velocity(pct));

Brain.Screen.setPenColor(purple);
Brain.Screen.setCursor(4, 1);
Brain.Screen.print("FrontRight Motor Velocity");
Brain.Screen.setPenColor(green);
Brain.Screen.setCursor(5, 1);
Brain.Screen.print(DT_FrontRight.velocity(pct));

Brain.Screen.setPenColor(purple);
Brain.Screen.setCursor(7, 1);
Brain.Screen.print("BackLeft Motor Velocity");
Brain.Screen.setPenColor(green);
Brain.Screen.setCursor(8, 1);
Brain.Screen.print(DT_BackLeft.velocity(pct));

Brain.Screen.setPenColor(purple);
Brain.Screen.setCursor(10, 1);
Brain.Screen.print("BackRight Motor Velocity");
Brain.Screen.setPenColor(green);
Brain.Screen.setCursor(11, 1);
Brain.Screen.print(DT_BackRight.velocity(pct));



if (Controller1.ButtonR1.pressing()) {
  FrontPistonB.set(true);
}

else if (Controller1.ButtonR2.pressing()) {
  FrontPistonB.set(false);
}

else {}


    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
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
