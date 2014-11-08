

/**
\file AngularVelocityRmsScaledInteger.h

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
#include "openjaus/mobility/Triggers/Fields/AngularVelocityRmsScaledInteger.h"
#include <cmath>

namespace openjaus
{
namespace mobility
{

const double AngularVelocityRmsScaledInteger::MIN_VALUE = 0.0;
const double AngularVelocityRmsScaledInteger::MAX_VALUE = 3.141592653589793;
const double AngularVelocityRmsScaledInteger::SCALE_FACTOR = 4.793763109162727E-5;

AngularVelocityRmsScaledInteger::AngularVelocityRmsScaledInteger()
{

}

AngularVelocityRmsScaledInteger::~AngularVelocityRmsScaledInteger()
{

}

bool AngularVelocityRmsScaledInteger::setValue(double value)
{
	if(value <= this->MAX_VALUE && value >= this->MIN_VALUE)
	{
		this->value = value;
		return true;
	}
	else
	{
		return false;
	}
}

void AngularVelocityRmsScaledInteger::toDouble(uint16_t intValue)
{
	this->value = (intValue * this->SCALE_FACTOR) + this->MIN_VALUE;
}

uint16_t AngularVelocityRmsScaledInteger::fromDouble(void) const
{
	uint16_t intValue = 0;
	intValue = static_cast<uint16_t>(floor((this->value - this->MIN_VALUE) / this->SCALE_FACTOR));
	return intValue;
}

int AngularVelocityRmsScaledInteger::to(system::Buffer *dst)
{
	return dst->pack(this->fromDouble());
}

int AngularVelocityRmsScaledInteger::from(system::Buffer *src)
{
	uint16_t intValue = 0;
	int byteSize = src->unpack(intValue);
	this->toDouble(intValue);
	return byteSize;
}

int AngularVelocityRmsScaledInteger::length(void)
{
	return sizeof(uint16_t);
}

std::string AngularVelocityRmsScaledInteger::toXml(unsigned char level) const
{
	std::ostringstream prefix;
	for(unsigned char i = 0; i < level; i++)
	{
		prefix << "\t";
	}

	std::ostringstream oss;
	oss << prefix.str() << "<ScaledInteger name=\"" << this->name << "\" intValue=\"" << this->fromDouble() << "\" doubleValue=\"" << this->value << "\" />\n";
	return oss.str();
}

} // namespace mobility
} // namespace openjaus

