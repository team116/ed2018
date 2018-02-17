#ifndef CLIMBER_H
#define CLIMBER_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include <PWMVictorSPX.h>
#include <../../Robot.h>

class Climber: public PIDSubsystem {
 public:

	shared_ptr<PWMVictorSPX> MOTOR_CLIMBER;
	shared_ptr<DigitalInput> climberTopLS;
	shared_ptr<DigitalInput> climberBottomLS;
	shared_ptr<SpeedController> climberSpeedController;
	shared_ptr<AnalogPotentiometer> STRING_POT;

	Climber();
	double ReturnPIDInput() override;
	void UsePIDOutput(double output) override;
	void InitDefaultCommand() override;

};

#endif
