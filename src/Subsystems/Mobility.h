#ifndef MOBILITY_H
#define MOBILITY_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include <PWMTalonSRX.h>


class Mobility: public frc::PIDSubsystem {
 public:
	std::shared_ptr<frc::SpeedController> rLspeedController;
	std::shared_ptr<PWMTalonSRX> REAR_LEFT_MOTOR;
	std::shared_ptr<frc::SpeedController> fLspeedController;
	std::shared_ptr<PWMTalonSRX> fRONT_LEFT_MOTOR;
	std::shared_ptr<frc::SpeedControllerGroup> leftSpeedController;
	std::shared_ptr<frc::SpeedController> rRspeedController;
	std::shared_ptr<PWMTalonSRX> REAR_RIGHT_MOTOR;
	std::shared_ptr<frc::SpeedController> fRspeedController;
	std::shared_ptr<PWMTalonSRX> FRONT_RIGHT_MOTOR;
	std::shared_ptr<frc::SpeedControllerGroup> rightSpeedController;

	std::shared_ptr<frc::RobotDrive> robotDrive41;

	std::shared_ptr<frc::Encoder> leftEncoder;
	std::shared_ptr<frc::Encoder> rightEncoder;

	Mobility();
	double ReturnPIDInput() override;
	void UsePIDOutput(double output) override;
	void InitDefaultCommand() override;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif
