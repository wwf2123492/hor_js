//
//  NSString+Password.h
//  03.数据加密
//
//  Created by 刘凡 on 13-12-10.
//  Copyright (c) 2013年 itcast. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCryptor.h>
#import <CommonCrypto/CommonDigest.h>

@interface NSString (Password)

/**
 *  SHA1加密
 */
@property (nonatomic,copy,readonly) NSString *sha1;

- (NSString *)md5String;


//3DES加密解密算法
- (NSString*)TripleDESWithKey:(NSString*)key encryptOrDecrypt:(CCOperation)encryptOrDecrypt ;

//DES加密解密算法
- (NSString*)DESWithKey:(NSString*)key encryptOrDecrypt:(CCOperation)encryptOrDecrypt ;

//GTMBase64编码
- (NSString * )encodeBase64;

//GTMBase64解码
- (NSString * )decodeBase64;

////URL编码
//- (NSString *)URLEncodedString;

//URL解码
- (NSString *)URLDecodedString;


@end
