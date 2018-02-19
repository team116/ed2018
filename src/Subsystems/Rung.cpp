#include "Rung.h"
#include "../RobotMap.h"
#include "Robot.h"

Rung::Rung() : Subsystem("Rung") {

}

void Rung::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

void Rung::Periodic() {
    // Put code here to be run every loop

}

void Rung::open() {
	BACK_BAR_SOLENOID->Set(false);
}

void Rung::close() {

}

// Put methods for controlling this subsystem
// here. Call these from Commands.

