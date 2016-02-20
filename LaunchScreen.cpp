/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LaunchScreen.cpp
 * Author: f22labs
 * 
 * Created on 20 February, 2016, 8:47 AM
 */

#include "LaunchScreen.h"

LaunchScreen::LaunchScreen() {
	containerView = new UIView();
	containerView->setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	buildStartButton();
	buildLogo();
}

void LaunchScreen::buildStartButton() {
  UIView* rippleLayer = new UIView();
	UIImage *img2 = UIImage::imageNamed("images/ripple.png");
  rippleLayer = UIImageView::initWithImage(img2);
  rippleLayer->setSize(200, 200);
  rippleLayer->setContentGravity(CLUTTER_CONTENT_GRAVITY_RESIZE_FILL);
  rippleLayer->setPosition((SCREEN_WIDTH - rippleLayer->getWidth())/2, (SCREEN_HEIGHT - rippleLayer->getHeight())/2);
  containerView->addSubView(rippleLayer);

	touchMe = new UIView();
	UIImage *img = UIImage::imageNamed("images/start.png");
  touchMe = UIImageView::initWithImage(img);
  touchMe->setSize(200, 200);
  touchMe->setContentGravity(CLUTTER_CONTENT_GRAVITY_RESIZE_FILL);
  touchMe->setPosition((SCREEN_WIDTH - touchMe->getWidth())/2, (SCREEN_HEIGHT - touchMe->getHeight())/2);
  containerView->addSubView(touchMe);



  CATransition* rippleAnimationX = new CATransition("scale-x");
	rippleAnimationX->setFromValue(G_TYPE_DOUBLE, rippleLayer->getScaleX());
	rippleAnimationX->setToValue(G_TYPE_DOUBLE, 1.25);
	rippleAnimationX->setDuration(1050);
	rippleLayer->addTransition(rippleAnimationX, "scale-x-up");
	rippleAnimationX->setRepeatCount(-1);
	rippleLayer->setPivotPoint(0.5,0.5);

	CATransition* rippleAnimationY = new CATransition("scale-y");
	rippleAnimationY->setFromValue(G_TYPE_DOUBLE, rippleLayer->getScaleX());
	rippleAnimationY->setToValue(G_TYPE_DOUBLE, 1.25);
	rippleAnimationY->setDuration(1050);
	rippleLayer->addTransition(rippleAnimationY, "scale-y-up");
	rippleAnimationY->setRepeatCount(-1);
	rippleLayer->setPivotPoint(0.5,0.5);

	CATransition* fadeoffTransition = new CATransition("opacity");
	fadeoffTransition->setFromValue(G_TYPE_UINT, 255);
	fadeoffTransition->setToValue(G_TYPE_UINT, 0);
	fadeoffTransition->setDuration(1050);
	rippleLayer->addTransition(fadeoffTransition, "fadeoff");
	fadeoffTransition->setRepeatCount(-1);
	
}

void LaunchScreen::buildLogo() {
	mallLogo = new UIView();
  UIImage *img = UIImage::imageNamed("images/logo.png");
  mallLogo = UIImageView::initWithImage(img);
  mallLogo->setContentGravity(CLUTTER_CONTENT_GRAVITY_RESIZE_FILL);
  mallLogo->setPosition((SCREEN_WIDTH - mallLogo->getWidth())/2, 35);
  mallLogo->setSize(200, 100);
  containerView->addSubView(mallLogo);
}

LaunchScreen::LaunchScreen(const LaunchScreen& orig) {
}

LaunchScreen::~LaunchScreen() {
}

