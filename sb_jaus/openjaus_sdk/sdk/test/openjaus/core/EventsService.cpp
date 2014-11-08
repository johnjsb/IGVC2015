// File Header Here

#include <openjaus.h>
#include "openjaus/core.h"
// Start of user code for additional includes:
// End of user code


namespace openjaus
{
namespace core
{

class EventsService : public Events
{
public:
	EventsService()
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
	try
	{
		openjaus::core::EventsService service;
	}
	catch(openjaus::system::Exception exp)
	{
		std::cout << exp.getDescription() << "\n";
	}
	
	return 0;	
	// End of user code
}


