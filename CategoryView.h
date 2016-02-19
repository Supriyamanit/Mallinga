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

#ifndef CATEGORYVIEW_H
#define CATEGORYVIEW_H
#include <glib.h>
#include <UIKit.h>
#include "CategoryCard.h"
#include "BrandGridView.h" 

class CategoryView : public UIView, public CategoryCardDelegate{
public:
	UIView *containerView;
    CategoryView(gint rows, gint columns);
    CategoryView(const CategoryView& orig);
    BrandGridView* buildBrandGrid(int i);
    void didTapBigButton(UIView *view);
    virtual ~CategoryView();
    CategoryCard *gridCards[15];
    gchar *bgImages[15];
    gchar *titles[15];
private:

};

#endif /* CATEGORYVIEW_H */

