// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2018, Deusty, LLC
// All rights reserved.
//
// Redistribution and use of this software in source and binary forms,
// with or without modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// * Neither the name of Deusty nor the names of its contributors may be used
//   to endorse or promote products derived from this software without specific
//   prior written permission of Deusty, LLC.

/**
 * Legacy macros used for 1.9.x backwards compatibility.
 *
 * Imported by default when importing a DALog.h directly and DA_LEGACY_MACROS is not defined and set to 0.
 **/
#if DA_LEGACY_MACROS

#warning CocoaLumberjack 1.9.x legacy macros enabled. \
Disable legacy macros by importing CocoaLumberjack.h or DALogMacros.h instead of DALog.h or add `#define DA_LEGACY_MACROS 0` before importing DALog.h.

#ifndef LOGV_LEVEL_DEF
    #define LOGV_LEVEL_DEF ddLogLevel
#endif

#define LOGV_FLAG_ERROR    DALogFlagError
#define LOGV_FLAG_WARN     DALogFlagWarning
#define LOGV_FLAG_INFO     DALogFlagInfo
#define LOGV_FLAG_DEBUG    DALogFlagDebug
#define LOGV_FLAG_VERBOSE  DALogFlagVerbose

#define LOGV_LEVEL_OFF     DALogLevelOff
#define LOGV_LEVEL_ERROR   DALogLevelError
#define LOGV_LEVEL_WARN    DALogLevelWarning
#define LOGV_LEVEL_INFO    DALogLevelInfo
#define LOGV_LEVEL_DEBUG   DALogLevelDebug
#define LOGV_LEVEL_VERBOSE DALogLevelVerbose
#define LOGV_LEVEL_ALL     DALogLevelAll

#define LOGV_ASYNC_ENABLED YES

#define LOGV_ASYNC_ERROR    ( NO && LOGV_ASYNC_ENABLED)
#define LOGV_ASYNC_WARN     (YES && LOGV_ASYNC_ENABLED)
#define LOGV_ASYNC_INFO     (YES && LOGV_ASYNC_ENABLED)
#define LOGV_ASYNC_DEBUG    (YES && LOGV_ASYNC_ENABLED)
#define LOGV_ASYNC_VERBOSE  (YES && LOGV_ASYNC_ENABLED)

#define LOGV_MACRO(isAsynchronous, lvl, flg, ctx, atag, fnct, frmt, ...) \
        [DALog log : isAsynchronous                                     \
             level : lvl                                                \
              flag : flg                                                \
           context : ctx                                                \
              file : __FILE__                                           \
          function : fnct                                               \
              line : __LINE__                                           \
               tag : atag                                               \
            format : (frmt), ## __VA_ARGS__]

#define LOGV_MAYBE(async, lvl, flg, ctx, fnct, frmt, ...)                       \
        do { if(lvl & flg) LOGV_MACRO(async, lvl, flg, ctx, nil, fnct, frmt, ##__VA_ARGS__); } while(0)

#define LOGV_OBJC_MAYBE(async, lvl, flg, ctx, frmt, ...) \
        LOGV_MAYBE(async, lvl, flg, ctx, __PRETTY_FUNCTION__, frmt, ## __VA_ARGS__)

#define DALogError(frmt, ...)   LOGV_OBJC_MAYBE(LOGV_ASYNC_ERROR,   LOGV_LEVEL_DEF, LOGV_FLAG_ERROR,   0, frmt, ##__VA_ARGS__)
#define DALogWarn(frmt, ...)    LOGV_OBJC_MAYBE(LOGV_ASYNC_WARN,    LOGV_LEVEL_DEF, LOGV_FLAG_WARN,    0, frmt, ##__VA_ARGS__)
#define DALogInfo(frmt, ...)    LOGV_OBJC_MAYBE(LOGV_ASYNC_INFO,    LOGV_LEVEL_DEF, LOGV_FLAG_INFO,    0, frmt, ##__VA_ARGS__)
#define DALogDebug(frmt, ...)   LOGV_OBJC_MAYBE(LOGV_ASYNC_DEBUG,   LOGV_LEVEL_DEF, LOGV_FLAG_DEBUG,   0, frmt, ##__VA_ARGS__)
#define DALogVerbose(frmt, ...) LOGV_OBJC_MAYBE(LOGV_ASYNC_VERBOSE, LOGV_LEVEL_DEF, LOGV_FLAG_VERBOSE, 0, frmt, ##__VA_ARGS__)

#endif
