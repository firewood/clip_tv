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
#import "GnName.h"
#import "GnContributor.h"

/** @addtogroup AudioMetadata Audio Metadata
 *  \brief Metadata classes for Audio results
 *  @{
 */


@interface GnArtist : GnMetadataObject

@property (nonatomic, readonly) GnName*             name;
@property (nonatomic, readonly) GnContributor*      contributor;

@end
/** @} */ // end of AudioMetadata
