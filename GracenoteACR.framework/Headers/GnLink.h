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
#import "GnMetadataObject.h"
#import "GnUser.h"


/** @defgroup Link Link 
 *  \brief Link APIs for image retrieval
 *  @{
 */


/** @name GnImageSize
 *  This group of GnImageSize strings are used to specify the size of the image data to be 
 *  retrieved by the getImageOfSize API. Not every size is necessarily availble for every image. 
 *  The size of the image is indicated by the name, e.g. GnImageSize75 is a 75x75 image
 */
///@{
extern NSString * const GnImageSize75;          
extern NSString * const GnImageSize110;         
extern NSString * const GnImageSize170;         
extern NSString * const GnImageSize220;         
extern NSString * const GnImageSize300;         
extern NSString * const GnImageSize450;         
extern NSString * const GnImageSize720;         
extern NSString * const GnImageSize1080;        

///@} // end of GnImageSize


/**
 *  The GnLink object is resposible for retrieving extra data about the various Metadata objects.
 *  As of this writing, only Image fretch is supported.
 */
@interface GnLink : GnObject

/**
 *  Initializes a link object with a metadata object and your application's GnUser. 
 *  Calling "get" APIs on this object will fetch the requested resources associated 
 *  with the Metadata Object.
 */
-(id)initWithMetadataObject:(GnMetadataObject*)object user:(GnUser*)user error:(NSError**)error;



/**
 *  Gets the number of different images for the Metadata object. 
 */
@property (nonatomic, readonly) NSUInteger      imageItemCount;


-(NSUInteger)coverArtCount;
-(NSData*)getCoverArtOfSize:(NSString*)GnImageSize error:(NSError**)error;

-(NSUInteger)genreArtCount;
-(NSData*)getGenreArtOfSize:(NSString*)GnImageSize error:(NSError**)error;

-(NSUInteger)imageItemCount;
/**
 *  Queries Gracenote Service to retrieve image data. 
 *  Images for GnVideoWork, GnVideoProduct, GnVideoContributor are JPEG
 *  Images for GnTvProgram and GnTvChannel are PNG
 */
-(NSData*)getImageOfSize:(NSString*)GnImageSize error:(NSError**)error;

-(NSUInteger)imageArtistItemCount;
-(NSData*)getImageArtistOfSize:(NSString*)GnImageSize error:(NSError**)error;

@end

/** @} */ // end of Link

