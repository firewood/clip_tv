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
#import "GnVideoContributor.h"
/** @addtogroup VideoMetadata Video Metadata
 *  \brief Metadata classes for Video results
 *  @{
 */

@interface GnVideoCredit : GnMetadataObject

@property (nonatomic, readonly)     NSString*               characterName;
@property (nonatomic, readonly)     NSString*               role;
@property (nonatomic, readonly)     NSString*               roleBilling;
@property (nonatomic, readonly)     NSString*               roleCategory;

@property (nonatomic, readonly)     GnVideoContributor*     contributor;


@property (nonatomic, readonly)     NSEnumerator*   seasons;        // GnVideoSeason
@property (nonatomic, readonly)     NSEnumerator*   series;         // GnVideoSeries
@property (nonatomic, readonly)     NSEnumerator*   works;          // GnVideoWork

@end
/** @} */ // end of VideoMetadata
