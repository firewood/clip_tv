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

@interface GnName : GnMetadataObject

@property (nonatomic, readonly) NSString* displayLanguage;
@property (nonatomic, readonly) NSString* display;
@property (nonatomic, readonly) NSString* sortable;
@property (nonatomic, readonly) NSString* family;
@property (nonatomic, readonly) NSString* given;
@property (nonatomic, readonly) NSString* prefix;
@property (nonatomic, readonly) NSString* globalID;

@end
/** @} */ // end of AudioMetadata
