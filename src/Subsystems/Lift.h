#ifndef LIFT_H
#define LIFT_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include <PWMTalonSRX.h>
#include <Robot.h>
#include <Log.h>

class Lift: public PIDSubsystem {
 public:
	shared_ptr<PWMTalonSRX> MOTOR_LIFT;

	shared_ptr<SpeedController> liftSpeedController;

	shared_ptr<DigitalInput> topLS;
	shared_ptr<DigitalInput> bottomLS;
	shared_ptr<AnalogPotentiometer> stringPot;

	Lift();
	double ReturnPIDInput() override;
	void UsePIDOutput(double output) override;
	void InitDefaultCommand() override;
};

#endif
