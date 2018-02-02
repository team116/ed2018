#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "ctre/Phoenix.h"

class RobotMap {
public:

	static shared_ptr<SpeedController> mobilityRLspeedController;
	static shared_ptr<WPI_TalonSRX> mobilityREAR_LEFT_MOTOR;
	static shared_ptr<frc::SpeedController> mobilityFLspeedController;
	static shared_ptr<WPI_TalonSRX> mobilityFRONT_LEFT_MOTOR;
	static shared_ptr<frc::SpeedControllerGroup> mobilityleftSpeedController;
	static shared_ptr<frc::SpeedController> mobilityRRspeedController;
	static shared_ptr<WPI_TalonSRX> mobilityREAR_RIGHT_MOTOR;
	static shared_ptr<frc::SpeedController> mobilityFRspeedController;
	static shared_ptr<WPI_TalonSRX> mobilityFRONT_RIGHT_MOTOR;
	static shared_ptr<frc::SpeedControllerGroup> mobilityrightSpeedController;
	static shared_ptr<frc::RobotDrive> mobilityRobotDrive;
	static shared_ptr<frc::Encoder> mobilityleftEncoder;
	static shared_ptr<frc::Encoder> mobilityrightEncoder;
	shared_ptr<Gyro> mobilitygyro;

	static shared_ptr<WPI_TalonSRX> liftMOTOR_LIFT;
	static shared_ptr<frc::SpeedController> liftliftSpeedController;
	static shared_ptr<frc::DigitalInput> lifttopLS;
	static shared_ptr<frc::DigitalInput> liftbottomLS;
	static shared_ptr<frc::AnalogPotentiometer> liftStringPot;

	static shared_ptr<frc::Solenoid> armsX_AXIS_LEFT_SOLENOID;
	static shared_ptr<frc::Solenoid> armsX_AXIS_RIGHT_SOLENOID;
	static shared_ptr<frc::Solenoid> armsY_AXIS_LEFT_SOLENOID;
	static shared_ptr<frc::Solenoid> armsY_AXIS_RIGHT_SOLENOID;

	static shared_ptr<frc::Solenoid> rungBACK_BAR_SOLENOID;

	static shared_ptr<WPI_VictorSPX> climberMOTOR_CLIMBER;
	static shared_ptr<frc::DigitalInput> climberclimberTopLS;
	static shared_ptr<frc::DigitalInput> climberclimberBottomLS;
	static shared_ptr<frc::SpeedController> climberclimberSpeedController;
	static shared_ptr<frc::AnalogPotentiometer> climberSTRING_POT;

	static shared_ptr<frc::DigitalOutput> lEDLightsLED;

	static shared_ptr<WPI_VictorSPX> conveyorBeltsMOTOR_LEFT_CON_BELT;
	static shared_ptr<WPI_VictorSPX> conveyorBeltsMOTOR_RIGHT_CON_BELT;
	static shared_ptr<frc::DifferentialDrive> conveyorBeltsDifferentialDrive2;
	static shared_ptr<frc::DigitalInput> conveyorBeltsleftConBeltLS;
	static shared_ptr<frc::DigitalInput> conveyorBeltsrightConBeltLS;
	static shared_ptr<frc::SpeedController> conveyorBeltsleftConBeltSpeedController;
	static shared_ptr<frc::SpeedController> conveyorBeltsrightConBeltSpeedController;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	static void init();
};
#endif
