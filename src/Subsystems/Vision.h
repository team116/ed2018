#ifndef SRC_SUBSYSTEMS_VISION_H_
#define SRC_SUBSYSTEMS_VISION_H_

#include <CameraServer.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Vision {
public:
	Vision();

	enum CameraMode {
		Human,
		Computer,
		None
	};

private:
	void process();

};

#endif /* SRC_SUBSYSTEMS_VISION_H_ */
