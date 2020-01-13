#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "DAFileLogger.h"
#import "DALegacyMacros.h"
#import "DALog.h"
#import "DALoggerNames.h"
#import "DALogManager.h"
#import "MidiLogger.h"
#import "MidiLoggerBridge.h"

FOUNDATION_EXPORT double MidiLoggerVersionNumber;
FOUNDATION_EXPORT const unsigned char MidiLoggerVersionString[];

