#include "Mobility.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include <PIDController.h>

Mobility::Mobility() : PIDSubsystem("Mobility", 1.0, 0.0, 0.0) {
    SetAbsoluteTolerance(0.2);
    GetPIDController()->SetContinuous(false);
    frc::LiveWindow::GetInstance()->AddActuator("Mobility", "PIDSubsystem Controller", GetPIDController());

    rLspeedController = RobotMap::mobilityRLspeedController;
    REAR_LEFT_MOTOR = RobotMap::mobilityREAR_LEFT_MOTOR;
    fLspeedController = RobotMap::mobilityFLspeedController;
    fRONT_LEFT_MOTOR = RobotMap::mobilityFRONT_LEFT_MOTOR;
    leftSpeedController = RobotMap::mobilityleftSpeedController;
    rRspeedController = RobotMap::mobilityRRspeedController;
    REAR_RIGHT_MOTOR = RobotMap::mobilityREAR_RIGHT_MOTOR;
    fRspeedController = RobotMap::mobilityFRspeedController;
    FRONT_RIGHT_MOTOR = RobotMap::mobilityFRONT_RIGHT_MOTOR;
    rightSpeedController = RobotMap::mobilityrightSpeedController;
    robotDrive41 = RobotMap::mobilityRobotDrive41;
    leftEncoder = RobotMap::mobilityleftEncoder;
    rightEncoder = RobotMap::mobilityrightEncoder;

    // Use these to get going:
    // SetSetpoint() -  Sets where the PID controller should move the system
    //                  to
    // Enable() - Enables the PID controller.
}

double Mobility::ReturnPIDInput() {
    // Return your input value for the PID loop
    // e.g. a sensor, like a potentiometer:
    // yourPot->SetAverageVoltage() / kYourMaxVoltage;

        return leftEncoder->PIDGet();
}

void Mobility::UsePIDOutput(double output) {
    // Use output to drive your system, like a motor
    // e.g. yourMotor->Set(output);

    leftSpeedController->PIDWrite(output);
    }

void Mobility::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());

}
