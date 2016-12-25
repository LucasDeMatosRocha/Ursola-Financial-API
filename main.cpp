#include <iostream>
#include "CashFlow.h"

using namespace std;
using namespace CashFlow;

int main(int argc,char* argv[])
{

	RollInTime cash;

	std::cout<<"FV: $ "<<cash.FutureValue(1000, 0.04, 10)<<std::endl;
	std::cout<<"PV: $ "<<cash.PresentValue(1480.24, 0.04, 10)<<std::endl;


	std::cin.get();

	return EXIT_SUCCESS;
}