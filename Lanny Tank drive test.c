#pragma config(Motor,  port1,           ArmMotor,      tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           LF,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           LB,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           RF,            tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RB,            tmotorVex393HighSpeed_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
		while (1==1)
	{
		motor[LF] = vexRT[Ch3];
		motor[LB] = vexRT[Ch3];
		motor[RF] = vexRT[Ch2];
		motor[RB] = vexRT[Ch2];


		if(vexRT(Btn5D) ==1)
		{
			motor[ArmMotor] = 127;
		}
		else if (vexRT(Btn5U) ==1)
		{
			motor[ArmMotor] = -127;
		}
		else
		{
			motor[ArmMotor] = 0;
		}
	}
}



