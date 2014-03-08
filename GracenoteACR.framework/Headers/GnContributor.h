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
#import "GnGenre.h"

/** @addtogroup AudioMetadata Audio Metadata
 *  \brief Metadata classes for Audio results
 *  @{
 */


@interface GnContributor : GnMetadataObject


@property (nonatomic, readonly) GnName*     name;
@property (nonatomic, readonly) GnName*     regional;
@property (nonatomic, readonly) GnName*     regionalLocal;
@property (nonatomic, readonly) GnName*     alternate;
@property (nonatomic, readonly) NSEnumerator* contributors;
@property (nonatomic, readonly) NSEnumerator* externalIDs;
@property (nonatomic, readonly) BOOL        isPartial;
@property (nonatomic, readonly) NSString*   gdoSerialized;
@property (nonatomic, readonly) NSString*   gnID;
@property (nonatomic, readonly) NSString*   gnuID;
@property (nonatomic, readonly) NSString*   productID;
@property (nonatomic, readonly) NSString*   tui;
@property (nonatomic, readonly) int         matchScore;
@property (nonatomic, readonly) NSString*   biography;
@property (nonatomic, readonly) NSString*   origin1;
@property (nonatomic, readonly) NSString*   origin2;
@property (nonatomic, readonly) NSString*   origin3;
@property (nonatomic, readonly) NSString*   origin4;
@property (nonatomic, readonly) NSString*   era1;
@property (nonatomic, readonly) NSString*   era2;
@property (nonatomic, readonly) NSString*   era3;
@property (nonatomic, readonly) NSString*   artistType1;
@property (nonatomic, readonly) NSString*   artistType2;
@property (nonatomic, readonly) NSString*   birthDate;
@property (nonatomic, readonly) NSString*   birthPlace;
@property (nonatomic, readonly) NSString*   deathDate;
@property (nonatomic, readonly) NSString*   deathPlace;
@property (nonatomic, readonly) NSString*   mediaSpace;

@end
/** @} */ // end of AudioMetadata
