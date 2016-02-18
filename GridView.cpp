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
    gridCards[i]->setData("index", GINT_TO_POINTER(i));
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

BrandGridView* GridView::buildBrandGrid(int i){
  switch(i){
    case 0: 
      return new BrandGridView(4,5);
      break;
  }
}

void GridView::brightTransition(UIView* layer){
  CATransition* rotateTransition = new CATransition("opacity");
  rotateTransition->setFromValue(G_TYPE_INT, layer->getOpacity());
  rotateTransition->setToValue(G_TYPE_INT, 0);
  rotateTransition->setDuration(3000);
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
  rotateTransition->setDuration(3000);
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