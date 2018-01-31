#ifndef LEDLIGHTS_H
#define LEDLIGHTS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <Robot.h>

class LEDLights: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	shared_ptr<DigitalOutput> lED;

public:
	LEDLights();
	void InitDefaultCommand() override;
	void Periodic() override;
};

#endif
