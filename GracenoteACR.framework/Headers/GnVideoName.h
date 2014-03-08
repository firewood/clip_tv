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

@interface GnVideoName : GnMetadataObject

@property   (nonatomic, readonly)   NSString* display;
@property   (nonatomic, readonly)   NSString* displayLanguage;
@property   (nonatomic, readonly)   NSString* family;
@property   (nonatomic, readonly)   NSString* given;
@property   (nonatomic, readonly)   NSString* sortable;
@property   (nonatomic, readonly)   NSString* prefix;

@end
/** @} */ // end of VideoMetadata
