/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CategoryCard.h
 * Author: f22labs
 *
 * Created on 16 February, 2016, 4:54 PM
 */

#ifndef BRANDCARD_H
#define BRANDCARD_H
#include <UIKit.h>

class BrandCardDelegate {
public:
  virtual ~BrandCardDelegate() {}
  virtual void didTapBigButton(UIView *view) = 0;
};

class BrandCard : public UIView {
public:

    BrandCard();
    BrandCard(const BrandCard& orig);
    
    void setupWith(char *imageName, gfloat width, gfloat height);
    void touchBegan(ClutterEvent* event);
    void touchEnded(ClutterEvent* event);
    void setDelegate(BrandCardDelegate *delegate);
    BrandCardDelegate *delegate;
    UIView *midLayer;
    virtual ~BrandCard();
private:
    UIImageView *baseImage;
    UILabel *lblTitle;
};
#endif /* BRANDCARD_H */

