/**
\file Time.h

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
#ifndef SYSTEM_TIME_H
#define SYSTEM_TIME_H

#include "openjaus/system/Time.h"
#include <string>
#include "openjaus/types.h"
#include <ostream>

// Start of user code for additional includes
// End of user code

namespace openjaus
{
namespace system
{
class Time;

/// \class Time Time.h
/// \brief This is a brief description.
/// Detailed description.
/// \author Name (name@email.com)
class OPENJAUS_EXPORT Time 
{
public:
	Time(); 
	virtual ~Time();
	// Start of user code for additional constructors
	// End of user code
	/// Accessor to get the value of seconds.
	int getSeconds() const;

	/// Accessor to set value of seconds.
	/// \param seconds The value of the new seconds.
	bool setSeconds(int seconds);

	/// Accessor to get the value of microseconds.
	int getMicroseconds() const;

	/// Accessor to set value of microseconds.
	/// \param microseconds The value of the new microseconds.
	bool setMicroseconds(int microseconds);

	/// Operation sleep.
	/// \param milliseconds 
	static void sleep(int milliseconds);

	/// Operation getTime.
	static Time getTime();

	/// Operation inSec.
	 double inSec();

	std::string toString() const;
	OPENJAUS_EXPORT friend std::ostream& operator<<(std::ostream& output, const Time& object);

protected:
	// Member attributes & references
	int seconds;
	int microseconds;

// Start of user code for additional member data
// End of user code

}; // class Time

// Start of user code for inline functions
// End of user code



} // namespace system
} // namespace openjaus

#endif // SYSTEM_TIME_H

