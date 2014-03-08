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
#import "GnVideoCredit.h"
#import "GnVideoEnums.h"

/** @addtogroup VideoMetadata Video Metadata
 *  \brief Metadata classes for Video results
 *  @{
 */

@interface GnVideoFeature : GnMetadataObject

@property (nonatomic, readonly)     GnVideoTitle*           title;
@property (nonatomic, readonly)     NSEnumerator*           chapters;
@property (nonatomic, readonly)     NSEnumerator*           credits;
@property (nonatomic, readonly)     NSEnumerator*           works;
@property (nonatomic, readonly)     NSString*               ordinal;
@property (nonatomic, readonly)     NSString*               matched;
@property (nonatomic, readonly)     NSString*               featureType;
@property (nonatomic, readonly)     NSString*               productionType;
@property (nonatomic, readonly)     NSString*               aspectRatio;
@property (nonatomic, readonly)     NSString*               aspectRatioType;
@property (nonatomic, readonly)     NSString*               duration;
@property (nonatomic, readonly)     NSString*               durationUnits;
@property (nonatomic, readonly)     NSEnumerator*           genres;
@property (nonatomic, readonly)     NSEnumerator*           plots;
@property (nonatomic, readonly)     NSEnumerator*           ratings;

// -(NSEnumerator*)creditsByRole:(GnVideoRoleType)roleType;  // GnVideoCredit

@end
/** @} */ // end of VideoMetadata
