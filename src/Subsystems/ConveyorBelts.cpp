// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ctre/Phoenix.h"


#include "ConveyorBelts.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

ConveyorBelts::ConveyorBelts() : frc::Subsystem("ConveyorBelts") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    mOTOR_LEFT_CON_BELT = RobotMap::conveyorBeltsMOTOR_LEFT_CON_BELT;
    mOTOR_RIGHT_CON_BELT = RobotMap::conveyorBeltsMOTOR_RIGHT_CON_BELT;
    differentialDrive2 = RobotMap::conveyorBeltsDifferentialDrive2;
    leftConBeltLS = RobotMap::conveyorBeltsleftConBeltLS;
    rightConBeltLS = RobotMap::conveyorBeltsrightConBeltLS;
    leftConBeltSpeedController = RobotMap::conveyorBeltsleftConBeltSpeedController;
    rightConBeltSpeedController = RobotMap::conveyorBeltsrightConBeltSpeedController;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void ConveyorBelts::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void ConveyorBelts::Periodic() {
    // Put code here to be run every loop

}


// Put methods for controlling this subsystem
// here. Call these from Commands.

