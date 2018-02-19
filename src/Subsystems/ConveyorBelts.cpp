#include "ctre/Phoenix.h"


#include "ConveyorBelts.h"
#include "../RobotMap.h"

ConveyorBelts::ConveyorBelts() : frc::Subsystem("ConveyorBelts") {

}

void ConveyorBelts::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

void ConveyorBelts::Periodic() {
    // Put code here to be run every loop
	if (leftConBeltLS == "on") {
		MOTOR_LEFT_CON_BELT->Set(0.0);
	}
	if (rightConBeltLS == "of") {
		MOTOR_RIGHT_CON_BELT->Set(0.0);
	}
}

/*void ConveyorBelts::StopLeftConBelt() {
	if (leftConBeltLS == "on") {
		MOTOR_LEFT_CON_BELT->Set(0.0);
	}
}

void ConveyorBelts::StopRightConBelt() {
	if (rightConBeltLS == "of") {
		MOTOR_RIGHT_CON_BELT->Set(0.0);
	}
}*/


// Put methods for controlling this subsystem
// here. Call these from Commands.

