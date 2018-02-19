//#ifndef ARMS_H
#define ARMS_H

#include "../Robot.h"
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"
#include <Solenoid.h>


class Arms: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities

	shared_ptr<Solenoid> x_AXIS_SOLENOID{3, 4};
	shared_ptr<Solenoid> y_AXIS_SOLENOID{7, 8};

	bool is_open = false;


public:
	Arms();
	void InitDefaultCommand() override;
	void Periodic() override;

	//these will be to open/close the arms
	void open();
	void close();
	bool isOpen();
	bool enabled();
	void enableCompressor();
	void disableCompressor();
};

//#endif
