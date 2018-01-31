#include "LEDLights.h"
#include "../RobotMap.h"

LEDLights::LEDLights() : frc::Subsystem("LEDLights") {
    lED = RobotMap::lEDLightsLED;
   }

void LEDLights::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

void LEDLights::Periodic() {
    // Put code here to be run every loop

}


// Put methods for controlling this subsystem
// here. Call these from Commands.

