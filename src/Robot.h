// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

#include "Commands/AutonomousCommand.h"
#include "Commands/pickUpCube.h"
#include "Commands/releaseCube.h"
#include "Subsystems/Arms.h"
#include "Subsystems/Climber.h"
#include "Subsystems/ConveyorBelts.h"
#include "Subsystems/LEDLights.h"
#include "Subsystems/Lift.h"
#include "Subsystems/Mobility.h"
#include "Subsystems/Rung.h"
#include "Subsystems/Vision.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "OI.h"

class Robot : public frc::TimedRobot {
public:
	frc::Command* autonomousCommand = nullptr;
	static std::unique_ptr<OI> oi;
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	frc::SendableChooser<frc::Command*> chooser;

	static std::shared_ptr<Mobility> mobility;
	static std::shared_ptr<Lift> lift;
	static std::shared_ptr<Arms> arms;
	static std::shared_ptr<Rung> rung;
	static std::shared_ptr<Climber> climber;
	static std::shared_ptr<LEDLights> lEDLights;
	static std::shared_ptr<ConveyorBelts> conveyorBelts;
	static std::shared_ptr<Vision> vision;

	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
};
#endif
