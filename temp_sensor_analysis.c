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
/*                                 Function declarations                       */
/*=============================================================================*/

/*===========================================================================

 FUNCTION    Input_Data

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
Input_Data(int input) {
  if (input < 0) {
    printf("Negative_Value");
    return Negative_Value;    
  } else if (input < MIN_TEMP) {
    printf("Sub_Threshold");
    return Sub_Threshold;
  } else if (input > MAX_TEMP) {
    printf("Over_Threshhold");
    return Over_Threshhold;
  } else {
    printf("No_Error");
    return No_Error;
  }
}

/*===========================================================================

 FUNCTION    Temp_Deviation

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
enum Error_Code Temp_Deviation(){
}

/*=============================================================================*/
/*                                     Main Function                           */
/*=============================================================================*/
int main() {
  enum Error_Code error_code = No_Error;
  printf("\n%d | Input_Data(-1)\n",Input_Data(-1));
  printf("\n%d | Input_Data(5)\n",Input_Data(5));
  printf("\n%d | Input_Data(80)\n",Input_Data(80));
  printf("\n%d | Input_Data(25)\n",Input_Data(25));
  printf("\n%d\n%d\n%d", MIN_TEMP,MAX_TEMP,DEV_TEMP);
  printf("\n%d\n",error_code);
  return 0;
}