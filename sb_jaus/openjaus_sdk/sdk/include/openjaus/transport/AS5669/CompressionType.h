/**
\file CompressionType.h

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
#ifndef COMPRESSIONTYPE_H
#define COMPRESSIONTYPE_H

#include <istream>
#include <ostream>
#include <string>

namespace openjaus
{
namespace transport
{
namespace AS5669
{

enum CompressionType
{
	NONE = 0,
	ZLIB = 1,
	BZIP2 = 2,
	LZMA = 3
};

inline std::ostream& operator<<(std::ostream& output, const CompressionType& enumValue)
{
	switch(enumValue)
	{
		case NONE:
			output << "NONE";
			break;
			
		case ZLIB:
			output << "ZLIB";
			break;
			
		case BZIP2:
			output << "BZIP2";
			break;
			
		case LZMA:
			output << "LZMA";
			break;
			
	}
	return output;
}

inline std::istream& operator>>(std::istream& input, CompressionType& enumValue)
{
	std::string enumString;
	input >> enumString;
	if(enumString.compare("NONE") == 0)
	{
		enumValue = NONE;
	}
	if(enumString.compare("ZLIB") == 0)
	{
		enumValue = ZLIB;
	}
	if(enumString.compare("BZIP2") == 0)
	{
		enumValue = BZIP2;
	}
	if(enumString.compare("LZMA") == 0)
	{
		enumValue = LZMA;
	}
    return input;
}

} // namespace AS5669
} // namespace transport
} // namespace openjaus

#endif // COMPRESSIONTYPE_H
