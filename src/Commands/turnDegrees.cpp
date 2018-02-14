#include "turnDegrees.h"

namespace frc {

turnDegrees::turnDegrees(float ang) {
	//mobility = Mobility::getInstance() needs to be translated
	angle = ang;
	setTimeout(2.0);
}

void turnDegrees::start() {
	//put "Action starting Turn Degrees. Angle: %f Timeout: %f", angle, getTimeout());
	//mobility->turnDegrees(angle); translate
}

void turnDegrees::process() {}


}

} /* namespace frc */
