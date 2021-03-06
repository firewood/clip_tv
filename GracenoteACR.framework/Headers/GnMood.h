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

/** @addtogroup AudioMetadata Audio Metadata
 *  \brief Metadata classes for Audio results
 *  @{
 */

@interface GnMood : GnMetadataObject

@property (nonatomic, readonly) NSString* level1;
@property (nonatomic, readonly) NSString* level2;

@end
/** @} */ // end of AudioMetadata
