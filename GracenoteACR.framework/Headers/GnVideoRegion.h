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

/** @addtogroup VideoMetadata Video Metadata
 *  Metadata classes for Video results
 *  @{
 */

@interface GnVideoRegion : GnMetadataObject

@property (nonatomic, readonly)     NSString*               regionDescription;
@property (nonatomic, readonly)     NSString*               ID;

@end
/** @} */ // end of VideoMetadata
