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
class GridView {
public:
		UIView *containerView;
    GridView(gint rows, gint columns);
    GridView(const GridView& orig);
    virtual ~GridView();
private:

};

#endif /* GRIDVIEW_H */

