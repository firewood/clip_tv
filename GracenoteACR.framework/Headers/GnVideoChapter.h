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
#import "GnVideoTitle.h"
#import "GnVideoEnums.h"
/** @addtogroup VideoMetadata Video Metadata
 *  \brief Metadata classes for Video results
 *  @{
 */

@interface GnVideoChapter : GnMetadataObject

@property (nonatomic, readonly)     GnVideoTitle*   title;
@property (nonatomic, readonly)     NSString*       ordinal;
@property (nonatomic, readonly)     NSString*       duration;
@property (nonatomic, readonly)     NSString*       durationUnits;

// -(NSEnumerator*)creditsByRole:(GnVideoRoleType)roleType;        // GnVideoCredit

@end
/** @} */ // end of VideoMetadata
