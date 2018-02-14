#include "ctre/Phoenix.h"


#include "ConveyorBelts.h"
#include "../RobotMap.h"

bool ISLEFTCONBELTON = true;
bool ISRIGHTCONBELTON = true;

ConveyorBelts::ConveyorBelts() : frc::Subsystem("ConveyorBelts") {

    MOTOR_LEFT_CON_BELT = RobotMap::conveyorBeltsMOTOR_LEFT_CON_BELT;
    MOTOR_RIGHT_CON_BELT = RobotMap::conveyorBeltsMOTOR_RIGHT_CON_BELT;
    differentialDrive2 = RobotMap::conveyorBeltsDifferentialDrive2;
    leftConBeltLS = RobotMap::conveyorBeltsleftConBeltLS;
    rightConBeltLS = RobotMap::conveyorBeltsrightConBeltLS;
    leftConBeltSpeedController = RobotMap::conveyorBeltsleftConBeltSpeedController;
    rightConBeltSpeedController = RobotMap::conveyorBeltsrightConBeltSpeedController;

}

void ConveyorBelts::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

void ConveyorBelts::Periodic() {
    // Put code here to be run every loop

}
bool ConveyorBelts::LeftConBeltIn(bool leftConBeltLS){
    if(leftConBeltLS == ISLEFTCONBELTON){
        RobotMap::conveyorBeltsleftConBeltSpeedController = 0;
    }
    else{
        RobotMap::conveyorBeltsleftConBeltSpeedController = -5;
    }
}

bool ConveyorBelts::RightConBeltIn(bool rightConBeltLS){
    if(rightConBeltLS == ISRIGHTCONBELTON){
        RobotMap::conveyorBeltsrightConBeltSpeedController = 0;
    }
    else{
        RobotMap::conveyorBeltsrightConBeltSpeedController = -5;
    }
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

