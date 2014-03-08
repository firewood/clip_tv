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
/** @addtogroup manager Manager 
 *  SDK Manager APIs
 *  @{
 */

@protocol GnLocaleLoadingStatusDelegate <NSObject>


-(void)statusCallbackWithStatus:(int)status bytesDone:(int)bytesDone bytesTotal:(int)bytesTotal;

@end
/** @} */ // End of Manager
