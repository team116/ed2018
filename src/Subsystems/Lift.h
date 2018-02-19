//#ifndef LIFT_H
#define LIFT_H

#define LEFT_LIFT_MOTOR 11
#define RIGHT_LIFT_MOTOR 10

#define leftLiftSpeedController 11
#define rightLiftSpeedController 10

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include <PWMTalonSRX.h>
#include <Robot.h>
#include <Log.h>
#include <DigitalInput.h>

class Lift: public PIDSubsystem {
 public:
	Lift();
	double ReturnPIDInput() override;
	void UsePIDOutput(double output) override;
	void InitDefaultCommand() override;

	void MoveLift(float speed);
	void process();
	float getSpeed();

private:
	shared_ptr<DigitalInput> topLS{26, 27, 28};
	shared_ptr<DigitalInput> bottomLS{29, 30, 31};
	shared_ptr<AnalogPotentiometer> stringPot;

	SpeedControllerGroup liftSpeedController{leftLiftSpeedController, rightLiftSpeedController};

	Timer* lift_timer;
	float lift_time;

	bool use_string_pot;
};

//#endif
