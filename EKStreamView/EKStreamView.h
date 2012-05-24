//
//  EKStreamView.h
//  StreamView
//
//  Created by Eli Wang on 1/16/12.
//  Copyright (c) 2012 ekohe.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "EKStreamViewCell.h"

@interface EKStreamViewCellInfo : NSObject 

@property (nonatomic, assign) CGRect frame;
@property (nonatomic, assign) NSUInteger index;

// You SHOULD ONLY access this property when this object is in visibleCellInfo!
@property (nonatomic, assign) EKStreamViewCell *cell;

@end

@class EKStreamView;

@protocol EKStreamViewDelegate <UIScrollViewDelegate>

- (NSInteger)numberOfCellsInStreamView:(EKStreamView *)streamView;
- (NSInteger)numberOfColumnsInStreamView:(EKStreamView *)streamView;
- (EKStreamViewCell *)streamView:(EKStreamView *)streamView cellAtIndex:(NSInteger)index;
- (CGFloat)streamView:(EKStreamView *)streamView heightForCellAtIndex:(NSInteger)index;

@optional

- (UIView *)headerForStreamView:(EKStreamView *)streamView;
- (UIView *)footerForStreamView:(EKStreamView *)streamView;

- (void)streamView:(EKStreamView *)streamView selectedCellAtIndex:(NSInteger)index;

@end


@interface EKStreamViewUIScrollViewDelegate : NSObject<UIScrollViewDelegate>
@property (nonatomic, assign) EKStreamView *streamView;

@end

@interface EKStreamView : UIScrollView<EKSelectableCell>
{
    NSMutableArray
    *cellHeightsByIndex,    // 1d
    *cellHeightsByColumn,   // 2d
    *rectsForCells;         // 2d EKWaterfallCellInfo
    
    NSMutableDictionary *cellCache; // reuseIdentifier => NSMutableArray
    NSSet *visibleCellInfo;
    UIView *headerView, *footerView;
    CGFloat columnWidth;
    EKStreamViewUIScrollViewDelegate *delegateObj;
}
@property (nonatomic, retain) NSSet *visibleCellInfo;
@property (nonatomic, retain) NSMutableDictionary *cellCache;

@property (nonatomic, assign) id<EKStreamViewDelegate> delegate;
@property (nonatomic, assign) CGFloat columnPadding;
@property (nonatomic, assign) CGFloat cellPadding;

@property (nonatomic, readonly) CGFloat columnWidth;

- (EKStreamViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier;
- (void)reloadData;

@end
