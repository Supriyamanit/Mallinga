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
	touchMe = new UIView();
	UIImage *img = UIImage::imageNamed("images/start.png");
  touchMe = UIImageView::initWithImage(img);
  touchMe->setSize(200, 200);
  touchMe->setContentGravity(CLUTTER_CONTENT_GRAVITY_RESIZE_FILL);
  touchMe->setPosition((SCREEN_WIDTH - touchMe->getWidth())/2, (SCREEN_HEIGHT - touchMe->getHeight())/2);
  containerView->addSubView(touchMe);

 //  CATransition* rippleAnimation = new CATransition("scale-x");
	// scaleDownXTransition->setFromValue(G_TYPE_DOUBLE, view->getScaleX());
	// scaleDownXTransition->setToValue(G_TYPE_DOUBLE, 0.0);
	// scaleDownXTransition->setDuration(250);
	// scaleDownXTransition->setDelegate(this);
	// scaleDownXTransition->setData("type", (char*)"scale-x-down");
	// scaleDownXTransition->setData("actor", view);
	// view->addTransition(scaleDownXTransition, "scale-x-down");
	// view->setPivotPoint(0.5,0.5);
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

