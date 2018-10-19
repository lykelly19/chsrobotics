#pragma config(Motor,  motor1,          RFMotor,       tmotorVexIQ, openLoop, driveRight)
#pragma config(Motor,  motor2,          LFMotor,       tmotorVexIQ, openLoop, reversed, driveLeft)
#pragma config(Motor,  motor3,          RBMotor,       tmotorVexIQ, openLoop, driveRight)
#pragma config(Motor,  motor4,          LBMotor,       tmotorVexIQ, openLoop, reversed, driveLeft)
#pragma config(Motor,  motor5,          ArmMotor,      tmotorVexIQ, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

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

task autonomous()
{
	//this code assumes you're on the right side

	// rotate to the left
	motor[ArmMotor] = 20;
	wait1Msec(1500);
	motor[ArmMotor] = 0;
	motor[LBMotor] = 63;  //currently for time
	wait1Msec(2500);
	motor[LBMotor] = 0;
	
	//move forward a bit
	motor[LBMotor] = 63;
	motor[RBMotor] = 63;
	motor[LFMotor] = 63;
	motor[RFMotor] = 63;
	wait1MSec(1000);

	// rotate to the right
	motor[RBMotor] = -63;  //currently for time
	wait1Msec(2500);
	motor[RBMotor] = 0;

// this code assumes you're on the left side
/*motor[RBMotor] = 63;  //currently for time
	wait1Msec(2500);
	motor[RBMotor] = 0;
	
	//move forward a bit
	motor[LBMotor] = 63;
	motor[RBMotor] = 63;
	motor[RFMotor] = 63;
	motor[LFMotor] = 63;
	wait1MSec(1000);

	motor[LBMotor] = -63;  //currently for time
	wait1Msec(2500);
	motor[LBMotor] = 0; */

	// move forward

	motor[port1] = 63;
	motor[port2] = 63;
	motor[port3] = 63;
  	motor[port4] = 63;
	wait1MSec(3000);
	motor[port1] = 0;
	motor[port2] = 0;
	motor[port3] = 0;
  	motor[port4] = 0;
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

task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
  
  	motor[LBMotor] = vexRT[Ch2];
  	motor[LFMotor] = vexRT[Ch2];
  	motor[RBMotor] = vexRT[Ch3];
  	motor[RLMotor] = vexRT[Ch3];
	  
	if(vexRT[Btn8U] == 1){
	   motor[ArmMotor] = 63;   
	}
	else if(vexRT[Btn8D] == 1){
	   motor[ArmMotor] = -63;
	}
	else{
	   motor[ArmMotor] = 0;
	}

	  
  }
}
