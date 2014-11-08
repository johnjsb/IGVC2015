

/**
\file TimeBitField.h

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
#include "openjaus/core/Triggers/Fields/TimeBitField.h"

namespace openjaus
{
namespace core
{

TimeBitField::TimeBitField() : 
	milliseconds(),
	seconds(),
	minutes(),
	hour(),
	day()
{

}

TimeBitField::~TimeBitField()
{

}

bool TimeBitField::setMilliseconds(long value)
{
	if(value < MILLISECONDS_MIN_VALUE || value > MILLISECONDS_MAX_VALUE)
	{
		//< \todo: Throw error?
		return false;
	}
	
	this->milliseconds = value;
	return true;
}
    
long TimeBitField::getMilliseconds(void) const
{
	return 	this->milliseconds;
}

bool TimeBitField::setSeconds(long value)
{
	if(value < SECONDS_MIN_VALUE || value > SECONDS_MAX_VALUE)
	{
		//< \todo: Throw error?
		return false;
	}
	
	this->seconds = value;
	return true;
}
    
long TimeBitField::getSeconds(void) const
{
	return 	this->seconds;
}

bool TimeBitField::setMinutes(long value)
{
	if(value < MINUTES_MIN_VALUE || value > MINUTES_MAX_VALUE)
	{
		//< \todo: Throw error?
		return false;
	}
	
	this->minutes = value;
	return true;
}
    
long TimeBitField::getMinutes(void) const
{
	return 	this->minutes;
}

bool TimeBitField::setHour(long value)
{
	if(value < HOUR_MIN_VALUE || value > HOUR_MAX_VALUE)
	{
		//< \todo: Throw error?
		return false;
	}
	
	this->hour = value;
	return true;
}
    
long TimeBitField::getHour(void) const
{
	return 	this->hour;
}

bool TimeBitField::setDay(long value)
{
	if(value < DAY_MIN_VALUE || value > DAY_MAX_VALUE)
	{
		//< \todo: Throw error?
		return false;
	}
	
	this->day = value;
	return true;
}
    
long TimeBitField::getDay(void) const
{
	return 	this->day;
}


int TimeBitField::to(system::Buffer *dst)
{
	uint32_t intValue = 0;

	intValue |= ((this->milliseconds & TimeBitField::MILLISECONDS_BIT_MASK) << TimeBitField::MILLISECONDS_START_BIT);
	intValue |= ((this->seconds & TimeBitField::SECONDS_BIT_MASK) << TimeBitField::SECONDS_START_BIT);
	intValue |= ((this->minutes & TimeBitField::MINUTES_BIT_MASK) << TimeBitField::MINUTES_START_BIT);
	intValue |= ((this->hour & TimeBitField::HOUR_BIT_MASK) << TimeBitField::HOUR_START_BIT);
	intValue |= ((this->day & TimeBitField::DAY_BIT_MASK) << TimeBitField::DAY_START_BIT);
	return dst->pack(intValue);
}

int TimeBitField::from(system::Buffer *src)
{
	int byteSize = 0;
	uint32_t intValue = 0;
	byteSize = src->unpack(intValue);

	this->milliseconds = (intValue >> (TimeBitField::MILLISECONDS_START_BIT)) & TimeBitField::MILLISECONDS_BIT_MASK;
	this->seconds = (intValue >> (TimeBitField::SECONDS_START_BIT)) & TimeBitField::SECONDS_BIT_MASK;
	this->minutes = (intValue >> (TimeBitField::MINUTES_START_BIT)) & TimeBitField::MINUTES_BIT_MASK;
	this->hour = (intValue >> (TimeBitField::HOUR_START_BIT)) & TimeBitField::HOUR_BIT_MASK;
	this->day = (intValue >> (TimeBitField::DAY_START_BIT)) & TimeBitField::DAY_BIT_MASK;

	return byteSize;
}

int TimeBitField::length(void)
{
	return sizeof(uint32_t);
}

void TimeBitField::copy(TimeBitField& source)
{
	this->setName(source.getName());
	this->setInterpretation(source.getInterpretation());
	this->setOptional(source.isOptional());

	setMilliseconds(source.getMilliseconds());
	setSeconds(source.getSeconds());
	setMinutes(source.getMinutes());
	setHour(source.getHour());
	setDay(source.getDay());

}

std::string TimeBitField::toXml(unsigned char level) const
{
	uint32_t intValue = 0;

	intValue |= ((this->milliseconds & TimeBitField::MILLISECONDS_BIT_MASK) << TimeBitField::MILLISECONDS_START_BIT);
	intValue |= ((this->seconds & TimeBitField::SECONDS_BIT_MASK) << TimeBitField::SECONDS_START_BIT);
	intValue |= ((this->minutes & TimeBitField::MINUTES_BIT_MASK) << TimeBitField::MINUTES_START_BIT);
	intValue |= ((this->hour & TimeBitField::HOUR_BIT_MASK) << TimeBitField::HOUR_START_BIT);
	intValue |= ((this->day & TimeBitField::DAY_BIT_MASK) << TimeBitField::DAY_START_BIT);

	std::ostringstream prefix;
	for(unsigned char i = 0; i < level; i++)
	{
		prefix << "\t";
	}

	std::ostringstream oss;
	oss << prefix.str() << "<BitField name=\"" << this->name << "\">\n";
	oss << prefix.str() << "\t" << "<intValue>" << intValue << "</intValue>\n";
	oss << prefix.str() << "\t" << "<fields>\n";
	oss << prefix.str() << "\t" << "<BitFieldRange name=\"Milliseconds\" value=\"" << getMilliseconds() << "\" />\n";
	oss << prefix.str() << "\t" << "<BitFieldRange name=\"Seconds\" value=\"" << getSeconds() << "\" />\n";
	oss << prefix.str() << "\t" << "<BitFieldRange name=\"Minutes\" value=\"" << getMinutes() << "\" />\n";
	oss << prefix.str() << "\t" << "<BitFieldRange name=\"Hour\" value=\"" << getHour() << "\" />\n";
	oss << prefix.str() << "\t" << "<BitFieldRange name=\"Day\" value=\"" << getDay() << "\" />\n";
	oss << prefix.str() << "\t" << "</fields>\n";
	oss << prefix.str() << "</BitField>\n";
	return oss.str();
}

} // namespace core
} // namespace openjaus
