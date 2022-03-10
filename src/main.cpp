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
// ForkLift             motor_group   10, 9           
// Controller1          controller                    
// FrontPistonB         digital_out   B               
// DT_FrontRight2       motor         18              
// DT_FrontLeft2        motor         19              
// BackPistonA          digital_out   C               
// Vsens                vision        1               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "vsens.h"

using namespace vex;

// A global instance of competition
competition Competition;
float Ch1;
float Ch2;
float Ch3;
float Ch4;

bool front_piston_status = true;
bool back_piston_status = true;

event checkRed = event();
event checkBlue = event();
event checkYellow = event();

void hasBlueCallback() {
  Brain.Screen.setFont(mono40);
  Brain.Screen.clearLine(1, black);
  Brain.Screen.setCursor(Brain.Screen.row(), 1);
  Brain.Screen.setCursor(1, 1);
  Vsens.takeSnapshot(NGOAL);
  if (Vsens.objectCount > 0) {
    Brain.Screen.print("Blue Object Found");
  } else {
    Brain.Screen.print("No Blue Object");
  }
}

void hasRedCallback() {
  Brain.Screen.setFont(mono40);
  Brain.Screen.clearLine(3, black);
  Brain.Screen.setCursor(Brain.Screen.row(), 1);
  Brain.Screen.setCursor(3, 1);
  Vsens.takeSnapshot(RGOAL);
  if (Vsens.objectCount > 0) {
    Brain.Screen.print("Red Object Found");
  } else {
    Brain.Screen.print("No Red Object");
  }
}

void hasYellowCallback() {
  Brain.Screen.setFont(mono40);
  Brain.Screen.clearLine(5, black);
  Brain.Screen.setCursor(Brain.Screen.row(), 1);
  Brain.Screen.setCursor(5, 1);
  Vsens.takeSnapshot(BGOAL);
  if (Vsens.objectCount > 0) {
    Brain.Screen.print("Green Object Found");
  } else {
    Brain.Screen.print("No Green Object");
  }
}

  

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


// skills autonomous framework

///
///
///

// Red-Goal Vision Sensor Autonomous Locator (VSAL)
void VRdrive(float delay, int dir, int prp) {
  Vsens.takeSnapshot(RGOAL);
  int error = abs(Vsens.largestObject.centerX - 150);
  float velo = (error * dir * 100) / prp;
  while(error > 5) {
    DT_FrontLeft.spin(reverse, velo, pct);
    DT_FrontRight.spin(forward, velo, pct);
    DT_BackLeft.spin(reverse, velo, pct);
    DT_BackRight.spin(forward, velo, pct);
    DT_FrontLeft2.spin(reverse, velo, pct);
    DT_FrontRight2.spin(forward, velo, pct);
    wait(delay, msec);
    Vsens.takeSnapshot(RGOAL);
    error = abs(Vsens.objects[0].centerX - 160);
    velo = (error * 100) / prp;
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print(error);
  }
    DT_FrontLeft.stop(brake);
    DT_FrontRight.stop(brake);
    DT_FrontLeft2.stop(brake);
    DT_FrontRight2.stop(brake);
    DT_BackLeft.stop(brake);
    DT_BackRight.stop(brake);
}

///
///
///

// Blue-Goal Vision Sensor Autonomous Locator (VSAL)
void VBdrive(float delay, int dir, int prp) {
  Vsens.takeSnapshot(BGOAL);
  int error = abs(Vsens.largestObject.centerX - 150);
  float velo = (error * dir * 100) / prp;
  while(error > 5) {
    DT_FrontLeft.spin(reverse, velo, pct);
    DT_FrontRight.spin(forward, velo, pct);
    DT_BackLeft.spin(reverse, velo, pct);
    DT_BackRight.spin(forward, velo, pct);
    DT_FrontLeft2.spin(reverse, velo, pct);
    DT_FrontRight2.spin(forward, velo, pct);
    wait(delay, msec);
    Vsens.takeSnapshot(BGOAL);
    error = abs(Vsens.objects[0].centerX - 160);
    velo = (error * 100) / prp;
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print(error);
  }
    DT_FrontLeft.stop(brake);
    DT_FrontRight.stop(brake);
    DT_FrontLeft2.stop(brake);
    DT_FrontRight2.stop(brake);
    DT_BackLeft.stop(brake);
    DT_BackRight.stop(brake);
}

///
///
///

// Neutral-Goal Vision Sensor Autonomous Locator (VSAL)
void VNdrive(float delay, int dir, int prp) {
  Vsens.takeSnapshot(NGOAL);
  int error = abs(Vsens.largestObject.centerX - 150);
  float velo = (error * dir * 100) / prp;
  while(error > 5) {
    DT_FrontLeft.spin(reverse, velo, pct);
    DT_FrontRight.spin(forward, velo, pct);
    DT_BackLeft.spin(reverse, velo, pct);
    DT_BackRight.spin(forward, velo, pct);
    DT_FrontLeft2.spin(reverse, velo, pct);
    DT_FrontRight2.spin(forward, velo, pct);
    wait(delay, msec);
    Vsens.takeSnapshot(NGOAL);
    error = abs(Vsens.objects[0].centerX - 160);
    velo = (error * 100) / prp;
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print(error);
  }
    DT_FrontLeft.stop(brake);
    DT_FrontRight.stop(brake);
    DT_FrontLeft2.stop(brake);
    DT_FrontRight2.stop(brake);
    DT_BackLeft.stop(brake);
    DT_BackRight.stop(brake);
}

///
///
///

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
  DT_FrontRight2.rotateFor(reverse, dist, rev, true);
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

void forkie(int velo, float dist, int delay) {
  ForkLift.setVelocity(velo, pct);
  ForkLift.rotateFor(forward, dist, rev);
  ForkLift.setVelocity(velo, pct);
  // ForkLift.rotateFor(reverse, dist, rev);
  wait(delay, msec);
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
/*                                                                     Autonomous Task                              */
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
  

  // current skills autonomous
  VNdrive(10, 1, 800);
  //turn(30, 1, 200);
  //VNdrive(10, -1, 800);
  /*drive(100, -3.600, 0);
  drive(40, -1.500, 0);
  BackPistonA.set(true);
  wait(300, msec);
  drive(90, 4.000, 100);
  turn(50, 1.050, 1000);
  drive(30, -4.400, 10);*/
  

  ///
  ///
  ///


  // current left-side field autonomous
  /*drive(100, -3.300, 100);
  drive(40, -1.100, 100);
  BackPistonA.set(true);
  wait(250, msec);
  // BackPistonA.set(false);
  // wait(100, msec);
  // BackPistonA.set(true);
  // wait(200, msec);
  drive(85, 4.000, 500);*/


  ///
  ///
  ///


  // current right-side field autonomous
  /*drive(100, -3.300, 100);
  drive(40, -1.100, 100);
  BackPistonA.set(true);
  wait(150, msec);
  // BackPistonA.set(false);
  // wait(100, msec);
  // BackPistonA.set(true);
  // wait(150, msec);
  drive(85, 4.000, 500);*/


  ///
  ///
  ///


  // previous left-side field autonomous
  /*drive(30, -1.000, 200);
  forkie(30, 0.3, 200);*/

  // previous right-side field autonomous
  /*drive(75, -3.750, 300);
  forkie(50, 0.300, 300);
  drive(80, 4.000, 500);*/


  // ancient left-side autonomous (will almost never be used again, it is here for the purpose of remembering our past)
  // FrontPistonB.set(false);
  // drive(40, 2.8, 750);
  // drive(70, -6, 0);

  // FrontPistonB.set(true);
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

    // Vsens
    checkBlue.broadcastAndWait();
    checkRed.broadcastAndWait();
    checkYellow.broadcastAndWait();


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



    if (Controller1.ButtonR1.pressing() && front_piston_status == true) {
      FrontPistonB.set(false);
      wait(200, msec);
      front_piston_status = false;
    } else if (Controller1.ButtonR1.pressing() && front_piston_status == false) {
      FrontPistonB.set(true);
      wait(200, msec);
      front_piston_status = true;
    } else {}

    if (Controller1.ButtonR2.pressing() && back_piston_status == true) {
      BackPistonA.set(false);
      wait(200, msec);
      back_piston_status = false;
    } else if (Controller1.ButtonR2.pressing() && back_piston_status == false) {
      BackPistonA.set(true);
      wait(200, msec);
      back_piston_status = true;
    } else {}


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
