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
 *  Metadata classes for Video results
 *  @{
 */

@interface GnVideoSuggestion : GnMetadataObject

@property (nonatomic, readonly)     NSString*               text;
@property (nonatomic, readonly)     NSString*               title;
@property (nonatomic, readonly)     NSString*               type;

@end
/** @} */ // end of VideoMetadata
