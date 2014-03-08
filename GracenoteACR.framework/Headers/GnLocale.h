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
//#import "GnLocaleLoadingStatusDelegate.h"
#import "GnUser.h"
#import "GnLocaleSetting.h"

/** @addtogroup manager Manager 
 *  SDK Manager APIs
 *  @{
 */


extern NSString * const GnLocaleTypeMusic;
extern NSString * const GnLocaleTypeVideo;
extern NSString * const GnLocaleTypePlaylist;
extern NSString * const GnLocaleTypeEPG;
extern NSString * const GnLocaleTypeUnknown;



@interface GnLocale : GnObject


-(id)initWithSerializedLocale:(NSString*)serializedLocale;
-(id)initWithUser:(GnUser*)user 
       localetype:(NSString*)type 
    localeSetting:(GnLocaleSetting*)setting;

@property (nonatomic, readonly)     NSString*           localeType;
@property (nonatomic, readonly)     GnLocaleSetting*    localeSetting;
@property (nonatomic, readonly)     NSString*           serializedLocale;

-(NSError*)loadLocaleData;

// TODO: status delegate



@end
/** @} */ // End of Manager
