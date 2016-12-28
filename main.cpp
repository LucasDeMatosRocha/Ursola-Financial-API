#include <iostream>
#include "CashFlow.h"

using namespace std;
using namespace CashFlow;

int main(int argc,char* argv[])
{

	RollInTime cash;

	double fv = cash.FutureValue(1000,// Present value ($)
		0.04,                         // Interest Rate (Tax,%)
		10);                          // Period Size (n)

	std::cout<< "FV : $ " << fv << std::endl ;

	double pv = cash.PresentValue(1480.24, // Future value ($)
		0.04,                              // Interest Rate (Tax,%)
		10);                               // Period Size (n)

	std::cout << "PV : $ " << pv << std::endl;


	std::cout << "Absolute Tax" << cash.GetTax(pv,fv) << std::endl; // Get Absolute Tax

	std::cin.get();

	return EXIT_SUCCESS;
}