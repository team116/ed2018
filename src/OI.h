// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	
	
	
	
	
	
	
	std::shared_ptr<frc::Joystick> joystick1;
	std::shared_ptr<frc::JoystickButton> hold;
	std::shared_ptr<frc::JoystickButton> scaleNeutral;
	std::shared_ptr<frc::JoystickButton> switchTop;
	std::shared_ptr<frc::JoystickButton> scaleBottom;
	std::shared_ptr<frc::JoystickButton> joy_left_con_belt;
	std::shared_ptr<frc::JoystickButton> rung;
	std::shared_ptr<frc::JoystickButton> closePistonButton;
	std::shared_ptr<frc::JoystickButton> openPistonButton;
	std::shared_ptr<frc::JoystickButton> scaleTop;
	std::shared_ptr<frc::Joystick> joy_con_belt_left;
	std::shared_ptr<frc::Joystick> joy_lift;
	std::shared_ptr<frc::Joystick> joy_climber;
	std::shared_ptr<frc::Joystick> joy_right;
	std::shared_ptr<frc::Joystick> joy_left;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	OI();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	std::shared_ptr<frc::Joystick> getjoy_left();
	std::shared_ptr<frc::Joystick> getjoy_right();
	std::shared_ptr<frc::Joystick> getjoy_climber();
	std::shared_ptr<frc::Joystick> getjoy_lift();
	std::shared_ptr<frc::Joystick> getjoy_con_belt_left();
	std::shared_ptr<frc::Joystick> getJoystick1();
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
};

#endif
