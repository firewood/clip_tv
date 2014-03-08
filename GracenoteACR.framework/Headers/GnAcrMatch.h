/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */


// Public header

#import <Foundation/Foundation.h>
#import "GnMetadataObject.h"
#import "GnVideoWork.h"
#import "GnTvAiring.h"
#import "GnCustomData.h"


/** @addtogroup AcrMetadata ACR Metadata
 *  Metadata classes for ACR match results
 *  @{
 */

/** 
 *  The GnAcrMatch object encapsulates the ACR metadata for a individual match 
 *  obtained from the GnResult of the IGnAcrResultDelegate acrResultReady method.
 */
@interface GnAcrMatch : GnMetadataObject 


/**
 *  The actual time position within the content at which the match was made. 
 *  The value will represent an integer number of milliseconds. 
 */
@property (nonatomic, readonly) NSString            *actualPosition;


/**
 *  The time position within the content at which the match was made, adjusted for time delays 
 *  introduced by the query subsystem. This delay includes network round trip, and other processing. 
 *  The value will represent an integer number of milliseconds. 
 */
@property (nonatomic, readonly) NSString            *adjustedPosition;



/**
 *  The title of the matched content, e.g. "Sienfeld" or "The Terminator"
 */
@property (nonatomic, readonly) GnVideoTitle            *title;

/**
 *  The subtitle of the matched content, e.g. an episode title 
 */
@property (nonatomic, readonly) GnVideoTitle            *subtitle;

/**
 *  The date that this content was ingested into the Gracenote Service
 *  This can be used to determine if the ACR Match data is for live broadcast 
 *  or time shifted content (DVR). 
 *  Uses ISO 8601 Date format, e.g. 2012-10-02T13:18:15,370884000
 *  The comma is a decimal point, i.e. 15.370884000 seconds.
 */
@property (nonatomic, readonly) NSString            *fingerprintCreationDate;





/**
 *  The GnTvAiring object related to this match, if available. 
 *  GnTvAiring objects contain info like channel, time, program data, etc.
 */
@property (nonatomic, readonly) GnTvAiring          *tvAiring;

/**
 *  The GnVideoWork object related to this match, if available.
 *  Additional info may be obtained by inspecting the GnVideoWork object.
 */
@property (nonatomic, readonly) GnVideoWork         *avWork;

/**
 *  If a match is made to a custom fingerprint bundle (GNFPCache), the custom binary 
 *  data will be retrieved via this property. See GnCustomData for more info.
 */
@property (nonatomic, readonly) GnCustomData        *customData;

@end

/** @} */ // end of AcrMetadata
