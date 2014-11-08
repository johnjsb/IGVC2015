
/**
\file ReportGlobalVector.h

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

#ifndef REPORTGLOBALVECTOR_H
#define REPORTGLOBALVECTOR_H

#include <openjaus.h>

#include "openjaus/mobility/Triggers/Fields/LinearSpeedScaledInteger.h"
#include "openjaus/mobility/Triggers/Fields/JausAltitudeScaledInteger.h"
#include "openjaus/mobility/Triggers/Fields/OrientationScaledInteger.h"
#include "openjaus/mobility/Triggers/Fields/OrientationScaledInteger.h"
#include "openjaus/mobility/Triggers/Fields/OrientationScaledInteger.h"

namespace openjaus
{
namespace mobility
{

/// \class ReportGlobalVector ReportGlobalVector.h
/// \brief ReportGlobalVector Message Implementation.
/// This message is used to provide the receiver the current values of the commanded global vector. The message data of
/// this message is identical to ID 0407h: SetGlobalVector.
class OPENJAUS_EXPORT ReportGlobalVector : public model::Message
{
public:
	ReportGlobalVector();
	ReportGlobalVector(model::Message *message);
	~ReportGlobalVector();
	
	static const uint16_t ID = 0x4407;

	/// \brief Pack this message to the given openjaus::system::Buffer. 
	/// \copybrief
	/// \param[out] dst - The destination openjaus::system::Buffer to which this message will be packed.
	/// \return The number of bytes packed into the destination buffer
	virtual int to(system::Buffer *dst);	

	/// \brief Unpack this message from the given openjaus::system::Buffer.
	/// \copybrief
	/// \param[in] src - The source openjaus::system::Buffer from which this message will be unpacked.
	/// \return The number of bytes unpacked from the source buffer
	virtual int from(system::Buffer *src);

	/// \brief Get the number of bytes this message would occupy in a serialized buffer. 
	/// \copybrief
	/// \return The number of bytes this message would occupy in a buffer
	virtual int length();
	
	/// \brief Used to serialize the runtime state of the message to an XML format. 
	/// \copybrief
	/// \param[in] level - Used to determine how many tabs are inserted per line for pretty formating. 
	/// \return The serialized XML string
	std::string toXml(unsigned char level=0) const;

	void setPresenceVector(uint8_t value);
	uint8_t getPresenceVector(void) const;
	bool isSpeedEnabled(void) const;
	void enableSpeed(void);
	void disableSpeed(void);
	bool isAltitudeEnabled(void) const;
	void enableAltitude(void);
	void disableAltitude(void);
	bool isHeadingEnabled(void) const;
	void enableHeading(void);
	void disableHeading(void);
	bool isRollEnabled(void) const;
	void enableRoll(void);
	void disableRoll(void);
	bool isPitchEnabled(void) const;
	void enablePitch(void);
	void disablePitch(void);


	double getSpeed_mps(void);
	void setSpeed_mps(double value);

	double getAltitude_m(void);
	void setAltitude_m(double value);

	double getHeading_rad(void);
	void setHeading_rad(double value);

	double getRoll_rad(void);
	void setRoll_rad(double value);

	double getPitch_rad(void);
	void setPitch_rad(double value);

private:
	LinearSpeedScaledInteger speed_mps;
	JausAltitudeScaledInteger altitude_m;
	OrientationScaledInteger heading_rad;
	OrientationScaledInteger roll_rad;
	OrientationScaledInteger pitch_rad;

	uint8_t presenceVector;
	enum pvEnum {SPEED_MPS = 0, ALTITUDE_M = 1, HEADING_RAD = 2, ROLL_RAD = 3, PITCH_RAD = 4};
};

} // namespace mobility
} // namespace openjaus

#endif // REPORTGLOBALVECTOR_H


