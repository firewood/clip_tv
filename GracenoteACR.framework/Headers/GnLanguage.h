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

@interface GnLanguage : GnMetadataObject

@property (nonatomic, readonly) NSString* display;
@property (nonatomic, readonly) NSString* code;

@end
/** @} */ // end of AudioMetadata
