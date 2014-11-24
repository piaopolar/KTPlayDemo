// KTPlay.h
//
// Copyright (c) 2014 KTplay  All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class KTUser;

@interface KTRewardItem : NSObject

/// 奖励名称
@property (nonatomic,copy) NSString * name;

/// 奖励ID
@property (nonatomic,copy) NSString * typeId;

/// 奖励值
@property (nonatomic) long long value;
@end

/// KTPlay分发奖励回调
typedef  void (^KTDidDispatchRewardsBlock)(NSArray * rewards);

/// KTPlay窗口打开时的回调
typedef  void (^KTViewDidAppearBlock)();

/// KTPlay窗口关闭时的回调
typedef  void (^KTViewDidDisappearBlock)();

/// KTPlay新状态回调
typedef  void (^KTActivityStatusChangedBlock)(BOOL hasNewActivity);

/// KTPlay 可用状态回调
typedef  void (^KTAvailabilityChangedBlock)(BOOL isEnabled);


/// KTPlay主类
@interface KTPlay : NSObject


/// @name 初始化
/** 初始化KTPlay SDK
 *  startWithAppKey方法必须在游戏AppDelgate的didFinishLaunchingWithOptions方法中调用
 *  @param appKey KTPlay App Key，在KTPlay开发者网站新建应用后获取
 *  @param appSecret KTPlay App Secret，在KTPlay开发者网站新建应用后获取
 **/

+(void)startWithAppKey:(NSString *)appKey appSecret:(NSString *)appSecret;

/// @name 设置用于显示KTPlay窗口的父容器
/**
 *  默认情况下,KTPlay会使用[[[[UIApplication sharedApplication] keyWindow] rootViewController] view]作为父容器，
 *  @param parentView KTPlay视图展示容器
 */

+(void)setKTParentView:(UIView *)parentView;

/// @name 打开/关闭KTPlay窗口
/** 显示KTPlay窗口
 *
 */
+(void)show;

/** 关闭KTPlay窗口
 *  通常情况下不需要调用此方法，KTPlay窗口由玩家主动关闭
 */
+(void)dismiss;

/// @name 分享图片/文本到KTPlay平台
/**
 *  @param imagePath 图片的绝对路径,为nil时，不分享图片
 *  @param description 图片的描述,为nil时，没有默认内容描述
 */
+(void)shareImageToKT:(NSString *)imagePath description:(NSString *)description;

/** 截取游戏当前画面并分享到KTPlay平台
 *  @param description 图片的描述
 */
+(void)shareScreenshotToKT:(NSString *)description;

/// @name KTPlay回调
/** 设置发放奖励回调
 * @param block 发放奖励回调
 */
+(void)setDidDispatchRewardsBlock:(KTDidDispatchRewardsBlock)block;

/** 设置KTPlay窗口显示时的回调
 *  @param block KTPlay窗口显示时的回调
 */
+(void)setViewDidAppearBlock:(KTViewDidAppearBlock)block;

/** 设置KTPlay窗口关闭时的回调
 *  @param block KTPlay窗口关闭时的回调
 */
+(void)setViewDidDisappearBlock:(KTViewDidDisappearBlock)block;


/** 设置KTPlay收到新动态时的回调
 *
 *  @param block KTPlay新消息回调
 */
+(void)setActivityStatusChangedBlock:(KTActivityStatusChangedBlock)block;

/** 设置KTPlay 可用状态变更回调
 *
 *  @param block KT可用状态变更回调
 */
+(void)setAvailabilityChangedBlock:(KTAvailabilityChangedBlock)block;


/// @name 其他辅助方法
/** 判断KTPlay是否可用
 *
 * KTPlay不可用的情况包括：<br/>
 * 1、设备不被支持<br/>
 * 2、在Portal上关闭 <br/>
 * @return KTPlay是否可用
 */
+(BOOL)isEnabled;

/**
 * @return KTPlay窗口是否正在显示
 */

+(BOOL)isShowing;

/**
 * 设置截图旋转角度
 * 一般情况下不需要此方法，在截图角度不正常时（可能由游戏引擎或会游戏开发方式导致），再调用此方法进行调整
 * @param degrees 截图旋转角度（注意，是角度而不是弧度，取值如90,180等）
 */
+(void)setScreenshotRotation:(float)degrees;

/**
 * 处理SNS客户端返回的信息
 * 为确保SNS（微信，QQ，新浪微博等）功能正确使用，需要在游戏AppDelegate的application: openURL: sourceApplication: annotation:n方法中调用此方法
 * @param url AppDelegate的openURL方法中传入的url，直接使用。
 */
+(void)handleOpenURL:(NSURL *)url;

/** 开启或关闭通知功能
 *
 *  @param enabled 为Yes时，开启通知，为No时关闭通知功能
 */
+(void)setNotificationEnabled:(BOOL)enabled;


/**
 *  @deprecated 使用show方法替代。
 */
+(void)showInView:(UIView *)parentView  __deprecated;



@end





