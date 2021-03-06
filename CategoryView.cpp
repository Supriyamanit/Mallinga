/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GridView.cpp
 * Author: f22labs
 * 
 * Created on 16 February, 2016, 12:38 PM
 */
#include <stdlib.h>
#include "CategoryView.h"
#include "BrandGridView.h"
#include "constants.h"
#include "CategoryCard.h"
#include "ShopCollectionView.h"
static gfloat columnGap = 25.0;
static gfloat rowGap = 25.0;

CategoryView::CategoryView(gint rows, gint columns) {
	
	bgImages[0] = "images/Icons/offer1.png";
  bgImages[1] = "images/Icons/dining.jpg";
  bgImages[2] = "images/Icons/clothing.jpg";
  bgImages[3] = "images/Icons/lifestyle.jpg";
  bgImages[4] = "images/Icons/footwear.jpg";
  bgImages[5] = "images/Icons/gifts.jpg";
	bgImages[6] = "images/Icons/jewellery.jpg";
  bgImages[7] = "images/Icons/offer3.png";
  bgImages[8] = "images/Icons/electronics.jpg";
	bgImages[9] = "images/Icons/spa.jpg";
	bgImages[10] = "images/brands/apparel/levis.png";
	bgImages[11] = "images/Icons/lifestyle.jpg";
	bgImages[12] = "images/Icons/watch.jpg";
	bgImages[13] = "images/Icons/lingerie.jpg";
	bgImages[14] = "images/Icons/offer2.png";

	char* logoPath = "images/logo.png";

	gfloat widthPerCell = 250 ;
	gfloat heightPerCell = 250 ;
	containerView = new UIView();

	UIView* logoView = new UIView();
	UIImage *img = UIImage::imageNamed(logoPath);
  logoView = UIImageView::initWithImage(img);
  logoView->setSize(200,100);
  logoView->setContentGravity(CLUTTER_CONTENT_GRAVITY_RESIZE_FILL);
  logoView->setPosition((SCREEN_WIDTH - logoView->getWidth())/2, 35);
  containerView->addSubView(logoView);

	
	for(gint i=0; i< columns * rows; i++){
		gfloat xPos = 280 + (i%columns)*(widthPerCell + columnGap) + columnGap;
		gfloat yPos = 140 + (i/columns)*(heightPerCell + rowGap) + rowGap;
		if(FALSE){
			UIView* promoView = new UIView();
			promoView->setBackgroundColor(CLUTTER_COLOR_Red);
			promoView->setPosition(xPos, yPos);
			promoView->setSize(widthPerCell, heightPerCell);
			containerView->addSubView(promoView);
		}else{
			gridCards[i] = new CategoryCard();
			gridCards[i]->setupWith(bgImages[i], widthPerCell, heightPerCell);
			gridCards[i]->setSize(widthPerCell, heightPerCell);
	    gridCards[i]->setData("index", GINT_TO_POINTER(i));
			gridCards[i]->setPosition(xPos, yPos);
			containerView->addSubView(gridCards[i]);
	    gridCards[i]->setDelegate(this);
		}
	}
}

CategoryView::CategoryView(const CategoryView& orig) {
}

CategoryView::~CategoryView() {
}

void CategoryView::didTapBigButton(UIView *view) {
  ShopCollectionView* shopView = new ShopCollectionView();
  containerView->setAlpha(0);
  globalSuperView->addSubView(shopView);
}