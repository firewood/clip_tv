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
#import "GnVideoRegion.h"

/** @addtogroup VideoMetadata Video Metadata
 *  \brief Metadata classes for Video results
 *  @{
 */

@interface GnVideoLayer : GnMetadataObject

@property (nonatomic, readonly)     NSEnumerator*           features;
@property (nonatomic, readonly)     NSString*               ordinal;
@property (nonatomic, readonly)     NSString*               matched;
@property (nonatomic, readonly)     NSString*               tvSystem;
@property (nonatomic, readonly)     GnVideoRegion*          region;
@property (nonatomic, readonly)     NSString*               regionCode;
@property (nonatomic, readonly)     NSString*               mediaType;


@end
/** @} */ // end of VideoMetadata
