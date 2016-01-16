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
#include "stdio.h"
#include "stdbool.h"
#include "math.h"

/*=============================================================================
                           CONSTANTS
=============================================================================*/                           
#define ZERO_DEGREE   0 // 0 degree celcius
#define MIN_TEMP      20 // Minimum temperature
#define MAX_TEMP      70 // Maximum temperature
#define DEV_TEMP      50 // Deviation of temperature between two measure times
#define ANALY_TIMER   10 // Store input data in 10 seconds to analyze 

/*=============================================================================
                           VARIANTS
=============================================================================*/
int min_mean_temp; // Minimum real meaning temperature
int calc_temp; // Input temperature to calculate
int average_temp;

/*=============================================================================
                           DEFINITION ERROR CODES
=============================================================================*/
enum ErrorCode { 
  NO_ERROR, // Has no any error
  NEGATIVE_VALUE, // Temperature input less than 0 degree celcius
  SUB_THRESHOLD, // Temperature input less than MIN_TEMP
  OVER_THRESHHOLD, // Temperature input greater than MAX_TEMP
  LARGE_DEV, // Temperature deviates too large
};