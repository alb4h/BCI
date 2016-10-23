/**
 * This is a tuorial for how to use the basic features of velocityPID. For
 * extra reference, see BCI\Modules\Core\velocityPID.h
 */

//We will have a quadrature encoder for the PID controller to run off of and a
//motor to control the robot
#pragma config(Sensor, dgtl7,  myQuad,  sensorQuadEncoder)
#pragma config(Motor,  port2,   myMotor, tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "..\..\BCI.h"

vel_PID myPID; //Make a pid controller

task main()
{
  //Initialize our pid controller with sensor myQuad and gains
  //kP = 1, kI = 2, and kD = 3
  vel_PID_InitController(&myPID, myQuad, 1, 2, 3);

  //Set the target velocity for our pid controller
  vel_PID_SetTargetVelocity(&myPID, 10);

  //Run our motor with the output of the pid controller
  motor[myMotor] = vel_PID_StepController(&myPID);
}
