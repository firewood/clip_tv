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
#import "GnUser.h"
#import "GnResult.h"
#import "GnID.h"
#import "GnAlbum.h"
#import "GnTrack.h"


/** @addtogroup musicID MusicID
 *  \brief MusicID Query APIs
 *  @{
 */



/** @name GnMusicIdFingerprintType
 *  Fingerprint types to be used with fingerprint APIs
 */
//@{
extern NSString * const GnMusicIdFingerprintTypeGNFPX;  ///< Gracenote Fingerprint Type
extern NSString * const GnMusicIdFingerprintTypeCMX;    ///< Cantametrix Fingerprint Type 
//@}


@protocol GnMusicIDStatusDelegate;

/** The GnMusicID object is responsible for making MusicID queries.
 */
@interface GnMusicID : GnObject


/**
 *  Initialzes a new GnMusicID object with the Application's GnUser object. The GnUser bust be 
 *  entitled for MusicID. Contact Gracenote Professional Services for more information about 
 *  Entitlements.
 */
-(id)initWithUser:(GnUser*)user error:(NSError**)error;


/** @name MusicID Stream
 *  These APIs prepare and perform MusicID Stream (fingerprint) queries. The typical workflow
 *  for fingerprint queries is: fingerprintBegin, fingerprintWrite, fingerprintEnd, then finally
 *  either of the findAlbums or findTracks. The begin/write/end combination converts PCM audio
 *  data into an audio fingerprint, then "find" submits the fingerprint query to the
 *  Gracenote Service.
 */
//@{

/**
 *  Call this method to initiate fingerprint generation. You must specify the fingerprint type,
 *  the sample rate of the incoming PCM audio, the sample size, and the number of channels.
 *  Currently the suported sample rate values are 8000 and 44100. 
 */
-(int)fingerprintBegin:(NSString*)fingerprintType
            sampleRate:(int)sampleRate
       sampleSizeBytes:(int)sampleSize
      numberOfChannels:(int)numberOfChannels
                 error:(NSError**)error;

/**
 *  Call this method to finalize the fingerprint. You should only call this fingerprintWrite
 *  has returned YES, indicating the fingerprint is ready for finalization.
 */
-(int)fingerprintEnd:(NSError**)error;

/**
 *  Call this method to feed PCM audio data into the fingerprinter. The data should be of the
 *  same format specified in the call to fingerprintBegin. Keep feeding new data to this API
 *  until it returns YES, indicating the fingerprinter has enough data. Then call fingerprintEnd.
 */
-(BOOL)fingerprintWrite:(const void*)data
               dataSize:(size_t)dataSize
                  error:(NSError**)error;

/**
 * Performs MusicID query for Albums matching a fingerprint generated from PCM audio.
 */
-(GnResult*)findAlbums:(NSError**)error;

/**
 * Performs MusicID query for Tracks matching a fingerprint generated from PCM audio.
 */
-(GnResult*)findTracks:(NSError**)error;

//@}




/** @name Albums
 *  These APIs perform Album queries
 */
//@{


/**
 *  Perform MusicID query for albums whose Table of Contents string (TOC) match the input.
 */
-(GnResult*)findAlbumsWithTOC:(NSString*)toc
                        error:(NSError**)error;

/**
 *  Perform MusicID query for albums whose TOC offsets match the input. tocOffsets is an array 
 *  of NSNumber objects representing the integer offsets of the TOC.
 */
-(GnResult*)findAlbumsWithTocOffsets:(NSArray*)tocOffsets
                               error:(NSError**)error;

/**
 *  Perform MusicID query for albums that match a given fingerprint and type.
 *  See GnMusicIdFingerprintType above.
 */
-(GnResult*)findAlbumsWithFingerprint:(NSString*)fingerprintData
                               fpType:(NSString*)type
                                error:(NSError**)error;

/**
 *  Perform MusicID query for albums that match a given TOC, fingerprint and type.
 *  See GnMusicIdFingerprintType above.
 */
-(GnResult*)findAlbumsWithTOC:(NSString*)toc
                  fingerprint:(NSString*)fingerprintData
                       fpType:(NSString*)type
                        error:(NSError**)error;

/**
 *  Perform MusicID query for albums that match a given GnID.
 */
-(GnResult*)findAlbumsWithGnID:(GnID*)gnid
                         error:(NSError**)error;

/**
 *  Perform MusicID query for albums that match a given album title, track title, or artist name. 
 *  Some input strings may be nil.
 */
-(GnResult*)findAlbumsWithTitle:(NSString*)albumTitle
                     trackTitle:(NSString*)trackTitle
                         artist:(NSString*)artist
                          error:(NSError**)error;

//@}



/** @name Tracks
 *  These APIs perform Track queries
 */
//@{



/**
 *  Perform MusicID query for tracks that match a given GnID.
 */
-(GnResult*)findTracksWithGnID:(GnID*)gnid
                         error:(NSError**)error;

/**
 *  Perform MusicID query for tracks that match a given fingerprint and type. 
 *  See GnMusicIdFingerprintType above.
 */
-(GnResult*)findTracksWithFingerprint:(NSString*)fingerprintData
                               fpType:(NSString*)type
                                error:(NSError**)error;
//@}


/**
 *  Perform MusicID query to get the full metadata for a partial GnAlbum object. 
 *  Partial GnAlbum objects ar indicated via the isPartial property.
 */
-(GnAlbum*)getFullAlbumContent:(GnAlbum*)partialAlbum error:(NSError**)error;

/**
 *  Perform MusicID query to get the full metadata for a partial GnTrack object.
 *  Partial GnTrack objects ar indicated via the isPartial property.
 */
-(GnTrack*)getFullTrackContent:(GnTrack*)partialTrack error:(NSError**)error;




/**
 *  To retrieve classical music data on a query, set this property to YES.
 *  An application's license must be entitled to retrieve this specialized data. 
 *  Contact your Gracenote Professional Services representative with any questions 
 *  about this enhanced functionality.
 */
@property (nonatomic, assign) BOOL          enableClassicalData;

/**
 *  To retrieve Mood or Tempo information about Tracks, set this property to YES.
 *  An application's license must be entitled to retrieve this specialized data.
 *  Contact your Gracenote Professional Services representative with any questions
 *  about this enhanced functionality.
 */
@property (nonatomic, assign) BOOL          enableDSPData;

/**
 *  Link data is thrid-party metadata associated with a query result (such as 
 *  Amazon ID, or Cover Art). To retrieve Link data on a query, set this property to YES.
 *  An application's license must be entitled to retrieve this specialized data.
 *  Contact your Gracenote Professional Services representative with any questions
 *  about this enhanced functionality.
 */
@property (nonatomic, assign) BOOL          enableLinkData;

/**
 *  Playlist Data
 *  An application's license must be entitled to retrieve this specialized data.
 *  Contact your Gracenote Professional Services representative with any questions
 *  about this enhanced functionality.
 */
@property (nonatomic, assign) BOOL          enablePlaylistData;

/**
 *  Use this function to get fingerprint data for cases where the application needs 
 *  to store the fingerprint data for its own purposes. Fingerprint data is available 
 *  after it has been generated via the sequence of methods: fingerprintBegin, 
 *  fingerprintWrite, fingerprintEnd. See these for more info.
 */
@property (nonatomic, readonly) NSString*     fingerprintData;

/**
 *  Use this function to set fingerprint data for cases where the application needs
 *  to load the fingerprint data for its own purposes. The application can use this 
 *  method in place of using fingerprintBegin, fingerprintWrite, fingerprintEnd.
 */
-(int)setFingerprintData:(NSString *)fingerprintData
                  fpType:(NSString*)fpType
                   error:(NSError**)error;


/**
 *  Indicates whether a response must return results only when an updated revision exists.
 */
@property (nonatomic, assign) BOOL          revisionCheck;

/**
 *  Use this property to set the lanquare preference of the query result. 
 *  See GnLocaleSetting for language choices.
 */
@property (nonatomic, assign) NSString*     language;

/**
 *  The number of results desired for this query object. The GnResult object returned by a query
 *  will have no more than this number of results contained within it.
 */
@property (nonatomic, assign) unsigned      rangeSize;

/**
 *  The starting index of results desired for this query object. The GnResult 
 *  object returned by a query will contain results from this index upward. The index is 1-based.
 */
@property (nonatomic, assign) unsigned      rangeStart;

/**
 *  Set this to ensure the result contains only the single best result for the query.
 */
@property (nonatomic, assign) BOOL          returnSingleResult;


/**
 *  Set the status object to which status messages will be sent. 
 *  (currently callbacks are not implemented)
 */
@property  (nonatomic, assign) id<GnMusicIDStatusDelegate> statusDelegate;



// TODO
//-(void)setLookupMode:(void*)mode;




@end


/** @} */ // End of MusicID
