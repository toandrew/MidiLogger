//
//  DALogManager.m
//  MidiLogger
//
//  Created by zengqingfu on 2019/1/14.
//  Copyright © 2019 dev. All rights reserved.
//

#import "DALogManager.h"
#import "DAFileLogger.h"

@interface DALogManager()
@property (nonatomic, strong) DALogFileManagerDefault *logFileManager;
@property (nonatomic, strong) DAFileLogger *fileLogger;
@property (nonatomic, strong) NSDateFormatter *dateFormatter;


@end

@implementation DALogManager
+ (instancetype)manager {
    static DALogManager *_sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _sharedInstance = [[self alloc] init];
    });
    return _sharedInstance;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        NSString *documentPath = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject;
        NSString *logPath = [documentPath stringByAppendingPathComponent:@"log_path"];
#if DEBUG
        NSLog(@"日志目录在：%@", logPath);
#endif
        _dateFormatter = [[NSDateFormatter alloc] init];
        [_dateFormatter setFormatterBehavior:NSDateFormatterBehavior10_4]; // 10.4+ style
        [_dateFormatter setDateFormat:@"yyyy/MM/dd HH:mm:ss:SSS"];

        _logFileManager = [[DALogFileManagerDefault alloc] initWithLogsDirectory:logPath];
//        _fileLogger = [[DAFileLogger alloc] initWithLogFileManager:_logFileManager];
    }
    return self;
}

- (void)start {
    _loging = YES;
    [_logFileManager createNewLogFile];

    if (_fileLogger) {
        [_fileLogger flush];
    }
    _fileLogger = [[DAFileLogger alloc] initWithLogFileManager:_logFileManager];
}

- (void)writeLog:(NSString *)tag
             andLog:(NSString *)log {

    if (!_loging) {
        return;
    }

    if (log.length == 0 || tag.length == 0) {
        return;
    }
    NSString *nLog = log;
    NSString *timePre = [_dateFormatter stringFromDate:[NSDate date]];
    if ([nLog hasSuffix:@"\n"]) {
        nLog = [NSString stringWithFormat:@"[%@][%@] %@", timePre, tag, log];
    } else {
        nLog = [NSString stringWithFormat:@"[%@][%@] %@\n", timePre, tag, log];
    }
    NSLog(@"%@", nLog);
    NSData *dat = [nLog dataUsingEncoding:NSUTF8StringEncoding];
    [_fileLogger logData:dat];
}

- (void)stop {
    _loging = NO;
    if (_fileLogger) {
        [_fileLogger flush];
    }
    _fileLogger = nil;
}

- (NSString *)logFilePath {
    [_fileLogger flush];
    NSString *path = _logFileManager.sortedLogFilePaths.firstObject;
    return path;
}
@end
