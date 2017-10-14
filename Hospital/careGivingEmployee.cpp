#include "careGivingEmployee.h"
#include <iostream>

void CareGivingEmployee::work() const
{
	std::cout << "CareGivingEmployee " << name <<" WORKING!" << std::endl;
}
void CareGivingEmployee::toOs(ostream& os) const
{
	os << "-----------CareGivingEmployee Details-----------" << endl; 
}