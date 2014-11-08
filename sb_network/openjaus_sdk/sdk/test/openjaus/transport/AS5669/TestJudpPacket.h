/**
\file TestJudpPacket.h

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

#include "openjaus/transport/AS5669/JudpPacket.h"
#include <cxxtest/TestSuite.h>
#include <stdio.h>
// Start of user code header files:
// End of user code

class TestJudpPacket : public CxxTest::TestSuite
{
public:
	// Start of user code TestJudpPacket:
	openjaus::transport::AS5669::JudpPacket *judpPacket;
	// End of user code
	
	void setUp()
	{
		// Start of user code test setup:
		judpPacket = new openjaus::transport::AS5669::JudpPacket();	
	
		// End of user code
	}

	void tearDown()
	{
		// Start of user code test tear down:
		
		delete judpPacket;
		// End of user code
	}

	void testConstruction()
	{
		// Start of user code testConstruction:
		TS_ASSERT(judpPacket);
		// End of user code
	}
	
	void testVersionAccessors()
	{
		// Start of user code testVersionAccessors:
		//unsigned char version;		
		//judpPacket->setVersion(version);
		//judpPacket->getVersion();
		// End of user code
	}
	
	void testWrappersAccessors()
	{
		// Start of user code testWrappersAccessors:
		//openjaus::transport::Wrapper wrappers;		
		//judpPacket->setWrappers(wrappers);
		//judpPacket->getWrappers();
		// End of user code
	}
	
	void testNextWrapperType()
	{
		// Start of user code testNextWrapperType:
		// End of user code
	}
	
	void testPopWrapper()
	{
		// Start of user code testPopWrapper:
		// End of user code
	}
	
	void testPushWrapper()
	{
		// Start of user code testPushWrapper:
		// End of user code
	}
	
	void testReset()
	{
		// Start of user code testReset:
		// End of user code
	}
	
	// Start of user code custom tests:
	// End of user code
};

