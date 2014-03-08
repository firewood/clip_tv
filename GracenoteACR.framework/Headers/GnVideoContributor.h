/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */


// Public header
// audited

#import "GnMetadataObject.h"
#import "GnVideoName.h"
/** @addtogroup VideoMetadata Video Metadata
 *  \brief Metadata classes for Video results
 *  @{
 */

@interface GnVideoContributor : GnMetadataObject

@property (nonatomic, readonly)     NSString*       biography;
@property (nonatomic, readonly)     NSString*       biographyLanguage;
@property (nonatomic, readonly)     NSString*       birthDate;
@property (nonatomic, readonly)     NSString*       birthPlace;
@property (nonatomic, readonly)     NSString*       deathDate;
@property (nonatomic, readonly)     NSString*       deathPlace;
@property (nonatomic, readonly)     NSString*       mediaSpace;
@property (nonatomic, readonly)     NSString*       productID;
@property (nonatomic, readonly)     NSString*       role;
@property (nonatomic, readonly)     NSString*       roleBilling;
@property (nonatomic, readonly)     NSString*       roleCategory;
@property (nonatomic, readonly)     NSString*       tui;
@property (nonatomic, readonly)     NSString*       tuiTag;
@property (nonatomic, readonly)     GnVideoName*    nameOfficial;
@property (nonatomic, readonly)     GnVideoName*    nameRegional;
@property (nonatomic, readonly)     GnVideoName*    nameRegionalLocale;

@property (nonatomic, readonly)     BOOL            isPartial;

@property (nonatomic, readonly)     NSEnumerator*   credits;        // GnVideoCredit
@property (nonatomic, readonly)     NSEnumerator*   externalIDs;    // GnExternalID
@property (nonatomic, readonly)     NSEnumerator*   genres;         // GnVideoGenre

@end
/** @} */ // end of VideoMetadata
