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
#include "BrandGridView.h"
#include "constants.h"
#include "BrandCard.h"
gfloat columnGap = 5.0;
gfloat rowGap = 5.0;

BrandGridView::BrandGridView(gint rows, gint columns) {

	bgImages[0] = "images/apparel/1.jpg";
  bgImages[1] = "images/accesories-and-footwear/1.jpg";
  bgImages[2] = "images/health-and-beauty/1.jpg";
  bgImages[3] = "images/home-and-lifestyle/1.jpg";
  bgImages[4] = "images/electronics/1.jpg";
  bgImages[5] = "images/toys-and-gifts/1.jpg";
	bgImages[6] = "images/dining/1.jpg";
  bgImages[7] = "images/entertaitment/1.jpg";
  bgImages[8] = "images/apparel/1.jpg";
  bgImages[9] = "images/accesories-and-footwear/1.jpg";
  bgImages[10] = "images/health-and-beauty/1.jpg";
  bgImages[11] = "images/home-and-lifestyle/1.jpg";
  bgImages[12] = "images/electronics/1.jpg";
  bgImages[13] = "images/toys-and-gifts/1.jpg";
	bgImages[14] = "images/dining/1.jpg";
  bgImages[15] = "images/entertaitment/1.jpg";
  bgImages[16] = "images/apparel/1.jpg";
  bgImages[17] = "images/accesories-and-footwear/1.jpg";
  bgImages[18] = "images/health-and-beauty/1.jpg";
  bgImages[19] = "images/home-and-lifestyle/1.jpg";
  bgImages[19] = "images/electronics/1.jpg";
  bgImages[20] = "images/toys-and-gifts/1.jpg";
	bgImages[21] = "images/dining/1.jpg";
  bgImages[22] = "images/entertaitment/1.jpg";
  bgImages[23] = "images/apparel/1.jpg";
  bgImages[24] = "images/accesories-and-footwear/1.jpg";

  
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
  titles[15] = "Entertainment";
  titles[16] = "Apparel";
  titles[17] = "Accessories & Footwear";
  titles[18] = "Health & Beauty";
  titles[19] = "Home & Lifestyle";
  titles[20] = "Electronics";
  titles[21] = "Toys & Gifts";
  titles[22] = "Dining";
  titles[23] = "Entertainment";
  titles[24] = "Apparel";

	gfloat widthPerCell = (SCREEN_WIDTH - (columns + 1)*columnGap)/columns ;
	gfloat heightPerCell = (SCREEN_HEIGHT - (rows + 1)*rowGap)/rows ;
	containerView = new UIView();
	for(gint i=0; i< columns * rows; i++){
		gfloat xPos = (i%columns)*(widthPerCell + columnGap) + columnGap;
		gfloat yPos = (i/columns)*(heightPerCell + rowGap) + rowGap;
		gridCards[i] = new BrandCard();
		gridCards[i]->setupWith(bgImages[i%25], titles[i%25], widthPerCell, heightPerCell);
		gridCards[i]->setSize(widthPerCell, heightPerCell);
		gridCards[i]->setPosition(xPos, yPos);
		containerView->addSubView(gridCards[i]);
	}
	brightTransition(gridCards[0]->midLayer);  
}

BrandGridView::BrandGridView(const BrandGridView& orig) {
}

BrandGridView::~BrandGridView() {
}

void BrandGridView::brightTransition(UIView* layer){
  CATransition* rotateTransition = new CATransition("opacity");
  rotateTransition->setFromValue(G_TYPE_INT, layer->getOpacity());
  rotateTransition->setToValue(G_TYPE_INT, 0);
  rotateTransition->setDuration(1000);
  rotateTransition->setData("actor", (UIView*)layer);

  layer->setData("transitionState", (char*)"on");
  layer->addTransition(rotateTransition, "opacity-up");
  rotateTransition->setData("name", (char*)"brighttransition");
  rotateTransition->setDelegate(this);
  rotateTransition->start();
}

void BrandGridView::dimTransition(UIView* layer){
  CATransition* rotateTransition = new CATransition("opacity");
  rotateTransition->setFromValue(G_TYPE_INT, layer->getOpacity());
  rotateTransition->setToValue(G_TYPE_INT, 155);
  rotateTransition->setDuration(1000);
  layer->setData("transitionState", (char*)"on");
  rotateTransition->setData("actor", (UIView*)layer);
  rotateTransition->setData("name", (char*)"dimtransition");
  layer->addTransition(rotateTransition, "opacity-down");
  rotateTransition->setDelegate(this);
  rotateTransition->start();
}

void BrandGridView::transitionDidFinish(CATimeline *timeline){
  if(!g_strcmp0((char*)timeline->getData("name"),"brighttransition")){
    UIView* actor = (UIView*)timeline->getData("actor");
    actor->removeAllTransition();
    actor->setData("transitionState", (char*)"off");
    dimTransition(actor);
    
    gint random = rand() % 60;  
    while(TRUE){
      if(g_strcmp0((char*)gridCards[random]->midLayer->getData("transitionState"), "on")){
        break;
      }
      random = rand() % 60;  
    }
    brightTransition(gridCards[random]->midLayer);
  }else if(!g_strcmp0((char*)timeline->getData("name"),"dimtransition")){
    UIView* actor = (UIView*)timeline->getData("actor");
    actor->setData("transitionState", (char*)"off");
    actor->removeAllTransition();
  }
}

void BrandGridView::didProgress(CATimeline *timeline,int msecs){
}