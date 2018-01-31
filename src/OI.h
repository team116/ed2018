#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <Robot.h>


class OI {
private:
	shared_ptr<Mobility> Robot::mobility;
	shared_ptr<Lift> Robot::lift;
	shared_ptr<Arms> Robot::arms;
	shared_ptr<Rung> Robot::rung;
	shared_ptr<Climber> Robot::climber;
	shared_ptr<LEDLights> Robot::lEDLights;
	shared_ptr<ConveyorBelts> Robot::conveyorBelts;
	shared_ptr<Vision> Robot::vision;
	unique_ptr<OI> Robot::oi;
	
	shared_ptr<Joystick> joystick1;
	shared_ptr<JoystickButton> hold;
	shared_ptr<JoystickButton> scaleNeutral;
	shared_ptr<JoystickButton> switchTop;
	shared_ptr<JoystickButton> scaleBottom;
	shared_ptr<JoystickButton> joy_left_con_belt;
	shared_ptr<JoystickButton> rung;
	shared_ptr<JoystickButton> closePistonButton;
	shared_ptr<JoystickButton> openPistonButton;
	shared_ptr<JoystickButton> scaleTop;
	shared_ptr<Joystick> joy_con_belt_left;
	shared_ptr<Joystick> joy_lift;
	shared_ptr<Joystick> joy_climber;
	shared_ptr<Joystick> joy_right;
	shared_ptr<Joystick> joy_left;

public:
	OI();

	void process();

	shared_ptr<Joystick> getjoy_left();
	shared_ptr<Joystick> getjoy_right();
	shared_ptr<Joystick> getjoy_climber();
	shared_ptr<Joystick> getjoy_lift();
	shared_ptr<Joystick> getjoy_con_belt_left();
	shared_ptr<Joystick> getJoystick1();

};

#endif
