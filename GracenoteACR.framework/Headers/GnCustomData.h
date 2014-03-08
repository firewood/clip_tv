/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */


// Public header

#import "GnMetadataObject.h"

@interface GnCustomData : GnMetadataObject

@property (nonatomic, readonly) NSData      *data;
@property (nonatomic, readonly) NSString    *dataID;

@end
