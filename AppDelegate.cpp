/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AppDelegate.cpp
 * Author: f22labs
 * 
 * Created on 16 February, 2016, 12:23 PM
 */

#include "AppDelegate.h"
#include "CategoryView.h"
#include "ShopCollectionView.h"
#include "LaunchScreen.h"
#include "constants.h"

static CategoryView *categoryGrid;
static LaunchScreen* launchScreen;
UIView *globalSuperView;

AppDelegate::AppDelegate() {
}

AppDelegate::AppDelegate(const AppDelegate& orig) {
}

AppDelegate::~AppDelegate() {
}

void AppDelegate::didLaunchApplicationWithOption(int argc, char** argv, UIApplication* application) {

  globalSuperView = application->superView;
  UIView *backgroundView = new UIView();
  UIImage *img = UIImage::imageNamed("images/background2.jpeg");
  backgroundView = UIImageView::initWithImage(img);
  backgroundView->setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
  backgroundView->setContentGravity(CLUTTER_CONTENT_GRAVITY_RESIZE_FILL);
  globalSuperView->addSubView(backgroundView);
	


	// launchScreen = new LaunchScreen();
	// globalSuperView->addSubView(launchScreen->containerView);
	// categoryGrid = new CategoryView(3,5);
 //  globalSuperView->addSubView(categoryGrid->containerView);
  ShopCollectionView *shopView = new ShopCollectionView();
  globalSuperView->addSubView(shopView);

	// launchScreen = new LaunchScreen();
	// globalSuperView->addSubView(launchScreen->containerView);
	// categoryGrid = new CategoryView(3,5);
  // globalSuperView->addSubView(categoryGrid->containerView);


	// launchScreen = new LaunchScreen();
	// globalSuperView->addSubView(launchScreen->containerView);
	// categoryGrid = new CategoryView(3,5);
  // globalSuperView->addSubView(categoryGrid->containerView);

}

CGSize AppDelegate::resizeScreen() {
    return CGSizeMake(1920,1080);
}

