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

#ifndef BRANDGRIDVIEW_H
#define BRANDGRIDVIEW_H
#include <glib.h>
#include <UIKit.h>
#include "BrandCard.h"

class BrandGridView : public UIView, public CATimelineProtocol {
public:

	UIView *containerView;
    BrandGridView(gint rows, gint columns);
    BrandGridView(const BrandGridView& orig);
    void transitionDidFinish(CATimeline *timeline);
    void didProgress(CATimeline *timeline,int msecs);
    void brightTransition(UIView *view);
    void dimTransition(UIView *view);
    virtual ~BrandGridView();
    BrandCard *gridCards[100];
    gchar *bgImages[8][20];
    gchar *titles[8][20];
private:

};

#endif /* BRANDGRIDVIEW_H */

