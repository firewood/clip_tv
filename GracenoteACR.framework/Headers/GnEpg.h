/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

// Public header


#import "GnObject.h"
#import "GnUser.h"
#import "IGnEpgStatusDelegate.h"
#import "GnResult.h"
#import "GnVideoContributor.h"
#import "GnVideoWork.h"
#import "GnVideoSeries.h"

#import "GnTvProgram.h"
#import "GnTvProvider.h"
#import "GnTvChannel.h"

/** @addtogroup epg EPG 
 *  \brief EPG Query APIs
 *  @{
 */

typedef enum
{
    GnEpgStatusTypeUnknown,
    GnEpgStatusTypeQueryBegin,
    GnEpgStatusTypeConnecting,
    GnEpgStatusTypeSending,
    GnEpgStatusTypeReceiving,
    GnEpgStatusTypeQueryComplete,
    GnEpgStatusTypeQueryDelete
}GnEpgStatusType;


/**
 * These countries are supported by the findProvidersWithPostalCode API.
*/
extern NSString * const GnEpgTvPostalCodeCountryUSA;
extern NSString * const GnEpgTvPostalCodeCountryCanada;




/** The GnEpg object is responsible for making EPG queries. 
 *  EPG queries can find TV airing information based on local 
 *  providers or broadcast channels. 
 */
@interface GnEpg : GnObject

/**
 *  Initialzes a new GnEpg object with the Application's GnUser object.
 */
-(id)initWithUser:(GnUser*)user
            error:(NSError**)error;





/** 
 *  Find all airings with a given GnVideoContributor. Restrict the results to the specific 
 *  channels given by the array of GnTvChannel objects. Only airings between startDate and endDate 
 *  will be returned. Passing nil for the contributor will give all airings for the given dates and channels.
 */
-(GnResult*)findAiringsWithContributor:(GnVideoContributor*)contributor 
                            onChannels:(NSArray*)channels 
                             startDate:(NSDate*)startDate
                               endDate:(NSDate*)endDate
                                 error:(NSError**)error;

/**
 *  Find all airings with a given GnVideoWork. Restrict the results to the specific 
 *  channels given by the array of GnTvChannel objects. Only airings between startDate and endDate 
 *  will be returned. Passing nil for the work will give all airings for the given dates and channels.
 */
-(GnResult*)findAiringsWithWork:(GnVideoWork*)work 
                     onChannels:(NSArray*)channels 
                      startDate:(NSDate*)startDate
                        endDate:(NSDate*)endDate
                          error:(NSError**)error;

/**
 *  Find all airings with a given GnVideoSeries. Restrict the results to the specific
 *  channels given by the array of GnTvChannel objects. Only airings between startDate and endDate
 *  will be returned. Passing nil for the series will give all airings for the given dates and channels.
 */
-(GnResult*)findAiringsWithSeries:(GnVideoSeries*)series
                       onChannels:(NSArray*)channels
                        startDate:(NSDate*)startDate
                          endDate:(NSDate*)endDate
                            error:(NSError**)error;

/**
 *  Find all airings on a given list of channels. Restrict the results to the specific
 *  channels given by the array of GnTvChannel objects. Only airings between startDate and endDate
 *  will be returned. Equivalent to passing nil for the Series/Work/Contributor in the 
 *  other "findAirings" APIs.
 */
-(GnResult*)findAiringsOnChannels:(NSArray*)channels
                        startDate:(NSDate*)startDate
                          endDate:(NSDate*)endDate
                            error:(NSError**)error;





/** 
 *  Query for all Tv providers for a given country and postal code.
 *  Only GnEpgTvPostalCodeCountryUSA supported
 *  The GnTvProvider results can be access via the "tvProviders" property of the GnResult object.
 */
-(GnResult*)findProvidersWithPostalCode:(NSString*)postalCode 
                               country:(NSString*)GnEpgTvPostalCodeCountry 
                                 error:(NSError**)error;




/**
 *  Query for all TV channels for a given GnTvProvider.
 *  The GnTvChannel results can be access via the "tvChannels" property of the GnResult object.
 */
-(GnResult*)findChannelsWithProvider:(GnTvProvider*)provider 
                               error:(NSError**)error;

/**
 *  Query for all TV channels for a given array of DVB strings. DVB strings are used in Europe
 *  and other regions. A DVB string has the format @"svbt://65024.1100.400"
 *  The GnTvChannel results can be access via the "tvChannels" property of the GnResult object.
 */
-(GnResult*)findChannelsWithDVBs:(NSArray*)dvbs
                           error:(NSError**)error;


/**
 *  Query for a complete GnTvChannel object given a partial object (from previous query) or
 *  synthesized object (TUI/Tag pair). Useful to get full external data support.
 *  The GnTvChannel results can be access via the "tvChannels" property of the GnResult object.
 */
-(GnResult*)findChannelsWithChannel:(GnTvChannel*)channel
                              error:(NSError**)error;


/**
 *  Query for a GnTvChannel object given a GnID object
 *  synthesized from a TUI/Tag pair. Useful to get a full object from a cached TUI/TAG pair.
 *  Equivalent to findChannelsWithChannel for the same TUI/TAG pair.
 */
-(GnResult*)findChannelsWithGnID:(GnID*)channelID
                           error:(NSError**)error;




/** 
 *  Query for a full TV Program metadata for a given partial GnTvProgram object, 
 *  e.g. the partial GnTvProgram inside a GnTvAiring object.
 *  The GnTvProgram results can be access via the "tvPrograms" property of the GnResult object.
 */
-(GnResult*)findProgramsWithProgram:(GnTvProgram*)program 
                             error:(NSError**)error;


/**
 *  Query for a GnTvProgram object given a GnID object
 *  synthesized from a TUI/Tag pair. Useful to get a full object from a cached TUI/TAG pair.
 *  Equivalent to findProgramsWithProgram for the same TUI/TAG pair.
 */
-(GnResult*)findProgramsWithGnID:(GnID*)programID
                           error:(NSError**)error;



/**
 *  Not implemented
 */
@property (nonatomic, assign)   id<IGnEpgStatusDelegate>    statusDelegate;

/**
 *  The number of results desired for this query object. The GnResult object returned by a "find" 
 *  will have no more than this number of results contained within it.
 */
@property (nonatomic, assign)   unsigned        rangeSize;

/**
 *  The starting index of results desired for this query object. The GnResult object returned by a "find" 
 *  will results from this index upward. The index is 1-based.
 */
@property (nonatomic, assign)   unsigned        rangeStart;


/**
 *  Set to YES to enable Link Data in the query results. The default value is NO. 
 *  Currently only External IDs are supported. See the externalIDs property of the GnTvProgram 
 *  for more info.
 */
@property (nonatomic, assign)   BOOL            enableLinkData;


@end

/** @} */ // end of epg

