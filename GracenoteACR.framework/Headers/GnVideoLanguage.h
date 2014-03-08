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

/** @addtogroup VideoMetadata Video Metadata
 *  \brief Metadata classes for Video results
 *  @{
 */

@interface GnVideoLanguage : GnMetadataObject


@property (nonatomic, readonly)     NSString*       code;
@property (nonatomic, readonly)     NSString*       display;

@end
/** @} */ // end of VideoMetadata
