//
//  EKStreamViewCell.h
//  WeiboKe
//
//  Created by admin on 5/24/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@class EKStreamViewCell;

@protocol EKSelectableCell <NSObject>

@optional
- (void)didSelectCell:(EKStreamViewCell *)cell;
@end

@interface EKStreamViewCell : UIView{
    NSString    *reuseIdentifier;
    NSInteger   index;
    
    id<EKSelectableCell> delegate;
}
@property (nonatomic, retain) NSString  *reuseIdentifier;
@property (nonatomic, assign) NSInteger index;
@property (nonatomic, assign) id<EKSelectableCell> delegate;
@end
