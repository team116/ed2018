#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/closePiston.h"
#include "Commands/deployRung.h"
#include "Commands/holdClimber.h"
#include "Commands/moveIntakeOut.h"
#include "Commands/moveLeft.h"
#include "Commands/moveLift.h"
#include "Commands/moveRight.h"
#include "Commands/movetoScaleBottom.h"
#include "Commands/movetoScaleNeutral.h"
#include "Commands/movetoScaleTop.h"
#include "Commands/movetoSwitchTop.h"
#include "Commands/openPiston.h"
#include "Commands/pickUpCube.h"
#include "Commands/releaseCube.h"
#include "Commands/rotateCube.h"
#include "Commands/stopIntake.h"


OI::OI() {
    // Process operator interface input here.
    joystick1.reset(new Joystick(4));
    
    hold.reset(new JoystickButton(joystick1.get(), 1));
    hold->WhenPressed(new holdClimber(0));

    scaleNeutral.reset(new JoystickButton(joystick1.get(), 1));
    scaleNeutral->WhenPressed(new movetoScaleNeutral(0));

    switchTop.reset(new JoystickButton(joystick1.get(), 1));
    switchTop->WhenPressed(new movetoSwitchTop(0));

    scaleBottom.reset(new JoystickButton(joystick1.get(), 1));
    scaleBottom->WhenPressed(new movetoScaleBottom(0));

    joy_left_con_belt.reset(new JoystickButton(joystick1.get(), 1));
    joy_left_con_belt->WhenPressed(new moveIntakeOut());

    rung.reset(new JoystickButton(joystick1.get(), 1));
    rung->WhenPressed(new deployRung());

    closePistonButton.reset(new JoystickButton(joystick1.get(), 1));
    closePistonButton->WhenPressed(new closePiston());

    openPistonButton.reset(new JoystickButton(joystick1.get(), 1));
    openPistonButton->WhenPressed(new openPiston());

    scaleTop.reset(new JoystickButton(joystick1.get(), 1));
    scaleTop->WhenPressed(new movetoScaleTop(0));

    joy_con_belt_left.reset(new Joystick(5));
    
    joy_lift.reset(new Joystick(3));
    
    joy_climber.reset(new Joystick(2));
    
    joy_right.reset(new Joystick(1));
    
    joy_left.reset(new Joystick(0));
    

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

shared_ptr<Joystick> OI::getJoystick1() {
   return joystick1;
}

