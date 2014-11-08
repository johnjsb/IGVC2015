
/**
\file ExecuteList.h

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
#include "openjaus/mobility/Triggers/ExecuteList.h"

namespace openjaus
{
namespace mobility
{

ExecuteList::ExecuteList() : 
	model::Message(),
	speed_mps(),
	elementUID()
{
	this->id = ExecuteList::ID; // Initialize id member
	setType(transport::JAUS_MESSAGE);

	this->presenceVector = 0;

	fields.push_back(&speed_mps);
	speed_mps.setName("Speed");
	speed_mps.setOptional(false);
	// Nothing to init

	fields.push_back(&elementUID);
	elementUID.setName("ElementUID");
	elementUID.setOptional(true);
	elementUID.setInterpretation("Element UID of the starting element. A value of zero (0) indicated the first (head) element of the list.");
	elementUID.setValue(0);

}

ExecuteList::ExecuteList(model::Message *message) :
	model::Message(message),
	speed_mps(),
	elementUID()
{
	this->id = ExecuteList::ID; // Initialize id member
	setType(transport::JAUS_MESSAGE);

	this->presenceVector = 0;

	fields.push_back(&speed_mps);
	speed_mps.setName("Speed");
	speed_mps.setOptional(false);
	// Nothing to init

	fields.push_back(&elementUID);
	elementUID.setName("ElementUID");
	elementUID.setOptional(true);
	elementUID.setInterpretation("Element UID of the starting element. A value of zero (0) indicated the first (head) element of the list.");
	elementUID.setValue(0);


	system::Buffer *payloadBuffer = dynamic_cast<system::Buffer *>(message->getPayload());
	if(payloadBuffer)
	{
		this->from(payloadBuffer);
		payloadBuffer->reset();
	}
}

ExecuteList::~ExecuteList()
{

}


double ExecuteList::getSpeed_mps(void)
{
	return this->speed_mps.getValue();
}

void ExecuteList::setSpeed_mps(double value)
{
	this->speed_mps.setValue(value);
}

uint16_t ExecuteList::getElementUID(void)
{
	return this->elementUID.getValue();
}

void ExecuteList::setElementUID(uint16_t value)
{
	this->elementUID.setValue(value);
}

int ExecuteList::to(system::Buffer *dst)
{
	int byteSize = dst->pack(this->id);
	byteSize += dst->pack(this->presenceVector);
	byteSize += dst->pack(speed_mps);
	if(this->isElementUIDEnabled())
	{
		byteSize += dst->pack(elementUID);
	}
	return byteSize;
}

int ExecuteList::from(system::Buffer *src)
{
	int byteSize = src->unpack(this->id);
	byteSize += src->unpack(this->presenceVector);
	byteSize += src->unpack(speed_mps);
	if(this->isElementUIDEnabled())
	{
		byteSize += src->unpack(elementUID);
	}
	return byteSize;
}

int ExecuteList::length(void)
{
	int length = 0;
	length += sizeof(uint16_t); // Message ID
	length += sizeof(uint8_t); // PresenceVector
	length += speed_mps.length(); // speed_mps
	if(this->isElementUIDEnabled())
	{
		length += elementUID.length(); // elementUID
	}
	return length;
}

std::string ExecuteList::toXml(unsigned char level) const
{
	std::ostringstream prefix;
	for(unsigned char i = 0; i < level; i++)
	{
		prefix << "\t";
	}

	std::ostringstream oss;
	oss << prefix.str() << "<Message name=\"ExecuteList\"";
	oss << " id=\"0x041E\" >\n";
	oss << prefix.str() << "\t" << "<PresenceVector size=\"uint8_t\">\n";
	oss << prefix.str() << "\t" << "\t" << "<value>0x" << std::hex << (uint64_t)this->getPresenceVector() << std::dec << "</value>\n";
	oss << prefix.str() << "\t" << "\t" << "<isElementUIDEnabled value=\"" << std::boolalpha << this->isElementUIDEnabled() << "\"/>\n";
	oss << prefix.str() << "\t" << "</PresenceVector>\n";
	oss << speed_mps.toXml(level+1); // speed_mps
	if(this->isElementUIDEnabled())
	{
		oss << elementUID.toXml(level+1); // elementUID
	}
	oss << prefix.str() << "</Message>\n";
	return oss.str();
}

void ExecuteList::setPresenceVector(uint8_t value)
{
	this->presenceVector = value;
}

uint8_t ExecuteList::getPresenceVector(void) const
{
	return this->presenceVector;
}

bool ExecuteList::isElementUIDEnabled(void) const
{
	return (this->presenceVector & (0x01 << ExecuteList::ELEMENTUID));
}

void ExecuteList::enableElementUID(void)
{
	this->presenceVector |= 0x01 << ExecuteList::ELEMENTUID;
}

void ExecuteList::disableElementUID(void)
{
	this->presenceVector &= ~(0x01 << ExecuteList::ELEMENTUID);
}

} // namespace mobility
} // namespace openjaus


