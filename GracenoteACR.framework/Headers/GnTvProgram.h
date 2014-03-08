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
#import "GnVideoSeries.h"

/** @addtogroup EpgMetadata EPG Metadata  
 *  \brief EPG Metadata Classes
 *  @{
 */


/** 
 *  The GnTvProgram object encapsulates data about a specific TV program.
 */
@interface GnTvProgram : GnMetadataObject

/**
 *  The title of the matched content, e.g. "Sienfeld" or "The Office"
 */
@property (nonatomic, readonly) GnVideoTitle            *title;

/**
 *  The subtitle of the matched content, e.g. an episode title 
 */
@property (nonatomic, readonly) GnVideoTitle            *subtitle;

/**
 *  The GnVideoWork object related to this program, if available. 
 *  Additional info may be obtained by inspecting the GnVideoWork object.
 */
@property (nonatomic, readonly) GnVideoWork*        avWork;

/**
 *  The GnVideoSeries object related to this program, if available. 
 *  Additional info may be obtained by inspecting the GnVideoSeries object.
 */
@property (nonatomic, readonly) GnVideoSeries*      series;

/**
 *  An NSEnumerator to iterate the 0 or more GnVideoCredit objects for this Tv Program. 
 *  GnVideoCredit objects have information about who was credited for the program and 
 *  how they contributed, e.g. character name, role, contributor, etc.
 */
@property (nonatomic, readonly) NSEnumerator*       credits;


/**
 *  The tui and tuiTag together make a unique identifier for this object in 
 *  the Gracenote Service. 
 */
@property (nonatomic, readonly) NSString*           tui;
@property (nonatomic, readonly) NSString*           tuiTag;


/**
 *  External IDs are 3rd party IDs used to cross link this metadata to 3rd party 
 *  services. Available IDs will vary according to the entitlements granted by
 *  Gracenote Professional Services. 
 *  To recieve this data in the response object, you must set enableLinkData=YES 
 *  in the GnEpg query object.
 */
@property (nonatomic, readonly) NSEnumerator*       externalIDs;    // GnExternalID

@property (nonatomic, readonly) NSString*           seasonCount;
@property (nonatomic, readonly) NSString*           seasonEpisode;
@property (nonatomic, readonly) NSString*           seasonEpisodeCount;
@property (nonatomic, readonly) NSString*           seasonNumber;
@property (nonatomic, readonly) NSString*           seriesEpisode;
@property (nonatomic, readonly) NSString*           seriesEpisodeCount;

/* TODO:
 * GNSDK_GDO_VALUE_LISTING
 */
 

@end
/** @} */ // End of EpgMetadata
