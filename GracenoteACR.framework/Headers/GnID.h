/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */


// Public header

#import <Foundation/Foundation.h>
#import "GnObject.h"
#import "GnMetadataObject.h"

/** @addtogroup manager Manager 
 *  SDK Manager APIs
 *  @{
 */

extern NSString * const GnIdSourceTypeAlbum;
extern NSString * const GnIdSourceTypeTrack;
extern NSString * const GnIdSourceTypeCDDBID;
extern NSString * const GnIdSourceTypeContributor;
extern NSString * const GnIdSourceTypeVideoDisc;
extern NSString * const GnIdSourceTypeVideoProduct;
extern NSString * const GnIdSourceTypeVideoWork;
extern NSString * const GnIdSourceTypeVideoSeason;
extern NSString * const GnIdSourceTypeVideoSeries;
extern NSString * const GnIdSourceTypeTvProgram;
extern NSString * const GnIdSourceTypeTvProvider;
extern NSString * const GnIdSourceTypeTvChannel;


@interface GnID : GnObject


-(id)initWithId:(NSString*)ID idTag:(NSString*)idTag sourceType:(NSString*)GnIdSourceType;

@property (nonatomic, readonly)  NSString* ID;
@property (nonatomic, readonly)  NSString* idTag;
@property (nonatomic, readonly)  NSString* sourceType;

@end
/** @} */ // End of Manager
