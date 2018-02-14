#include "Lift.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include <PIDController.h>

bool ISTOPON = true;
bool ISBOTTOMON = true;
const double LIFTSPEEDUP = .25;
const double LIFTSPEEDDOWN = -.25;

Lift::Lift() : PIDSubsystem("Lift", 1.0, 0.0, 0.0) {
    SetAbsoluteTolerance(0.2);
    GetPIDController()->SetContinuous(false);
    LiveWindow::GetInstance()->AddActuator("Lift", "PIDSubsystem Controller", GetPIDController());

    MOTOR_LIFT = RobotMap::liftMOTOR_LIFT;

    liftSpeedController = RobotMap::liftliftSpeedController;

    topLS = RobotMap::lifttopLS;
    bottomLS = RobotMap::liftbottomLS;
    stringPot = RobotMap::liftStringPot;

    // Use these to get going:
    // SetSetpoint() -  Sets where the PID controller should move the system
    //                  to
    // Enable() - Enables the PID controller.
}

double Lift::ReturnPIDInput() {
    // Return your input value for the PID loop
    // e.g. a sensor, like a potentiometer:
    // yourPot->SetAverageVoltage() / kYourMaxVoltage;
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
        return stringPot->Get();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
}

void Lift::UsePIDOutput(double output) {
    // Use output to drive your system, like a motor
    // e.g. yourMotor->Set(output);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
    liftSpeedController->PIDWrite(output);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
}

void Lift::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());

}
bool LiftTopLimitSwitch(bool topLS){
    if(topLS == ISTOPON){
        shared_ptr<SpeedController> liftSpeedController = LIFTSPEEDUP;
    }
}

bool LiftBottomLimitSwitch(bool bottomLS){
    if(bottomLS == ISBOTTOMON){
        shared_ptr<SpeedController> liftSpeedController = LIFTSPEEDDOWN;
    }
}
