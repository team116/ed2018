#ifndef SRC_SUBSYSTEMS_HOOK_H_
#define SRC_SUBSYSTEMS_HOOK_H_

#include <Robot.h>
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "src/RobotMap.h"
#include <Solenoid.h>

class Hook: public Subsystem {
private:
	shared_ptr<Solenoid> HOOK_SOLENOID = {1,2};
public:
	Hook();
	void InitDefaultCommand() override;
	void Periodic() override;

	void ExtendHook();
};

#endif /* SRC_SUBSYSTEMS_HOOK_H_ */
