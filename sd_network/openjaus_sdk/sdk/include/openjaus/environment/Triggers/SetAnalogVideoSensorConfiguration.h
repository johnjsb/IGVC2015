
/**
\file SetAnalogVideoSensorConfiguration.h

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

#ifndef SETANALOGVIDEOSENSORCONFIGURATION_H
#define SETANALOGVIDEOSENSORCONFIGURATION_H

#include <openjaus.h>

#include "openjaus/environment/Triggers/Fields/RequestIdRecRefRecord.h"
#include "openjaus/environment/Triggers/Fields/AnalogVideoSensorConfigurationListRefArray.h"

namespace openjaus
{
namespace environment
{

/// \class SetAnalogVideoSensorConfiguration SetAnalogVideoSensorConfiguration.h
/// \brief SetAnalogVideoSensorConfiguration Message Implementation.
/// This message is used to set the configuration of the analog video sensor associated with the service. Configuration
/// is based off of each sensor’s capabilities as described in the Report Analog Video Sensor Capabilities message. This
/// message shall cause the receiving service to reply to the sender with a Confirm Sensor Configuration message. If the
/// configuration specified is invalid for a given sensor ID, the confirm message shall contain an Analog Video Error
/// Record for the given Sensor ID however other, valid, configurations specified shall be set (if they exist).
class OPENJAUS_EXPORT SetAnalogVideoSensorConfiguration : public model::Message
{
public:
	SetAnalogVideoSensorConfiguration();
	SetAnalogVideoSensorConfiguration(model::Message *message);
	~SetAnalogVideoSensorConfiguration();
	
	static const uint16_t ID = 0x0806;

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



	RequestIdRecRefRecord& getRequestIdRec(void);

	AnalogVideoSensorConfigurationListRefArray& getAnalogVideoSensorConfigurationList(void);

private:
	RequestIdRecRefRecord requestIdRec;
	AnalogVideoSensorConfigurationListRefArray analogVideoSensorConfigurationList;

};

} // namespace environment
} // namespace openjaus

#endif // SETANALOGVIDEOSENSORCONFIGURATION_H

