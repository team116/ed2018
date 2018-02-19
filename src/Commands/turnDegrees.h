#ifndef SRC_COMMANDS_AUTOACTIONS_TURNDEGREES_H_
#define SRC_COMMANDS_AUTOACTIONS_TURNDEGREES_H_

#include "Commands/CommandGroup.h"
#include "../Subsystems/Mobility.h"

namespace frc {

class turnDegrees: public CommandGroup {
public:
	turnDegrees(float ang);

	void start();

	void process();

	void end();

	bool isFinished();

private:
	//Mobility* mobility;
	float angle;
};

} /* namespace frc */

#endif /* SRC_COMMANDS_AUTOACTIONS_TURNDEGREES_H_ */
