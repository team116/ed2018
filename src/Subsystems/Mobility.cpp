#include "Mobility.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include <PIDController.h>
#include <PIDSource.h>
#include <PIDOutput.h>
#include <Commands/tankDriveWithJoysticks.h>

const float MAX_SPEED = 10; //Find actual number
const float PI = 3.14159265;

Mobility::Mobility() : PIDSubsystem("Mobility", 1.0, 0.0, 0.0) {
    SetAbsoluteTolerance(0.2);
    GetPIDController()->SetContinuous(true);
    LiveWindow::GetInstance()->AddActuator("Mobility", "PIDSubsystem Controller", GetPIDController());

    //Speed Controller Groups
    leftSpeedController = RobotMap::mobilityleftSpeedController;
    rightSpeedController = RobotMap::mobilityrightSpeedController;

    //Speed Controllers
    rLspeedController = RobotMap::mobilityRLspeedController;
    fLspeedController = RobotMap::mobilityFLspeedController;
    rRspeedController = RobotMap::mobilityRRspeedController;
    fRspeedController = RobotMap::mobilityFRspeedController;

    //Motor Controllers
    REAR_LEFT_MOTOR = RobotMap::mobilityREAR_LEFT_MOTOR;
    FRONT_LEFT_MOTOR = RobotMap::mobilityFRONT_LEFT_MOTOR;
    REAR_RIGHT_MOTOR = RobotMap::mobilityREAR_RIGHT_MOTOR;
    FRONT_RIGHT_MOTOR = RobotMap::mobilityFRONT_RIGHT_MOTOR;

    robotDrive = RobotMap::mobilityRobotDrive;

    //Sensors
    leftEncoder = RobotMap::mobilityleftEncoder;
    rightEncoder = RobotMap::mobilityrightEncoder;
    //analogGyro = RobotMap::mobilityanalogGyro;

    // Use these to get going:
    // SetSetpoint() -  Sets where the PID controller should move the system
    //                  to
    // Enable() - Enables the PID controller.

GetPIDController()->Enable();
	REAR_LEFT_MOTOR->SetSafetyEnabled(true);
	FRONT_LEFT_MOTOR->SetSafetyEnabled(true);
	REAR_RIGHT_MOTOR->SetSafetyEnabled(true);
	FRONT_RIGHT_MOTOR->SetSafetyEnabled(true);

	//Circumference in feet = 6 in / (12 in/ft) * PI
	mobilityleftEncoder.SetDistancePerPulse(static_cast<double>(0.5 * PI) / 4000);
	mobilityrightEncoder.SetDistancePerPulse(static_cast<double>(0.5 * PI) / 4000);

	AddChild("Left Encoder", mobilityleftEncoder);
	AddChild("Right Encoder", mobilityrightEncoder);
}

void Mobility::UsePIDOutput(double output) {
    // Use output to drive your system, like a motor
    // e.g. yourMotor->Set(output);

    leftSpeedController->PIDWrite(output);
    }

void Mobility::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    SetDefaultCommand(new tankDriveWithJoysticks());

}

void Mobility::Log() {
	SmartDashboard::PutNumber("Left Distance", mobilityleftEncoder.GetDistance());
	SmartDashboard::PutNumber("Right Distance", mobilityrightEncoder.GetDistance());
	SmartDashboard::PutNumber("Left Speed", mobilityleftEncoder.GetRate());
		//SmartDashboard::PutNumber("Right Speed", m_rightEncoder.GetRate());
		//SmartDashboard::PutNumber("Gyro", m_gyro.GetAngle());
}

void Mobility::Drive(float left, float right) {
	robotDrive.TankDrive(left, right);
}

/*float Mobility::GetGyro() {
	return gyro.GetAngle();
}*/

void Mobility::Reset() {
	//rest gyro
	mobilityleftEncoder.Reset();
	mobilityrightEncoder.Reset();
}

float Mobility::GetDistance() {
	return (mobilityleftEncoder.GetDistance() + mobilityrightEncoder.GetDistance()) / 2.0;
}

/*float Mobility::GetDistanceToObstacle() {
	return m_rangefinder.GetAverageVoltage();
}*/
