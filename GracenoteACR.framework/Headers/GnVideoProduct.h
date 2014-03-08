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
#import "GnVideoDisc.h"
#import "GnVideoLanguage.h"
#import "GnVideoRegion.h"

/** @addtogroup VideoMetadata Video Metadata
 *  \brief Metadata classes for Video results
 *  @{
 */

@interface GnVideoProduct : GnMetadataObject

@property (nonatomic, readonly)     NSString*               aspectRatio;
@property (nonatomic, readonly)     NSString*               aspectRatioType;
@property (nonatomic, readonly)     NSString*               dateOriginalRelease;
@property (nonatomic, readonly)     NSString*               dateRelease;
@property (nonatomic, readonly)     NSString*               duration;
@property (nonatomic, readonly)     NSString*               durationUnits;

@property (nonatomic, readonly)     GnVideoLanguage*        language;
@property (nonatomic, readonly)     GnVideoDisc*            matchedDisc;
@property (nonatomic, readonly)     GnVideoLayer*           matchedLayer;
@property (nonatomic, readonly)     GnVideoSide*            matchedSide;
@property (nonatomic, readonly)     NSString*               notes;
@property (nonatomic, readonly)     NSString*               productID;
@property (nonatomic, readonly)     NSString*               productionType;
@property (nonatomic, readonly)     GnVideoRegion*          region;
@property (nonatomic, readonly)     NSString*               tui;
@property (nonatomic, readonly)     NSString*               tuiTag;

@property (nonatomic, readonly)     GnVideoTitle*           title;
@property (nonatomic, readonly)     BOOL                    isPartial;


@property (nonatomic, readonly)     NSEnumerator*           discs;
@property (nonatomic, readonly)     NSEnumerator*           externalIDs;
@property (nonatomic, readonly)     NSEnumerator*           genres;
@property (nonatomic, readonly)     NSEnumerator*           ratings;


@end
/** @} */ // end of VideoMetadata
