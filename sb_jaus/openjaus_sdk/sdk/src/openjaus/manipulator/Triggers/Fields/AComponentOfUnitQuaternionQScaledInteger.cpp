

/**
\file AComponentOfUnitQuaternionQScaledInteger.h

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
#include "openjaus/manipulator/Triggers/Fields/AComponentOfUnitQuaternionQScaledInteger.h"
#include <cmath>

namespace openjaus
{
namespace manipulator
{

const double AComponentOfUnitQuaternionQScaledInteger::MIN_VALUE = -1.0;
const double AComponentOfUnitQuaternionQScaledInteger::MAX_VALUE = 1.0;
const double AComponentOfUnitQuaternionQScaledInteger::SCALE_FACTOR = 4.656612874161595E-10;

AComponentOfUnitQuaternionQScaledInteger::AComponentOfUnitQuaternionQScaledInteger()
{

}

AComponentOfUnitQuaternionQScaledInteger::~AComponentOfUnitQuaternionQScaledInteger()
{

}

bool AComponentOfUnitQuaternionQScaledInteger::setValue(double value)
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

void AComponentOfUnitQuaternionQScaledInteger::toDouble(uint32_t intValue)
{
	this->value = (intValue * this->SCALE_FACTOR) + this->MIN_VALUE;
}

uint32_t AComponentOfUnitQuaternionQScaledInteger::fromDouble(void) const
{
	uint32_t intValue = 0;
	intValue = static_cast<uint32_t>(floor((this->value - this->MIN_VALUE) / this->SCALE_FACTOR));
	return intValue;
}

int AComponentOfUnitQuaternionQScaledInteger::to(system::Buffer *dst)
{
	return dst->pack(this->fromDouble());
}

int AComponentOfUnitQuaternionQScaledInteger::from(system::Buffer *src)
{
	uint32_t intValue = 0;
	int byteSize = src->unpack(intValue);
	this->toDouble(intValue);
	return byteSize;
}

int AComponentOfUnitQuaternionQScaledInteger::length(void)
{
	return sizeof(uint32_t);
}

std::string AComponentOfUnitQuaternionQScaledInteger::toXml(unsigned char level) const
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

} // namespace manipulator
} // namespace openjaus

