//
//  ViewController.m
//  TestJS
//
//  Created by 吴滔 on 2019/3/28.
//  Copyright © 2019 吴滔. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self teset];
    
}
-(void)teset{
//    UIButton* btn = [[UIButton alloc] init];
//    btn.backgroundColor = [UIColor redColor];
}
-(void)run_inNative{
    NSLog(@"this is run in native");
    if([self respondsToSelector:@selector(runInJS1)]){
        [self performSelector:@selector(runInJS1) withObject:nil];
    }
}

@end
