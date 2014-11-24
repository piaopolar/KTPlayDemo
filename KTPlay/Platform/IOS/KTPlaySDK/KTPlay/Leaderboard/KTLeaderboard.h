// KTLeaderboard.h
//
// Copyright (c) 2014 KTplay  All rights reserved.


#import <Foundation/Foundation.h>
@interface KTLeaderboardPaginator : NSObject
/// 上榜人数
@property (nonatomic) int total;

/// 下一页起始位置，nextCursor在gameLeaderboard中是无效的
@property (nonatomic, copy) NSString * nextCursor;

/// 上一页起始位置，previousCursor在gameLeaderboard中是无效的
@property (nonatomic, copy) NSString * previousCursor;

/// KTUser数组
@property (nonatomic, copy) NSArray * items;

/// 排行榜名字
@property (nonatomic, copy) NSString * leaderboardName;

/// 排行榜图标
@property (nonatomic, copy) NSString * leaderboardIcon;

/// 排行榜ID
@property (nonatomic, copy) NSString * leaderboardId;

/// 排行榜单结算ID，保留字段，暂时无用
@property (nonatomic, copy) NSString * periodicalSummaryId;

/// 我的排名
@property (nonatomic) NSInteger myRank;

/// 我的积分
@property (nonatomic,copy) NSString *myScore;

@end

@interface KTLeaderboard : NSObject

/** 获取好友排行榜数据
 *  @param leaderboardId 排行榜Type，此数据在开发者网站获取
 *  @param startIndex  排行榜起始位置，如果传-1 返回当前登录用户排名所处位置的排行榜数据。
 *  @param count  获取排行榜单页数据记录条数。
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
 * + 150901	排行榜不存在
 */
+(void)friendsLeaderboard:(NSString *)leaderboardId startIndex:(int)startIndex count:(int)count success:(void (^)(KTLeaderboardPaginator * leaderboard))success failure:(void(^)(NSError * error))failure;

/** 获取游戏排行榜数据
 *  @param leaderboardId 排行榜id，此数据在开发者网站获取
 *  @param startIndex  排行榜起始位置
 *  @param count  获取排行榜单页数据记录条数
 *  @param success 成功回调
 *  @param failure 失败回调。
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
 * + 150901	排行榜不存在
 */
+(void)globalLeaderboard:(NSString *)leaderboardId startIndex:(int)startIndex count:(int)count success:(void (^)(KTLeaderboardPaginator * leaderboard))success failure:(void(^)(NSError * error))failure;

/**
 *  @deprecated 使用globalLeaderboard方法替代。
 */
+(void)gameLeaderboard:(NSString *)leaderboardId pageIndex:(int)pageIndex pageSize:(int)pageSize success:(void (^)(KTLeaderboardPaginator * leaderboard))success failure:(void(^)(NSError * error))failure __deprecated;



/** 上传得分
 *  @param leaderboardId 排行榜Type ，此数据在开发者网站获取
 *  @param score 游戏得分
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
+(void)reportScore:(long long)score leaderboardId:(NSString *)leaderboardId success:(void (^)())success failure:(void(^)(NSError * error))failure;
@end
