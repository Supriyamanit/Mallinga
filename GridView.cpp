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

#include "GridView.h"
#include "constants.h"
gfloat columnGap = 10.0;
gfloat rowGap = 10.0;

GridView::GridView(gint rows, gint columns) {
	gfloat widthPerCell = (SCREEN_WIDTH - (columns + 1)*columnGap)/columns ;
	gfloat heightPerCell = (SCREEN_HEIGHT - (rows + 1)*rowGap)/rows ;
	containerView = new UIView();
	UIView *GridCards[columns * rows];
	for(gint i=0; i< columns * rows; i++){
		gfloat xPos = (i%columns)*(widthPerCell + columnGap) + columnGap;
		gfloat yPos = (i/columns)*(heightPerCell + rowGap) + rowGap;
		GridCards[i] = new UIView();
		GridCards[i]->setSize(widthPerCell, heightPerCell);
		GridCards[i]->setPosition(xPos, yPos);
		GridCards[i]->setBackgroundColor(CLUTTER_COLOR_Red);
		containerView->addSubView(GridCards[i]);
	}
}

GridView::GridView(const GridView& orig) {
}

GridView::~GridView() {
}

