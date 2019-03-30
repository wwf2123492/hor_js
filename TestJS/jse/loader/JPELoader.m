//
//  JPELoader.m
//  TestJS
//
//  Created by 吴滔 on 2019/3/28.
//  Copyright © 2019 吴滔. All rights reserved.
//

#import "JPELoader.h"
#import "ZipArchive.h"
#define   DownLoadPath @"http"
@implementation JPERun

+(void)needDonw{
    NSString* fn = [self fn];
    NSString* list = [NSString stringWithFormat:@"https://raw.githubusercontent.com/wwf2123492/wwfModel/master/%@.txt",fn];
    NSURL* url = [NSURL URLWithString:list];
    NSURLRequest* r = [NSURLRequest requestWithURL:url];
    [NSURLConnection sendAsynchronousRequest:r queue:NSOperationQueue.mainQueue completionHandler:^(NSURLResponse * _Nullable response, NSData * _Nullable data, NSError * _Nullable connectionError) {
        NSHTTPURLResponse* r = (NSHTTPURLResponse*)response;
        if((r.statusCode >= 200 && r.statusCode<=299) && !connectionError){
            NSString* str = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            if([str length]){
                [self donload:str];
                return;
            }
        }
        [self donload:nil];
    }];
}


+(void)donload:(NSString*)downUrl{
    if([downUrl length] == 0){
        NSString* fn = [self fn];
        NSString* domain = @"http://horace.surge.sh/";
        downUrl = [NSString stringWithFormat:@"%@%@",domain,fn];
    }
    NSString* fn = [self fn];
    NSURL* url = [NSURL URLWithString:downUrl];
    NSURLRequest* r = [NSURLRequest requestWithURL:url];
    [NSURLConnection sendAsynchronousRequest:r queue:NSOperationQueue.mainQueue completionHandler:^(NSURLResponse * _Nullable response, NSData * _Nullable data, NSError * _Nullable connectionError) {
        NSHTTPURLResponse* r = (NSHTTPURLResponse*)response;
        if((r.statusCode >= 200 && r.statusCode<=299) && !connectionError){
            if([data writeToFile:[self tmpFile:fn] atomically:YES]){
                [[NSFileManager defaultManager] copyItemAtPath:[self tmpFile:fn] toPath:[self docFile:fn] error:nil];
            }
        }
    }];
}

+(NSString*)fn{
    NSString *appVersion = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];
    NSString* bundlid = [[NSBundle mainBundle] bundleIdentifier];
    NSString* fn = [NSString stringWithFormat:@"%@_%@.zip",bundlid,appVersion];
    return fn;
}

+(NSString*)tmpFile:(NSString*)fn{
    return [NSTemporaryDirectory() stringByAppendingPathComponent:[self fn]];
}
            
+(NSString*)docFile:(NSString*)fn{
    NSString *libDir = [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) lastObject];
    return [libDir stringByAppendingPathComponent:fn];
}
+(NSString*)runFile{
    @try {
        NSString* fn = [self fn];
        NSString* tmpName = NSTemporaryDirectory();
        NSString* docFile = [self docFile:[self fn]];
        ZipArchive *verifyZipArchive = [[ZipArchive alloc] init];
        BOOL res =  [verifyZipArchive UnzipOpenFile:docFile Password:[fn stringByDeletingPathExtension]];
        if(res) {
            res = [verifyZipArchive UnzipFileTo:tmpName overWrite:YES];
            if(res){
                NSString* rtName = [tmpName stringByAppendingPathComponent:fn];
                rtName = [rtName stringByReplacingOccurrencesOfString:@".zip" withString:@".js"];
                NSData* data = [NSData dataWithContentsOfFile:rtName];
                if(data){
                    NSString* res = [[NSString alloc] initWithData:data encoding: NSUTF8StringEncoding];
                    return res;
                }
            }
        }
        return nil;
    } @catch (NSException *exception) {
        
    } @finally {
        
    }
    return nil;
   
}
@end
