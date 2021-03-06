#ifndef MOVETOSWITCHTOP_H
#define MOVETOSWITCHTOP_H


#include "Commands/Subsystem.h"
#include "../Subsystems/Lift.h"
#include "../Robot.h"


class movetoSwitchTop: public frc::Command {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

movetoSwitchTop(double setpoint);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES
    double m_setpoint = 18.0; //18 inches off the ground needs testing
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES
};

#endif
