#ifndef RUNG_H
#define RUNG_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Rung: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<frc::Solenoid> BACK_BAR_SOLENOID;

public:
	Rung();
	void InitDefaultCommand() override;
	void Periodic() override;
	};

#endif
