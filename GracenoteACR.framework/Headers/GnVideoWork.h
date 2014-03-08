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

#import <Foundation/Foundation.h>
#import "GnMetadataObject.h"
#import "GnVideoTitle.h"
#import "GnVideoSeries.h"
#import "GnVideoEnums.h"
#import "GnVideoFranchise.h"

/** @addtogroup VideoMetadata Video Metadata
 *  \brief Metadata classes for Video results
 *  @{
 */


@interface GnVideoWork : GnMetadataObject


@property (nonatomic, readonly) GnVideoTitle*       title;
@property (nonatomic, readonly) GnVideoFranchise*   franchise; 
@property (nonatomic, readonly) GnVideoTitle*       seriesTitle;
@property (nonatomic, readonly) NSEnumerator*       credits;        // GnVideoCredit
@property (nonatomic, readonly) NSEnumerator*       products;       //GnVideoProduct
@property (nonatomic, readonly) NSEnumerator*       seasons;        //GnVideoSeason
@property (nonatomic, readonly) GnVideoSeries*      series;    
@property (nonatomic, readonly) NSEnumerator*       externalIDs;    // GnExternalID

@property (nonatomic, readonly) BOOL                isPartial;
@property (nonatomic, readonly) NSString*           gdoSerialized;
@property (nonatomic, readonly) NSString*           gnID;
@property (nonatomic, readonly) NSString*           gnuID;
@property (nonatomic, readonly) NSString*           productID;
@property (nonatomic, readonly) NSString*           tui;
@property (nonatomic, readonly) NSString*           tuiTag;

@property (nonatomic, readonly) NSString*           dateOriginalRelease;
@property (nonatomic, readonly) NSString*           duration;
@property (nonatomic, readonly) NSString*           durationUnits;
@property (nonatomic, readonly) NSString*           origin1;
@property (nonatomic, readonly) NSString*           origin2;
@property (nonatomic, readonly) NSString*           origin3;
@property (nonatomic, readonly) NSString*           origin4;
@property (nonatomic, readonly) NSEnumerator*       genres;
@property (nonatomic, readonly) NSString*           matchedProductTUI;
@property (nonatomic, readonly) NSEnumerator*       plots;          // GNVideoPlot
@property (nonatomic, readonly) NSString*           productionType;
@property (nonatomic, readonly) NSString*           seasonCount;
@property (nonatomic, readonly) NSString*           seasonEpisode;
@property (nonatomic, readonly) NSString*           seasonEpisodeCount;
@property (nonatomic, readonly) NSString*           seasonNumber;
@property (nonatomic, readonly) NSString*           seriesEpisode;
@property (nonatomic, readonly) NSString*           seriesEpisodeCount;

@property (nonatomic, readonly) NSEnumerator*       ratings;        //GnVideoRating
@property (nonatomic, readonly) NSString*           workType;
@property (nonatomic, readonly) NSString*           serialType;

@property (nonatomic, readonly) NSString*           audience;
@property (nonatomic, readonly) NSString*           mood;
@property (nonatomic, readonly) NSString*           storyType;
@property (nonatomic, readonly) NSString*           reputation;
@property (nonatomic, readonly) NSString*           scenario;
@property (nonatomic, readonly) NSString*           settingEnvironment;
@property (nonatomic, readonly) NSString*           settingTimePeriod;
@property (nonatomic, readonly) NSString*           source;
@property (nonatomic, readonly) NSString*           style;
@property (nonatomic, readonly) NSString*           topic;

// -(NSEnumerator*)creditsByRole:(GnVideoRoleType)roleType;  // GnVideoCredit


@end
/** @} */ // end of VideoMetadata

