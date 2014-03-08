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
#import "GnCredit.h"
#import "GnTitle.h"

/** @addtogroup AudioMetadata Audio Metadata
 *  \brief Metadata classes for Audio results
 *  @{
 */

@interface GnAudioWork : GnMetadataObject

@property   (nonatomic, readonly) GnTitle*      titleOfficial;
@property   (nonatomic, readonly) GnTitle*      titleRegional;
@property   (nonatomic, readonly) GnTitle*      titleRegionalLocale;
@property   (nonatomic, readonly) GnTitle*      titleAlternate;
@property   (nonatomic, readonly) GnTitle*      titleTLS;
@property   (nonatomic, readonly) NSEnumerator* credits;
@property   (nonatomic, readonly) NSString*     gdoSerialized;
@property   (nonatomic, readonly) NSString*     gnID;
@property   (nonatomic, readonly) NSString*     gnuID;
@property   (nonatomic, readonly) NSString*     productID;
@property   (nonatomic, readonly) NSString*     discoverSeed;
@property   (nonatomic, readonly) NSString*     tui;
@property   (nonatomic, readonly) NSString*     tuiTag;
@property   (nonatomic, readonly) NSString*     getComposition;

@end
/** @} */ // end of AudioMetadata
