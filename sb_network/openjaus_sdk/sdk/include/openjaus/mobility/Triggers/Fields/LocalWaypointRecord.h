
/**
\file LocalWaypointRec.h

\par Copyright
Copyright (c) 2012, OpenJAUS, LLC
All rights reserved.

This file is part of the OpenJAUS Software Development Kit (SDK). This 
software is distributed under one of two licenses, the OpenJAUS SDK 
Commercial End User License Agreement or the OpenJAUS SDK Non-Commercial 
End User License Agreement. The appropriate licensing details were included 
in with your developer credentials and software download. See the LICENSE 
file included with this software for full details.
 
THIS SOFTWARE IS PROVIDED BY THE LICENSOR (OPENJAUS LCC) "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE LICENSOR BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THE SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
DAMAGE. THE LICENSOR DOES NOT WARRANT THAT THE LICENSED SOFTWARE WILL MEET
LICENSEE'S REQUIREMENTS OR THAT THE OPERATION OF THE LICENSED SOFTWARE
WILL BE UNINTERRUPTED OR ERROR-FREE, OR THAT ERRORS IN THE LICENSED
SOFTWARE WILL BE CORRECTED.

\ Software History
- [2011-08-23] - Added AS6057: Manipulators
- [2011-08-01] - Added AS6060: Environment Sensing
- [2011-06-16] - First Release 

*/

#ifndef LOCALWAYPOINTRECORD_H
#define LOCALWAYPOINTRECORD_H

#include <openjaus.h>
#include "openjaus/mobility/Triggers/Fields/LocalPositionScaledInteger.h"
#include "openjaus/mobility/Triggers/Fields/LocalPositionScaledInteger.h"
#include "openjaus/mobility/Triggers/Fields/LocalPositionScaledInteger.h"
#include "openjaus/mobility/Triggers/Fields/OrientationScaledInteger.h"
#include "openjaus/mobility/Triggers/Fields/OrientationScaledInteger.h"
#include "openjaus/mobility/Triggers/Fields/OrientationScaledInteger.h"
#include "openjaus/mobility/Triggers/Fields/WaypointToleranceRefScaledInteger.h"
#include "openjaus/mobility/Triggers/Fields/PathToleranceRefScaledInteger.h"

namespace openjaus
{
namespace mobility
{

class OPENJAUS_EXPORT LocalWaypointRecord : public openjaus::model::fields::Record
{
public:
	LocalWaypointRecord();
	LocalWaypointRecord(const LocalWaypointRecord &source);
	~LocalWaypointRecord();

	void copy(LocalWaypointRecord& source);
	virtual int to(system::Buffer *dst);
	virtual int from(system::Buffer *src);
	virtual int length(void);
	std::string toXml(unsigned char level=0) const;
	
	void setPresenceVector(uint8_t value);
	uint8_t getPresenceVector(void) const;
	bool isZEnabled(void) const;
	void enableZ(void);
	void disableZ(void);

	bool isRollEnabled(void) const;
	void enableRoll(void);
	void disableRoll(void);

	bool isPitchEnabled(void) const;
	void enablePitch(void);
	void disablePitch(void);

	bool isYawEnabled(void) const;
	void enableYaw(void);
	void disableYaw(void);

	bool isWaypointToleranceEnabled(void) const;
	void enableWaypointTolerance(void);
	void disableWaypointTolerance(void);

	bool isPathToleranceEnabled(void) const;
	void enablePathTolerance(void);
	void disablePathTolerance(void);


	double getX_m(void);
	void setX_m(double value);

	double getY_m(void);
	void setY_m(double value);

	double getZ_m(void);
	void setZ_m(double value);

	double getRoll_rad(void);
	void setRoll_rad(double value);

	double getPitch_rad(void);
	void setPitch_rad(double value);

	double getYaw_rad(void);
	void setYaw_rad(double value);

	double getWaypointTolerance_m(void);
	void setWaypointTolerance_m(double value);

	double getPathTolerance(void);
	void setPathTolerance(double value);

protected:
	LocalPositionScaledInteger x_m;
	LocalPositionScaledInteger y_m;
	LocalPositionScaledInteger z_m;
	OrientationScaledInteger roll_rad;
	OrientationScaledInteger pitch_rad;
	OrientationScaledInteger yaw_rad;
	WaypointToleranceRefScaledInteger waypointTolerance_m;
	PathToleranceRefScaledInteger pathTolerance;

	uint8_t presenceVector;
	enum pvEnum {Z_M = 0, ROLL_RAD = 1, PITCH_RAD = 2, YAW_RAD = 3, WAYPOINTTOLERANCE_M = 4, PATHTOLERANCE = 5};
};

} // namespace mobility
} // namespace openjaus

#endif // LOCALWAYPOINTRECORD_H
