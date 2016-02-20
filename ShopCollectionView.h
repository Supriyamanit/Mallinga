/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShopCollectionView.h
 * Author: hariharasudhan
 *
 * Created on February 20, 2016, 5:30 AM
 */

#ifndef SHOPCOLLECTIONVIEW_H
#define SHOPCOLLECTIONVIEW_H

 #include <UIKit.h>
 #include "ShopCard.h"

class ShopCollectionView: public UIView {
public:
    ShopCollectionView();
    ShopCollectionView(const ShopCollectionView& orig);
    virtual ~ShopCollectionView();
private:
	UIBoxLayout *boxLayout;
	ShopCard *card[10];
};

#endif /* SHOPCOLLECTIONVIEW_H */

