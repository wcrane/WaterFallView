//
//  EKStreamViewCell.m
//  WeiboKe
//
//  Created by admin on 5/24/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "EKStreamViewCell.h"

@implementation EKStreamViewCell

@synthesize reuseIdentifier;
@synthesize index;
@synthesize delegate;

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
    return self;
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event{
    UITouch *touch = [touches anyObject];
    if (touch) {
        if (self.delegate && [self.delegate respondsToSelector:@selector(didSelectCell:)]) {
            [self.delegate didSelectCell:self];
        }
    }
}

- (void)dealloc{
    self.reuseIdentifier = nil;
    [super dealloc];
}
@end
