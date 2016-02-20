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

	for(int i=0;i<10;i++){
		card[i] = new ShopCard();
		this->addSubView(card[i]);
		card[i]->setSize(550,1080);
		card[i]->setBackgroundColor(CLUTTER_COLOR_Aluminium1);
	}
}

ShopCollectionView::ShopCollectionView(const ShopCollectionView& orig) {
}

ShopCollectionView::~ShopCollectionView() {
}

