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
#import "GnUserOption.h"

/** @addtogroup manager Manager 
 *  SDK Manager APIs
 *  @{
 */


typedef enum  
{
    GnUserRegistrationType_NewUser
    
}GnUserRegistrationType;

@interface GnUser :  GnObject


-(id)initWithClientId:(NSString*)clientId 
          clientIdTag:(NSString*)clientIdTag 
           appVersion:(NSString*)appVer 
     registrationType:(GnUserRegistrationType)type
                error:(NSError**)error;



//-(id)initWithLegacySerializedUser:(NSString*)legacySerializedUser
//                         clientId:(NSString*)clientId 
//                      clientIdTag:(NSString*)clientIdTag 
//                       appVersion:(NSString*)appVer
//                            error:(NSError**)error;



-(id)initWithSerializedUser:(NSString*)serializedUser error:(NSError**)error;




@property (nonatomic, readonly) NSString*       serializedUser;
@property (nonatomic, readonly) GnUserOption*   option;


@end
/** @} */ // End of Manager
