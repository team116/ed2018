#include <Robot.h>
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "ctre/phoenix.h"
#include <DigitalInput.h>
#include <DigitalOutput.h>
#include <Solenoid.h>
#include <SpeedControllerGroup.h>
#include <AnalogPotentiometer.h>
#include <Encoder.h>
#include <Gyro.h>
#include <RobotDrive.h>
#include <PWMTalonSRX.h>
#include <PWMVictorSPX.h>

shared_ptr<SpeedController> RobotMap::mobilityRLspeedController;
shared_ptr<WPI_TalonSRX> RobotMap::mobilityREAR_LEFT_MOTOR;
shared_ptr<SpeedController> RobotMap::mobilityFLspeedController;
shared_ptr<WPI_TalonSRX> RobotMap::mobilityFRONT_LEFT_MOTOR;
shared_ptr<SpeedControllerGroup> RobotMap::mobilityleftSpeedController;
shared_ptr<SpeedController> RobotMap::mobilityRRspeedController;
shared_ptr<WPI_TalonSRX> RobotMap::mobilityREAR_RIGHT_MOTOR;
shared_ptr<SpeedController> RobotMap::mobilityFRspeedController;
shared_ptr<WPI_TalonSRX> RobotMap::mobilityFRONT_RIGHT_MOTOR;
shared_ptr<SpeedControllerGroup> RobotMap::mobilityrightSpeedController;
shared_ptr<RobotDrive> RobotMap::mobilityRobotDrive41;
shared_ptr<Encoder> RobotMap::mobilityleftEncoder;
shared_ptr<Encoder> RobotMap::mobilityrightEncoder;
shared_ptr<Gyro> RobotMap::mobilitygyro;

shared_ptr<WPI_TalonSRX> RobotMap::liftMOTOR_LIFT;
shared_ptr<SpeedController> RobotMap::liftliftSpeedController;
shared_ptr<DigitalInput> RobotMap::lifttopLS;
shared_ptr<DigitalInput> RobotMap::liftbottomLS;
shared_ptr<AnalogPotentiometer> RobotMap::liftStringPot;

shared_ptr<Solenoid> RobotMap::armsX_AXIS_LEFT_SOLENOID;
shared_ptr<Solenoid> RobotMap::armsX_AXIS_RIGHT_SOLENOID;
shared_ptr<Solenoid> RobotMap::armsY_AXIS_LEFT_SOLENOID;
shared_ptr<Solenoid> RobotMap::armsY_AXIS_RIGHT_SOLENOID;

shared_ptr<Solenoid> RobotMap::rungBACK_BAR_SOLENOID;

shared_ptr<WPI_VictorSPX> RobotMap::climberMOTOR_CLIMBER;
shared_ptr<DigitalInput> RobotMap::climberclimberTopLS;
shared_ptr<DigitalInput> RobotMap::climberclimberBottomLS;
shared_ptr<SpeedController> RobotMap::climberclimberSpeedController;
shared_ptr<AnalogPotentiometer> RobotMap::climberSTRING_POT;

shared_ptr<DigitalOutput> RobotMap::lEDLightsLED;

shared_ptr<WPI_VictorSPX> RobotMap::conveyorBeltsMOTOR_LEFT_CON_BELT;
shared_ptr<WPI_VictorSPX> RobotMap::conveyorBeltsMOTOR_RIGHT_CON_BELT;
shared_ptr<DifferentialDrive> RobotMap::conveyorBeltsDifferentialDrive2;
shared_ptr<DigitalInput> RobotMap::conveyorBeltsleftConBeltLS;
shared_ptr<DigitalInput> RobotMap::conveyorBeltsrightConBeltLS;
shared_ptr<SpeedController> RobotMap::conveyorBeltsleftConBeltSpeedController;
shared_ptr<SpeedController> RobotMap::conveyorBeltsrightConBeltSpeedController;

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    mobilityRLspeedController.reset(new PWMTalonSRX(2));
    lw->AddActuator("Mobility", "RLspeedController", static_pointer_cast<PWMTalonSRX>(mobilityRLspeedController));
    
    mobilityREAR_LEFT_MOTOR.reset(new WPI_TalonSRX(1));
    
    
    mobilityFLspeedController.reset(new PWMTalonSRX(6));
    lw->AddActuator("Mobility", "FLspeedController", static_pointer_cast<PWMTalonSRX>(mobilityFLspeedController));
    
    mobilityFRONT_LEFT_MOTOR.reset(new WPI_TalonSRX(2));
    
    
    mobilityleftSpeedController = make_shared<SpeedControllerGroup>(*mobilityRLspeedController, *mobilityFLspeedController  );
    lw->AddActuator("Mobility", "leftSpeedController", mobilityleftSpeedController);
    
    mobilityRRspeedController.reset(new PWMTalonSRX(1));
    lw->AddActuator("Mobility", "RRspeedController", static_pointer_cast<PWMTalonSRX>(mobilityRRspeedController));
    
    mobilityREAR_RIGHT_MOTOR.reset(new WPI_TalonSRX(0));
    

    mobilityFRspeedController.reset(new PWMTalonSRX(8));
    lw->AddActuator("Mobility", "FRspeedController", static_pointer_cast<PWMTalonSRX>(mobilityFRspeedController));
    
    mobilityFRONT_RIGHT_MOTOR.reset(new WPI_TalonSRX(7));
    
    
    mobilityrightSpeedController = make_shared<SpeedControllerGroup>(*mobilityRRspeedController, *mobilityFRspeedController  );
    lw->AddActuator("Mobility", "rightSpeedController", mobilityrightSpeedController);
    
    mobilityRobotDrive41.reset(new RobotDrive(mobilityFLspeedController, mobilityRLspeedController,
              mobilityFRspeedController, mobilityRRspeedController));
    
    mobilityRobotDrive41->SetSafetyEnabled(true);
    mobilityRobotDrive41->SetExpiration(0.1);
    mobilityRobotDrive41->SetSensitivity(0.5);
    mobilityRobotDrive41->SetMaxOutput(1.0);

    mobilityleftEncoder.reset(new Encoder(0, 1, false, frc::Encoder::k4X));
    lw->AddSensor("Mobility", "leftEncoder", mobilityleftEncoder);
    mobilityleftEncoder->SetDistancePerPulse(1.0);
    mobilityleftEncoder->SetPIDSourceType(PIDSourceType::kRate);

    mobilityrightEncoder.reset(new Encoder(2, 3, false, Encoder::k4X));
    lw->AddSensor("Mobility", "rightEncoder", mobilityrightEncoder);
    mobilityrightEncoder->SetDistancePerPulse(1.0);
    mobilityrightEncoder->SetPIDSourceType(PIDSourceType::kRate);

    liftMOTOR_LIFT.reset(new WPI_TalonSRX(6));
    
    liftliftSpeedController.reset(new PWMTalonSRX(3));
    lw->AddActuator("Lift", "liftSpeedController", static_pointer_cast<PWMTalonSRX>(liftliftSpeedController));
    
    lifttopLS.reset(new DigitalInput(4));
    lw->AddSensor("Lift", "topLS", lifttopLS);
    
    liftbottomLS.reset(new DigitalInput(5));
    lw->AddSensor("Lift", "bottomLS", liftbottomLS);
    
    liftStringPot.reset(new AnalogPotentiometer(0, 1.0, 0.0));
    lw->AddSensor("Lift", "String Pot", liftStringPot);
    
    armsX_AXIS_LEFT_SOLENOID.reset(new Solenoid(0, 0));
    lw->AddActuator("Arms", "X_AXIS_LEFT_SOLENOID", armsX_AXIS_LEFT_SOLENOID);
    
    armsX_AXIS_RIGHT_SOLENOID.reset(new Solenoid(0, 2));
    lw->AddActuator("Arms", "X_AXIS_RIGHT_SOLENOID", armsX_AXIS_RIGHT_SOLENOID);
    
    armsY_AXIS_LEFT_SOLENOID.reset(new Solenoid(0, 1));
    lw->AddActuator("Arms", "Y_AXIS_LEFT_SOLENOID", armsY_AXIS_LEFT_SOLENOID);
    
    armsY_AXIS_RIGHT_SOLENOID.reset(new Solenoid(0, 3));
    lw->AddActuator("Arms", "Y_AXIS_RIGHT_SOLENOID", armsY_AXIS_RIGHT_SOLENOID);
    
    rungBACK_BAR_SOLENOID.reset(new Solenoid(0, 4));
    lw->AddActuator("Rung", "BACK_BAR_SOLENOID", rungBACK_BAR_SOLENOID);
    
    climberMOTOR_CLIMBER.reset(new WPI_VictorSPX(4));
    
    
    climberclimberTopLS.reset(new DigitalInput(6));
    lw->AddSensor("Climber", "climberTopLS", climberclimberTopLS);
    
    climberclimberBottomLS.reset(new DigitalInput(11));
    lw->AddSensor("Climber", "climberBottomLS", climberclimberBottomLS);
    
    climberclimberSpeedController.reset(new PWMVictorSPX(5));
    lw->AddActuator("Climber", "climberSpeedController", static_pointer_cast<PWMVictorSPX>(climberclimberSpeedController));
    
    climberSTRING_POT.reset(new AnalogPotentiometer(1, 1.0, 0.0));
    lw->AddSensor("Climber", "STRING_POT", climberSTRING_POT);
    
    lEDLightsLED.reset(new DigitalOutput(8));
    lw->AddActuator("LEDLights", "LED", lEDLightsLED);
    
    conveyorBeltsMOTOR_LEFT_CON_BELT.reset(new WPI_VictorSPX(5));
    
    
    conveyorBeltsMOTOR_RIGHT_CON_BELT.reset(new WPI_VictorSPX(8));
    
    
    conveyorBeltsDifferentialDrive2.reset(new DifferentialDrive(*conveyorBeltsMOTOR_LEFT_CON_BELT, *conveyorBeltsMOTOR_RIGHT_CON_BELT));
    lw->AddActuator("ConveyorBelts", "Differential Drive 2", conveyorBeltsDifferentialDrive2);
    conveyorBeltsDifferentialDrive2->SetSafetyEnabled(true);
        conveyorBeltsDifferentialDrive2->SetExpiration(0.1);
        conveyorBeltsDifferentialDrive2->SetMaxOutput(1.0);

    conveyorBeltsleftConBeltLS.reset(new DigitalInput(7));
    lw->AddSensor("ConveyorBelts", "leftConBeltLS", conveyorBeltsleftConBeltLS);
    
    conveyorBeltsrightConBeltLS.reset(new DigitalInput(12));
    lw->AddSensor("ConveyorBelts", "rightConBeltLS", conveyorBeltsrightConBeltLS);
    
    conveyorBeltsleftConBeltSpeedController.reset(new PWMVictorSPX(0));
    lw->AddActuator("ConveyorBelts", "leftConBeltSpeedController", static_pointer_cast<PWMVictorSPX>(conveyorBeltsleftConBeltSpeedController));
    
    conveyorBeltsrightConBeltSpeedController.reset(new PWMVictorSPX(4));
    lw->AddActuator("ConveyorBelts", "rightConBeltSpeedController", static_pointer_cast<PWMVictorSPX>(conveyorBeltsrightConBeltSpeedController));
    
}
