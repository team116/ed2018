using namespace frc;
using namespace std;

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
#include "OI.h"

#include <Drive\DifferentialDrive.h>

class Robot : public TimedRobot {
public:
	Command* autonomousCommand = nullptr;
	static unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();
	SendableChooser<Command*> chooser;

	static shared_ptr<Mobility> mobility;
	static shared_ptr<Lift> lift;
	static shared_ptr<Arms> arms;
	static shared_ptr<Rung> rung;
	static shared_ptr<Climber> climber;
	static shared_ptr<LEDLights> lEDLights;
	static shared_ptr<ConveyorBelts> conveyorBelts;
	static shared_ptr<Vision> vision;

	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
};
#endif
