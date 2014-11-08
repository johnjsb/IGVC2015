/**
\file PanTiltJointPositionDriver.h

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

#ifndef PANTILTJOINTPOSITIONDRIVER_SERVICE_INTERFACE_H
#define PANTILTJOINTPOSITIONDRIVER_SERVICE_INTERFACE_H

#include <openjaus.h>
#include "openjaus/manipulator/Triggers/QueryPanTiltSpecifications.h"
#include "openjaus/manipulator/Triggers/QueryCommandedPanTiltJointPosition.h"
#include "openjaus/manipulator/Triggers/QueryPanTiltMotionProfile.h"
#include "openjaus/manipulator/Triggers/SetPanTiltJointPosition.h"
#include "openjaus/manipulator/Triggers/SetPanTiltMotionProfile.h"
#include "openjaus/manipulator/Triggers/ReportPanTiltSpecifications.h"
#include "openjaus/manipulator/Triggers/ReportCommandedPanTiltJointPosition.h"
#include "openjaus/manipulator/Triggers/ReportPanTiltMotionProfile.h"
namespace openjaus
{
namespace manipulator
{

/// \class PanTiltJointPositionDriverInterface PanTiltJointPositionDriverInterface.h
/// \brief Provides an abstract interface for the %PanTiltJointPositionDriver service. 
/// <p>
/// The function of the Pan Tilt Joint Position Driver is to perform closed-loop joint position control.  A single
/// target is provided via the Set Pan Tilt Joint Position message.  The target remains unchanged until a new Set Pan
/// Tilt Joint Position message is received.  The Set Pan Tilt Motion Profile message is used to set maximum velocity
/// and acceleration rates for each of the two variable joint parameters. All motions utilize the motion profile data
/// that was most recently sent.  Default settings are not assumed so that upon initialization this message must be sent
/// before the first Set Pan Tilt Joint Position message is sent.  The desired joint parameter values are input to the
/// service via the Set Pan Tilt Joint Position message.
/// </p><br/><br/>
/// <b>URI:</b> %urn:jaus:jss:manipulator:PanTiltJointPositionDriver<br/><br/>
/// <b>Version:</b> 1.0<br/><br/>
/// <b>Inherits From:</b><ul>
/// </ul>
/// </dd>

class OPENJAUS_EXPORT PanTiltJointPositionDriverInterface
{
public:
	virtual ~PanTiltJointPositionDriverInterface(){};
	
	/// \brief Set the desired joint values for the pan tilt mechanism
	/// Set the desired joint values for the pan tilt mechanism
	/// \param[in]  setPanTiltJointPosition - Input Trigger.
	/// \return Whether the message was properly processed by this action. 
	virtual bool setPanTiltJointPosition(SetPanTiltJointPosition *setPanTiltJointPosition) = 0;

	/// \brief Set the motion profile parameters for the pan tilt mechanism
	/// Set the motion profile parameters for the pan tilt mechanism
	/// \param[in]  setPanTiltMotionProfile - Input Trigger.
	/// \return Whether the message was properly processed by this action. 
	virtual bool setPanTiltMotionProfile(SetPanTiltMotionProfile *setPanTiltMotionProfile) = 0;

	/// \brief Send a report Pan Tilt specifications message
	/// Send a report Pan Tilt specifications message
	/// \param[in] queryPanTiltSpecifications - Input Trigger.
	/// \return ReportPanTiltSpecifications Output Message.
	virtual ReportPanTiltSpecifications getReportPanTiltSpecifications(QueryPanTiltSpecifications *queryPanTiltSpecifications) = 0;

	/// \brief Send a Report Commanded Pan Tilt Joint Position message
	/// Send a Report Commanded Pan Tilt Joint Position message
	/// \param[in] queryCommandedPanTiltJointPosition - Input Trigger.
	/// \return ReportCommandedPanTiltJointPosition Output Message.
	virtual ReportCommandedPanTiltJointPosition getReportCommandedPanTiltJointPosition(QueryCommandedPanTiltJointPosition *queryCommandedPanTiltJointPosition) = 0;

	/// \brief Send a Report Pan Tilt Motion Profile message
	/// Send a Report Pan Tilt Motion Profile message
	/// \param[in] queryPanTiltMotionProfile - Input Trigger.
	/// \return ReportPanTiltMotionProfile Output Message.
	virtual ReportPanTiltMotionProfile getReportPanTiltMotionProfile(QueryPanTiltMotionProfile *queryPanTiltMotionProfile) = 0;

	/// \brief isControllingPanTiltJointPositionClient condition.
	/// isControllingPanTiltJointPositionClient condition.
	/// \param[in]  setPanTiltJointPosition - Input Trigger.
	/// \return Whether the condition is true. 
	virtual bool isControllingPanTiltJointPositionClient(SetPanTiltJointPosition *setPanTiltJointPosition) = 0;

	/// \brief isControllingPanTiltJointPositionClient condition.
	/// isControllingPanTiltJointPositionClient condition.
	/// \param[in]  setPanTiltMotionProfile - Input Trigger.
	/// \return Whether the condition is true. 
	virtual bool isControllingPanTiltJointPositionClient(SetPanTiltMotionProfile *setPanTiltMotionProfile) = 0;

};

} // namespace manipulator
} // namespace openjaus

#endif // PANTILTJOINTPOSITIONDRIVER_SERVICE_INTERFACE_H
