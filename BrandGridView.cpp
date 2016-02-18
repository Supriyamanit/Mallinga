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

	bgImages[0][0] = "images/brands/apparel/allen.jpg";
  bgImages[0][1] = "images/brands/apparel/zara.png";
  bgImages[0][2] = "images/brands/apparel/arrow.jpg";
  bgImages[0][3] = "images/brands/apparel/biba.jpg";
  bgImages[0][4] = "images/brands/apparel/chemistry.jpg";
  bgImages[0][5] = "images/brands/apparel/fab.jpg";
	bgImages[0][6] = "images/brands/apparel/levis.png";
  bgImages[0][7] = "images/brands/apparel/lifestyle.png";
  bgImages[0][8] = "images/brands/apparel/lee.jpg";
  bgImages[0][9] = "images/brands/apparel/marks.png";
  bgImages[0][10] = "images/brands/apparel/max.jpg";
  bgImages[0][11] = "images/brands/apparel/kappa.jpg";
  bgImages[0][12] = "images/brands/apparel/peter.png";
  bgImages[0][13] = "images/brands/apparel/tommy.jpg";
	bgImages[0][14] = "images/brands/apparel/ucb.png";
  bgImages[0][15] = "images/brands/apparel/uspa.jpg";
  bgImages[0][16] = "images/brands/apparel/van.jpg";
  bgImages[0][17] = "images/brands/apparel/vero.jpg";
  bgImages[0][18] = "images/brands/apparel/w.jpg";
  bgImages[0][19] = "images/brands/apparel/westside.jpg";

	
	gfloat heightPerCell = (SCREEN_HEIGHT - (rows + 1)*rowGap)/rows ;
  gfloat widthPerCell = 1.618 * heightPerCell ;
	containerView = new UIView();
	for(gint i=0; i< columns * rows; i++){
		gfloat xPos = (i%columns)*(widthPerCell + columnGap) + columnGap;
		gfloat yPos = (i/columns)*(heightPerCell + rowGap) + rowGap;
		gridCards[i] = new BrandCard();
		gridCards[i]->setupWith(bgImages[0][i%20], widthPerCell, heightPerCell);
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
    
    gint random = rand() % 20;  
    while(TRUE){
      if(g_strcmp0((char*)gridCards[random]->midLayer->getData("transitionState"), "on")){
        break;
      }
      random = rand() % 20;  
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