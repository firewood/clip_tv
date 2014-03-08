/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

#import "GN_ACR_SDKViewController.h"
//#import <AudioToolbox/AudioToolbox.h>

#import "common.h"

#define SAVED_USER_KEY_ACR @"savedUserACR"
#define SAVED_USER_KEY_MUSIC @"savedUserMUSIC"
#define ADAPTIVE_TAG  12


// Activity indicator add-on for UIButton
@interface UIButton(sampleApp)

-(void)setBusy:(BOOL)busy;
@end

@implementation UIButton(sampleApp)

-(void)setBusy:(BOOL)busy
{
    if (busy) {
        // add spinner
        UIView *view = [self viewWithTag:987654321];
        if (!view) {
            UIActivityIndicatorView *spinner = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
            spinner.center = CGPointMake(CGRectGetMidX(self.bounds), CGRectGetMidY(self.bounds));
            [spinner startAnimating];
            spinner.tag = 987654321;
            [self addSubview:spinner];
            self.enabled = NO;
        }
        
    }
    else
    {
        //remove spinner
        UIView *spinner = [self viewWithTag:987654321];
        [spinner removeFromSuperview];
        self.enabled = YES;
    }
}


@end


@implementation GN_ACR_SDKViewController

// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad
{
    [super viewDidLoad];
    isWebViewReady_ = NO;
	statusTextView.font = [UIFont fontWithName:@"Trebuchet MS" size:12.0f];
	resultsTextView.font = [UIFont fontWithName:@"Trebuchet MS" size:12.0f];
    
    // Determine whether a method is available on an existing class
    if([[AVAudioSession sharedInstance] respondsToSelector:@selector(requestRecordPermission:)])
    {
        [[AVAudioSession sharedInstance] requestRecordPermission:^(BOOL granted) {
            if (!granted)
            {
                // Warn no access to microphone
                for (UIButton *buttonItem in buttonCollection) {
                    [buttonItem setEnabled:NO];
                }
                [self updateStatusMessage:[NSString stringWithFormat:@"Microphone not permitted"]];
            }
        }];
    }

    
    
    // generate web view
    webView_ = [[UIWebView alloc] init];
    webView_.frame = self.view.bounds;
    webView_.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    webView_.scalesPageToFit = YES;
    webView_.delegate = self;
    [self.view addSubview:webView_];
    NSURLRequest* request = [NSURLRequest requestWithURL:[NSURL URLWithString:@"http://54.249.175.51/temp.html"]];
    [webView_ loadRequest:request];

 
    NSLog(@"viewDidLoad");

    
    [self acrButtonPressed:buttonACR];
    
    
}


-(void)appendProgramContent:(NSString *)msg {
    if (isWebViewReady_) {
//        [webView_ stringByEvaluatingJavaScriptFromString:[NSString stringWithFormat:@"add_CM_clip('%@');", msg]];
        [webView_ stringByEvaluatingJavaScriptFromString:[NSString stringWithFormat:@"add_program_clip({'title':'%@','detail':'det'});", msg]];
    }
}


-(void)webViewDidFinishLoad:(UIWebView*)webView{
    
    NSLog(@"webViewDidFinishLoad");
    isWebViewReady_ = YES;

    [self appendProgramContent:@"webViewDidFinishLoad"];
    
    
//    NSString *text = @"test message";
//    [webView_ stringByEvaluatingJavaScriptFromString:[NSString stringWithFormat:@"add_CM_clip('%@');", text]];
//    text = @"日本語のテスト";
//    [webView_ stringByEvaluatingJavaScriptFromString:[NSString stringWithFormat:@"add_CM_clip('%@');", text]];
}


// Sample app UI helpers
#define logLimit    3000

- (void)formatLog:(NSString *)msg textView:(UITextView*)textView{
    if (msg) {
        NSString *currentText = textView.text;
        NSString *newtext = [msg stringByAppendingFormat:@"\n%@",currentText];
        if (newtext.length >= logLimit)
        {
            NSRange limit = {0, logLimit};
            NSRange finalNewline = [newtext rangeOfString:@"\n" options:NSBackwardsSearch range:limit];
            NSRange subRange = {0, finalNewline.location};
            newtext = [newtext substringWithRange:subRange];
            newtext = [newtext stringByAppendingFormat:@"\nLog truncated to conserve memory."];
        }
        textView.text = newtext;
    }
}


-(void)updateStatusMessage:(NSString *)msg{
    
    // make sure UI updates are on the main thread
    if ([NSThread isMainThread]) {
        [self formatLog:msg textView:statusTextView];

        [self appendProgramContent:msg];

    } else {
        [self performSelectorOnMainThread:@selector(updateStatusMessage:) withObject:msg waitUntilDone:NO];
    }
    
}


-(void)updateResultMessage:(NSString *)msg{
    // make sure UI updates are on the main thread
    if ([NSThread isMainThread]) {
        [self formatLog:msg textView:resultsTextView];

        [self appendProgramContent:msg];
        
    } else {
        [self performSelectorOnMainThread:@selector(updateResultMessage:) withObject:msg waitUntilDone:NO];
    }
    
}




// SDK example code



-(GnUser*)getUserACR
{
    // It is best practice to cache users after the first launch of the app.
    // This sample code shows how to serialize and save the user for subsequent launches.
    
    if (!mUserACR) {
        NSError *error = nil;
        NSString *savedUser = [[NSUserDefaults standardUserDefaults] objectForKey:SAVED_USER_KEY_ACR];
        
        if (savedUser)
        {
            mUserACR = [[GnUser alloc] initWithSerializedUser:savedUser
                                                        error:&error];
        }
        else
        {
            mUserACR = [[GnUser alloc] initWithClientId:CLIENT_ID_VIDEO
                                            clientIdTag:CLIENT_TAG_VIDEO
                                             appVersion:@"any string you prefer, e.g. '1.0'"
                                       registrationType:GnUserRegistrationType_NewUser error:&error];
            
            if (mUserACR) {
                // this should be saved somewhere secure like the keychain,
                // but this is outside the scope of the sample code.
                [[NSUserDefaults standardUserDefaults] setObject:mUserACR.serializedUser
                                                          forKey:SAVED_USER_KEY_ACR];
                [[NSUserDefaults standardUserDefaults] synchronize];
            }
        }
        
        if (error) {
            [self updateStatusMessage:[NSString stringWithFormat:@"getUserACR: ERROR: %@", error.localizedDescription]];
        }
        
    }
    return mUserACR;
}

#if ENABLE_MUSIC_ID
-(GnUser*)getUserMusic
{
    // It is best practice to cache users after the first launch of the app.
    // This sample code shows how to serialize and save the user for subsequent launches.
    
    if (!mUserMusic) {
        NSError *error = nil;
        NSString *savedUser = [[NSUserDefaults standardUserDefaults] objectForKey:SAVED_USER_KEY_MUSIC];
        
        if (savedUser)
        {
            mUserMusic = [[GnUser alloc] initWithSerializedUser:savedUser error:&error];
        }
        else
        {
            mUserMusic = [[GnUser alloc] initWithClientId:CLIENT_ID_MUSIC
                                              clientIdTag:CLIENT_TAG_MUSIC
                                               appVersion:@"any string you prefer, e.g. '1.0'"
                                         registrationType:GnUserRegistrationType_NewUser error:&error];
            
            if (mUserMusic) {
                // this should be saved somewhere secure like the keychain,
                // but this is outside the scope of the sample code.
                [[NSUserDefaults standardUserDefaults] setObject:mUserMusic.serializedUser
                                                          forKey:SAVED_USER_KEY_MUSIC];
                [[NSUserDefaults standardUserDefaults] synchronize];
            }
        }
        
        if (error) {
            [self updateStatusMessage:[NSString stringWithFormat:@"getUserMusic: ERROR: %@", error.localizedDescription]];
        }
        
    }
    return mUserMusic;
}
#endif


-(void)doManualLookUp{
    
    if (!mACR || !mSource) {
        [self updateStatusMessage:@"Error: ACR not running."];
        return;
    }
    // Call doManualLookup to request that a query be made immediately
    // the request will be honored as soon as appropriate
    NSError *error = [mACR doManualLookup];
    if (error) {
        [self updateStatusMessage:[error localizedDescription]];
    }
    else
        [self updateStatusMessage:@"Manual Lookup requested"];
    
}

- (void)dealloc {
    
    // release all retained SDK objects!
#if ENABLE_MUSIC_ID
    [mUserMusic release];
    [mAudioCache release];
    [mMusicQuery release];
#endif
    [mUserACR release];
    [mACR release];
    [mManager release];
    [mLatestAcrMatch release];
    
	[statusTextView release];
	[resultsTextView release];
    [mSource release];
    [super dealloc];
}


- (void)stopACR
{
    NSError *error;
    error = [mSource stop];
    
    [mSource release];
    
    // Deallocation of GnAcr objects may block until all status and result delegate callbacks are complete.
    // Be careful not to block these callbacks for long periods of time.
    // Also, do not release GnAcr objects in the delegate callbacks
    [mACR release];
    
    mSource = nil;
    mACR = nil;
    
    NSString *msg;
    if (error)
        msg = [NSString stringWithFormat:@"Source Stop ERROR: %@ (0x%x)", error.localizedDescription, error.code];
    else
        msg = @"ACR Stopped";
    // schedule this UI update after any pending Status/Result UI updates
    [self performSelectorOnMainThread:@selector(updateStatusMessage:) withObject:msg waitUntilDone:NO];
    
    
}

- (void)initManager:(NSError **)error
{
    // Create/init a manager with customers's license. Only create one manager per app instance.
    if (!mManager) {

        mManager = [[GnSdkManager alloc] initWithLicense:LICENSE_STRING error:error];
        // set up local cacheing
        if(mManager){
            NSArray *paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory,
                                                                 NSUserDomainMask,
                                                                 YES);
            
            // It is advised to explicitly set the storage folders for the SDK.
            // These paths are used intenally to the SDK but the application may decide the
            // best location for certain caches.
            NSString *cacheFolderPath = [paths objectAtIndex:0];
            [GnStorageSqlite setStorageFolder:cacheFolderPath error:error];
            // [GnStorageSqlite setStorageFileSize:10240 error:error];     // 5 MB
            [GnStorageSqlite setStorageMemorySize:512 error:error];    // 512 KB
            
            // It is advised to explicitly set the GnFPCache storage folder on each launch.
            [GnFPCache setStorageFolder:cacheFolderPath error:error];
            
            // now we can ingest any bundles we have available
            [self loadFPBundle];
        }
    }
}

-(IBAction)acrButtonPressed:(UIButton*)sender
{
    
    
    NSError *error = nil;
    BOOL isPlaying = sender.selected;
    
    if (!isPlaying) {
        
        [self initManager:&error];
        
        if (error){
            // [self updateResultMessage:error.localizedDescription];
            [self updateStatusMessage:[NSString stringWithFormat:@"Initialization failure"]];
            return;
        }
        
        
        NSString *versionMessage = [NSString stringWithFormat:@"ACR version %@", [mManager productVersion]];
        [self updateStatusMessage:versionMessage];
        
        // reuse saved user or create a new one
        GnUser *acrUser = [self getUserACR];
        
        if (!acrUser) {
            [self updateStatusMessage:[NSString stringWithFormat:@"Invalid User"]];
            return;
        }
        
        // create ACR object with user
        mACR = [[GnACR alloc] initWithUser:acrUser
                                     error:&error];
        
        
        // set the delegates to receive status and results
        // this class implements the delegate protocols
        // IGnAcrResultDelegate, IGnAcrStatusDelegate
        // via delegate methods acrResultReady: and acrStatusReady:
        mACR.statusDelegate = self;
        mACR.resultDelegate = self;
        
        if (error) {
            NSString *msg = [NSString stringWithFormat:@"ACR init ERROR: %@ (0x%x)", error.localizedDescription, error.code];
            [self updateStatusMessage:msg];
            return;
        }
        
        // set the Audio config on the ACR object
        GnAcrAudioConfig *config =
        [[[GnAcrAudioConfig alloc] initWithAudioSourceType:GnAcrAudioSourceMic
                                                sampleRate:GnAcrAudioSampleRate44100 // only 8000, and 44100 are supported
                                                    format:GnAcrAudioSampleFormatPCM16
                                               numChannels:1] autorelease];
        
        error = [mACR audioInitWithAudioConfig:config];
        if (error) {
            NSString *msg = [NSString stringWithFormat:@"Audio init ERROR: %@ (0x%x)", error.localizedDescription, error.code];
            [self updateStatusMessage:msg];
            return;
        }
        
        mIsAdaptive = FALSE;
//        [mACR setOptimizationMode:GnAcrOptimizationDefault];
        [mACR setOptimizationMode:GnAcrOptimizationSpeed];
        [mACR setLookupCacheOnly:YES];
        [mACR setPreferredMaxQueryInterval:4];
        

        
#if ENABLE_MUSIC_ID
        if(!mAudioCache){
            // create audio cache
            int byteCapacity = config.sampleRate * config.format * config.numChannels * 10; // 10 seconds
            mAudioCache = [[GnCircularBuffer alloc] initWithCapacity:byteCapacity];
        }
#endif
        
        
        // Create the audio source with the same config used for the mACR object
        mSource = [[GnAudioSourceiOSMic alloc] initWithAudioConfig:config];
        // specify the delegate object which will receive the audio data callback
        mSource.audioDelegate = self;
        
        
        // Start the audio Source
        error = [mSource start];
        if (error) {
            NSString *msg = [NSString stringWithFormat:@"Source Start ERROR: %@ (0x%x)", error.localizedDescription, error.code];
            [self updateStatusMessage:msg];
            return;
        }
        
        
        [self updateStatusMessage:@"ACR Start Success"];
        // ACR setup complete
        // Results and status will come via delegate callback (acrStatusReady and acrResultReady)
        
        
        // AVAudioSessionDelegate
        [[AVAudioSession sharedInstance] setDelegate:self];
        
        
    }
    else
    {
        [self stopACR];
        [[AVAudioSession sharedInstance] setDelegate:nil];
        
    }
    
    
    // toggle the UI
    
    sender.selected = !sender.selected;
    
}


//  This sample app uses the GnAudioSourceiOSMic class to handle the microphone input. The GnAudioSourceiOSMic
//  class does not assume or take responsibility for mic input interruptions or route changes.
//  This is the responsibility of the application. To learn more about handling these types of
//  interruptions, familiarize yourself with the AVAudioSession documentation from Apple.
//  http://developer.apple.com/library/ios/#documentation/Audio/Conceptual/AudioSessionProgrammingGuide/Introduction/Introduction.html


// AVAudioSessionDelegate methods
// these 2 methods inform the app of an audio interruption such as a phone call
// the sample code here stops the audio source and resets the ACR objects as
// though the Stop button was pressed.
- (void)beginInterruption
{
    // respond to interruption (phone call, etc)
    // stop audio
    [self stopACR];
    // reset UI button
    buttonACR.selected = NO;
    [self updateStatusMessage:@"ACR Stopped due to audio interruption"];
    
}

-(void)endInterruption
{
    //    NSLog(@"endInterruption");
}



-(NSString*) currentTime{
    
    NSDateFormatter *timeFormat = [[[NSDateFormatter alloc] init] autorelease];
    [timeFormat setDateFormat:@"HH:mm:ss"];
    
    NSDate *now = [[[NSDate alloc] init]autorelease];
    NSString *theTime = [timeFormat stringFromDate:now];
    return theTime;
}


-(void)acrStatusReady:(GnAcrStatus*)status
{
    @autoreleasepool {
        // This status callback will be called periodically with status from the ACR subsystem
        // You can use these statuses as you like.
        
        // These callbacks may occur on threads other than the main thread.
        // Be careful not to block these callbacks for long periods of time.
        
        
        NSString *message = nil;
        BOOL doShowStatus = YES;
        
        switch (status.statusType) {
            case GnAcrStatusTypeSilent:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:SILENCE_KEY];
                message = [NSString stringWithFormat:@"Silence %10.2f", status.value];
                break;
            case GnAcrStatusTypeSilentRatio:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:RATIO_KEY];
                message = [NSString stringWithFormat:@"Silence ratio %10.3f", status.value];
                break;
            case GnAcrStatusTypeError:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:ERROR_KEY];
                message = [NSString stringWithFormat:@"ERROR %@ (0x%x)", [status.error localizedDescription], status.error.code];
                break;
            case GnAcrStatusTypeNoMatchMode:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:MODE_KEY];
                message = [NSString stringWithFormat:@"No Match Mode %10.0f secs between queries", status.value];
                break;
            case GnAcrStatusTypeConnecting:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:NETWORK_KEY];
                message = [NSString stringWithFormat:@"Connecting"];
                break;
            case GnAcrStatusTypeFingerprintGenerated:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:FP_KEY];
                message = [NSString stringWithFormat:@"Fingerprint Generated"];
                break;
            case GnAcrStatusTypeFingerprintStarted:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:FP_KEY];
                message = [NSString stringWithFormat:@"Fingerprint Started"];
                break;
            case GnAcrStatusTypeLocalLookupComplete:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:LOCAL_KEY];
                message = [NSString stringWithFormat:@"Local Lookup Complete"];
                break;
            case GnAcrStatusTypeMusic:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:NSM_KEY];
                message = [NSString stringWithFormat:@"Music"];
                break;
            case GnAcrStatusTypeNetworkReceiving:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:NETWORK_KEY];
                message = [NSString stringWithFormat:@"Network Receiving"];
                break;
            case GnAcrStatusTypeNetworkSending:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:NETWORK_KEY];
                message = [NSString stringWithFormat:@"Network Sending"];
                break;
            case GnAcrStatusTypeNoise:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:NSM_KEY];
                message = [NSString stringWithFormat:@"Noise"];
                break;
            case GnAcrStatusTypeSpeech:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:NSM_KEY];
                message = [NSString stringWithFormat:@"Speech"];
                break;
            case GnAcrStatusTypeNormalMatchMode:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:MODE_KEY];
                message = [NSString stringWithFormat:@"Normal Match Mode"];
                break;
            case GnAcrStatusTypeOnlineLookupComplete:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:ONLINE_KEY];
                message = [NSString stringWithFormat:@"Online Lookup Complete"];
                break;
            case GnAcrStatusTypeQueryBegin:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:ONLINE_KEY];
                message = [NSString stringWithFormat:@"Online Query Begin"];
                break;
            case GnAcrStatusTypeRecordingStarted:
                message = [NSString stringWithFormat:@"Recording Started"];
                break;
            case GnAcrStatusTypeDebug:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:DEBUG_KEY];
                message = [NSString stringWithFormat:@"Debug %@)", status.message];
                break;
            case GnAcrStatusTypeTransition:
                doShowStatus = ![[NSUserDefaults standardUserDefaults] boolForKey:TRANSITION_KEY];
                message = [NSString stringWithFormat:@"Transition"];
                break;
            default:
                break;
        }
        
        if (doShowStatus && message) {
            [self updateStatusMessage:[NSString stringWithFormat:@"(%@) ACR Status: %@", [self currentTime], message]];
        }
        
    }
}



-(void)acrResultReady:(GnResult*)result
{
    @autoreleasepool {
        // ACR query results will be returned in this callback
        // Below is an example of how to access the result metadata.
        
        // These callbacks may occur on threads other than the main thread.
        // Be careful not to block these callbacks for long periods of time.
        
        
        // Get the enumerator to access the ACR Match objects (GnAcrMatch)
        NSEnumerator *matches = result.acrMatches;
        int count = 0;
        
        // for each GnAcrMatch returned in the GnResult
        for (GnAcrMatch *match in matches) {
            count++;
            
            if (count == 1) {
                // remember the first match for use with secondary query
                [mLatestAcrMatch release];
                mLatestAcrMatch = [match retain];
            }
            
            // Get the title and subtitle from this GnAcrMatch
            NSString *acrTitle = match.title.display;
            NSString *acrSubtitle = match.subtitle.display;
            
            if (!acrSubtitle) {
                acrSubtitle = @"";
            }
            
            // Retreive the GnTvAiring from the GnAcrMatch
            GnTvAiring *airing = match.tvAiring;
            // Retreive the GnTvChannel from the GnTvAiring
            GnTvChannel *channel = airing.channel;
            
            // Get the Channel callsign for display
            NSString *channelCallsign = channel.callsign;
            
            // Get the position (ms from beginning of work/program) of the GnAcrMatch
            NSString* matchPosition = match.actualPosition;
            NSString* positionFormatted = @"";
            
            if (matchPosition != nil) {
                
                int seconds = [matchPosition intValue] / 1000;
                NSInteger remindMinute = seconds / 60;
                NSInteger remindHours = remindMinute / 60;
                NSInteger remindMinutes = seconds - (remindHours * 3600);
                NSInteger remindMinuteNew = remindMinutes / 60;
                NSInteger remindSecond = seconds - (remindMinuteNew * 60) - (remindHours * 3600);
                positionFormatted = [NSString stringWithFormat:@"%02d:%02d:%02d",remindHours,remindMinuteNew,remindSecond];
            }
            
            if(match.customData){
                NSString *customDataID = match.customData.dataID;
                NSString *resultString = [NSString stringWithFormat:@"ACR Custom Data: %@ %@ (Match #%d)", customDataID, positionFormatted, count];
                [self updateResultMessage:resultString];

                
                
                
                
            } else {
                NSString *resultString = [NSString stringWithFormat:@"ACR: %@ %@ %@ %@ (Match #%d)", acrTitle, acrSubtitle, channelCallsign, positionFormatted, count];
                [self updateResultMessage:resultString];
            }
            
            // here are more examples of how to get metadata from a result
            if (0) {
                NSLog(@"Match Title :       %@", match.title.display);
                NSLog(@"Match subtitle:     %@", match.subtitle.display);
                NSLog(@"Match actual pos:   %@", match.actualPosition);
                NSLog(@"Match adjusted pos: %@", match.adjustedPosition);
                
                GnVideoWork *work = match.avWork;
                if (work) {
                    NSLog(@"work tui:        %@", work.tui);
                    NSLog(@"work tag:        %@", work.tuiTag);
                    NSLog(@"work title:      %@", work.title.display);
                    NSLog(@"work is partial: %@", work.isPartial?@"YES":@"NO");
                }
                else
                    NSLog(@"No AV Work for this ACR match");
                
                GnTvAiring *airing = match.tvAiring;
                if (airing) {
                    NSLog(@"airing start:   %@", airing.dateStart);
                    NSLog(@"airing end:     %@", airing.dateEnd);
                    
                    
                    GnTvChannel *channel = airing.channel;
                    if (channel) {
                        NSLog(@"channel tui:      %@", channel.tui);
                        NSLog(@"channel tag:      %@", channel.tuiTag);
                        NSLog(@"channel name:     %@", channel.name);
                        NSLog(@"channel callsign: %@", channel.callsign);
                        NSLog(@"channel number:   %@", channel.number);
                    }
                    GnTvProgram *program = airing.tvProgram;
                    if (program) {
                        NSLog(@"program tui:      %@", program.tui);
                        NSLog(@"program tag:      %@", program.tuiTag);
                        NSLog(@"program title:    %@", program.title.display);
                        NSLog(@"program subtitle: %@", program.subtitle.display);
                        GnVideoWork *programWork = program.avWork;
                        if (programWork) {
                            NSLog(@"program work tui:      %@", programWork.tui);
                            NSLog(@"program work tag:      %@", programWork.tuiTag);
                            NSLog(@"program work title:    %@", programWork.title.display);
                        }
                    }
                }
            }
            
            
        }
        if (count == 0) {
            [self updateResultMessage:[NSString stringWithFormat:@"ACR: No match (%@)", [self currentTime]]];
        }
        
        
        
    }
    
}


// This is an example of how to do a secondary lookup on the
// ACR match returned from the acrResultsReady callback.
-(void)secondaryQueryBackgroundTask:(UIButton*)sender
{
    @autoreleasepool {
        NSError *error = nil;
        
        [self initManager:&error];
        
        if (error){
            [self updateResultMessage:error.localizedDescription];
            goto cleanup;
        }
        
        GnUser *acrUser = [self getUserACR];
        
        if (!acrUser) {
            goto cleanup;
        }
        
        GnAcrMatch *theMatch = [[mLatestAcrMatch retain] autorelease];
        
        
        [self updateResultMessage:@"Secondary Query started..."];
        
        GnTvProgram *theProgram = theMatch.tvAiring.tvProgram;
        GnVideoWork *theWork    = theMatch.avWork;
        
        
        if (theProgram) {
            // do secondary query to get full program details such as credits and contributors
            // create epg query object
            GnEpg *epgQuery = [[GnEpg alloc] initWithUser:acrUser error:&error];
            if (error){
                [self updateResultMessage:error.localizedDescription];
                goto cleanup;
            }
            GnResult *programResult = [epgQuery findProgramsWithProgram:theProgram error:&error];
            [epgQuery release];
            if (error){
                [self updateResultMessage:error.localizedDescription];
                goto cleanup;
            }
            
            NSEnumerator *programs = programResult.tvPrograms;
            for (GnTvProgram *program in programs) {
                NSString *displayString = [NSString stringWithFormat:@"Secondary Query: %@", program.title.display];
                [self updateResultMessage:displayString];
            }
            
        }
        else if (theWork)
        {
            // if work is no tv program, try querying for work data
            GnVideo *videoQuery = [[GnVideo alloc] initWithUser:acrUser error:&error];
            if (error){
                [self updateResultMessage:error.localizedDescription];
                goto cleanup;
            }
            GnResult *result = [videoQuery findWorksWithWork:theWork error:&error];
            [videoQuery release];
            if (error){
                [self updateResultMessage:error.localizedDescription];
                goto cleanup;
            }
            
            NSEnumerator *works = result.videoWorks;
            for (GnVideoWork *work in works) {
                NSString *displayString = [NSString stringWithFormat:@"Secondary Query: %@", work.title.display];
                [self updateResultMessage:displayString];
            }
            
        }
        
        
    }
cleanup:
    {
        [sender performSelectorOnMainThread:@selector(setBusy:) withObject:nil waitUntilDone:NO];
    }
}


-(IBAction)secondaryQueryButtonPressed:(UIButton*)sender
{
    
    if (!mLatestAcrMatch) {
        [self updateResultMessage:@"No ACR match obtained. Secondary query cancelled."];
        return;
    }
    
    // because EPG and Video queries are synchronous you should execute them in the background
    [sender setBusy:YES];
    [self performSelectorInBackground:@selector(secondaryQueryBackgroundTask:) withObject:sender];
}



-(IBAction)settingsButtonPressed
{
    mSettingsController = [[[SettingsController alloc] initWithNibName:@"SettingsController" bundle:nil] autorelease];
    mSettingsController.settingsDelegate = self;
    [self presentModalViewController:mSettingsController animated:YES];
}

-(NSUInteger)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskPortrait;
}

-(BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
    return toInterfaceOrientation==UIInterfaceOrientationPortrait;
}


// GnAudioSourceDelegate method
-(void)audioBytesReady:(void const * const)bytes length:(int)length
{
    // The GnAudioSourceiOSMic object pointed to by mSource will call this method when audio is available
    // from the input device. The application can then pass the audio into the GnAcr writeBytes to feed audio
    // to ACR, or use the audio otherwise, by copying to memory, file, etc. This audio can also be fed into
    // GnMusicID writeBytes to do a music query.
    
    // this callback is called from a background thread. It is important to not block this
    // callback for very long. It is advised to offload UI updates and expensive computations to the main thread.
    NSError *error = nil;

    error = [mACR writeBytes:bytes length:length];
    if (error) {
        NSLog(@"audioBytesReady error: %@", error);
    }
    
#if ENABLE_MUSIC_ID
    // cache audio for later music query
    [mAudioCache writeBytes:bytes length:length];
#endif
    
}


// MusicID methods

-(IBAction)doMusicID
{
#if ENABLE_MUSIC_ID
    NSError *error = nil;
    [self initManager:&error];
    if (error){
        // [self updateResultMessage:error.localizedDescription];
        [self updateStatusMessage:[NSString stringWithFormat:@"Initialization failure"]];
        return;
    }

    // music ID queries are syncronous, so don't do them on the main thread.
    [self performSelectorInBackground:@selector(musicIDBackgroundTask) withObject:nil];
#else
    [self updateResultMessage:@"MusicID not enabled"];
#endif
}

#if ENABLE_MUSIC_ID

-(void)musicIDBackgroundTask
{
    @autoreleasepool {
        NSError *error = nil;

        GnUser *musicUser = [self getUserMusic];
        
        if (!musicUser) {
            [self updateStatusMessage:[NSString stringWithFormat:@"Invalid User"]];
            return;
        }

        if(!mMusicQuery){
            mMusicQuery = [[GnMusicID alloc] initWithUser:musicUser error:&error];
        }
        // make sure these params are the same as you set up in the audio input
        [mMusicQuery fingerprintBegin:GnMusicIdFingerprintTypeGNFPX
                          sampleRate:44100 // only 8000, and 44100 are supported
                     sampleSizeBytes:2
                    numberOfChannels:1
                               error:&error];
        
        if (error) {
            NSString *msg = [NSString stringWithFormat:@"Audio init ERROR: %@ (0x%x)", error.localizedDescription, error.code];
            [self updateStatusMessage:msg];
            return;
        }
        
        BOOL fingerprintComplete = NO;
        int buffSize = 44100*2*1*1;     // 1 second of audio
        char *tempBuffer = (char*)malloc(buffSize);
        int bytesRead = 0;
        int totalBytesRead = 0;
        
        // feed fingerprinter until it is satisfied, or we exhaust our cache
        do {
            bytesRead = [mAudioCache readBytes:tempBuffer length:buffSize];
            totalBytesRead += bytesRead;
            fingerprintComplete = [mMusicQuery fingerprintWrite:tempBuffer
                                                      dataSize:bytesRead
                                                         error:&error];
        }while (!fingerprintComplete && bytesRead!=0);
        
        //    float time = (float)totalBytesRead /44100/2/1;
        //    NSLog(@"total read %3.1f sec (%d bytes)", time, totalBytesRead);
        
        if (!fingerprintComplete) {
            // aborted due to exhausted cache
            [self updateStatusMessage:@"MusicID: fingerprinter underflow"];
        }
        else
        {
            // fingerprinter happy
            [mMusicQuery fingerprintEnd:&error];
            GnResult *trackResult = [mMusicQuery findTracks:&error];
            if (error) {
                NSString *msg = [NSString stringWithFormat:@"MusicID: %@ (0x%x)", error.localizedDescription, error.code];
                [self updateStatusMessage:msg];
            }
            else
            {
                NSEnumerator *tracks = trackResult.tracks;
                int count = 0;
                for (GnTrack *track in tracks) {
                    count++;
                    NSString *trackTitle = track.titleOfficial.display;
                    NSString *trackArtist = track.artist.name.display;
                    NSEnumerator *trackAlbums = track.albums;
                    GnAlbum *firstAlbum = trackAlbums.nextObject;
                    NSString *trackAlbum = firstAlbum.titleOfficial.display;
                    
                    NSString *msg = [NSString stringWithFormat:@"MusicID: Aritst: %@   \n\tAlbum: %@  \n\tTrack:  %@",
                                     trackArtist, trackAlbum, trackTitle];
                    [self updateResultMessage:msg];
                    
                }
                if (count == 0) {
                    [self updateResultMessage:@"MusicID: No match"];
                    
                }
            }
        }
        
        free(tempBuffer);
        
    }
}
#endif




-(IBAction)loadFPBundle
{
    NSError *error = nil;
    [self initManager:&error];
    if (error){
        // [self updateResultMessage:error.localizedDescription];
        [self updateStatusMessage:[NSString stringWithFormat:@"Initialization failure"]];
        return;
    }
    
    
    // This app looks in the Documents folder for a subfolder called "bundles" containing
    // files to ingest. Then it loads each bundle in turn. Your app may load bundles
    // as you see fit.
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,
                                                         NSUserDomainMask,
                                                         YES);
    NSString *docDirectryPath = [paths objectAtIndex:0];
    
    NSArray *directoryContent =
    [[NSFileManager defaultManager] contentsOfDirectoryAtPath:docDirectryPath error:&error];
    
    for (NSString *item in directoryContent)
    {
        
        
        
        NSLog(@"cache:%@", item);
        
        
        
        
        NSString *extension = [item pathExtension];
        // if ([extension isEqualToString:@"bi"] ) {
            // initiate the ingestion of each file in turn.
            NSString *fullPath = [docDirectryPath stringByAppendingPathComponent:item];
            bundleFileHandle = [NSFileHandle fileHandleForReadingAtPath:fullPath];
            // the callback readBundleData:capacity:numBytesRead: will be called to
            // load the data before ingest: will return.
            [GnFPCache ingest:self error:&error];
            NSString *status = nil;
            if (error) {
                status =
                [NSString stringWithFormat:@"Bundle ingestion error for %@: %@ (%x)", item, error.localizedDescription, error.code ];
            }
            else
            {
                status = [NSString stringWithFormat:@"Bundle ingestion success: %@", item];
            }
            [self updateStatusMessage:status];
        // }
    }
}

-(BOOL)readBundleData:(void*)data
             capacity:(size_t)capacity
         numBytesRead:(size_t*)numBytesRead
{
    // Load the requested number of bytes into the given data buffer.
    // This callback will be called repeatedly until the ingestion is complete.
    
    NSData *fileData = [bundleFileHandle readDataOfLength:capacity];
    [fileData getBytes:data length:fileData.length];
    // report actual bytes read
    *numBytesRead = fileData.length;
    
    // the return value indicates whether an error occured and 
    // that the ingestion should be aborted
    return NO;
}

-(void) currentlySelectedSettings
{
    switch ([[NSUserDefaults standardUserDefaults] integerForKey:@"Optimization"]) {
        case 0:
            [mACR setOptimizationMode:GnAcrOptimizationDefault];
            break;
        case 1:
            [mACR setOptimizationMode:GnAcrOptimizationSpeed];
            break;
        case 2:
            [mACR setOptimizationMode:GnAcrOptimizationAccuracy];
            break;
        case 3:
            [mACR setOptimizationMode:GnAcrOptimizationAdaptive];
            break;
        default:
            break;
    }
}

@end
