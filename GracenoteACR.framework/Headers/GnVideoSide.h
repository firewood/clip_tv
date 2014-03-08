/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */


// Public header
// audited

#import "GnMetadataObject.h"
#import "GnVideoLayer.h"
#import "GnVideoTitle.h"

/** @addtogroup VideoMetadata Video Metadata
 *  Metadata classes for Video results
 *  @{
 */

@interface GnVideoSide : GnMetadataObject

@property (nonatomic, readonly)     GnVideoLayer*           layer;
@property (nonatomic, readonly)     NSString*               ordinal;
@property (nonatomic, readonly)     NSString*               matched;
@property (nonatomic, readonly)     GnVideoLayer*           matchedLayer;

@end
/** @} */ // end of VideoMetadata
