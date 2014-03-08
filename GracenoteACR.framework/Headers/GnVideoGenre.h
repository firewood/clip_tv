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

/** @addtogroup VideoMetadata Video Metadata
 *  \brief Metadata classes for Video results
 *  @{
 */

@interface GnVideoGenre : GnMetadataObject

@property (nonatomic, readonly)     NSString*       level1;
@property (nonatomic, readonly)     NSString*       level2;
@property (nonatomic, readonly)     NSString*       level3;

@end
/** @} */ // end of VideoMetadata
