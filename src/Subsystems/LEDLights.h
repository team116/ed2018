#ifndef LEDLIGHTS_H
#define LEDLIGHTS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class LEDLights: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<frc::DigitalOutput> lED;

public:
	LEDLights();
	void InitDefaultCommand() override;
	void Periodic() override;
};

#endif
