#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "ctre/Phoenix.h"

class RobotMap {
public:

	static shared_ptr<SpeedController> mobilityRLspeedController;
	static shared_ptr<WPI_TalonSRX> mobilityREAR_LEFT_MOTOR;
	static shared_ptr<SpeedController> mobilityFLspeedController;
	static shared_ptr<WPI_TalonSRX> mobilityFRONT_LEFT_MOTOR;
	static shared_ptr<SpeedControllerGroup> mobilityleftSpeedController;
	static shared_ptr<SpeedController> mobilityRRspeedController;
	static shared_ptr<WPI_TalonSRX> mobilityREAR_RIGHT_MOTOR;
	static shared_ptr<SpeedController> mobilityFRspeedController;
	static shared_ptr<WPI_TalonSRX> mobilityFRONT_RIGHT_MOTOR;
	static shared_ptr<SpeedControllerGroup> mobilityrightSpeedController;
	static shared_ptr<RobotDrive> mobilityRobotDrive;
	static shared_ptr<Encoder> mobilityleftEncoder;
	static shared_ptr<Encoder> mobilityrightEncoder;
	shared_ptr<Gyro> mobilitygyro;

	static shared_ptr<WPI_TalonSRX> liftMOTOR_LIFT;
	static shared_ptr<SpeedController> liftliftSpeedController;
	static shared_ptr<DigitalInput> lifttopLS;
	static shared_ptr<DigitalInput> liftbottomLS;
	static shared_ptr<AnalogPotentiometer> liftStringPot;

	static shared_ptr<Solenoid> armsX_AXIS_LEFT_SOLENOID;
	static shared_ptr<Solenoid> armsX_AXIS_RIGHT_SOLENOID;
	static shared_ptr<Solenoid> armsY_AXIS_LEFT_SOLENOID;
	static shared_ptr<Solenoid> armsY_AXIS_RIGHT_SOLENOID;

	static shared_ptr<Solenoid> rungBACK_BAR_SOLENOID;

	static shared_ptr<WPI_VictorSPX> climberMOTOR_CLIMBER;
	static shared_ptr<DigitalInput> climberclimberTopLS;
	static shared_ptr<DigitalInput> climberclimberBottomLS;
	static shared_ptr<SpeedController> climberclimberSpeedController;
	static shared_ptr<AnalogPotentiometer> climberSTRING_POT;

	static shared_ptr<DigitalOutput> lEDLightsLED;

	static shared_ptr<WPI_VictorSPX> conveyorBeltsMOTOR_LEFT_CON_BELT;
	static shared_ptr<WPI_VictorSPX> conveyorBeltsMOTOR_RIGHT_CON_BELT;
	static shared_ptr<DifferentialDrive> conveyorBeltsDifferentialDrive2;
	static shared_ptr<DigitalInput> conveyorBeltsleftConBeltLS;
	static shared_ptr<DigitalInput> conveyorBeltsrightConBeltLS;
	static shared_ptr<SpeedController> conveyorBeltsleftConBeltSpeedController;
	static shared_ptr<SpeedController> conveyorBeltsrightConBeltSpeedController;

	static void init();
};
#endif
