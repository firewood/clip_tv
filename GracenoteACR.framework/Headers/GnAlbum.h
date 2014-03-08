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
#import "GnArtist.h"
#import "GnGenre.h"
#import "GnTitle.h"
#import "GnLanguage.h"
#import "GnCredit.h"
#import "GnAudioWork.h"

/** @addtogroup AudioMetadata Audio Metadata
 *  \brief Metadata classes for Audio results
 *  @{
 */

@interface GnAlbum : GnMetadataObject

@property   (nonatomic, readonly) GnArtist*     artist;
@property   (nonatomic, readonly) GnTitle*      titleOfficial;
@property   (nonatomic, readonly) GnTitle*      titleRegional;
@property   (nonatomic, readonly) GnTitle*      titleRegionalLocale;
@property   (nonatomic, readonly) GnTitle*      titleAlternate;
@property   (nonatomic, readonly) GnTitle*      titleTLS;

@property   (nonatomic, readonly) NSEnumerator* externalIDs;
@property   (nonatomic, readonly) NSEnumerator* tracks;
@property   (nonatomic, readonly) NSEnumerator* matchedTracks;

@property   (nonatomic, readonly) NSEnumerator* audioWorks;
@property   (nonatomic, readonly) BOOL          isPartial;
@property   (nonatomic, readonly) NSString*     globalID;
@property   (nonatomic, readonly) NSString*     gdoSerialized;
@property   (nonatomic, readonly) NSString*     gnID;
@property   (nonatomic, readonly) NSString*     gnuID;
@property   (nonatomic, readonly) NSString*     productID;
@property   (nonatomic, readonly) NSString*     discoverSeed;
@property   (nonatomic, readonly) NSString*     tui;
@property   (nonatomic, readonly) NSString*     tuiTag;
@property   (nonatomic, readonly) int           matchScore;
@property   (nonatomic, readonly) GnLanguage*   packageLanguage;
@property   (nonatomic, readonly) NSString*     year;
@property   (nonatomic, readonly) GnGenre*      genre;
@property   (nonatomic, readonly) NSString*     label;
@property   (nonatomic, readonly) int           numberOfDiscs;
@property   (nonatomic, readonly) int           discNumber;
@property   (nonatomic, readonly) int           trackCount;
@property   (nonatomic, readonly) BOOL          isCompilation;
@property   (nonatomic, readonly) BOOL          isClassicalDataAvailable;
@property   (nonatomic, readonly) int           trackMatchedNumber;
@property   (nonatomic, readonly) int           trackMatchedPosition;


@end
/** @} */ // end of AudioMetadata
