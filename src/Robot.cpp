using namespace frc;
using namespace std;

#include "Robot.h"

shared_ptr<Mobility> Robot::mobility;
shared_ptr<Lift> Robot::lift;
shared_ptr<Arms> Robot::arms;
shared_ptr<Rung> Robot::rung;
shared_ptr<Climber> Robot::climber;
shared_ptr<ConveyorBelts> Robot::conveyorBelts;
shared_ptr<LEDLights> Robot::lEDLights;
shared_ptr<Vision> Robot::vision;
shared_ptr<Hook>Robot::hook;
unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	RobotMap::init();

   mobility.reset(new Mobility());
   lift.reset(new Lift());
   arms.reset(new Arms());
   rung.reset(new Rung());
   climber.reset(new Climber());
   lEDLights.reset(new LEDLights());
   conveyorBelts.reset(new ConveyorBelts());
   vision.reset(new Vision());

	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// Add commands to Autonomous Sendable Chooser
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	chooser.AddObject("pickUpCube", new pickUpCube());
	chooser.AddObject("releaseCube", new releaseCube());

	chooser.AddDefault("Autonomous Command", new AutonomousCommand());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	SmartDashboard::PutData("Auto Modes", &chooser);
}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
std::string gameData;
gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
if(gameData.length() > 0) {
	if(gameData[0] == 'L') {
		//Put left auto code here
		DriverStation::ReportError("Switch is on the left!");
	}
	else {
	//Put right auto code here
	DriverStation::ReportError("Switch is on the right!");
	}
}
if (gameData[1] == 'L') {
	DriverStation::ReportError("Scale is on the left!");
}
else {
	DriverStation::ReportError("Scale is on the right!");
}

	autonomousCommand = chooser.GetSelected();
	if (autonomousCommand != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	Log();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand != nullptr) {
		autonomousCommand->Cancel();
	}
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	Log();
	lift->Periodic();
	oi->process();
	conveyorBelts->Periodic();
}

void Robot::TestPeriodic() {}

void Robot::DisabledInit() {

}
START_ROBOT_CLASS(Robot);

