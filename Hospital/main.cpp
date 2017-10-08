#include <iostream>
#include <string.h>
#include "HospitalController.h"

using namespace std;

int main()
{
	HospitalController* hc = new HospitalController();
	hc->run();
	delete hc;
	system("pause");
}
