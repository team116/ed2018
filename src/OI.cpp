#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutoPlays/AutonomousCommand.h"
#include "Commandfile.h"


OI::OI() {
    // Process operator interface input here.
    joy_con_belt_left.reset(new Joystick(5));

    buttonbox1.reset(new Joystick(4));

    joy_lift.reset(new Joystick(3));

    joy_climber.reset(new Joystick(2));

    joy_right.reset(new Joystick(1));

    //connecting the buttons
    //hold.WhenPressed(new hold());
    closePistonButton.WhenPressed(new closePiston());
    openPistonButton.WhenPressed(new openPiston());
    movetoScaleBottomButton.WhenPressed(new movetoScaleBottom(520));
    movetoScaleNeutralButton.WhenPressed(new movetoScaleNeutral(600));
    movetoScaleTopButton.WhenPressed(new movetoScaleTop(720));
    movetoSwitchTopButton.WhenPressed(new movetoSwitchTop(15));
    pickUpCubeButton.WhenPressed(new pickUpCube());
    releaseCubeButton.WhenPressed(new releaseCube());
	rotateCubeButton.WhenPressed(new rotateCube());

    // SmartDashboard Buttons
    SmartDashboard::PutData("holdClimber", new holdClimber(0));
    SmartDashboard::PutData("rotateCube", new rotateCube());
    SmartDashboard::PutData("releaseCube", new releaseCube());
    SmartDashboard::PutData("pickUpCube", new pickUpCube());
    SmartDashboard::PutData("stopIntake", new stopIntake());
    SmartDashboard::PutData("moveLift", new moveLift());
    SmartDashboard::PutData("moveRight", new moveRight());
    SmartDashboard::PutData("moveLeft", new moveLeft());
    SmartDashboard::PutData("movetoScaleTop", new movetoScaleTop(0));
    SmartDashboard::PutData("movetoScaleNeutral", new movetoScaleNeutral(0));
    SmartDashboard::PutData("movetoSwitchTop", new movetoSwitchTop(0));
    SmartDashboard::PutData("movetoScaleBottom", new movetoScaleBottom(0));
    SmartDashboard::PutData("moveIntakeOut", new moveIntakeOut());
    SmartDashboard::PutData("closePiston", new closePiston());
    SmartDashboard::PutData("openPiston", new openPiston());
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

