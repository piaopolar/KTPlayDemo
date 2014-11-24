// KTFriendship.h
//
// Copyright (c) 2014 KTplay  All rights reserved.

#import <Foundation/Foundation.h>

@interface KTFriendship : NSObject


/// 显示KTPlay好友邀请窗口
+(void)showFriendRequestsView;


/**发送好友邀请
 *  @param targetUserIds 对方的KTPlay userId，可添加多人
 *  @param success 成功回调
 *  @param failure 失败回调
 *
 *  错误码：
 *
 * + 150001	缺少必要参数
 * + 150002	请求的API未找到
 * + 150003	请求的http方法不被允许
 * + 150004	无效参数
 * + 150005	数据库访问错误
 * + 150006	缓存访问错误
 * + 150007	服务器内部错误
 * + 150103	记录不存在
 * + 150104	无效的登陆token ，需要重新登录
 * + 150105	黑名单用户
 * + 150701	不能加自己为好友
 * + 150702	你们已经是好友
 * + 150703	你已经达到好友数量上限
 * + 150704	对方已经达到好友数量上限
 * + 150705	你已经邀请过他了
 */
+(void)sendFriendRequests:(NSArray *)targetUserIds success:(void (^)(int count))success failure:(void(^)(NSError * error))failure;



/**获取好友列表
 *  @param success 成功回调
 *  @param failure 失败回调
 *
 *  错误码：
 *
 * + 150001	缺少必要参数
 * + 150002	请求的API未找到
 * + 150003	请求的http方法不被允许
 * + 150004	无效参数
 * + 150005	数据库访问错误
 * + 150006	缓存访问错误
 * + 150007	服务器内部错误
 * + 150103	记录不存在
 * + 150104	无效的登陆token ，需要重新登录
 * + 150105	黑名单用户
 */
+(void)friendList:(void (^)(NSArray* users))success failure:(void(^)(NSError * error))failure;
@end
