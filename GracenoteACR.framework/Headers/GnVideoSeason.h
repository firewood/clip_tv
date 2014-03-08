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
#import "GnVideoFranchise.h"
#import "GnVideoSeries.h"

/** @addtogroup VideoMetadata Video Metadata
 *  Metadata classes for Video results
 *  @{
 */


@interface GnVideoSeason : GnMetadataObject

@property (nonatomic, readonly)     NSString*               audience;
@property (nonatomic, readonly)     NSString*               dateOriginalRelease;
@property (nonatomic, readonly)     NSString*               duration;
@property (nonatomic, readonly)     NSString*               durationUnits;
@property (nonatomic, readonly)     GnVideoSeries*          series;
@property (nonatomic, readonly)     NSString*               mood;
@property (nonatomic, readonly)     NSString*               origin1;
@property (nonatomic, readonly)     NSString*               origin2;
@property (nonatomic, readonly)     NSString*               origin3;
@property (nonatomic, readonly)     NSString*               origin4;
@property (nonatomic, readonly)     NSString*               productID;
@property (nonatomic, readonly)     NSString*               productionType;
@property (nonatomic, readonly)     NSString*               reputation;
@property (nonatomic, readonly)     NSString*               scenario;
@property (nonatomic, readonly)     NSString*               seasonCount;
@property (nonatomic, readonly)     NSString*               seasonNumber;
@property (nonatomic, readonly)     NSString*               serialType;
@property (nonatomic, readonly)     NSString*               settingEnvironment;
@property (nonatomic, readonly)     NSString*               settingTimePeriod;
@property (nonatomic, readonly)     NSString*               source;
@property (nonatomic, readonly)     NSString*               storyType;
@property (nonatomic, readonly)     NSString*               style;
@property (nonatomic, readonly)     GnVideoTitle*           title;
@property (nonatomic, readonly)     NSString*               topic;
@property (nonatomic, readonly)     NSString*               tui;
@property (nonatomic, readonly)     NSString*               tuiTag;
@property (nonatomic, readonly)     NSString*               workType;
@property (nonatomic, readonly)     BOOL                    isPartial;
@property (nonatomic, readonly)     NSString*               gdoSerialized;
@property (nonatomic, readonly)     NSString*               gnID;
@property (nonatomic, readonly)     NSString*               gnuID;
@property (nonatomic, readonly)     NSEnumerator*           credits;
@property (nonatomic, readonly)     NSEnumerator*           externalIDs;
@property (nonatomic, readonly)     GnVideoFranchise*       franchise; 
@property (nonatomic, readonly)     NSEnumerator*           genres;
@property (nonatomic, readonly)     NSEnumerator*           products;
@property (nonatomic, readonly)     NSEnumerator*           plots;
@property (nonatomic, readonly)     NSEnumerator*           ratings;
@property (nonatomic, readonly)     NSEnumerator*           works;


@end
/** @} */ // end of VideoMetadata
