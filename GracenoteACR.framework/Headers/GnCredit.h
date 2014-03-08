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
#import "GnContributor.h"
#import "GnName.h"

/** @addtogroup AudioMetadata Audio Metadata
 *  \brief Metadata classes for Audio results
 *  @{
 */

@interface GnCredit : GnMetadataObject

@property (nonatomic, readonly) GnName*         name;
@property (nonatomic, readonly) GnName*         regional;

@property (nonatomic, readonly) GnContributor*  contributor;


@property (nonatomic, readonly) NSString*   role;
@property (nonatomic, readonly) NSString*   roleBilling;
@property (nonatomic, readonly) NSString*   roleCategory;
@property (nonatomic, readonly) NSString*   artistType1;
@property (nonatomic, readonly) NSString*   artistType2;
@property (nonatomic, readonly) NSString*   origin1;
@property (nonatomic, readonly) NSString*   origin2;
@property (nonatomic, readonly) NSString*   origin3;
@property (nonatomic, readonly) NSString*   origin4;
@property (nonatomic, readonly) NSString*   era1;
@property (nonatomic, readonly) NSString*   era2;
@property (nonatomic, readonly) NSString*   era3;

@end
/** @} */ // end of AudioMetadata
