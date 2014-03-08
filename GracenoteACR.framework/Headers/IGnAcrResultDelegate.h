/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */


// Public header


#import <Foundation/Foundation.h>

#import "GnResult.h"

/** @addtogroup acr ACR 
 *  \brief ACR Query APIs
 *  @{
 */



/**
 *
 */
@protocol IGnAcrResultDelegate <NSObject>

/**
 *
 */
-(void)acrResultReady:(GnResult*)result;

@end
/** @} */ // end of acr
