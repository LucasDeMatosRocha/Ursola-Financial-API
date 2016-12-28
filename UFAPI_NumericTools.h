#pragma once
#include "CashFlow.h"

namespace UFAPI_NumericTools
{
#
	using namespace CashFlow;

    class Tools_for_Tax_Handling
	{
	  private:

		  const double from_Days  = 1.0;
		  const double from_Month = 2.0;
		  const double from_Year  = 3.0;
		  
		  const double to_Days  =  0.1;
		  const double to_Month =  0.2;
		  const double to_Year  =  0.3;

	  public: 

		  double convert_Period(double* from,double Periods,double* To)
		  {
			  if(from == &from_Days && To == &from_Month)
			  {
				  Periods = Periods / 30;
			  }
			  

			  return Periods;
		  }


	};
	
	
};