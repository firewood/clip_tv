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

/** @addtogroup manager Manager 
 *  SDK Manager APIs
 *  @{
 */


extern NSString * const GnRegionDefault;
extern NSString * const GnRegionJapan;
extern NSString * const GnRegionGlobal;
extern NSString * const GnRegionUS;
extern NSString * const GnRegionChina;
extern NSString * const GnRegionEurope;
extern NSString * const GnRegionTaiwan;
extern NSString * const GnRegionKorea;

extern NSString * const GnLanguageArabic;
extern NSString * const GnLanguageBhasaIndonesia;
extern NSString * const GnLanguageBulgarian;
extern NSString * const GnLanguageChineseSimplified;
extern NSString * const GnLanguageChineseTraditional;
extern NSString * const GnLanguageCroatian;
extern NSString * const GnLanguageCzech;
extern NSString * const GnLanguageDanish;
extern NSString * const GnLanguageDutch;
extern NSString * const GnLanguageEnglish;
extern NSString * const GnLanguageFarsi;
extern NSString * const GnLanguageFinnish;
extern NSString * const GnLanguageFrench;
extern NSString * const GnLanguageGerman;
extern NSString * const GnLanguageGreek;
extern NSString * const GnLanguageHungarian;
extern NSString * const GnLanguageItalian;
extern NSString * const GnLanguageJapanese;
extern NSString * const GnLanguageKorean;
extern NSString * const GnLanguageNorwegian;
extern NSString * const GnLanguagePolish;
extern NSString * const GnLanguageProtugeseBrazil;
extern NSString * const GnLanguageRomanian;
extern NSString * const GnLanguageRussian;
extern NSString * const GnLanguageSerbian;
extern NSString * const GnLanguageSlovak;
extern NSString * const GnLanguageSpanish;
extern NSString * const GnLanguageSwedish;
extern NSString * const GnLanguageThai;
extern NSString * const GnLanguageTurkish;
extern NSString * const GnLanguageVietnamese;

extern NSString * const GnDescriptorDefault;
extern NSString * const GnDescriptorDetailed;
extern NSString * const GnDescriptorSimplified;



@interface GnLocaleSetting : GnObject

// default setting
// Language English
-(id)init;

-(id)initWithRegion:(NSString*)region 
           language:(NSString*)language 
         descriptor:(NSString*)descriptor;
    
@property (nonatomic, readonly) NSString*       region;
@property (nonatomic, readonly) NSString*       language;
@property (nonatomic, readonly) NSString*       descriptor;

@end
/** @} */ // End of Manager
