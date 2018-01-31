#include "Rung.h"
#include "../RobotMap.h"

Rung::Rung() : Subsystem("Rung") {
    BACK_BAR_SOLENOID = RobotMap::rungBACK_BAR_SOLENOID;
}

void Rung::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

void Rung::Periodic() {
    // Put code here to be run every loop

}


// Put methods for controlling this subsystem
// here. Call these from Commands.

