//
//  DiscPublisher.h
//  Primiera
//
//  Created by Alessandro Volz on 2/9/10.
//  Copyright 2010 OsiriX Team. All rights reserved.
//

#import <JobManager/PTJobManager.h>

@class DiscPublisherJob, DiscPublisherStatus;

@interface DiscPublisher : NSObject {
	@private
	NSMutableArray* _jobs;
	DiscPublisherStatus* _status;
    JM_BinSelection _binSelection;
}

@property(readonly) DiscPublisherStatus* status;

-(JM_BinSelection&)binSelection;

+(NSString*)baseDirPath;
+(NSString*)jobsDirPath;

+(void)initializeJobManager;
+(void)terminateJobManager;

-(id)createJobOfClass:(Class)c; // c must inherit from DiscPublisherJob
-(DiscPublisherJob*)createJob;
-(DiscPublisherJob*)createPrintOnlyJob;

-(void)robot:(UInt32)robot systemAction:(UInt32)action;

-(void)applyBinSelection:(JM_BinSelection*)binsel;

@end
