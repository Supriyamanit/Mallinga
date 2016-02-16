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
#include "GridView.h"
#include "constants.h"
#include "CategoryCard.h"
gfloat columnGap = 10.0;
gfloat rowGap = 10.0;

GridView::GridView(gint rows, gint columns) {

	bgImages[0] = "images/accesories-and-footwear/1.jpg";
  bgImages[1] = "images/apparel/1.jpg";
  bgImages[2] = "images/dining/1.jpg";
  bgImages[3] = "images/electronics/1.jpg";
  bgImages[4] = "images/entertaitment/1.jpg";
  bgImages[5] = "images/health-and-beauty/1.jpg";
  bgImages[6] = "images/home-and-lifestyle/1.jpg";
  bgImages[7] = "images/toys-and-gifts/1.jpg";
  
  titles[0] = "Accessories";
  titles[1] = "Apparel";
  titles[2] = "Dining";
  titles[3] = "Electronics";
  titles[4] = "Entertainment";
  titles[5] = "Health & Beauty";
  titles[6] = "Home & Lifestyle";
  titles[7] = "Toys & Gifts";

	gfloat widthPerCell = (SCREEN_WIDTH - (columns + 1)*columnGap)/columns ;
	gfloat heightPerCell = (SCREEN_HEIGHT - (rows + 1)*rowGap)/rows ;
	containerView = new UIView();
	for(gint i=0; i< columns * rows; i++){
		gfloat xPos = (i%columns)*(widthPerCell + columnGap) + columnGap;
		gfloat yPos = (i/columns)*(heightPerCell + rowGap) + rowGap;
		gridCards[i] = new CategoryCard();
		gridCards[i]->setupWith(bgImages[i], titles[i], widthPerCell, heightPerCell);
		gridCards[i]->setSize(widthPerCell, heightPerCell);
		gridCards[i]->setPosition(xPos, yPos);
		containerView->addSubView(gridCards[i]);
	}
	brightTransition(gridCards[0]->midLayer);  
}

GridView::GridView(const GridView& orig) {
}

GridView::~GridView() {
}

void GridView::didTapBigButton(UIView *view) {
  
}

void GridView::brightTransition(UIView* layer){
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

void GridView::dimTransition(UIView* layer){
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

void GridView::transitionDidFinish(CATimeline *timeline){
  if(!g_strcmp0((char*)timeline->getData("name"),"brighttransition")){
    UIView* actor = (UIView*)timeline->getData("actor");
    actor->removeAllTransition();
    actor->setData("transitionState", (char*)"off");
    dimTransition(actor);
    
    gint random = rand() % 8;  
    while(TRUE){
      if(g_strcmp0((char*)gridCards[random]->midLayer->getData("transitionState"), "on")){
        break;
      }
      random = rand() % 8;  
    }
    brightTransition(gridCards[random]->midLayer);
  }else if(!g_strcmp0((char*)timeline->getData("name"),"dimtransition")){
    UIView* actor = (UIView*)timeline->getData("actor");
    actor->setData("transitionState", (char*)"off");
    actor->removeAllTransition();
  }
}

void GridView::didProgress(CATimeline *timeline,int msecs){
}