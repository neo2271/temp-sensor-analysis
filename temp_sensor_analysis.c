// Copyright (c) 2016 by NeOTiM

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

/* Included headers */
#include "stdio.h"
#include "math.h"


/* Constants */
#define MAX_TEMP      70 // Maximum temperature
#define MIN_TEMP      20 // Minimum temperature
#define DEV_TEMP      50 // Deviation of temperature between two measure times
#define ANALY_TIMER   10 // Store input data in 10 seconds to analyze


/* Definition Errors */
typedef enum Error_Define {
  TRUE_FALSE           =   FALSE; // True = has no any error; False = has some errors
	Negative_Value       =   -1; // Less than 0 degree celcius
	Sub_Threshold        =   0; // Less than MIN_TEMP
	Over_Threshhold      =   1; // More than MAX_TEMP
};


/*=============================================================================*/
/*     							Function declarations   					   */
/*=============================================================================*/


/*===========================================================================

FUNCTION    Input_Data

DESCRIPTION
  

DEPENDENCIES
  None.

RETURN VALUE
  FALSE = failure, else TRUE.
  Currently all the internal boolean return functions called by
  this function just returns TRUE w/o doing anything.

SIDE EFFECTS
  None

===========================================================================*/
static boolean Input_Data(int input)
{
  if (input < 0 )
  {
    return FALSE;    
  } else if (input < MIN_TEMP)
  {
    return FALSE
  } else if (input > MAX_TEMP)
  {
    return FALSE;
  } else 
  {
    return TRUE;  
  }  
}
