/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */


// Public header


#import "GnObject.h"


/** @addtogroup video Video 
 *  \brief Video Query APIs
 *  @{
 */



@interface GnVideoWorkResultFilter : GnObject

@property (nonatomic, readonly)     NSMutableSet*   excludeGenres;
@property (nonatomic, readonly)     NSMutableSet*   includeGenres;
@property (nonatomic, readonly)     NSMutableSet*   excludeOrigins;
@property (nonatomic, readonly)     NSMutableSet*   includeOrigins;
@property (nonatomic, readonly)     NSMutableSet*   excludeProductionTypes;
@property (nonatomic, readonly)     NSMutableSet*   includeProductionTypes;
@property (nonatomic, readonly)     NSMutableSet*   excludeSerialTypes;
@property (nonatomic, readonly)     NSMutableSet*   includeSerialTypes;

@end


/** @name GnVideoFilterValueProductionType
 *  Search options for GnVideoFilterValueProductionType 
 */
///@{

extern NSString * const GnVideoFilterValueProductionTypeAnimation;
extern NSString * const GnVideoFilterValueProductionTypeDocumentary;
extern NSString * const GnVideoFilterValueProductionTypeEducational;
extern NSString * const GnVideoFilterValueProductionTypeGameShow;
extern NSString * const GnVideoFilterValueProductionTypeInstructional;
extern NSString * const GnVideoFilterValueProductionTypeKaraoke;
extern NSString * const GnVideoFilterValueProductionTypeLivePerformance;
extern NSString * const GnVideoFilterValueProductionTypeMiniSeries;
extern NSString * const GnVideoFilterValueProductionTypeMotionPicture;
extern NSString * const GnVideoFilterValueProductionTypeMusicVideo;
extern NSString * const GnVideoFilterValueProductionTypeSerial;
extern NSString * const GnVideoFilterValueProductionTypeShortFeature;
extern NSString * const GnVideoFilterValueProductionTypeSportingEvent;
extern NSString * const GnVideoFilterValueProductionTypeStageProduction;
extern NSString * const GnVideoFilterValueProductionTypeTVSeries;
extern NSString * const GnVideoFilterValueProductionTypeVarietyShow;
///@}



/** @name GnVideoFilterValueGenre
 *  Search options for GnVideoFilterValueGenre 
 */
///@{
extern NSString * const GnVideoFilterValueGenreActionAdventure;
extern NSString * const GnVideoFilterValueGenreAdult;
extern NSString * const GnVideoFilterValueGenreAnimation;
extern NSString * const GnVideoFilterValueGenreChildren;
extern NSString * const GnVideoFilterValueGenreComedy;
extern NSString * const GnVideoFilterValueGenreDocumentary;
extern NSString * const GnVideoFilterValueGenreDrama;
extern NSString * const GnVideoFilterValueGenreHorror;
extern NSString * const GnVideoFilterValueGenreMusical;
extern NSString * const GnVideoFilterValueGenreSuspense;
extern NSString * const GnVideoFilterValueGenreExperimental;
extern NSString * const GnVideoFilterValueGenreOther;
extern NSString * const GnVideoFilterValueGenreRomance;
extern NSString * const GnVideoFilterValueGenreSciFiFantasy;
extern NSString * const GnVideoFilterValueGenreSpecialInterestEducation;
extern NSString * const GnVideoFilterValueGenreMusicAndPerformingArts;
extern NSString * const GnVideoFilterValueGenreSports;
extern NSString * const GnVideoFilterValueGenreTelevisionAndInternet;
extern NSString * const GnVideoFilterValueGenreMilitaryAndWar;
extern NSString * const GnVideoFilterValueGenreWestern;
///@}

/** @} */ // End of Video
