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
static gfloat columnGap = 25.0;
static gfloat rowGap = 25.0;

CategoryView::CategoryView(gint rows, gint columns) {
	bgImages[0] = "images/apparel/1.jpg";
  bgImages[1] = "images/accesories-and-footwear/1.jpg";
  bgImages[2] = "images/health-and-beauty/1.jpg";
  bgImages[3] = "images/home-and-lifestyle/1.jpg";
  bgImages[4] = "images/electronics/1.jpg";
  bgImages[5] = "images/toys-and-gifts/1.jpg";
	bgImages[6] = "images/dining/1.jpg";
  bgImages[7] = "images/entertaitment/1.jpg";
  bgImages[8] = "images/brands/apparel/allen.jpg";
	bgImages[9] = "images/brands/apparel/zara.png";
	bgImages[10] = "images/brands/apparel/arrow.jpg";
	bgImages[11] = "images/brands/apparel/biba.jpg";
	bgImages[12] = "images/brands/apparel/chemistry.jpg";
	bgImages[13] = "images/brands/apparel/fab.jpg";
	bgImages[14] = "images/brands/apparel/levis.png";
	char* logoPath = "images/brands/apparel/levis.png";

  
  titles[0] = "Apparel";
  titles[1] = "Accessories & Footwear";
  titles[2] = "Health & Beauty";
  titles[3] = "Home & Lifestyle";
  titles[4] = "Electronics";
  titles[5] = "Toys & Gifts";
  titles[6] = "Dining";
  titles[7] = "Entertainment";
  titles[8] = "Apparel";
  titles[9] = "Accessories & Footwear";
  titles[10] = "Health & Beauty";
  titles[11] = "Home & Lifestyle";
  titles[12] = "Electronics";
  titles[13] = "Toys & Gifts";
  titles[14] = "Dining";

	gfloat widthPerCell = 250 ;
	gfloat heightPerCell = 250 ;
	containerView = new UIView();

	UIView* logoView = new UIView();
	UIImage *img = UIImage::imageNamed(logoPath);
  logoView = UIImageView::initWithImage(img);
  logoView->setSize(100,100);
  logoView->setContentGravity(CLUTTER_CONTENT_GRAVITY_RESIZE_FILL);
  logoView->setPosition((SCREEN_WIDTH - logoView->getWidth())/2, 20);
  containerView->addSubView(logoView);

	
	for(gint i=0; i< columns * rows; i++){
		gfloat xPos = 280 + (i%columns)*(widthPerCell + columnGap) + columnGap;
		gfloat yPos = 140 + (i/columns)*(heightPerCell + rowGap) + rowGap;
		if(i==7){
			UIView* promoView = new UIView();
			promoView->setBackgroundColor(CLUTTER_COLOR_Red);
			promoView->setPosition(xPos, yPos);
			promoView->setSize(widthPerCell, heightPerCell);
			containerView->addSubView(promoView);
		}else{
			gridCards[i] = new CategoryCard();
			gridCards[i]->setupWith(bgImages[i], titles[i], widthPerCell, heightPerCell);
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
  
  for(int i=0; i<8; i++){
    gridCards[i]->midLayer->removeAllTransition();
    gridCards[i]->midLayer->setData("transitionState", (char*)"off");
  }
	
  for(int i=0; i<8; i++){

    
    gfloat width = gridCards[i]->getWidth();
    gfloat height = gridCards[i]->getHeight();
    gridCards[i]->setPivotPoint(0.0,0.0);
    gridCards[i]->setEasing(0,1250,CLUTTER_LINEAR);
    if(i == GPOINTER_TO_INT(view->getData("index"))){
      gridCards[i]->midLayer->setEasing(0,1250,CLUTTER_LINEAR);
      gridCards[i]->midLayer->setAlpha(0);  
    }
    gridCards[i]->setScaleWithGravity(0.25,0.25,CLUTTER_GRAVITY_NORTH_WEST);
    gridCards[i]->setPosition(50,(SCREEN_HEIGHT - 20)/8*i +10);
	}

  BrandGridView *brandGrid = buildBrandGrid(GPOINTER_TO_INT(view->getData("index")));
  containerView->addSubView(brandGrid->containerView);
  brandGrid->containerView->setPosition(SCREEN_WIDTH,0);
  brandGrid->containerView->setAlpha(0);
  brandGrid->containerView->setEasing(0,1250,CLUTTER_LINEAR);
  brandGrid->containerView->setAlpha(255);
  brandGrid->containerView->setPosition(200,0);
}

BrandGridView* CategoryView::buildBrandGrid(int i){
  switch(i){
    case 0: 
      return new BrandGridView(4,5);
      break;
  }
}