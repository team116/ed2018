#ifndef SRC_COMMANDS_COMMANDFILE_H_
#define SRC_COMMANDS_COMMANDFILE_H_

#include <../Robot.h>
#include "closePiston.h"
#include "openPiston.h"
#include "deployRung.h"
#include "holdClimber.h"
#include "moveIntakeOut.h"
#include "moveLeft.h"
#include "moveRight.h"
#include "moveLift.h"
#include "movetoScaleBottom.h"
#include "movetoScaleNeutral.h"
#include "movetoScaletop.h"
#include "movetoSwitchTop.h"
#include "pickUpCube.h"
#include "releaseCube.h"
#include "rotateCube.h"
#include "stopIntake.h"
#include "driveDistance.h"


class Commandfile {
public:
	Commandfile();
};

#endif /* SRC_COMMANDS_COMMANDFILE_H_ */
