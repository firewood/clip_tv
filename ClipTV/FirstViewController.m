//
//  FirstViewController.m
//  ClipTV
//
//  Created by Kenichi Aramaki on 2014/03/08.
//  Copyright (c) 2014年 SeeM. All rights reserved.
//

#import "FirstViewController.h"

@interface FirstViewController ()

@end

@implementation FirstViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.

    
    // generate web view
    webView_ = [[UIWebView alloc] init];
    webView_.frame = self.view.bounds;
    webView_.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    webView_.scalesPageToFit = YES;
    webView_.delegate = self;
    [self.view addSubview:webView_];
    NSURLRequest* request = [NSURLRequest requestWithURL:[NSURL URLWithString:@"http://54.249.175.51/"]];
    [webView_ loadRequest:request];
    
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
