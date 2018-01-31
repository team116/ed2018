#ifndef RUNG_H
#define RUNG_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <Robot.h>

class Rung: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities

	shared_ptr<Solenoid> BACK_BAR_SOLENOID;

public:
	Rung();
	void InitDefaultCommand() override;
	void Periodic() override;
	};

#endif
