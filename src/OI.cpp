#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutoPlays/AutonomousCommand.h"
#include "Commandfile.h"


OI::OI() {
    // Process operator interface input here.
    joy_con_belt_left.reset(new Joystick(5));

    joy_con_belt_right.reset(new Joystick(6));

    buttonbox1.reset(new Joystick(4));

    joy_lift.reset(new Joystick(3));

    joy_climber.reset(new Joystick(2));

    joy_right.reset(new Joystick(1));

    joy_left.reset(new Joystick(0));

    //connecting the buttons
    //hold.WhenPressed(new hold());
    closePistonButton.WhenPressed(new closePiston());
    SmartDashboard::PutData("closePiston", new closePiston());

    openPistonButton.WhenPressed(new openPiston());
    SmartDashboard::PutData("openPiston", new openPiston());

    movetoScaleBottomButton.WhenPressed(new movetoScaleBottom(520));
    SmartDashboard::PutData("movetoScaleBottom", new movetoScaleBottom(0));

    movetoScaleNeutralButton.WhenPressed(new movetoScaleNeutral(600));
    SmartDashboard::PutData("movetoScaleNeutral", new movetoScaleNeutral(0));

    movetoScaleTopButton.WhenPressed(new movetoScaleTop(720));
    SmartDashboard::PutData("movetoScaleTop", new movetoScaleTop(0));

    movetoSwitchTopButton.WhenPressed(new movetoSwitchTop(15));
    SmartDashboard::PutData("movetoSwitchTop", new movetoSwitchTop(0));

    pickUpCubeButton.WhenPressed(new pickUpCube());
    SmartDashboard::PutData("pickUpCube", new pickUpCube());

    releaseCubeButton.WhenPressed(new releaseCube());
    SmartDashboard::PutData("rotateCube", new rotateCube());

	rotateCubeButton.WhenPressed(new rotateCube());
	 SmartDashboard::PutData("rotateCube", new rotateCube());

    // SmartDashboard Buttons
    SmartDashboard::PutData("holdClimber", new holdClimber(0));
    SmartDashboard::PutData("stopIntake", new stopIntake());
    SmartDashboard::PutData("moveLift", new moveLift());
    SmartDashboard::PutData("moveRight", new moveRight());
    SmartDashboard::PutData("moveLeft", new moveLeft());
    SmartDashboard::PutData("moveIntakeOut", new moveIntakeOut());
    SmartDashboard::PutData("deployRung", new deployRung());
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
}


shared_ptr<Joystick> OI::getjoy_left() {
   return joy_left;
}

shared_ptr<Joystick> OI::getjoy_right() {
   return joy_right;
}

shared_ptr<Joystick> OI::getjoy_climber() {
   return joy_climber;
}

shared_ptr<Joystick> OI::getjoy_lift() {
   return joy_lift;
}

shared_ptr<Joystick> OI::getjoy_con_belt_left() {
   return joy_con_belt_left;
}
shared_ptr<Joystick> OI::getjoy_con_belt_right() {
	return joy_con_belt_right;
}

shared_ptr<Joystick> OI::getJoystick1() {
   return buttonbox1;
}

