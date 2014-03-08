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
#import "GnMetadataObject.h"
/** @addtogroup VideoMetadata Video Metadata
 *  \brief Metadata classes for Video results
 *  @{
 */


@interface GnVideoTitle : GnMetadataObject

@property   (nonatomic, readonly)   NSString* display;
@property   (nonatomic, readonly)   NSString* prefix;
@property   (nonatomic, readonly)   NSString* sortable;
@property   (nonatomic, readonly)   NSString* main;
@property   (nonatomic, readonly)   NSString* edition;


@end
/** @} */ // end of VideoMetadata
