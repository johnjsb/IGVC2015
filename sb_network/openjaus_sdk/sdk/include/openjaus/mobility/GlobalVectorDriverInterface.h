/**
\file GlobalVectorDriver.h

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

#ifndef GLOBALVECTORDRIVER_SERVICE_INTERFACE_H
#define GLOBALVECTORDRIVER_SERVICE_INTERFACE_H

#include <openjaus.h>
#include "openjaus/core/ManagementInterface.h"
#include "openjaus/mobility/Triggers/SetGlobalVector.h"
#include "openjaus/mobility/Triggers/QueryGlobalVector.h"
#include "openjaus/mobility/Triggers/ReportGlobalVector.h"
namespace openjaus
{
namespace mobility
{

/// \class GlobalVectorDriverInterface GlobalVectorDriverInterface.h
/// \brief Provides an abstract interface for the %GlobalVectorDriver service. 
/// <p>
/// The function of the Global Vector Driver is to perform closed loop control of the desired global heading, altitude
/// and speed of a mobile platform. The Global Vector Driver takes the desired heading of the platform as measured with
/// respect to the global coordinate system and the desired speed of the platform. The desired heading angle is defined
/// in a right hand sense about the Z axis of the global coordinate system (the Z axis points downward) where North is
/// defined as zero degrees. The desired Altitude, measured in accordance with the WGS 84 standard, provides a means
/// through which systems capable of flight can be controlled. For ground-based systems, the Altitude field is ignored.
/// The Global Vector Driver also receives data from the Global Pose Sensor and the Velocity State Sensor. This
/// information allows the Global Vector Driver to perform closed loop control on the platform’s global heading,
/// altitude and speed.
/// </p><br/><br/>
/// <b>URI:</b> %urn:jaus:jss:mobility:GlobalVectorDriver<br/><br/>
/// <b>Version:</b> 1.0<br/><br/>
/// <b>Inherits From:</b><ul>
/// <li>urn:jaus:jss:core:Management</li>
/// </ul>
/// </dd>

class OPENJAUS_EXPORT GlobalVectorDriverInterface
{
public:
	virtual ~GlobalVectorDriverInterface(){};
	
	/// \brief Send a Report Global Vector message.
	/// Send a Report Global Vector message.
	/// \param[in] queryGlobalVector - Input Trigger.
	/// \return ReportGlobalVector Output Message.
	virtual ReportGlobalVector getReportGlobalVector(QueryGlobalVector *queryGlobalVector) = 0;

	/// \brief SetGlobalVector action with input SetGlobalVector.
	/// SetGlobalVector action with input SetGlobalVector.
	/// \param[in]  setGlobalVector - Input Trigger.
	/// \return Whether the message was properly processed by this action. 
	virtual bool setGlobalVector(SetGlobalVector *setGlobalVector) = 0;

	/// \brief isControllingGvdClient condition.
	/// isControllingGvdClient condition.
	/// \param[in]  setGlobalVector - Input Trigger.
	/// \return Whether the condition is true. 
	virtual bool isControllingGvdClient(SetGlobalVector *setGlobalVector) = 0;

};

} // namespace mobility
} // namespace openjaus

#endif // GLOBALVECTORDRIVER_SERVICE_INTERFACE_H
