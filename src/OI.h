#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <Robot.h>
#include <Joystick.h>
#include <Buttons/JoystickButton.h>
#include "Commandfile.h"


class OI {
private:
	static OI* INSTANCE;

	shared_ptr<Mobility> Robot::mobility;
	shared_ptr<Lift> Robot::lift;
	shared_ptr<Arms> Robot::arms;
	shared_ptr<Rung> Robot::rung;
	shared_ptr<Climber> Robot::climber;
	shared_ptr<LEDLights> Robot::lEDLights;
	shared_ptr<ConveyorBelts> Robot::conveyorBelts;
	shared_ptr<Vision> Robot::vision;
	unique_ptr<OI> Robot::oi;
	
	//joysticks
	shared_ptr<Joystick> buttonbox1;
	shared_ptr<Joystick> joy_con_belt_left;
	shared_ptr<Joystick> joy_con_belt_right;
	shared_ptr<Joystick> joy_climber;
	shared_ptr<Joystick> joy_lift;
	shared_ptr<Joystick> joy_right;
	shared_ptr<Joystick> joy_left;

	//Buttons
	JoystickButton hold{buttonbox1, 0};	//what joystick, what button #
	JoystickButton closePistonButton{buttonbox1, 1};
	JoystickButton openPistonButton{buttonbox1, 2};
	JoystickButton movetoScaleBottomButton{buttonbox1, 3};
	JoystickButton movetoScaleNeutralButton{buttonbox1, 4};
	JoystickButton movetoScaleTopButton{buttonbox1, 5};
	JoystickButton movetoSwitchTopButton{buttonbox1, 6};
	JoystickButton pickUpCubeButton{buttonbox1, 7};
	JoystickButton releaseCubeButton{buttonbox1, 8};
	JoystickButton rotateCubeButton{buttonbox1, 9};

public:
	OI();
	Joystick& GetJoystick();

	void process();

	shared_ptr<Joystick> getjoy_left();
	shared_ptr<Joystick> getjoy_right();
	shared_ptr<Joystick> getjoy_climber();
	shared_ptr<Joystick> getjoy_lift();
	shared_ptr<Joystick> getjoy_con_belt_left();
	shared_ptr<Joystick> getjoy_con_belt_right();
	shared_ptr<Joystick> getJoystick1();

};

#endif
