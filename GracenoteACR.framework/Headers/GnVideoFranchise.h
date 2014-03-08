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
#import "GnVideoTitle.h"

/** @addtogroup VideoMetadata Video Metadata
 *  \brief Metadata classes for Video results
 *  @{
 */

@interface GnVideoFranchise : GnMetadataObject

@property (nonatomic, readonly) NSString*       count;
@property (nonatomic, readonly) NSString*       num;
@property (nonatomic, readonly) GnVideoTitle*   title;

@end
/** @} */ // end of VideoMetadata
