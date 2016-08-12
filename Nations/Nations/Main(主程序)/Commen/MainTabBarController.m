//
//  MainTabBarController.m
//  Nations
//
//  Created by LB on 16/7/11.
//  Copyright © 2016年 LB. All rights reserved.
//

#import "MainTabBarController.h"
#import "MinViewController.h"
#import "ZuViewController.h"
#import "TuanViewController.h"
#import "JieViewController.h"
#import "CameraViewController.h"
#import "UIImage+Image.h"


//重复点击tabBar上按钮，刷新当前界面功能
NSString * const repeateClickTabBarAction = @"repeateClickTabBarAction";

@interface MainTabBarController ()<UITabBarControllerDelegate>
/** 设置重复点击TabBar的临时控制器 */
@property (nonatomic,weak) UIViewController *lastViewController;
@end

@implementation MainTabBarController

- (void)viewDidLoad {
    [super viewDidLoad];

    // 添加所有子控制器
    [self setupAllViewControllers];
    // 设置首个控制器
    _lastViewController = self.childViewControllers.firstObject;
}

#pragma mark - UITabBarControllerDelegate

- (void)tabBarController:(UITabBarController *)tabBarController didSelectViewController:(UIViewController *)viewController {
    
    if (_lastViewController == viewController) {
        // 发出通知 通知对应的子控制器去刷新界面
        [[NSNotificationCenter defaultCenter] postNotificationName:repeateClickTabBarAction object:nil];
    }
    _lastViewController = viewController;
}

#pragma mark - 设置TabBar
- (void)setupAllTabBarButton {
    
    //设置TabBar按钮的内容
    MinViewController *minVc = self.childViewControllers[0];
    minVc.tabBarItem.image = [UIImage imageNamed:@"tab_live"];
    minVc.tabBarItem.selectedImage = [UIImage imageWithOriginalRenderingMode:@"tab_live_p"];
    
    ZuViewController *zuVc = self.childViewControllers[1];
    zuVc.tabBarItem.image = [UIImage imageNamed:@"tab_live"];
    zuVc.tabBarItem.selectedImage = [UIImage imageWithOriginalRenderingMode:@"tab_live_p"];
    
    CameraViewController *cameraVc = self.childViewControllers[2];
    cameraVc.tabBarItem.image = [UIImage imageNamed:@"tab_room"];
    cameraVc.tabBarItem.selectedImage = [UIImage imageWithOriginalRenderingMode:@"tab_room_p"];

    TuanViewController *tuanVc = self.childViewControllers[3];
    tuanVc.tabBarItem.image = [UIImage imageNamed:@"tab_me"];
    tuanVc.tabBarItem.selectedImage = [UIImage imageWithOriginalRenderingMode:@"tab_me_p"];
    
    JieViewController *jieVc = self.childViewControllers[4];
    jieVc.tabBarItem.image = [UIImage imageNamed:@"tab_me"];
    jieVc.tabBarItem.selectedImage = [UIImage imageWithOriginalRenderingMode:@"tab_me_p"];
    
    
    UIEdgeInsets imageInsets = UIEdgeInsetsMake(6, 0, -6, 0);
    minVc.tabBarItem.imageInsets = imageInsets;
    zuVc.tabBarItem.imageInsets = imageInsets;
    cameraVc.tabBarItem.imageInsets = imageInsets;
    tuanVc.tabBarItem.imageInsets = imageInsets;
    jieVc.tabBarItem.imageInsets = imageInsets;
    
    //隐藏阴影线
    [[UITabBar appearance] setShadowImage:[UIImage new]];
//    [[UITabBar appearance] setBackgroundImage:[[UIImage alloc] init]];
}

#pragma mark ---- <添加所有的子控制>
- (void)setupAllViewControllers {
    
    // 初始化并添加TabBar对应的控制器
    [self addChildViweController:[[MinViewController    alloc] init]];
    [self addChildViweController:[[ZuViewController     alloc] init]];
    [self addChildViweController:[[CameraViewController alloc] init]];
    [self addChildViweController:[[TuanViewController   alloc] init]];
    [self addChildViweController:[[JieViewController    alloc] init]];
    
    // 设置所有TabBar按钮样式
    [self setupAllTabBarButton];
}

- (void)addChildViweController:(UIViewController *)vc {
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
    nav.navigationItem.titleView = [[UIView alloc] init];
    [self addChildViewController:nav];
}

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self name:repeateClickTabBarAction object:nil];
}

@end
