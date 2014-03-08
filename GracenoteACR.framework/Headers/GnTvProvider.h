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
#import "GnVideoName.h"
/** @addtogroup EpgMetadata EPG Metadata  
 *  \brief EPG Metadata Classes
 *  @{
 */


/** 
 *  The GnTvProvider object encapsulates data about a specific 
 *  North American Tv Provider.
 */
@interface GnTvProvider : GnMetadataObject

/**
 *  The name of the provider, e.g. DirecTV
 */
@property (nonatomic, readonly) GnVideoName*           name;

/**
 *  The place of the provider, e.g. San Francisco
 */
@property (nonatomic, readonly) NSString*           place;

/**
 *  The tui and tuiTag together make a unique identifier for this object in 
 *  the Gracenote Service. 
 */
@property (nonatomic, readonly) NSString*           tui;
@property (nonatomic, readonly) NSString*           tuiTag;

@end
/** @} */ // End of EpgMetadata
