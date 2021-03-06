#include "movetoScaleNeutral.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

movetoScaleNeutral::movetoScaleNeutral(double setpoint): Command() {
    m_setpoint = setpoint;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::lift.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void movetoScaleNeutral::Initialize() {
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZE
    Robot::lift->Enable();
    Robot::lift->SetSetpoint(m_setpoint);
        // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZE
}

// Called repeatedly when this Command is scheduled to run
void movetoScaleNeutral::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool movetoScaleNeutral::IsFinished() {
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ISFINISHED
    return Robot::lift->OnTarget();
        // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ISFINISHED
}

// Called once after isFinished returns true
void movetoScaleNeutral::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void movetoScaleNeutral::Interrupted() {

}
