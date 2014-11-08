/**
\file Setting.h

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
#ifndef SYSTEM_SETTING_H
#define SYSTEM_SETTING_H

#include "openjaus/system/Accessable.h"
#include <string>
#include "openjaus/types.h"
#include <ostream>

// Start of user code for additional includes
#include <sstream>
// End of user code

namespace openjaus
{
namespace system
{

/// \class Setting Setting.h

class OPENJAUS_EXPORT Setting : public Accessable
{
public:
	Setting(); 
	virtual ~Setting();
	// Start of user code for additional constructors
	// End of user code
	/// Accessor to get the value of key.
	std::string getKey() const;

	/// Accessor to set value of key.
	/// \param key The value of the new key.
	bool setKey(std::string key);

	/// Accessor to get the value of valueStr.
	std::string getValueStr() const;

	/// Accessor to set value of valueStr.
	/// \param valueStr The value of the new valueStr.
	bool setValueStr(std::string valueStr);

	/// Accessor to get the value of comment.
	std::string getComment() const;

	/// Accessor to set value of comment.
	/// \param comment The value of the new comment.
	bool setComment(std::string comment);

	/// Accessor to get the value of saveDefault.
	bool isSaveDefault() const;

	/// Accessor to set value of saveDefault.
	/// \param saveDefault The value of the new saveDefault.
	bool setSaveDefault(bool saveDefault);

	std::string toString() const;
	OPENJAUS_EXPORT friend std::ostream& operator<<(std::ostream& output, const Setting& object);

protected:
	// Member attributes & references
	std::string key;
	std::string valueStr;
	std::string comment;
	bool saveDefault;

// Start of user code for additional member data
// End of user code

}; // class Setting

// Start of user code for inline functions
// End of user code



} // namespace system
} // namespace openjaus

#endif // SYSTEM_SETTING_H

