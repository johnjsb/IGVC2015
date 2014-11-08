
/**
\file ReportVelocityCommand.h

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
#include "openjaus/mobility/Triggers/ReportVelocityCommand.h"

namespace openjaus
{
namespace mobility
{

ReportVelocityCommand::ReportVelocityCommand() : 
	model::Message(),
	commandType(),
	velocityX_mps(),
	velocityY_mps(),
	velocityZ_mps(),
	rollRate_rps(),
	pitchRate_rps(),
	yawRate_rps()
{
	this->id = ReportVelocityCommand::ID; // Initialize id member
	setType(transport::JAUS_MESSAGE);

	this->presenceVector = 0;

	fields.push_back(&commandType);
	commandType.setName("CommandType");
	commandType.setOptional(false);
	// Nothing to init

	fields.push_back(&velocityX_mps);
	velocityX_mps.setName("VelocityX");
	velocityX_mps.setOptional(true);
	// Nothing to init

	fields.push_back(&velocityY_mps);
	velocityY_mps.setName("VelocityY");
	velocityY_mps.setOptional(true);
	// Nothing to init

	fields.push_back(&velocityZ_mps);
	velocityZ_mps.setName("VelocityZ");
	velocityZ_mps.setOptional(true);
	// Nothing to init

	fields.push_back(&rollRate_rps);
	rollRate_rps.setName("RollRate");
	rollRate_rps.setOptional(true);
	// Nothing to init

	fields.push_back(&pitchRate_rps);
	pitchRate_rps.setName("PitchRate");
	pitchRate_rps.setOptional(true);
	// Nothing to init

	fields.push_back(&yawRate_rps);
	yawRate_rps.setName("YawRate");
	yawRate_rps.setOptional(true);
	// Nothing to init

}

ReportVelocityCommand::ReportVelocityCommand(model::Message *message) :
	model::Message(message),
	commandType(),
	velocityX_mps(),
	velocityY_mps(),
	velocityZ_mps(),
	rollRate_rps(),
	pitchRate_rps(),
	yawRate_rps()
{
	this->id = ReportVelocityCommand::ID; // Initialize id member
	setType(transport::JAUS_MESSAGE);

	this->presenceVector = 0;

	fields.push_back(&commandType);
	commandType.setName("CommandType");
	commandType.setOptional(false);
	// Nothing to init

	fields.push_back(&velocityX_mps);
	velocityX_mps.setName("VelocityX");
	velocityX_mps.setOptional(true);
	// Nothing to init

	fields.push_back(&velocityY_mps);
	velocityY_mps.setName("VelocityY");
	velocityY_mps.setOptional(true);
	// Nothing to init

	fields.push_back(&velocityZ_mps);
	velocityZ_mps.setName("VelocityZ");
	velocityZ_mps.setOptional(true);
	// Nothing to init

	fields.push_back(&rollRate_rps);
	rollRate_rps.setName("RollRate");
	rollRate_rps.setOptional(true);
	// Nothing to init

	fields.push_back(&pitchRate_rps);
	pitchRate_rps.setName("PitchRate");
	pitchRate_rps.setOptional(true);
	// Nothing to init

	fields.push_back(&yawRate_rps);
	yawRate_rps.setName("YawRate");
	yawRate_rps.setOptional(true);
	// Nothing to init


	system::Buffer *payloadBuffer = dynamic_cast<system::Buffer *>(message->getPayload());
	if(payloadBuffer)
	{
		this->from(payloadBuffer);
		payloadBuffer->reset();
	}
}

ReportVelocityCommand::~ReportVelocityCommand()
{

}


VelocityCommandTypeEnumeration::VelocityCommandTypeEnum ReportVelocityCommand::getCommandType(void)
{
	return this->commandType.getValue();
}

void ReportVelocityCommand::setCommandType(VelocityCommandTypeEnumeration::VelocityCommandTypeEnum value)
{
	this->commandType.setValue(value);
}

double ReportVelocityCommand::getVelocityX_mps(void)
{
	return this->velocityX_mps.getValue();
}

void ReportVelocityCommand::setVelocityX_mps(double value)
{
	this->velocityX_mps.setValue(value);
}

double ReportVelocityCommand::getVelocityY_mps(void)
{
	return this->velocityY_mps.getValue();
}

void ReportVelocityCommand::setVelocityY_mps(double value)
{
	this->velocityY_mps.setValue(value);
}

double ReportVelocityCommand::getVelocityZ_mps(void)
{
	return this->velocityZ_mps.getValue();
}

void ReportVelocityCommand::setVelocityZ_mps(double value)
{
	this->velocityZ_mps.setValue(value);
}

double ReportVelocityCommand::getRollRate_rps(void)
{
	return this->rollRate_rps.getValue();
}

void ReportVelocityCommand::setRollRate_rps(double value)
{
	this->rollRate_rps.setValue(value);
}

double ReportVelocityCommand::getPitchRate_rps(void)
{
	return this->pitchRate_rps.getValue();
}

void ReportVelocityCommand::setPitchRate_rps(double value)
{
	this->pitchRate_rps.setValue(value);
}

double ReportVelocityCommand::getYawRate_rps(void)
{
	return this->yawRate_rps.getValue();
}

void ReportVelocityCommand::setYawRate_rps(double value)
{
	this->yawRate_rps.setValue(value);
}

int ReportVelocityCommand::to(system::Buffer *dst)
{
	int byteSize = dst->pack(this->id);
	byteSize += dst->pack(this->presenceVector);
	byteSize += dst->pack(commandType);
	if(this->isVelocityXEnabled())
	{
		byteSize += dst->pack(velocityX_mps);
	}
	if(this->isVelocityYEnabled())
	{
		byteSize += dst->pack(velocityY_mps);
	}
	if(this->isVelocityZEnabled())
	{
		byteSize += dst->pack(velocityZ_mps);
	}
	if(this->isRollRateEnabled())
	{
		byteSize += dst->pack(rollRate_rps);
	}
	if(this->isPitchRateEnabled())
	{
		byteSize += dst->pack(pitchRate_rps);
	}
	if(this->isYawRateEnabled())
	{
		byteSize += dst->pack(yawRate_rps);
	}
	return byteSize;
}

int ReportVelocityCommand::from(system::Buffer *src)
{
	int byteSize = src->unpack(this->id);
	byteSize += src->unpack(this->presenceVector);
	byteSize += src->unpack(commandType);
	if(this->isVelocityXEnabled())
	{
		byteSize += src->unpack(velocityX_mps);
	}
	if(this->isVelocityYEnabled())
	{
		byteSize += src->unpack(velocityY_mps);
	}
	if(this->isVelocityZEnabled())
	{
		byteSize += src->unpack(velocityZ_mps);
	}
	if(this->isRollRateEnabled())
	{
		byteSize += src->unpack(rollRate_rps);
	}
	if(this->isPitchRateEnabled())
	{
		byteSize += src->unpack(pitchRate_rps);
	}
	if(this->isYawRateEnabled())
	{
		byteSize += src->unpack(yawRate_rps);
	}
	return byteSize;
}

int ReportVelocityCommand::length(void)
{
	int length = 0;
	length += sizeof(uint16_t); // Message ID
	length += sizeof(uint8_t); // PresenceVector
	length += commandType.length(); // commandType
	if(this->isVelocityXEnabled())
	{
		length += velocityX_mps.length(); // velocityX_mps
	}
	if(this->isVelocityYEnabled())
	{
		length += velocityY_mps.length(); // velocityY_mps
	}
	if(this->isVelocityZEnabled())
	{
		length += velocityZ_mps.length(); // velocityZ_mps
	}
	if(this->isRollRateEnabled())
	{
		length += rollRate_rps.length(); // rollRate_rps
	}
	if(this->isPitchRateEnabled())
	{
		length += pitchRate_rps.length(); // pitchRate_rps
	}
	if(this->isYawRateEnabled())
	{
		length += yawRate_rps.length(); // yawRate_rps
	}
	return length;
}

std::string ReportVelocityCommand::toXml(unsigned char level) const
{
	std::ostringstream prefix;
	for(unsigned char i = 0; i < level; i++)
	{
		prefix << "\t";
	}

	std::ostringstream oss;
	oss << prefix.str() << "<Message name=\"ReportVelocityCommand\"";
	oss << " id=\"0x4415\" >\n";
	oss << prefix.str() << "\t" << "<PresenceVector size=\"uint8_t\">\n";
	oss << prefix.str() << "\t" << "\t" << "<value>0x" << std::hex << (uint64_t)this->getPresenceVector() << std::dec << "</value>\n";
	oss << prefix.str() << "\t" << "\t" << "<isVelocityXEnabled value=\"" << std::boolalpha << this->isVelocityXEnabled() << "\"/>\n";
	oss << prefix.str() << "\t" << "\t" << "<isVelocityYEnabled value=\"" << std::boolalpha << this->isVelocityYEnabled() << "\"/>\n";
	oss << prefix.str() << "\t" << "\t" << "<isVelocityZEnabled value=\"" << std::boolalpha << this->isVelocityZEnabled() << "\"/>\n";
	oss << prefix.str() << "\t" << "\t" << "<isRollRateEnabled value=\"" << std::boolalpha << this->isRollRateEnabled() << "\"/>\n";
	oss << prefix.str() << "\t" << "\t" << "<isPitchRateEnabled value=\"" << std::boolalpha << this->isPitchRateEnabled() << "\"/>\n";
	oss << prefix.str() << "\t" << "\t" << "<isYawRateEnabled value=\"" << std::boolalpha << this->isYawRateEnabled() << "\"/>\n";
	oss << prefix.str() << "\t" << "</PresenceVector>\n";
	oss << commandType.toXml(level+1); // commandType
	if(this->isVelocityXEnabled())
	{
		oss << velocityX_mps.toXml(level+1); // velocityX_mps
	}
	if(this->isVelocityYEnabled())
	{
		oss << velocityY_mps.toXml(level+1); // velocityY_mps
	}
	if(this->isVelocityZEnabled())
	{
		oss << velocityZ_mps.toXml(level+1); // velocityZ_mps
	}
	if(this->isRollRateEnabled())
	{
		oss << rollRate_rps.toXml(level+1); // rollRate_rps
	}
	if(this->isPitchRateEnabled())
	{
		oss << pitchRate_rps.toXml(level+1); // pitchRate_rps
	}
	if(this->isYawRateEnabled())
	{
		oss << yawRate_rps.toXml(level+1); // yawRate_rps
	}
	oss << prefix.str() << "</Message>\n";
	return oss.str();
}

void ReportVelocityCommand::setPresenceVector(uint8_t value)
{
	this->presenceVector = value;
}

uint8_t ReportVelocityCommand::getPresenceVector(void) const
{
	return this->presenceVector;
}

bool ReportVelocityCommand::isVelocityXEnabled(void) const
{
	return (this->presenceVector & (0x01 << ReportVelocityCommand::VELOCITYX_MPS));
}

void ReportVelocityCommand::enableVelocityX(void)
{
	this->presenceVector |= 0x01 << ReportVelocityCommand::VELOCITYX_MPS;
}

void ReportVelocityCommand::disableVelocityX(void)
{
	this->presenceVector &= ~(0x01 << ReportVelocityCommand::VELOCITYX_MPS);
}

bool ReportVelocityCommand::isVelocityYEnabled(void) const
{
	return (this->presenceVector & (0x01 << ReportVelocityCommand::VELOCITYY_MPS));
}

void ReportVelocityCommand::enableVelocityY(void)
{
	this->presenceVector |= 0x01 << ReportVelocityCommand::VELOCITYY_MPS;
}

void ReportVelocityCommand::disableVelocityY(void)
{
	this->presenceVector &= ~(0x01 << ReportVelocityCommand::VELOCITYY_MPS);
}

bool ReportVelocityCommand::isVelocityZEnabled(void) const
{
	return (this->presenceVector & (0x01 << ReportVelocityCommand::VELOCITYZ_MPS));
}

void ReportVelocityCommand::enableVelocityZ(void)
{
	this->presenceVector |= 0x01 << ReportVelocityCommand::VELOCITYZ_MPS;
}

void ReportVelocityCommand::disableVelocityZ(void)
{
	this->presenceVector &= ~(0x01 << ReportVelocityCommand::VELOCITYZ_MPS);
}

bool ReportVelocityCommand::isRollRateEnabled(void) const
{
	return (this->presenceVector & (0x01 << ReportVelocityCommand::ROLLRATE_RPS));
}

void ReportVelocityCommand::enableRollRate(void)
{
	this->presenceVector |= 0x01 << ReportVelocityCommand::ROLLRATE_RPS;
}

void ReportVelocityCommand::disableRollRate(void)
{
	this->presenceVector &= ~(0x01 << ReportVelocityCommand::ROLLRATE_RPS);
}

bool ReportVelocityCommand::isPitchRateEnabled(void) const
{
	return (this->presenceVector & (0x01 << ReportVelocityCommand::PITCHRATE_RPS));
}

void ReportVelocityCommand::enablePitchRate(void)
{
	this->presenceVector |= 0x01 << ReportVelocityCommand::PITCHRATE_RPS;
}

void ReportVelocityCommand::disablePitchRate(void)
{
	this->presenceVector &= ~(0x01 << ReportVelocityCommand::PITCHRATE_RPS);
}

bool ReportVelocityCommand::isYawRateEnabled(void) const
{
	return (this->presenceVector & (0x01 << ReportVelocityCommand::YAWRATE_RPS));
}

void ReportVelocityCommand::enableYawRate(void)
{
	this->presenceVector |= 0x01 << ReportVelocityCommand::YAWRATE_RPS;
}

void ReportVelocityCommand::disableYawRate(void)
{
	this->presenceVector &= ~(0x01 << ReportVelocityCommand::YAWRATE_RPS);
}

} // namespace mobility
} // namespace openjaus


