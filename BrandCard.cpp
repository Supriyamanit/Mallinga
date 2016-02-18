/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CategoryCard.cpp
 * Author: f22labs
 * 
 * Created on 16 February, 2016, 4:54 PM
 */

#include "BrandCard.h"
#define OVERLAY_ALPHA 150
#define DEFAULT_ANIMATION_SPEED 200

BrandCard::BrandCard() {
	this->setUserInteractionEnabled(TRUE);
}

BrandCard::BrandCard(const BrandCard& orig) {
}

BrandCard::~BrandCard() {
}

void BrandCard::setupWith(char *imageName, gfloat width, gfloat height){
	this->setSize(width,height);
  
  UIImage *img = UIImage::imageNamed(imageName);
  
  this->baseImage = UIImageView::initWithImage(img);
  this->baseImage->setSize(this->getWidth(),this->getHeight());
  this->baseImage->setContentGravity(CLUTTER_CONTENT_GRAVITY_RESIZE_FILL);
  this->addSubView(this->baseImage);
  
  this->midLayer = new UIView();
  this->midLayer->setBackgroundColor(CLUTTER_COLOR_Black);
  this->midLayer->setSize(this->getWidth(),this->getHeight());
  this->midLayer->setAlpha(OVERLAY_ALPHA);
  this->addSubView(this->midLayer);
  
  this->setClip(0,0,this->getWidth(),this->getHeight());
}

void BrandCard::touchBegan(ClutterEvent* event) {
}

void BrandCard::touchEnded(ClutterEvent* event) {
  this->delegate->didTapBigButton(this);
}

void BrandCard::setDelegate(BrandCardDelegate *delegate) {
    this->delegate = delegate;
}