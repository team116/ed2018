#ifndef LIFT_H
#define LIFT_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include <PWMTalonSRX.h>

class Lift: public frc::PIDSubsystem {
 public:
	std::shared_ptr<PWMTalonSRX> MOTOR_LIFT;

	std::shared_ptr<frc::SpeedController> liftSpeedController;

	std::shared_ptr<frc::DigitalInput> topLS;
	std::shared_ptr<frc::DigitalInput> bottomLS;
	std::shared_ptr<frc::AnalogPotentiometer> stringPot;

	Lift();
	double ReturnPIDInput() override;
	void UsePIDOutput(double output) override;
	void InitDefaultCommand() override;
};

#endif
