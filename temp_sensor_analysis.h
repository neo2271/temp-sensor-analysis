/* Source file: temp_sensor_analysis.h Copyright (c) 2016 by NeOTiM */

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
#include "stdbool.h"
#include "stdio.h"
#include "math.h"

/*=============================================================================
                           CONSTANTS
=============================================================================*/                           
#define MAX_TEMP      70 // Maximum temperature
#define MIN_TEMP      20 // Minimum temperature
#define DEV_TEMP      50 // Deviation of temperature between two measure times
#define ANALY_TIMER   10 // Store input data in 10 seconds to analyze 

/*=============================================================================
                           VARIANTS
=============================================================================*/
int average_temp;

/*=============================================================================
                           DEFINITION ERROR CODES
=============================================================================*/
enum Error_Code { 
  No_Error, // Has no any error
  Negative_Value, // Temperature input less than 0 degree celcius
  Sub_Threshold, // Temperature input less than MIN_TEMP
  Over_Threshhold, // Temperature input greater than MAX_TEMP
  Large_Dev, // Temperature deviates too large
};