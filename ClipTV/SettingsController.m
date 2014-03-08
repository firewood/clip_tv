/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

#import "SettingsController.h"
#import "SettingsDelegate.h"

#define TRANSITION_TAG  11

#define SILENCE_TAG     1
#define NSM_TAG         2
#define RATIO_TAG       3

#define LOCAL_TAG       4
#define ONLINE_TAG      5

#define NETWORK_TAG     6
#define DEBUG_TAG       7

#define ERROR_TAG       8
#define FP_TAG          9
#define MODE_TAG        10

@implementation SettingsController
@synthesize settingsDelegate;

- (void) dealloc
{
    self.displaySettings = nil;
    self.optimizationModes = nil;
    [super dealloc];
    
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
     
    self.displaySettings = [NSArray arrayWithObjects:TRANSITION_KEY, SILENCE_KEY, NSM_KEY, RATIO_KEY, LOCAL_KEY, ONLINE_KEY, NETWORK_KEY, DEBUG_KEY, ERROR_KEY, FP_KEY, MODE_KEY,  nil];
    
    self.optimizationModes = [NSArray arrayWithObjects:@"Default",@"Speed",@"Accuracy",@"Adaptive",  nil];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}


-(IBAction)settingsSwitch:(UISwitch*)sender
{
    switch (sender.tag) {
        case TRANSITION_TAG:
            [[NSUserDefaults standardUserDefaults] setBool:!sender.isOn 
                                                    forKey:TRANSITION_KEY];
            break;
            
        case SILENCE_TAG:
            [[NSUserDefaults standardUserDefaults] setBool:!sender.isOn 
                                                    forKey:SILENCE_KEY];
            break;
            
        case NSM_TAG:
            [[NSUserDefaults standardUserDefaults] setBool:!sender.isOn 
                                                    forKey:NSM_KEY];
            break;
            
        case RATIO_TAG:
            [[NSUserDefaults standardUserDefaults] setBool:!sender.isOn 
                                                    forKey:RATIO_KEY];
            break;
            
        case LOCAL_TAG:
            [[NSUserDefaults standardUserDefaults] setBool:!sender.isOn 
                                                    forKey:LOCAL_KEY];
            break;
            
        case ONLINE_TAG:
            [[NSUserDefaults standardUserDefaults] setBool:!sender.isOn 
                                                    forKey:ONLINE_KEY];
            break;
            
        case NETWORK_TAG:
            [[NSUserDefaults standardUserDefaults] setBool:!sender.isOn 
                                                    forKey:NETWORK_KEY];
            break;
            
        case DEBUG_TAG:
            [[NSUserDefaults standardUserDefaults] setBool:!sender.isOn 
                                                    forKey:DEBUG_KEY];
            break;
            
        case ERROR_TAG:
            [[NSUserDefaults standardUserDefaults] setBool:!sender.isOn 
                                                    forKey:ERROR_KEY];
            break;
            
        case FP_TAG:
            [[NSUserDefaults standardUserDefaults] setBool:!sender.isOn 
                                                    forKey:FP_KEY];
            break;
            
        case MODE_TAG:
            [[NSUserDefaults standardUserDefaults] setBool:!sender.isOn 
                                                    forKey:MODE_KEY];
            break;
            
            
        default:
            break;
    }
    [[NSUserDefaults standardUserDefaults] synchronize];
}



-(IBAction)dismissMe:(id)sender
{
    if(self.settingsDelegate && [self.settingsDelegate conformsToProtocol:@protocol(SettingsDelegate)])
    {
        [self.settingsDelegate currentlySelectedSettings];
    }
    [self dismissModalViewControllerAnimated:YES];
}

-(NSInteger) tableView:(UITableView*) tableView numberOfRowsInSection:(NSInteger)section
{
    switch(section)
    {
    case 0:
        return self.displaySettings.count;
    case 1:
        return self.optimizationModes.count;
    }
    return 0;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 2;
}


-(UITableViewCell*) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString*cellIdentifier = @"TABLEVIEWCELL";
    
    UITableViewCell *cell = nil;
    
    if(!cell)
    {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIdentifier] autorelease];
    }
    
    switch(indexPath.section)
    {
    case 0:
        cell.textLabel.text = [self.displaySettings objectAtIndex:indexPath.row];
        if(![[NSUserDefaults standardUserDefaults] boolForKey:cell.textLabel.text])
        {
            [cell setAccessoryType:UITableViewCellAccessoryCheckmark];
        }
        break;
    case 1:
        cell.textLabel.text = [self.optimizationModes objectAtIndex:indexPath.row];
        if([[NSUserDefaults standardUserDefaults] integerForKey:@"Optimization"] == indexPath.row)
        {
            [cell setAccessoryType:UITableViewCellAccessoryCheckmark];
        }
        else
        {
            [cell setAccessoryType:UITableViewCellAccessoryNone];
        }
    
        break;
    }
    /*
    switch (self.selectedIndexPath.section)
    {
        case 0:
            if(self.selectedIndexPath.row==indexPath.row)
            {
                if(cell.accessoryType == UITableViewCellAccessoryCheckmark)
                    [cell setAccessoryType:UITableViewCellAccessoryNone];
                else
                    [cell setAccessoryType:UITableViewCellAccessoryCheckmark];
            }
            break;
            
        case 1:
            if(self.selectedIndexPath.row==indexPath.row && self.selectedIndexPath.section==1)
            {
                [cell setAccessoryType:UITableViewCellAccessoryCheckmark];
            }
            else
            {
                [cell setAccessoryType:UITableViewCellAccessoryNone];
            }

            break;
        default:
            break;
    }*/
   
    return cell;
}

-(void) tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    // self.selectedIndexPath = indexPath;
    
    switch (indexPath.section) {
        case 0:
            if([[NSUserDefaults standardUserDefaults] boolForKey:[self.displaySettings objectAtIndex:indexPath.row]])
            {
                [[NSUserDefaults standardUserDefaults] setBool:NO forKey:[self.displaySettings objectAtIndex:indexPath.row]];
            }
            else
            {
                [[NSUserDefaults standardUserDefaults] setBool:YES forKey:[self.displaySettings objectAtIndex:indexPath.row]];
            }
            break;
        case 1:
            [[NSUserDefaults standardUserDefaults] setInteger:indexPath.row forKey:@"Optimization"];
            break;
        default:
            break;
    }
    [tableView reloadData];
}

@end
