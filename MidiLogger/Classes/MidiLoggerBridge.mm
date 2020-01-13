//
//  MidiLoggerBridge.m
//  MidiLoggerKit
//
//  Created by zengqingfu on 2019/1/15.
//  Copyright © 2019 dev. All rights reserved.
//
#import "DALogManager.h"

bool isLoging() {
    BOOL v = [DALogManager manager].isLoging;
    return v;
}

void startLog() {
    [[DALogManager manager] start];
}

void writeLog(const char *tag, const char *log) {
    if (strlen(log) == 0 || strlen(tag) == 0) {
        return;
    }

    NSString *pTag = [NSString stringWithUTF8String:tag];
    NSString *str = [NSString stringWithUTF8String:log];
    [[DALogManager manager] writeLog:pTag andLog:str];
}

void writeNLog(NSString *tag, NSString *log) {
    [[DALogManager manager] writeLog:tag andLog:log];
}

void stopLog() {
    [[DALogManager manager] stop];
}

NSString *logPath() {
    return [[DALogManager manager] logFilePath];
}
