/**
\file AccelerationStateSensor.h

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

#ifndef ACCELERATIONSTATESENSOR_SERVICE_INTERFACE_H
#define ACCELERATIONSTATESENSOR_SERVICE_INTERFACE_H

#include <openjaus.h>
#include "openjaus/core/EventsInterface.h"
#include "openjaus/mobility/Triggers/QueryAccelerationState.h"
#include "openjaus/mobility/Triggers/ReportAccelerationState.h"
namespace openjaus
{
namespace mobility
{

/// \class AccelerationStateSensorInterface AccelerationStateSensorInterface.h
/// \brief Provides an abstract interface for the %AccelerationStateSensor service. 
/// <p>
/// This service reports the acceleration  state of the unmanned platform.  The Acceleration State Sensor reports the
/// acceleration state that is the first derivative (the rate of change) of the velocity state reported by the Velocity
/// State Sensor. Refer to the description on Velocity State Sensor for coordinate details. 
/// </p><br/><br/>
/// <b>URI:</b> %urn:jaus:jss:mobility:AccelerationStateSensor<br/><br/>
/// <b>Version:</b> 1.0<br/><br/>
/// <b>Inherits From:</b><ul>
/// <li>urn:jaus:jss:core:Events</li>
/// </ul>
/// </dd>

class OPENJAUS_EXPORT AccelerationStateSensorInterface
{
public:
	virtual ~AccelerationStateSensorInterface(){};
	
	/// \brief Send action for ReportAccelerationState with input message QueryAccelerationState.
	/// Send action for ReportAccelerationState with input message QueryAccelerationState.
	/// \param[in] queryAccelerationState - Input Trigger.
	/// \return ReportAccelerationState Output Message.
	virtual ReportAccelerationState getReportAccelerationState(QueryAccelerationState *queryAccelerationState) = 0;

};

} // namespace mobility
} // namespace openjaus

#endif // ACCELERATIONSTATESENSOR_SERVICE_INTERFACE_H
