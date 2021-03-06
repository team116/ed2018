//#ifndef MOBILITY_H
#define MOBILITY_H

#define REAR_LEFT_MOTOR 1
#define REAR_RIGHT_MOTOR 2
#define FRONT_LEFT_MOTOR 3
#define FRONT_RIGHT_MOTOR 6
#define MOBILITY_LEFT_REAR_MOTOR_CONTROLLER 1
#define MOBILITY_RIGHT_FRONT_MOTOR_CONTROLLER 2
#define MOBILITY_LEFT_FRONT_MOTOR_CONTROLLER 3
#define MOBILITY_RIGHT_REAR_MOTOR_CONTROLLER 6

#include "../Robot.h"
#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include <PWMTalonSRX.h>
#include "../Log.h"
#include "Vision.h"
#include <Encoder.h>
#include <AnalogGyro.h>
#include <AnalogInput.h>

using namespace std;
using namespace frc;

class Mobility: public PIDSubsystem {
 public:
	//Speed Controller Groups
	shared_ptr<SpeedControllerGroup> leftSpeedController;
	shared_ptr<SpeedControllerGroup> rightSpeedController;

	//Speed controller are at the top, defined
	//Motor Controllers are at the top, defined

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

	void MoveDistance(float distance);

	//void Drive(float left, float right);

	float GetGyro();

	Encoder& GetLeftEncoder();

	Encoder& GetRightEncoder();

	void Reset();

	float GetDistance();

	float GetDistanceToObstacle();

private:
	SpeedControllerGroup mobilityleftSpeedController{MOBILITY_LEFT_REAR_MOTOR_CONTROLLER, MOBILITY_LEFT_FRONT_MOTOR_CONTROLLER};

	SpeedControllerGroup mobilityrightSpeedController{MOBILITY_RIGHT_REAR_MOTOR_CONTROLLER, MOBILITY_RIGHT_FRONT_MOTOR_CONTROLLER};

	DifferentialDrive mobilityRobotDrive{mobilityleftSpeedController, mobilityrightSpeedController};

	Encoder mobilityleftEncoder{1, 2, true};
	Encoder mobilityrightEncoder{3, 4, true};
	//AnalogInput {};
	//AnalogGyro {};
	double ReturnPIDInput();
	void UsePIDOutput(double output);

	//sensor toggles
	bool use_left_drive_encoder;
	bool use_right_drive_encoder;

	//manual stuff
	Timer* drive_distance_timer;
	float drive_dist_time;
	Timer* turn_degrees_timer;
	float turn_deg_time;
};

//#endif
