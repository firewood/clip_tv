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
#import "GnAcrStatus.h"

/** @addtogroup acr ACR 
 *  \brief ACR Query APIs
 *  @{
 */



/**
 *  The IGnAcrStatusDelegate protocol defines the interface an object must implement to receive 
 *  status callbacks from a GnACR object. The GnACR object has a statusDelegate property that 
 *  accepts this protocol and will call this callback when a status is to be communicated.
 */
@protocol IGnAcrStatusDelegate <NSObject>

/**
 *  This method will be called on the statusDelegate object when a status is to be communicated. The status is encapsulated in a GnAcrStatus object passed to this callback API.
 */
-(void)acrStatusReady:(GnAcrStatus*)status;

@end
/** @} */ // end of acr
