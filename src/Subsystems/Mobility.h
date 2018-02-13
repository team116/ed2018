#ifndef MOBILITY_H
#define MOBILITY_H

#include <Robot.h>
#include <../Robot.h>
#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include <PWMTalonSRX.h>
#include <Log.h>
#include <Vision.h>
#include <Encoder.h>
#include <AnalogGyro.h>
#include <AnalogInput.h>

class Mobility: public PIDSubsystem {
 public:
	//Speed Controller Groups
	shared_ptr<SpeedControllerGroup> leftSpeedController;
	shared_ptr<SpeedControllerGroup> rightSpeedController;

	//Speed Controllers
	shared_ptr<SpeedController> rLspeedController;
	shared_ptr<SpeedController> fLspeedController;
	shared_ptr<SpeedController> rRspeedController;
	shared_ptr<SpeedController> fRspeedController;

	//Motor Controllers
	shared_ptr<PWMTalonSRX> REAR_LEFT_MOTOR;
	shared_ptr<PWMTalonSRX> FRONT_LEFT_MOTOR;
	shared_ptr<PWMTalonSRX> REAR_RIGHT_MOTOR;
	shared_ptr<PWMTalonSRX> FRONT_RIGHT_MOTOR;

	shared_ptr<RobotDrive> robotDrive;

	//Sensors
	shared_ptr<Encoder> leftEncoder;
	shared_ptr<Encoder> rightEncoder;
	shared_ptr<Gyro> analogGyro;
	//add infrared sensors

	//Other Variables
	/*float straight_speed;
	bool is_turn_degrees_on;
	bool driving_straight;
	bool is_drive_distance_on;*/

	Mobility();
	void process();

	void InitDefaultCommand();

	void TankDrive(float left, float right);

	void Log();

	//void Drive(float left, float right);

	float GetGyro();

	Encoder& GetLeftEncoder();

	Encoder& GetRightEncoder();

	void Reset();

	float GetDistance();

	float GetDistanceToObstacle();

private:
	PWMTalonSRX mobilityRLspeedController{4};
	PWMTalonSRX mobilityFLspeedController{3};
	SpeedControllerGroup mobilityleftSpeedController{mobilityRLspeedController, mobilityFLspeedController};

	PWMTalonSRX mobilityRRspeedController{5};
	PWMTalonSRX mobilityFRspeedController{6};
	SpeedControllerGroup mobilityrightSpeedController{mobilityRRspeedController, mobilityFRspeedController};

	DifferentialDrive mobilityRobotDrive{mobilityleftSpeedController, mobilityrightSpeedController};

	Encoder mobilityleftEncoder{1, 2, true};
	Encoder mobilityrightEncoder{3, 4, false};
	//AnalogInput {};
	//AnalogGyro {};
	double ReturnPIDInput();
	void UsePIDOutput(double output);
};

#endif
