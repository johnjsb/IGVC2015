// File Header Here

#include <openjaus.h>
#include "openjaus/core.h"
// Start of user code for additional includes:
// End of user code


namespace openjaus
{
namespace core
{

class AccessControlService : public AccessControl
{
public:
	AccessControlService()
	{
	};
	
	// Start of user code for Constructor:
	
	// End of user code
};

} // namespace core
} // namespace openjaus

int main(void)
{
	// Start of user code for main:
	openjaus::core::AccessControlService service;
	
	return 0;	
	// End of user code
}

