/* Source file: temp_sensor_analysis.c Copyright (c) 2016 by NeOTiM */

/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

 Temperature Sensor Output Data Analysis for Controlling System

 GENERAL DESCRIPTION
 Contains main implementation of Analyzing Temperature Sensor's Output Data

 EXTERNALIZED FUNCTIONS
 None

 INITIALIZATION AND SEQUENCING REQUIREMENTS


 Copyright (c) 2016 NeOTiM

 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/*===========================================================================

 EDIT HISTORY FOR MODULE

 This section contains comments describing changes made to the module.
 Notice that changes are listed in reverse chronological order.

 $Header:

 when       who    what, where, why
 --------   ---     ----------------------------------------------------------
 15/01/16   ND     Created

 ===========================================================================*/

/*=============================================================================
                           INCLUDE FILES
=============================================================================*/
#include "temp_sensor_analysis.h"

/*=============================================================================*/
/*                                 FUNCTION DECLARATIONS                       */
/*=============================================================================*/

/*===========================================================================

 FUNCTION    InputDataCheck

 DESCRIPTION
 Checking Input Data from Temperature Sensor

 DEPENDENCIES
 None.

 RETURN VALUE
 If has no error, returns 0;
 If has some error, return the order of error code in Error_Code

 SIDE EFFECTS
 None

 ===========================================================================*/
enum ErrorCode InputTempCheck() {
  if (calc_temp < ZERO_DEGREE) {
    return NEGATIVE_VALUE;    
  } else if (calc_temp < MIN_TEMP) {
    return SUB_THRESHOLD;
  } else if (calc_temp > MAX_TEMP) {
    return OVER_THRESHHOLD;
  } else {
    return NO_ERROR;
  }
}

/*===========================================================================

 FUNCTION    TempDeviation

 DESCRIPTION
 Running timer to count deviant temperature

 DEPENDENCIES
 None.

 RETURN VALUE
 FALSE = failure, else TRUE.
 Currently all the internal boolean return functions called by
 this function just returns TRUE w/o doing anything.

 SIDE EFFECTS
 None

 ===========================================================================*/
int TempDeviation(){
  double dev_temp;

  dev_temp = sqrt(pow(calc_temp-min_mean_temp,2));
  return (int) dev_temp;
}

/*===========================================================================

 FUNCTION    TempSensorAnalysis

 DESCRIPTION
 Running timer to count deviant temperature

 DEPENDENCIES
 None.

 RETURN VALUE
 FALSE = failure, else TRUE.
 Currently all the internal boolean return functions called by
 this function just returns TRUE w/o doing anything.

 SIDE EFFECTS
 None

 ===========================================================================*/
bool TempSensorAnalysis(int input_min_mean_temp, int input_temp){
  min_mean_temp = input_min_mean_temp;
  calc_temp = input_temp;
  if (InputTempCheck() == NO_ERROR)
  {      
    TempDeviation();
    return true;
  } else
  return false;
}

/*=============================================================================*/
/*                                     TEST FUNCTION                           */
/*=============================================================================*/
int main() { 
  
  if (!TempSensorAnalysis(21, -1))
  {
    printf("\nErrorCode: %d \n",InputTempCheck());
    printf("Check: %d \n",TempSensorAnalysis(min_mean_temp, calc_temp));
    printf("calc_temp: %d \n",calc_temp);
    printf("min_mean_temp: %d \n",min_mean_temp);
  }

  if (!TempSensorAnalysis(24, 5))
  {
    printf("\nErrorCode: %d \n",InputTempCheck());
    printf("Check: %d \n",TempSensorAnalysis(min_mean_temp, calc_temp));
    printf("calc_temp: %d \n",calc_temp);
    printf("min_mean_temp: %d \n",min_mean_temp);
  }

  if (!TempSensorAnalysis(22, 80))
  {
    printf("\nErrorCode: %d \n",InputTempCheck());
    printf("Check: %d \n",TempSensorAnalysis(min_mean_temp, calc_temp));
    printf("calc_temp: %d \n",calc_temp);
    printf("min_mean_temp: %d \n",min_mean_temp);
  }

  if (TempSensorAnalysis(30, 25))
  {
    printf("\nErrorCode: %d \n",InputTempCheck());
    printf("Check: %d \n",TempSensorAnalysis(min_mean_temp, calc_temp));
    printf("calc_temp: %d \n",calc_temp);
    printf("min_mean_temp: %d \n",min_mean_temp);
  }  

  return 0;
}