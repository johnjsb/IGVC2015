
/**
\file ReportJointVelocity.h

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

#include <openjaus.h>
#include "openjaus/manipulator/Triggers/ReportJointVelocity.h"

namespace openjaus
{
namespace manipulator
{

ReportJointVelocity::ReportJointVelocity() : 
	model::Message(),
	jointVelocityList()
{
	this->id = ReportJointVelocity::ID; // Initialize id member
	setType(transport::JAUS_MESSAGE);


	fields.push_back(&jointVelocityList);
	jointVelocityList.setName("JointVelocityList");
	jointVelocityList.setOptional(false);
	// Nothing to Init

}

ReportJointVelocity::ReportJointVelocity(model::Message *message) :
	model::Message(message),
	jointVelocityList()
{
	this->id = ReportJointVelocity::ID; // Initialize id member
	setType(transport::JAUS_MESSAGE);


	fields.push_back(&jointVelocityList);
	jointVelocityList.setName("JointVelocityList");
	jointVelocityList.setOptional(false);
	// Nothing to Init


	system::Buffer *payloadBuffer = dynamic_cast<system::Buffer *>(message->getPayload());
	if(payloadBuffer)
	{
		this->from(payloadBuffer);
		payloadBuffer->reset();
	}
}

ReportJointVelocity::~ReportJointVelocity()
{

}


JointVelocityList& ReportJointVelocity::getJointVelocityList(void)
{
	return this->jointVelocityList;
}

int ReportJointVelocity::to(system::Buffer *dst)
{
	int byteSize = dst->pack(this->id);
	byteSize += dst->pack(jointVelocityList);
	return byteSize;
}

int ReportJointVelocity::from(system::Buffer *src)
{
	int byteSize = src->unpack(this->id);
	byteSize += src->unpack(jointVelocityList);
	return byteSize;
}

int ReportJointVelocity::length(void)
{
	int length = 0;
	length += sizeof(uint16_t); // Message ID
	length += jointVelocityList.length(); // jointVelocityList
	return length;
}

std::string ReportJointVelocity::toXml(unsigned char level) const
{
	std::ostringstream prefix;
	for(unsigned char i = 0; i < level; i++)
	{
		prefix << "\t";
	}

	std::ostringstream oss;
	oss << prefix.str() << "<Message name=\"ReportJointVelocity\"";
	oss << " id=\"0x4603\" >\n";
	oss << jointVelocityList.toXml(level+1); // jointVelocityList
	oss << prefix.str() << "</Message>\n";
	return oss.str();
}

} // namespace manipulator
} // namespace openjaus


