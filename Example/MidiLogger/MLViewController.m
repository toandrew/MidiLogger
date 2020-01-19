//
//  MLViewController.m
//  MidiLogger
//
//  Created by toandrew on 01/13/2020.
//  Copyright (c) 2020 toandrew. All rights reserved.
//

#import "MLViewController.h"

#import <MidiLoggerBridge.h>

@interface MLViewController ()

@end

@implementation MLViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)logMessage:(NSString *)message {
    if (isLoging()) {
        writeNLog(@"AudioRt", message);
    } else {
        NSLog(@"[AudioRt]%@", message);
    }
}

@end
