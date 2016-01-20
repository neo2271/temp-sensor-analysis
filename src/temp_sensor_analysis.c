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
#include "../inc/temp_sensor_analysis.h"

/*=============================================================================*/
/*                                 FUNCTION DECLARATIONS                       */
/*=============================================================================*/

/*===========================================================================

 FUNCTION    InputErrorDefine

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
enum ErrorCode InputErrorDefine() {
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

 FUNCTION    InputTempCheck

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
bool InputTempCheck(){
  if (InputErrorDefine() == NO_ERROR && min_mean_temp >= MIN_TEMP && min_mean_temp <= MAX_TEMP) 
    return true;
  else
  return false;
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
  int dev_temp;

  if (calc_temp > min_mean_temp)
    dev_temp = calc_temp - min_mean_temp;
  else
    dev_temp = min_mean_temp - calc_temp;

  return dev_temp;
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

  if (InputTempCheck())
  {
    if (TempDeviation() > DEV_TEMP)
      return false;
    else
      return true;
  } else
  return false;
}

/*=============================================================================*/
/*                                     TEST FUNCTION                           */
/*=============================================================================*/
int main() { 
  bool check;
  
  // Test 01
  check = TempSensorAnalysis(21, -10);
  printf("\n--- Test 01 ---");
  printf("\nErrorCode: %d \n",InputErrorDefine());
  printf("Check: %d \n",TempSensorAnalysis(min_mean_temp, calc_temp));
  printf("calc_temp: %d \n",calc_temp);
  printf("min_mean_temp: %d \n",min_mean_temp);
  printf("TempDeviation: %d \n",TempDeviation());
  
  // Test 02
  check = TempSensorAnalysis(24, 5);
  printf("\n--- Test 02 ---");
  printf("\nErrorCode: %d \n",InputErrorDefine());
  printf("Check: %d \n",TempSensorAnalysis(min_mean_temp, calc_temp));
  printf("calc_temp: %d \n",calc_temp);
  printf("min_mean_temp: %d \n",min_mean_temp);
  printf("TempDeviation: %d \n",TempDeviation());
  
  // Test 03
  check = TempSensorAnalysis(22, 80);
  printf("\n--- Test 03 ---");
  printf("\nErrorCode: %d \n",InputErrorDefine());
  printf("Check: %d \n",TempSensorAnalysis(min_mean_temp, calc_temp));
  printf("calc_temp: %d \n",calc_temp);
  printf("min_mean_temp: %d \n",min_mean_temp);
  printf("TempDeviation: %d \n",TempDeviation());
  
  // Test 04
  check = TempSensorAnalysis(30, 25);
  printf("\n--- Test 04 ---");
  printf("\nErrorCode: %d \n",InputErrorDefine());
  printf("Check: %d \n",TempSensorAnalysis(min_mean_temp, calc_temp));
  printf("calc_temp: %d \n",calc_temp);
  printf("min_mean_temp: %d \n",min_mean_temp);
  printf("TempDeviation: %d \n",TempDeviation());
  
  // Test 05
  check = TempSensorAnalysis(71, 20);
  printf("\n--- Test 05 ---");
  printf("\nErrorCode: %d \n",InputErrorDefine());
  printf("Check: %d \n",TempSensorAnalysis(min_mean_temp, calc_temp));
  printf("calc_temp: %d \n",calc_temp);
  printf("min_mean_temp: %d \n",min_mean_temp);
  printf("TempDeviation: %d \n",TempDeviation());
  
  return 0;
}