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

/** @addtogroup EpgMetadata EPG Metadata  
 *  \brief EPG Metadata Classes
 *  @{
 */


/** 
 *  The GnTvChannel object encapsulates data about a specific TV broadcast or provider channel.
 */
@interface GnTvChannel : GnMetadataObject


/**
 *  The name of the channel, i.e. Lifetime HD
 */
@property (nonatomic, readonly) NSString*           name;

/**
 *  The callsign of the channel, i.e. LIFEHD
 */
@property (nonatomic, readonly) NSString*           callsign;

/**
 *  The provider-assigned number of the channel, i.e. "256". This number will only be 
 *  valid for channels obtained from the findChannelsWithProvider API of GnEpg.
 */
@property (nonatomic, readonly) NSString*           number;

/**
 *  With a findAirings query of the GnEPG object, the API requires an array of channels 
 *  on which to search. Upon obtaining the results of a findAirings query, the channel 
 *  ident will refer to the index of the array of channels. The channel object obtained from 
 *  a GnTvAiring object can often be only partially populated. The application should maintain 
 *  the original channels array to properly reference the complete channel data.
 */
@property (nonatomic, readonly) int                 ident;



/** @name European Broadcast Channels
 *  European broadcast channels are identified via the tuple of ONID, TSID, SID.
 *  These fields are valid only for channels obtained from the findChannelsWithDVBs API.
 */
///@{
 

/**
 *  The ONID of a European broadcast channel
 */
@property (nonatomic, readonly) NSString*           ONID;

/**
 *  The TSID of a European broadcast channel
 */
@property (nonatomic, readonly) NSString*           TSID;

/**
 *  The SID of a European broadcast channel
 */
@property (nonatomic, readonly) NSString*           SID;
///@}




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

@end
/** @} */ // End of EpgMetadata
