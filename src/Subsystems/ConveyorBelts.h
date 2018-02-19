//#ifndef CONVEYORBELTS_H
#define CONVEYORBELTS_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ConveyorBelts: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities

	shared_ptr<WPI_VictorSPX> MOTOR_LEFT_CON_BELT{8};
	shared_ptr<WPI_VictorSPX> MOTOR_RIGHT_CON_BELT{7};
	shared_ptr<frc::SpeedController> leftConBeltSpeedController{8};
	shared_ptr<frc::SpeedController> rightConBeltSpeedController{7};
	//std::shared_ptr<frc::DifferentialDrive> differentialDrive2;

	shared_ptr<frc::DigitalInput> leftConBeltLS{35, 36, 37};
	shared_ptr<frc::DigitalInput> rightConBeltLS{32, 33, 34};

public:
	ConveyorBelts();
	void InitDefaultCommand() override;
	void Periodic() override;

	void StopLeftConBelt();
	void StopRightConBelt();
};

//#endif
