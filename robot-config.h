#include "robot-config.h"
/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Arcade Control 
This program instructs your robot to use remote control values to move the robot. 

Robot Configuration:
[Smart Port]    [Name]        [Type]           [Description]       [Reversed]
Motor Port 1    LeftMotor     V5 Smart Motor    Left side motor     false
Motor Port 10   RightMotor    V5 Smart Motor    Right side motor    true
Motor Port 3    ArmMotor      V5 Smart Motor    Arm motor          false
Motor Port 8    ClawMotor     V5 Smart Motor    Claw motor         false

----------------------------------------------------------------------------------------------------*/          

int main() {
    
    //Display that the program has started to the screen.
    Brain.Screen.print("Tank Control Program Started");
    
    //Use these variables to set the speed of the arm and claw.
    int armSpeedPCT = 50;
    int clawSpeedPCT = 50;
    
    
    //Create an infinite loop so that the program can pull remote control values every iteration.
    //This loop causes the program to run forever.
    while(1) {

        //Drive Control
        //Set the left and right motor to spin forward using the controller Axis values as the velocity value.
        //Since we are using a single joystick, we will need to calculate the final volicity for each motor.
        LeftMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value())/2, vex::velocityUnits::pct); //(Axis3+Axis4)/2
        RightMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/2, vex::velocityUnits::pct);//(Axis3-Axis4)/2
  
        
		vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources.
    }

}
