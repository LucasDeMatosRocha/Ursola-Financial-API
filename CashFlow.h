#pragma once

#include <math.h>
#include <iostream>
#include <Windows.h>
#include <queue>

namespace CashFlow
{
	class RollInTime_ErrorHandling
	{
	private:

        #define err_RollInTime_ErrorHandling_SUCESS                 0000
		#define err_RollInTime_ErrorHandling_INVALID_PERIOD         0001
		#define err_RollInTime_ErrorHandling_INVALID_PRESENTEVALUE  0002
        #define err_RollInTime_ErrorHandling_INVALID_FUTUREEVALUE   0003
        #define err_RollInTime_ErrorHandling_INVALID_INSTERESTRATE  0004

	public:

		double Check_DataInput_OnFinancial_Funcion_FV(double * _PresentValue,double * _InterestRate,double * _PeriodSize)
		{
		  /*
		   * Return : Error Code by the Result.
		   * Used to store Error Code for Debug Operation.
		   */
		  
			double  ErrToReturn_Check_DataInput_OnFinancial_Funcion_FV;


		  /*
		   * Check if "PV" (Present Value) is Valid for a Mathematical Operation in Finance 
		   */

		  if(_PresentValue > (0))
		  {
			  ErrToReturn_Check_DataInput_OnFinancial_Funcion_FV = err_RollInTime_ErrorHandling_SUCESS;
		  }
		  else 
		  {
			  ErrToReturn_Check_DataInput_OnFinancial_Funcion_FV = (err_RollInTime_ErrorHandling_INVALID_PRESENTEVALUE);
		  }

		  /*
		   * Check if "i" (Insterest Rate) is Valid for a Mathematical Operation in Finance
		   */

		  if (_InterestRate > (0))
		  {
			  ErrToReturn_Check_DataInput_OnFinancial_Funcion_FV = err_RollInTime_ErrorHandling_SUCESS;
		  }
		  else
		  {
			  ErrToReturn_Check_DataInput_OnFinancial_Funcion_FV = (err_RollInTime_ErrorHandling_INVALID_INSTERESTRATE);
		  }

		  /*
		   * Check if "n" (Period Size) is Valid for a Mathematical Operation in Finance
		   */

		  if (_PeriodSize > (0))
		  {
			  ErrToReturn_Check_DataInput_OnFinancial_Funcion_FV = err_RollInTime_ErrorHandling_SUCESS;
		  }
		  else
		  {
			  ErrToReturn_Check_DataInput_OnFinancial_Funcion_FV = (err_RollInTime_ErrorHandling_INVALID_PERIOD);
		  }

		  return ErrToReturn_Check_DataInput_OnFinancial_Funcion_FV;
		}

		double Check_DataInput_OnFinancial_Funcion_PV(double * _FutureValue, double * _InterestRate, double * _PeriodSize)
		{
			/*
			* Return : Error Code by the Result.
			* Used to store Error Code for Debug Operation.
			*/

			double  ErrToReturn_Check_DataInput_OnFinancial_Funcion_PV;


			/*
			* Check if "PV" (Future Value) is Valid for a Mathematical Operation in Finance
			*/

			if (_FutureValue > (0))
			{
				ErrToReturn_Check_DataInput_OnFinancial_Funcion_PV = err_RollInTime_ErrorHandling_SUCESS;
			}
			else
			{
				ErrToReturn_Check_DataInput_OnFinancial_Funcion_PV = (err_RollInTime_ErrorHandling_INVALID_FUTUREEVALUE);
			}

			/*
			* Check if "i" (Insterest Rate) is Valid for a Mathematical Operation in Finance
			*/

			if (_InterestRate > (0))
			{
				ErrToReturn_Check_DataInput_OnFinancial_Funcion_PV = err_RollInTime_ErrorHandling_SUCESS;
			}
			else
			{
				ErrToReturn_Check_DataInput_OnFinancial_Funcion_PV = (err_RollInTime_ErrorHandling_INVALID_INSTERESTRATE);
			}

			/*
			* Check if "n" (Period Size) is Valid for a Mathematical Operation in Finance
			*/

			if (_PeriodSize > (0))
			{
				ErrToReturn_Check_DataInput_OnFinancial_Funcion_PV = err_RollInTime_ErrorHandling_SUCESS;
			}
			else
			{
				ErrToReturn_Check_DataInput_OnFinancial_Funcion_PV = (err_RollInTime_ErrorHandling_INVALID_PERIOD);
			}

			return ErrToReturn_Check_DataInput_OnFinancial_Funcion_PV;
		}

	};


	class RollInTime
	{
     	private:

			const double * minimalPeriod = 0x0;

    	public:

			// User ONLY for NPV ou NFV

			/*
			 * Future Value (FV)
			 *
			 * FV = VP * (1+i)^n
			 *
			 *
			 * PV : Present Value
			 * i  : Interest Rate
			 * n  : Period Size
		     */

			double FutureValue(double PresenteValue,double InterestRate,double PeriodSize)
			{
				double FutureValue_Result; 
			
				/*
				 * First Time : Internal (NONDEBUG) Financial Math Error Handling.
				 */

				RollInTime_ErrorHandling errHandling;
				errHandling.Check_DataInput_OnFinancial_Funcion_FV(&PresenteValue, &InterestRate, &PeriodSize);
			
				try 
				{
					FutureValue_Result = (PresenteValue) * (pow((1 + InterestRate), PeriodSize));
				}
				catch(char* ErrCode_Message[])
				{
				   /*
					* Second Time : External (DEBUG) Runtime Error Handling.
					*/

					if (ErrCode_Message != nullptr) {
                        #define ErrCode_DBG = ErrCode_Message;
					}
				}

				return FutureValue_Result;
			}
	


			/*
			* Present Value (PV)
			*
			* PV = FV / (1+i)^n
			*
			*
			* FV : Future Value
			* i  : Interest Rate
			* n  : Period Size
			*/

			double PresentValue(double FutureValue, double InterestRate, double PeriodSize)
			{
				double PresentValue_Result; // *minimalPeriod;

										   /*
										   * First Time : Internal (NONDEBUG) Financial Math Error Handling.
										   */

				RollInTime_ErrorHandling errHandling;
				errHandling.Check_DataInput_OnFinancial_Funcion_PV(&FutureValue, &InterestRate, &PeriodSize);

				try
				{
					PresentValue_Result = (FutureValue) / (pow((1 + InterestRate), PeriodSize));
				}
				catch (char* ErrCode_Message[])
				{
					/*
					* Second Time : External (DEBUG) Runtime Error Handling.
					*/

					if (ErrCode_Message != nullptr) {
#define ErrCode_DBG = ErrCode_Message;
					}
				}

				return PresentValue_Result;
			}


			/*
			* Absolute Tax (Math)
			*
			* ABS Tax = FV / PV
			*
			* PV : Present Value
			* FV : Future Value
			*/

			double GetTax(double FutureValue,double PresentValue)
			{
				double TaxaValue;

				try
				{
			    	TaxaValue = FutureValue / PresentValue;
				}
				catch (char* ErrCode_Message[])
				{
					/*
					* Second Time : External (DEBUG) Runtime Error Handling.
					*/

					if (ErrCode_Message != nullptr) {
#define ErrCode_DBG = ErrCode_Message;
					}
				}
			
			
				return TaxaValue;
			}

	};

	/*
	 * Get Net Present and Future Values
     */

	class NetValues
	{
	private:

		double count = 0;

	public:
		std::queue<double> CashInFlow;
	


		/*
		* Net Present Value (NPV)
		*
		* NPV = Σ[FV / (1+i)^n] - I0
		*
		* I0 : Investment (FV0)
		* FV : Future Value
		* i  : Interest Rate
		* n  : Period Size
		*/

		double NetPresentValue(double FutureValue,double Investment, double InterestRate, double PeriodSize)
		{
			double PresentValue_Result;
				

										/*
										* First Time : Internal (NONDEBUG) Financial Math Error Handling.
										*/

			RollInTime_ErrorHandling errHandling;
			errHandling.Check_DataInput_OnFinancial_Funcion_PV(&FutureValue, &InterestRate, &PeriodSize);

			try
			{
				while (count < PeriodSize)
				{
					count += 1;
					
					PresentValue_Result  = (FutureValue) / (pow((1 + InterestRate), PeriodSize));
					CashInFlow.push(PresentValue_Result);

					PresentValue_Result -= Investment;

				}
			}
			catch (char* ErrCode_Message[])
			{
				/*
				* Second Time : External (DEBUG) Runtime Error Handling.
				*/

				if (ErrCode_Message != nullptr) {
#define ErrCode_DBG = ErrCode_Message;
				}
			}

			return PresentValue_Result;
		}


		/*
		 * Get the Net Present Value CashFlow
		 * or Get until some point of CashFlow.
		 */


#define NONE 0.0

		void GetFull_NPV_CashFlow(bool return_all_cashflow,bool return_until_some_specifc_period,double specific_period)
		{
			
			if(return_all_cashflow == true)
			{
			// Full CASH FLOW.

				
				
			}
			else
			{
			// Limited CASH FLOW.


			}

		}


	};

}