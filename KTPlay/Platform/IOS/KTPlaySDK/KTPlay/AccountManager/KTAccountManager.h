// KTAccountManager.h
//
// Copyright (c) 2014 KTplay  All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class KTUser;

typedef  void (^KTLoginStatusChangedBlock)(BOOL isLoggedIn, KTUser * account);


@interface KTAccountManager : NSObject


/**
 * 使用网游用户登录
 * @param gameUserId 游戏用户ID
 * @param gameCode 游戏代码
 * @param success 成功回调
 * @param failure 失败回调
 */
+(void)loginWithGameUser:(NSString *)gameUserId success:(void (^)(KTUser *user))success failure:(void (^)(NSError *error))failure;


/**
 * 修改当前登录用户的昵称
 * @param nickname 新昵称
 * @param success 成功回调
 * @param failure 失败回调
 */
+(void)setNickname:(NSString *)nickname  success:(void (^)(KTUser *user))success failure:(void (^)(NSError *error))failure;


/**
 * 登出当前用户
 */
+(void)logout;


///  设置KTPlay登录状态变更回调
/*
*
*  @param ktLoginStatusChangedBlock 登录状态变更回调
*
**/
+(void)setLoginStatusChangedBlock:(KTLoginStatusChangedBlock)ktLoginStatusChangedBlock ;


/// @name 显示KTPlay独立登录窗口
/**
 *  @param closeable 呼出窗口是否包含关闭按钮。 YES 能关闭，NO 不能关闭
 *  @param success 注册，登录成功回掉
 *  @param failure 关闭独立登录窗口，或其登录失败异常情况
 */
+(void)showLoginView:(BOOL)closeable success:(void (^)( KTUser * account))success
             failure:(void (^)(NSError *error))failure;




///@name 其他用户相关接口
/** 获取用户信息
 *  @param userId KTPlay用户的ID
 *  @param success 获取成功回调
 *  @param failure 获取成功失败回调
 *
 *  错误码：
 *
 * + 150001	缺少必要参数
 * + 150002	请求的API未找到
 * + 150003	请求的http方法不被允许
 * + 150004	无效参数
 * + 150005	数据库访问错误
 * + 150006	Reids访问错误
 * + 150007	服务器内部错误
 * + 150103	记录不存在
 * + 150104	无效的登陆token ，需要重新登录
 * + 150105	黑名单用户
 */
+(void)userProfile:(NSString *)userId success:(void (^)(KTUser * user))success failure:(void(^)(NSError * error))failure;


/** 判断用户是否已登录
 *  @return KTPlay是否已有用户登录
 */
+(BOOL)isLoggedIn;


/** 获取当前用户信息
 *  @return 返回当前登录用户信息，如果用户未登录返回为nil
 */
+(KTUser *)currentAccount;

@end
