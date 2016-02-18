/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GridView.h
 * Author: f22labs
 *
 * Created on 16 February, 2016, 12:38 PM
 */

#ifndef GRIDVIEW_H
#define GRIDVIEW_H
#include <glib.h>
#include <UIKit.h>
#include "CategoryCard.h"
 #include "BrandGridView.h"

class GridView : public UIView, public CategoryCardDelegate, public CATimelineProtocol {
public:
	UIView *containerView;
    GridView(gint rows, gint columns);
    GridView(const GridView& orig);
    BrandGridView* buildBrandGrid(int i);
    void didTapBigButton(UIView *view);
    void transitionDidFinish(CATimeline *timeline);
    void didProgress(CATimeline *timeline,int msecs);
    void brightTransition(UIView *view);
    void dimTransition(UIView *view);
    virtual ~GridView();
    CategoryCard *gridCards[8];
    gchar *bgImages[8];
    gchar *titles[8];
private:

};

#endif /* GRIDVIEW_H */

