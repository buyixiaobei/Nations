//
//  Define.h
//  Nations
//
//  Created by LB on 16/7/11.
//  Copyright © 2016年 LB. All rights reserved.
//

#ifndef Define_h
#define Define_h

#define ApplicationDelegate (AppDelegate *)[[UIApplication sharedApplication] delegate]
#define PI 3.14159265358979323846264338327950288
#define LOCAL(msg,...) [CommonView localizedTextWithName:msg]
#define KeyWindow             [UIApplication sharedApplication].keyWindow

#define NTES_USE_CLEAR_BAR - (BOOL)useClearBar{return YES;}
#define NTES_FORBID_INTERACTIVE_POP - (BOOL)forbidInteractivePop{return YES;}

#define UIColorFromRGBA(rgbValue, alphaValue) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0x00FF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0x0000FF))/255.0 \
alpha:alphaValue]

#define UIColorFromRGB(rgbValue) UIColorFromRGBA(rgbValue, 1.0)

//回到主线程(同步)
#define dispatch_sync_main_safe(block)\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_sync(dispatch_get_main_queue(), block);\
}

//回到主线程(异步)
#define dispatch_async_main_safe(block)\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_async(dispatch_get_main_queue(), block);\
}

//static inline void method_execute_frequency(id obj ,SEL selecter, NSTimeInterval timeInterval){
//    static dispatch_once_t onceToken;
//    dispatch_once(&onceToken, ^{
//        [obj performSelector:selecter withObject:nil afterDelay:0];
//        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(timeInterval * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//            onceToken = 0;
//        });
//    });
//}

// Device & OS
#define IS_IOS8 [[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0
#define IS_IOS9 [[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0
#define IS_IOS7 [[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0
#define IS_DOWN_IOS7 [[[UIDevice currentDevice] systemVersion] floatValue] < 7.0
#define IS_IPHONE4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO )
#define IS_IPHONE5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define IS_IPHONE6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO )
#define IS_IPHONE6P ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO )
#define IS_IPHONE ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)

// DEBUG
//#ifdef DEBUG
//#define NSLog(...) NSLog(__VA_ARGS__)
//#define debugMethod() NSLog(@"%s", __func__)
//#else
//#define NSLog(...)
//#define debugMethod()
//#endif
//
//#ifdef DEBUG
//
//#define DEBUGLINE [NSString stringWithFormat:@"m:%d",__LINE__]
//#define DEBUGS [NSString stringWithFormat:@"%sm:%d ",__PRETTY_FUNCTION__,__LINE__]
//#define DEBUGLog NSLog(@"%@",DEBUGS);
//#define DEBUGMSG(msg,...) NSLog(@"%@\n%@",[NSString stringWithFormat:msg, ## __VA_ARGS__],DEBUGS);
//#define DEBUGERR(msg,...) NSLog(@"<Error> %@%@",DEBUGS,[NSString stringWithFormat:msg, ## __VA_ARGS__]);
//#define DEBUGdealloc NSLog(@" >*** %@ %p",DEBUGS,self);
//#define DEBUG_START_TIMER NSTimeInterval debug_start = [NSDate timeIntervalSinceReferenceDate]; DEBUGLog(@"START_TIMER");
//#define DEBUG_END_TIMER(msg,...)  NSTimeInterval debug_stop = [NSDate timeIntervalSinceReferenceDate]; NSLog(@"END_TIMER %f: %@",debug_stop-debug_start,[NSString stringWithFormat:msg, ## __VA_ARGS__]);
//
//#else
//
//#define DEBUGLINE @""
//#define DEBUGS @""
//#define DEBUGLog
//#define DEBUGMSG(msg,...)
//#define DEBUGERR(msg,...)
//#define DEBUGdealloc
//#define DEBUG_START_TIMER
//#define DEBUG_END_TIMER(msg,...)
//
//#endif

// 日志输出
#import <CocoaLumberjack/CocoaLumberjack.h>

#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)

#ifdef DEBUG
static DDLogLevel ddLogLevel = DDLogLevelVerbose;
#else
static DDLogLevel ddLogLevel = DDLogLevelInfo;
#endif


// Views
#define WIDTH(view) view.frame.size.width
#define HEIGHT(view) view.frame.size.height
#define LEFT(view) view.frame.origin.x
#define TOP(view) view.frame.origin.y
#define BOTTOM(view) (view.frame.origin.y + view.frame.size.height)
#define RIGHT(view) (view.frame.origin.x + view.frame.size.width)

#define MainScreenBounds [UIScreen mainScreen].bounds
#define MainScreenWidth [UIScreen mainScreen].bounds.size.width
#define MainScreenHeight [UIScreen mainScreen].bounds.size.height
#define NavigationBarHeight 64
#define MainSreenWidthScale   MainScreenWidth / 320

// Random
#define RANDOM_MINUS_1_TO_1() ((random() / (GLfloat)0x3fffffff )-1.0)
#define RANDOM_0_TO_1() ((random() / (GLfloat)0x7fffffff ))

// Networking
#define IsConnected() !([[Reachability reachabilityForInternetConnection] currentReachabilityStatus] == NotReachable)
#define ShowNetworkActivityIndicator() [UIApplication sharedApplication].networkActivityIndicatorVisible = YES
#define HideNetworkActivityIndicator() [UIApplication sharedApplication].networkActivityIndicatorVisible = NO

// Misc
#define UserDefaultsOFK(key) [[NSUserDefaults standardUserDefaults] objectForKey:key]
#define UserDefaultsSFK(object,key) [[NSUserDefaults standardUserDefaults] setObject:object forKey:key]
#define UserDefaultsSynchronize [[NSUserDefaults standardUserDefaults] synchronize]
#define UserDefaultsRemove(key) [[NSUserDefaults standardUserDefaults] removeObjectForKey:key]

#define DEGREES_TO_RADIANS(angle) ((angle) / 180.0 * M_PI)
#define URLIFY(urlString) [NSURL URLWithString:urlString]
#define S(string, args...) [NSString stringWithFormat:string, args]
#define ALERT(title, msg, cancelButton, cancelButton1) [[[UIAlertView alloc] initWithTitle:title message:msg delegate:nil cancelButtonTitle:cancelButton otherButtonTitles:cancelButton1,nil] show]

#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define RGBColor(r,g,b,a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define RGBColor(r,g,b,a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]

#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;

/************************ 颜色值 ****************************/

//主颜色
#define MainColor               @"#8B60AF"//@"#63caff" // 蓝色 (主颜色)
#define MainGreenColor          @"#ABC337"//@"#b8e986" // 绿色

//背景颜色
#define BgColor_F0F0F0          @"#f0f0f0" // 灰色
#define BgColor_FFFFFF          @"#ffffff" // 白色
#define BgColor_00000           @"#000000" // 黑色

//字体颜色
#define TextColor_Big           @"#241047" // 大号字体颜色
#define TextColor_MidSmall      @"#8a8a8a" // 中号和小号字体颜色
#define TextColor_InputDef      @"#CCCCCC" // 输入框提示字体颜色，不可编辑颜色，border颜色
#define TextColor_ImageText     @"#D6E03E" // 图片上字体的颜色
//其他颜色
#define Color_Border            @"#d4d4d4" // 边框颜色
#define Color_Line              @"#eaeaea" // 线颜色
#define Color_FFFDE8            @"#fffde8" // 便条纸 淡黄色
#define Color_BBBBBB            @"#bbbbbb"
#define Color_Ora_F5A623        @"#F5A623" // 课程点的颜色（橙色）
#define Color_Black_211147      @"#211147"
#define Color_bgGray_EFF3F4     @"#EFF3F4"
#define Color_RedColor          @"#FF0000" //红色

#define COLOR_6F53A0            @"#6F53A0" //已确认
#define COLOR_230F48            @"#230F48"

/************************ 字体 *********************************/

#define TextFont_Eighteen           [UIFont systemFontOfSize:18]            // 标题文字，大按钮字体
#define TextFont_Big_Seventeen      [UIFont systemFontOfSize:17]            // 列表一级字体，导航按钮
#define TextFont_Mid_Sixteen        [UIFont systemFontOfSize:16]            // 列表详情，中按钮
#define TextFont_Con_Fourteen       [UIFont systemFontOfSize:14]            // 内容简要，详情
#define TextFont_Sub_Thirteen       [UIFont systemFontOfSize:13]            // 列表二级字体,内容标记
#define TextFont_Oth_Twelve         [UIFont systemFontOfSize:12]            // 其他字体
#define TextFont_Oth_Eleven         [UIFont systemFontOfSize:11]
#define TextFont_Oth_Ten            [UIFont systemFontOfSize:10]

/*******other**********/

/** 屏幕比例 */
#define ScreenScaleWidth(width) ((width) * MainScreenWidth / 320)
#define ScreenScaleHeight(height) ((height) * MainScreenHeight / 568)

//主URL
#define MAINURL               @"MainURL"


//用户token
#define MyToken               @"MyToken_XHManager"
//用户mobileUserId
#define MyMobileUserId        @"mobileUserId_XHManager"
//用户userId
#define MyUserId              @"userId_XHManager"


#endif /* Define_h */
