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
#include "BrandGridView.h"
#include "constants.h"
#include "CategoryCard.h"
static gfloat columnGap = 5.0;
static gfloat rowGap = 5.0;

GridView::GridView(gint rows, gint columns) {

	bgImages[0] = "images/apparel/1.jpg";
  bgImages[1] = "images/accesories-and-footwear/1.jpg";
  bgImages[2] = "images/health-and-beauty/1.jpg";
  bgImages[3] = "images/home-and-lifestyle/1.jpg";
  bgImages[4] = "images/electronics/1.jpg";
  bgImages[5] = "images/toys-and-gifts/1.jpg";
	bgImages[6] = "images/dining/1.jpg";
  bgImages[7] = "images/entertaitment/1.jpg";
  
  titles[0] = "Apparel";
  titles[1] = "Accessories & Footwear";
  titles[2] = "Health & Beauty";
  titles[3] = "Home & Lifestyle";
  titles[4] = "Electronics";
  titles[5] = "Toys & Gifts";
  titles[6] = "Dining";
  titles[7] = "Entertainment";

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
    gridCards[i]->setDelegate(this);
	}
	brightTransition(gridCards[0]->midLayer);  
}

GridView::GridView(const GridView& orig) {
}

GridView::~GridView() {
}

void GridView::didTapBigButton(UIView *view) {
  
  for(int i=0; i<8; i++){
    gridCards[i]->midLayer->removeAllTransition();
    gridCards[i]->midLayer->setData("transitionState", (char*)"off");
  }
	
  for(int i=0; i<8; i++){
    
    gfloat width = gridCards[i]->getWidth();
    gfloat height = gridCards[i]->getHeight();
    CATransition* scaleDownXTransition = new CATransition("scale-x");
    scaleDownXTransition->setFromValue(G_TYPE_DOUBLE, 1.0);
    scaleDownXTransition->setToValue(G_TYPE_DOUBLE, 0.25);
    scaleDownXTransition->setDuration(250);
    scaleDownXTransition->setRemoveOnComplete(TRUE);
    
    CATransition* scaleDownYTransition = new CATransition("scale-y");
    scaleDownYTransition->setFromValue(G_TYPE_DOUBLE, 1.0);
    scaleDownYTransition->setToValue(G_TYPE_DOUBLE, 0.25);
    scaleDownYTransition->setDuration(250);
    scaleDownYTransition->setRemoveOnComplete(TRUE);

    CATransition* positionChangeTransition = new CATransition("x");
    positionChangeTransition->setFromValue(G_TYPE_INT, gridCards[i]->getPosition().x);
    positionChangeTransition->setToValue(G_TYPE_INT, 10);
    positionChangeTransition->setDuration(250);
    positionChangeTransition->setRemoveOnComplete(TRUE);

    CATransition* positionYChangeTransition = new CATransition("y");
    positionYChangeTransition->setFromValue(G_TYPE_INT, gridCards[i]->getPosition().y);
    positionYChangeTransition->setToValue(G_TYPE_INT, (SCREEN_HEIGHT - 20)/8*i +10);
    positionYChangeTransition->setDuration(250);
    positionYChangeTransition->setRemoveOnComplete(TRUE);
    
    gridCards[i]->addTransition(scaleDownXTransition, "scale-down-x");
    gridCards[i]->addTransition(scaleDownYTransition, "scale-down-y");
    gridCards[i]->addTransition(positionChangeTransition, "move-x");
    gridCards[i]->addTransition(positionYChangeTransition, "move-y");
	}

  BrandGridView *brandGrid = new BrandGridView(5,5);
  
  containerView->addSubView(brandGrid->containerView);
  brandGrid->containerView->setPosition(200,0);
}


void GridView::brightTransition(UIView* layer){
  CATransition* rotateTransition = new CATransition("opacity");
  rotateTransition->setFromValue(G_TYPE_INT, layer->getOpacity());
  rotateTransition->setToValue(G_TYPE_INT, 0);
  rotateTransition->setDuration(100);
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
  rotateTransition->setDuration(100);
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