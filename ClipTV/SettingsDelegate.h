//
//  SettingsDelegate.h
//  GN_ACR_SDK
//
//  Created by Sekhar Venkata on 9/5/13.
//
//

#import <Foundation/Foundation.h>

@protocol SettingsDelegate <NSObject>

@required
-(void) currentlySelectedSettings;
@end
