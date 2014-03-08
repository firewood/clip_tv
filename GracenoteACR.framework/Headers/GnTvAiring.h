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
#import "GnTvChannel.h"
#import "GnTvProgram.h"


/** @addtogroup EpgMetadata EPG Metadata  
 *  \brief EPG Metadata Classes
 *  @{
 */


/** 
 *  The GnTvProgram object encapsulates data about a specific airing of a TV program.
 */
@interface GnTvAiring : GnMetadataObject

/**
 *  The start date of the airing, in UTC format. e.g. 2012-05-02T18:30
 */
@property (nonatomic, readonly) NSString*           dateStart;

/**
 *  The end date of the airing, in UTC format. e.g. 2012-05-02T19:00
 */
@property (nonatomic, readonly) NSString*           dateEnd;

/**
 *  The duration of the airing. A string representation of integer time units, e.g. "3600000"
 */
@property (nonatomic, readonly) NSString*           duration;   

/**
 *  The time units of the duration, e.g. "ms" for milliseconds.
 */
@property (nonatomic, readonly) NSString*           durationUnit; 

/**
 *  The TV channel of the airing. Further information can be obtained from inspecting the 
 *  GnTvChannel object, e.g. channel name.
 */
@property (nonatomic, readonly) GnTvChannel*        channel;

/**
 *  The TV program related to this airing. Further information can be obtained from inspecting the 
 *  GnTvProgram object, e.g. program title
 */
@property (nonatomic, readonly) GnTvProgram*        tvProgram;


@end
/** @} */ // End of EpgMetadata
