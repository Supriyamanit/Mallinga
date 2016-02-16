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

#include "CategoryCard.h"
#define OVERLAY_ALPHA 150
#define DEFAULT_ANIMATION_SPEED 200

CategoryCard::CategoryCard() {
	this->setUserInteractionEnabled(TRUE);
}

CategoryCard::CategoryCard(const CategoryCard& orig) {
}

CategoryCard::~CategoryCard() {
}

void CategoryCard::setupWith(char *imageName, char *title, gfloat width, gfloat height){
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
  
  this->lblTitle = new UILabel();
  this->lblTitle->setFontWithSize("DIN Condensed,20");
  this->lblTitle->setTextColor(CLUTTER_COLOR_White);
  this->lblTitle->setTextAlignment(PANGO_ALIGN_CENTER);
  this->lblTitle->setText(title);
  this->lblTitle->setLineWrap(TRUE);
  this->lblTitle->setSize(320,300);

  this->addSubView(this->lblTitle);
  this->setClip(0,0,this->getWidth(),this->getHeight());
}

void CategoryCard::touchBegan(ClutterEvent* event) {
  
  this->midLayer->setEasing(0.0,DEFAULT_ANIMATION_SPEED,CLUTTER_LINEAR);
  this->midLayer->setAlpha(0);
  this->midLayer->restoreEasing();
  this->baseImage->setEasing(0.0,DEFAULT_ANIMATION_SPEED,CLUTTER_LINEAR);
  this->baseImage->setScale(1.1,1.1);
  this->baseImage->restoreEasing();
}

void CategoryCard::touchEnded(ClutterEvent* event) {
  this->midLayer->setEasing(0.0,DEFAULT_ANIMATION_SPEED,CLUTTER_LINEAR);
  this->midLayer->setAlpha(OVERLAY_ALPHA);
  this->midLayer->restoreEasing();
  this->baseImage->setEasing(0.0,DEFAULT_ANIMATION_SPEED,CLUTTER_LINEAR);
  this->baseImage->setScale(1.0,1.0);
  this->baseImage->restoreEasing();
  this->delegate->didTapBigButton(this);
}

void CategoryCard::setDelegate(CategoryCardDelegate *delegate) {
    this->delegate = delegate;
}