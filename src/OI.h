#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <Robot.h>
#include "RobotMap.h"
#include <Joystick.h>
#include <DigitalInput.h>
#include <Buttons/JoystickButton.h>
#include "Commandfile.h"
#include "Subsystems/Arms.h"
#include "Subsystems/Mobility.h"
#include "Subsystems/ConveyorBelts.h"
#include "Subsystems/Hook.h"
#include "Subsystems/Lift.h"
#include "Subsystems/Rung.h"

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
	
	//joystick port assignments
	const static int JoystickChannel0 = 0;
	const static int JoystickChannel1 = 1;
	const static int JoystickChannel2 = 2;

	//joysticks
	shared_ptr<Joystick> buttonbox1{JoystickChannel0};
	shared_ptr<Joystick> joy_right{JoystickChannel1};
	shared_ptr<Joystick> joy_left{JoystickChannel2};
	shared_ptr<Joystick> joy_con_belt_left;
	shared_ptr<Joystick> joy_con_belt_right;
	shared_ptr<Joystick> joy_climber;
	shared_ptr<Joystick> joy_multistage;


	JoystickButton switchXArms{buttonbox1, 13};
	JoystickButton switchYArms{buttonbox1, 12};
	JoystickButton switchRung{buttonbox1, 14};
	JoystickButton switchHook{buttonbox1, 15};

	JoystickButton switch0{buttonbox1, 1};
	JoystickButton switch1{buttonbox1, 2};
	JoystickButton switch2{buttonbox1, 3};
	JoystickButton switch3{buttonbox1, 4};
	JoystickButton switch4{buttonbox1, 5};
	JoystickButton switch5{buttonbox1, 6};
	JoystickButton switch6{buttonbox1, 7};
	JoystickButton switch7{buttonbox1, 8};
	JoystickButton switch8{buttonbox1, 9};
	JoystickButton switch9{buttonbox1, 10};
	JoystickButton switch10{buttonbox1, 11};


public:
	OI();
	Joystick& GetJoystick();

	void process();

	shared_ptr<Joystick> getjoy_left();
	shared_ptr<Joystick> getjoy_right();
	shared_ptr<Joystick> getjoy_multistage();
	shared_ptr<Joystick> getjoy_intake();
	shared_ptr<Joystick> getJoystick1();

};

#endif
