#include <iostream>
#include <string>
#include "HospitalController.h"

using namespace std;

int main()
{
	// create dynamic to see all d'ots
	HospitalController* hc = new HospitalController();
	hc->run();
	delete hc;
	system("pause");
}
