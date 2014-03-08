/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */


// Public header
// Audited

#import "GnMetadataObject.h"

/** @addtogroup VideoMetadata Video Metadata
 *  \brief Metadata classes for Video results
 *  @{
 */

@interface GnVideoPlot : GnMetadataObject

@property   (nonatomic, readonly)   NSString* synopsis;
@property   (nonatomic, readonly)   NSString* synopsisLanguage;

@end
/** @} */ // end of VideoMetadata
