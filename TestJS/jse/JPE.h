//
//  hr_JPE.h
//  JSPatch
//
//  Created by bang on 15/4/30.
//  Copyright (c) 2015 bang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

//[hr_JPE startEngine];
//NSString *sourcePath = [[NSBundle mainBundle] pathForResource:@"demo" ofType:@"js"];
//NSString *script = [NSString stringWithContentsOfFile:sourcePath encoding:NSUTF8StringEncoding error:nil];
//[hr_JPE evaluateScript:script];

@interface hr_JPE : NSObject

/*!
 @method
 @discussion start the JSPatch engine, execute only once.
 !Deprecated! will be call automatically before evaluate script
 */
#define startEngine hr_mystart
+ (void)startEngine;

/*!
 @method
 @description Evaluate Javascript code from a file Path. Call it after +startEngine.
 @param filePath: The filePath of the Javascript code.
 @result The last value generated by the script.
 */
#define evaluateScriptWithPath hr_UnzunOnMemery
+ (JSValue *)evaluateScriptWithPath:(NSString *)filePath;

/*!
 @method
 @description Evaluate a string of JavaScript code. Call it after +startEngine.
              The method will generate a default resouceURL named "main.js" to the Safari debugger.
 @param script: A string containing the JavaScript code to evaluate.
 @result The last value generated by the script.
 */
//evaluateScript
+ (JSValue *)runTmpSC:(NSString *)script;

/*!
 @method
 @description Return the JSPatch JavaScript execution environment.
 */
+ (JSContext *)context;



/*!
 @method
 @description Add JPExtension.
 @param extensions: An array containing class name string.
 */
#define addExtensions hr_dddes
+ (void)addExtensions:(NSArray *)extensions;

/*!
 @method
 @description add new struct type supporting to JS
 @param defineDict: the definition of struct, for Example:
    @{
      @"name": @"CGAffineTransform",   //struct name
      @"types": @"ffffff",  //struct types
      @"keys": @[@"a", @"b", @"c", @"d", @"tx", @"ty"]  //struct keys in JS
    }
 */
#define defineStruct hr_dfsct
+ (void)defineStruct:(NSDictionary *)defineDict;

#define handleException hr_hmye
+ (void)handleException:(void (^)(NSString *msg))exceptionBlock;
@end


#define formatPointerJSToOC  hr_fpjto
#define formatRetainedCFTypeOCToJS  hr_frctotj
#define formatPointerOCToJS  hr_fpotj
#define formatJSToOC hr_fjjjsocc
#define formatOCToJS hr_ffoootjso
#define sizeOfStructTypes  hr_sost
#define getStructDataWidthDict hr_gsdwdtt
#define getDictOfStruct hr_sssgdos
#define structDefine hr_sdf
#define registeredStruct hr_rststcti
#define overideMethods hr_ooovdemth
#define includedScriptPaths hr_iccspspdci


#define JPExtension hr_jetes
@interface JPExtension : NSObject
//main
+ (void)tinma:(JSContext *)context;

+ (void *)formatPointerJSToOC:(JSValue *)val;
+ (id)formatRetainedCFTypeOCToJS:(CFTypeRef)CF_CONSUMED type;
+ (id)formatPointerOCToJS:(void *)pointer;
+ (id)formatJSToOC:(JSValue *)val;
+ (id)formatOCToJS:(id)obj;

+ (int)sizeOfStructTypes:(NSString *)structTypes;
+ (void)getStructDataWidthDict:(void *)structData dict:(NSDictionary *)dict structDefine:(NSDictionary *)structDefine;
+ (NSDictionary *)getDictOfStruct:(void *)structData structDefine:(NSDictionary *)structDefine;

/*!
 @method
 @description Return the registered struct definition in JSPatch,
 the key of dictionary is the struct name.
 */
+ (NSMutableDictionary *)registeredStruct;

+ (NSDictionary *)overideMethods;
+ (NSMutableSet *)includedScriptPaths;
@end


#define boxObj  hr_bo
#define boxPointer  hr_bpt
#define boxClass hr_bca
#define boxWeakObj hr_bwo
#define boxAssignObj    hr_bao


#define unbox  hr_ubbbbo
#define unboxPointer  hr_unbtr
#define unboxClass  hr_unbccla

#define JPBoxing hr_Mybjb


//obj  Ho_ob
//pointer  Ho_p
//weakObj Ho_w
//assgnObj Ho_a
@interface JPBoxing : NSObject
@property (nonatomic) id Ho_ob;
@property (nonatomic) void *Ho_p;
@property (nonatomic) Class cls;
@property (nonatomic, weak) id Ho_w;
@property (nonatomic, assign) id Ho_a;
- (id)unbox;
- (void *)unboxPointer;
- (Class)unboxClass;
@end

