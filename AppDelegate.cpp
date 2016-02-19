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
static CategoryView *categoryGrid;
UIView *globalSuperView;

AppDelegate::AppDelegate() {
}

AppDelegate::AppDelegate(const AppDelegate& orig) {
}

AppDelegate::~AppDelegate() {
}

void AppDelegate::didLaunchApplicationWithOption(int argc, char** argv, UIApplication* application) {
  // categoryGrid = new GridView( 2, 4);
  categoryGrid = new CategoryView(3,5);
  globalSuperView = application->superView;
  globalSuperView->setBackgroundColor(CLUTTER_COLOR_Black);
  globalSuperView->addSubView(categoryGrid->containerView);
}

CGSize AppDelegate::resizeScreen() {
    return CGSizeMake(1920,1080);
}

