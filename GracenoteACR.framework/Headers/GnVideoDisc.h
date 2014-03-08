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
#import "GnVideoSide.h"
#import "GnVideoTitle.h"

/** @addtogroup VideoMetadata Video Metadata
 *  \brief Metadata classes for Video results
 *  @{
 */

@interface GnVideoDisc : GnMetadataObject


@property (nonatomic, readonly)     GnVideoLayer*   matchedLayer;
@property (nonatomic, readonly)     GnVideoSide*    matchedSide;

@property (nonatomic, readonly)     GnVideoTitle*   title;
@property (nonatomic, readonly)     NSEnumerator*   sides;
@property (nonatomic, readonly)     NSString*       productID;
@property (nonatomic, readonly)     NSString*       tui;
@property (nonatomic, readonly)     NSString*       tuiTag;
@property (nonatomic, readonly)     NSString*       ordinal;
@property (nonatomic, readonly)     NSString*       matched;


@end
/** @} */ // end of VideoMetadata
