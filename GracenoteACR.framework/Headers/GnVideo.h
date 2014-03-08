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
#import "GnVideoContributor.h"
#import "GnVideoSeries.h"
#import "GnVideoSeason.h"
#import "GnVideoWork.h"
#import "GnVideoProduct.h"
#import "GnUser.h"
#import "GnResult.h"
#import "GnVideoWorkResultFilter.h"

/** @addtogroup video Video 
 *  \brief Video Query APIs
 *  @{
 */


@protocol GnVideoStatusDelegate;




@interface GnVideo : GnObject


-(id)initWithUser:(GnUser*)user error:(NSError**)error;

/** @name FindContributors
 *  APIs to find GnVideoContributor results 
 */
///@{

-(GnResult*)findContributorsWithGnID :          (GnID*)gnID error:(NSError**)error;
-(GnResult*)findContributorsWithProduct :       (GnVideoProduct*)gdo error:(NSError**)error;
-(GnResult*)findContributorsWithWork :          (GnVideoWork*)work error:(NSError**)error;
-(GnResult*)findContributorsWithContributor:    (GnVideoContributor*)contributor error:(NSError**)error;
-(GnResult*)findContributorsWithSeries:         (GnVideoSeries*)series error:(NSError**)error;
-(GnResult*)findContributorsWithSeason:         (GnVideoSeason*)season error:(NSError**)error;
-(GnResult*)findContributorWithSearchField:     (NSString*)GnVideoContributorSearchField 
                                searchText:     (NSString*)searchText
                                     error:     (NSError**)error;
// TODO: Contributor search with extended ID
///@}


/** @name FindSeasons
 *  APIs to find GnVideoSeason results 
 */
///@{

-(GnResult*)findSeasonsWithGnID :         (GnID*)gnID error:(NSError**)error;
-(GnResult*)findSeasonsWithProduct :      (GnVideoProduct*)work error:(NSError**)error;
-(GnResult*)findSeasonsWithWork :         (GnVideoWork*)work error:(NSError**)error;
-(GnResult*)findSeasonsWithContributor:   (GnVideoContributor*)contributor error:(NSError**)error;
-(GnResult*)findSeasonsWithSeries:        (GnVideoSeries*)series error:(NSError**)error;
-(GnResult*)findSeasonsWithSeason:        (GnVideoSeason*)season error:(NSError**)error;
// TODO: -(GnResult*)findSeriesWithSearchField:
// TODO: Seasons search with extended ID
///@}

/** @name FindWorks
 *  APIs to find GnVideoWork results 
 */
///@{

-(GnResult*)findWorksWithGnID :         (GnID*)gnID error:(NSError**)error;
-(GnResult*)findWorksWithProduct:       (GnVideoProduct*)product error:(NSError**)error;
-(GnResult*)findWorksWithWork :         (GnVideoWork*)work error:(NSError**)error;
-(GnResult*)findWorksWithContributor:   (GnVideoContributor*)contributor error:(NSError**)error;
-(GnResult*)findWorksWithSeries:        (GnVideoSeries*)series error:(NSError**)error;
-(GnResult*)findWorksWithSeason:        (GnVideoSeason*)season error:(NSError**)error;
-(GnResult*)findWorksWithSearchField:   (NSString*)GnVideoWorkSearchField 
                          searchText:   (NSString*)searchText 
                              filter:   (GnVideoWorkResultFilter*)filter    //!< pass nil for no filtering
                               error:   (NSError**)error;
// TODO: work search with extended ID
///@}



/** @name FindProducts
 *  APIs to find GnVideoProduct results 
 */
///@{

-(GnResult*)findProductsWithGnID :          (GnID*)gnID error:(NSError**)error;
-(GnResult*)findProductsWithProduct:        (GnVideoProduct*)gdo error:(NSError**)error;
-(GnResult*)findProductsWithWork :          (GnVideoWork*)gdo error:(NSError**)error;
-(GnResult*)findProductsWithContributor:    (GnVideoContributor*)gdo error:(NSError**)error;
-(GnResult*)findProductsWithSeries:         (GnVideoSeries*)gdo error:(NSError**)error;
-(GnResult*)findProductsWithSeason:         (GnVideoSeason*)gdo error:(NSError**)error;
-(GnResult*)findProductsWithSearchField:    (NSString*)GnVideoProductSearchField 
                             searchText:    (NSString*)searchText
                                  error:    (NSError**)error;
// TODO: Products search with extended ID
///@}



/** @name Find Series
 *  APIs to find GnVideoSeries results
 */
///@{

-(GnResult*)findSeriesWithGnID :         (GnID*)gnID error:(NSError**)error;
-(GnResult*)findSeriesWithWork :         (GnVideoWork*)work error:(NSError**)error;
-(GnResult*)findSeriesWithContributor:   (GnVideoContributor*)contributor error:(NSError**)error;
-(GnResult*)findSeriesWithSeries:        (GnVideoSeries*)series error:(NSError**)error;
-(GnResult*)findSeriesWithSeason:        (GnVideoSeason*)season error:(NSError**)error;
-(GnResult*)findSeriesWithSearchField:   (NSString*)GnVideoSeriesSearchField 
                           searchText:   (NSString*)searchText
                                error:   (NSError**)error;
// TODO: Series search with extended ID
///@}



/** @name FindSuggestions
 *  APIs to find GnVideoSuggestion results 
 */
///@{
-(GnResult*)findSuggestionsWithSearchField:(NSString*)GnVideoSuggestionSearchField 
                                searchText:(NSString*)searchText
                                     error:(NSError**)error;
///@}




@property (nonatomic, assign)   BOOL            enableLinkData;
@property (nonatomic, assign)   BOOL            disableCache;
@property (nonatomic, assign)   NSString*       language;
@property (nonatomic, assign)   unsigned        rangeSize;
@property (nonatomic, assign)   unsigned        rangeStart;

// TODO Status delegate
@property (nonatomic, assign)   id<GnVideoStatusDelegate>   delegate;

@end




/** @name GnVideoWorkSearchField
 *  Search options for GnVideoWorkSearchField 
 */
///@{
extern NSString * const GnVideoWorkSearchFieldCharacterName;    //!< Search for work by character name 
extern NSString * const GnVideoWorkSearchFieldWorkFranchise;    //!< Search for work  by franchise 
extern NSString * const GnVideoWorkSearchFieldWorkSeries;       //!< Search for work  by series 
extern NSString * const GnVideoWorkSearchFieldWorkTitle;        //!< Search for work  by work title 
extern NSString * const GnVideoWorkSearchFieldContributorName;  //!< Search for work  by contributor name 
///@}

/** @name GnVideoContributorSearchField
 *  Search options for GnVideoContributorSearchField 
 */
///@{
extern NSString * const GnVideoContributorSearchFieldContributorName;   //!< Search for contributor by contributor name 
///@}

/** @name GnVideoProductSearchField
 *  Search options for GnVideoProductSearchField 
 */
///@{
extern NSString * const GnVideoProductSearchFieldProductTitle;  //!< Search for product  by product title 
///@}


/** @name GnVideoSeriesSearchField
 *  Search options for GnVideoSeriesSearchField 
 */
///@{
extern NSString * const GnVideoSeriesSearchFieldSeriesTitle;        //!< Search for series by series title 
extern NSString * const GnVideoSeriesSearchFieldContributorName;    //!< Search for series by contributor name 
///@}

/** @name GnVideoSuggestionSearchField
 *  Search options for GnVideoSuggestionSearchField 
 */
///@{
extern NSString * const GnVideoSuggestionSearchFieldCharacterName;      //!< Search for suggestion by character name 
extern NSString * const GnVideoSuggestionSearchFieldProductTitle;       //!< Search for suggestion by product title 
extern NSString * const GnVideoSuggestionSearchFieldSeriesTitle;        //!< Search for suggestion by series title 
extern NSString * const GnVideoSuggestionSearchFieldWorkFranchise;      //!< Search for suggestion by work franchise 
extern NSString * const GnVideoSuggestionSearchFieldWorkSeries;         //!< Search for suggestion by work series 
extern NSString * const GnVideoSuggestionSearchFieldWorkTitle;          //!< Search for suggestion by work title 
extern NSString * const GnVideoSuggestionSearchFieldContributorName;    //!< Search for suggestion by contributor name 
///@}


/** @} */ // End of Video

