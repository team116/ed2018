// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef CLIMBER_H
#define CLIMBER_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include <PWMVictorSPX.h>

class Climber: public frc::PIDSubsystem {
 public:

	std::shared_ptr<PWMVictorSPX> MOTOR_CLIMBER;
	std::shared_ptr<frc::DigitalInput> climberTopLS;
	std::shared_ptr<frc::DigitalInput> climberBottomLS;
	std::shared_ptr<frc::SpeedController> climberSpeedController;
	std::shared_ptr<frc::AnalogPotentiometer> sTRING_POT;

	Climber();
	double ReturnPIDInput() override;
	void UsePIDOutput(double output) override;
	void InitDefaultCommand() override;

};

#endif
