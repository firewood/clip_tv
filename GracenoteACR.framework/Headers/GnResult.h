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

/** @addtogroup metadata Metadata (General) 
 *  General Metadata Classes
 *  @{
 */


typedef enum
{
    GnResultTypeTrack,
    GnResultTypeAlbum,
    GnResultTypeSuggestion,
    GnResultTypeContributor,
    GnResultTypeProduct,
    GnResultTypeSeason,
    GnResultTypeSeries,
    GnResultTypeWork,
    GnResultTypeMatch,
    GnResultTypeMusicMatch = GnResultTypeMatch,
    GnResultTypeTvProgram,
    GnResultTypeTvProvider,
    GnResultTypeTvAiring,
    GnResultTypeTvChannel,
    GnResultTypeAcrMatch
}
GnResultType;



/** 
 *  GnResult is the universal reponse object for all SDK queries. It encapsulates all 
 *  metadata objects returned from a specific "find" API and the IGnAcrResultDelegate 
 *  callback. To access the indivudual results for a query, iterate over the NSEnumerator 
 *  of the appropriate result type. Typically, only one NSEnumerator is valid for a given result. 
 *  This will depend on the "find" API from which the GnResult object was returned.
 */
@interface GnResult : GnMetadataObject


/** @name Video Results
 *  This group of enumerators are used to get the individual results for queries made with 
 *  the GnVideo object. Only one of these will be valid for a given GnResult object. Which 
 *  one will depend on which "find" API was used to obtain the GnResult.
 */
///@{

/**
 *  Used to access individual GnVideoContributor objects resulting from a findContributors query. 
 *  It will be empty for other types of queries. 
 */
@property (nonatomic, readonly) NSEnumerator*       videoContributors;

/**
 *  Used to access individual GnVideoProduct objects resulting from a findProducts query. 
 *  It will be empty for other types of queries. 
 */
@property (nonatomic, readonly) NSEnumerator*       videoProducts;

/**
 *  Used to access individual GnVideoSuggestion objects resulting from a findSuggestions query. 
 *  It will be empty for other types of queries. 
 */
@property (nonatomic, readonly) NSEnumerator*       videoSuggestions;

/**
 *  Used to access individual GnVideoSeason objects resulting from a findSeasons query. 
 *  It will be empty for other types of queries. 
 */
@property (nonatomic, readonly) NSEnumerator*       videoSeasons;

/**
 *  Used to access individual GnVideoSeries objects resulting from a findSeries query. 
 *  It will be empty for other types of queries. 
 */
@property (nonatomic, readonly) NSEnumerator*       videoSeries;

/**
 *  Used to access individual GnVideoWork objects resulting from a findWorks query. 
 *  It will be empty for other types of queries. 
 */
@property (nonatomic, readonly) NSEnumerator*       videoWorks;
///@} // end of VideoResults


/** @name ACR Results
 *  This group of enumerators are used to get the individual results for queries made with 
 *  the GnACR object. These results will be obtained via the acrResultReady method of the 
 *  IGnAcrResultDelegate protocol.
 */
///@{


/**
 *  Used to access individual GnAcrMatch objects resulting from a IGnAcrResultDelegate callback. 
 *  It will be empty for other types of queries. 
 */
@property (nonatomic, readonly) NSEnumerator*       acrMatches;
///@} // end of ACRResults


/** @name EPG Results
 *  This group of enumerators are used to get the individual results for queries made with 
 *  the GnEPG object. Only one of these will be valid for a given GnResult object. Which 
 *  one will depend on which "find" API was used to obtain the GnResult.
 */
///@{


/**
 *  Used to access individual GnTvProgram objects resulting from a findPrograms query. 
 *  It will be empty for other types of queries. 
 */
@property (nonatomic, readonly) NSEnumerator*       tvPrograms;

/**
 *  Used to access individual GnTvProvider objects resulting from a findProviders query. 
 *  It will be empty for other types of queries. 
 */
@property (nonatomic, readonly) NSEnumerator*       tvProviders;

/**
 *  Used to access individual GnTvAiring objects resulting from a findAirings query. 
 *  It will be empty for other types of queries. 
 */
@property (nonatomic, readonly) NSEnumerator*       tvAirings;

/**
 *  Used to access individual GnTvChannel objects resulting from a findChannels query. 
 *  It will be empty for other types of queries. 
 */
@property (nonatomic, readonly) NSEnumerator*       tvChannels;
///@}   // end of EPGResults



/** @name MusicID Results
 *  This group of enumerators are used to get the individual results for queries made with
 *  the GnMusicID object. Only one of these will be valid for a given GnResult object. Which
 *  one will depend on which "find" API was used to obtain the GnResult.
 */
///@{

/**
 *  Used to access individual GnAlbum objects resulting from a findAlbums query.
 *  It will be empty for other types of queries.
 */
@property (nonatomic, readonly) NSEnumerator*       albums;

/**
 *  Used to access individual GnTrack objects resulting from a findTracks query.
 *  It will be empty for other types of queries.
 */
@property (nonatomic, readonly) NSEnumerator*       tracks;


///@}   // end of MusicID Results






@property (nonatomic, readonly) NSString*           rangeStart;
@property (nonatomic, readonly) NSString*           rangeEnd;
@property (nonatomic, readonly) NSString*           rangeTotal;

@property (nonatomic, readonly) GnResultType        resultType;



@end
/** @} */ // End of metadata
