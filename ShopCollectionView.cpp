/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShopCollectionView.cpp
 * Author: hariharasudhan
 * 
 * Created on February 20, 2016, 5:30 AM
 */

#include "ShopCollectionView.h"

ShopCollectionView::ShopCollectionView() {
	boxLayout = new UIBoxLayout;
	boxLayout->setOrientation(CLUTTER_ORIENTATION_HORIZONTAL);
	boxLayout->setSpacing(10);
	this->setLayoutManager(boxLayout);
	this->setSize(1920,1080);
	UIPanGestureRecognizer *panGRecognizer = new UIPanGestureRecognizer();
	panGRecognizer->setAxis(CLUTTER_PAN_X_AXIS);
  this->addGestureRecognizer(panGRecognizer);
  this->setUserInteractionEnabled(TRUE);
  panGRecognizer->setDelegate(this);
  panGRecognizer->setInterpolate(TRUE);


	for(int i=0;i<10;i++){
		ShopDetails *details = g_new0(ShopDetails,1);
		details->imagePath = "images/shops/shoe.png";
		details->title = "Metro Shoes";
		details->description = "Metro Shoes is an online shoe store in India with popular shoe brands for men, women and kids. Buy branded footwear online at lowest.";
		details->openHours = "11AM to 9PM";
		details->phoneNumber = "044 6666 6666";
		card[i] = new ShopCard(details);
		this->addSubView(card[i]);
		card[i]->setSize(550,1080);
		card[i]->setBackgroundColor(CLUTTER_COLOR_Transparent);
	}
}

ShopCollectionView::ShopCollectionView(const ShopCollectionView& orig) {
}

ShopCollectionView::~ShopCollectionView() {
}

gboolean ShopCollectionView::videDidPan(UIPanGestureRecognizer *recognizer, gboolean isInterpolated){
  return TRUE;
}

void ShopCollectionView::panDidEnd(UIPanGestureRecognizer *recognizer) {  
}
