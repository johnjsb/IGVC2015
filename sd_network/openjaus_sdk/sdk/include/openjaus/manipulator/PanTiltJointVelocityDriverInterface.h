/**
\file PanTiltJointVelocityDriver.h

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

#ifndef PANTILTJOINTVELOCITYDRIVER_SERVICE_INTERFACE_H
#define PANTILTJOINTVELOCITYDRIVER_SERVICE_INTERFACE_H

#include <openjaus.h>
#include "openjaus/manipulator/Triggers/QueryPanTiltSpecifications.h"
#include "openjaus/manipulator/Triggers/SetPanTiltJointVelocity.h"
#include "openjaus/manipulator/Triggers/SetPanTiltMotionProfile.h"
#include "openjaus/manipulator/Triggers/QueryCommandedPanTiltJointVelocity.h"
#include "openjaus/manipulator/Triggers/QueryPanTiltMotionProfile.h"
#include "openjaus/manipulator/Triggers/ReportPanTiltSpecifications.h"
#include "openjaus/manipulator/Triggers/ReportCommandedPanTiltJointVelocity.h"
#include "openjaus/manipulator/Triggers/ReportPanTiltMotionProfile.h"
namespace openjaus
{
namespace manipulator
{

/// \class PanTiltJointVelocityDriverInterface PanTiltJointVelocityDriverInterface.h
/// \brief Provides an abstract interface for the %PanTiltJointVelocityDriver service. 
/// <p>
/// The function of the Pan Tilt Joint Velocity Joint Velocity Driver is to perform closed-loop joint velocity control. 
/// The input is the desired instantaneous desired joint velocities for the pan tilt mechanism.  The Set Pan Tilt Motion
/// Profile message is used to set maximum velocity and acceleration rates for both of the variable joint parameters.
/// All motions utilize the motion profile data that was most recently sent.  Default settings are not assumed so that
/// upon initialization this message must be sent before the first Set Pan Tilt Joint Velocity message is sent.  It is
/// assumed that the pan tilt mechanism begins motion immediately after receiving the Set Pan Tilt Joint Velocity
/// message.
/// </p><br/><br/>
/// <b>URI:</b> %urn:jaus:jss:manipulator:PanTiltJointVelocityDriver<br/><br/>
/// <b>Version:</b> 1.0<br/><br/>
/// <b>Inherits From:</b><ul>
/// </ul>
/// </dd>

class OPENJAUS_EXPORT PanTiltJointVelocityDriverInterface
{
public:
	virtual ~PanTiltJointVelocityDriverInterface(){};
	
	/// \brief Set the desired velocities for the individual joints of the Pan Tilt mechanism
	/// Set the desired velocities for the individual joints of the Pan Tilt mechanism
	/// \param[in]  setPanTiltJointVelocity - Input Trigger.
	/// \return Whether the message was properly processed by this action. 
	virtual bool setPanTiltJointVelocity(SetPanTiltJointVelocity *setPanTiltJointVelocity) = 0;

	/// \brief Set the motion profile parameters for the Pan Tilt mechanism
	/// Set the motion profile parameters for the Pan Tilt mechanism
	/// \param[in]  setPanTiltMotionProfile - Input Trigger.
	/// \return Whether the message was properly processed by this action. 
	virtual bool setPanTiltMotionProfile(SetPanTiltMotionProfile *setPanTiltMotionProfile) = 0;

	/// \brief Send a report Pan Tilt specs message
	/// Send a report Pan Tilt specs message
	/// \param[in] queryPanTiltSpecifications - Input Trigger.
	/// \return ReportPanTiltSpecifications Output Message.
	virtual ReportPanTiltSpecifications getReportPanTiltSpecifications(QueryPanTiltSpecifications *queryPanTiltSpecifications) = 0;

	/// \brief Send a Report Commanded Pan Tilt Joint Velocity message
	/// Send a Report Commanded Pan Tilt Joint Velocity message
	/// \param[in] queryCommandedPanTiltJointVelocity - Input Trigger.
	/// \return ReportCommandedPanTiltJointVelocity Output Message.
	virtual ReportCommandedPanTiltJointVelocity getReportCommandedPanTiltJointVelocity(QueryCommandedPanTiltJointVelocity *queryCommandedPanTiltJointVelocity) = 0;

	/// \brief Send a Report Pan Tilt Motion Profile message
	/// Send a Report Pan Tilt Motion Profile message
	/// \param[in] queryPanTiltMotionProfile - Input Trigger.
	/// \return ReportPanTiltMotionProfile Output Message.
	virtual ReportPanTiltMotionProfile getReportPanTiltMotionProfile(QueryPanTiltMotionProfile *queryPanTiltMotionProfile) = 0;

	/// \brief isControllingPanTiltVelocityClient condition.
	/// isControllingPanTiltVelocityClient condition.
	/// \param[in]  setPanTiltJointVelocity - Input Trigger.
	/// \return Whether the condition is true. 
	virtual bool isControllingPanTiltVelocityClient(SetPanTiltJointVelocity *setPanTiltJointVelocity) = 0;

	/// \brief isControllingPanTiltVelocityClient condition.
	/// isControllingPanTiltVelocityClient condition.
	/// \param[in]  setPanTiltMotionProfile - Input Trigger.
	/// \return Whether the condition is true. 
	virtual bool isControllingPanTiltVelocityClient(SetPanTiltMotionProfile *setPanTiltMotionProfile) = 0;

};

} // namespace manipulator
} // namespace openjaus

#endif // PANTILTJOINTVELOCITYDRIVER_SERVICE_INTERFACE_H