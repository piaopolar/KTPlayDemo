// KTUser.h
//
// Copyright (c) 2014 KTplay  All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "KTPlay.h"


@interface KTUser : NSObject
///KT用户唯一标识符
@property (nonatomic, copy) NSString * userId;

///KT用户头像
@property (nonatomic, copy) NSString * headerUrl;

///KT用户昵称
@property (nonatomic, copy) NSString * nickname;

///性别  0:未知;1:男;2:女
@property (nonatomic) NSInteger  gender;

///城市
@property (nonatomic, copy) NSString * city;

///扩展属性，得分
@property (nonatomic, copy) NSString * score;

///扩展属性，排行
@property (nonatomic) long long rank;

///SNS用户ID
@property (nonatomic,copy) NSString *           snsUserId;

///sns登录类型登录的，此值才有效
@property (nonatomic,copy) NSString *           loginType;

///游戏用户唯一标识符,游戏登录有效
@property (nonatomic,copy) NSString *           gameUserId;

@end


