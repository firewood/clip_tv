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
#import "GnObject.h"

/** @addtogroup manager Manager 
 *  SDK Manager APIs
 *  @{
 */


@interface GnUserOption : GnObject



@property (nonatomic, assign)   NSString*   proxyPassword;
@property (nonatomic, assign)   NSString*   proxyUser;
@property (nonatomic, assign)   NSString*   proxyServer;
@property (nonatomic, assign)   NSString*   locationID;

@property (nonatomic, assign)   unsigned         cacheExpiration;
@property (nonatomic, assign)   unsigned         networkTimeout;

@property (nonatomic, assign)   BOOL        networkLoadBalance;


@end
/** @} */ // End of Manager
