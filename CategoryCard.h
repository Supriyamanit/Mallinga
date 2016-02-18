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

#ifndef CATEGORYCARD_H
#define CATEGORYCARD_H
#include <UIKit.h>

class CategoryCardDelegate {
public:
  virtual ~CategoryCardDelegate() {}
  virtual void didTapBigButton(UIView *view) = 0;
};

class CategoryCard : public UIView {
public:
    CategoryCard();
    CategoryCard(const CategoryCard& orig);
    
    void setupWith(char *imageName, char *title, gfloat width, gfloat height);
    void touchBegan(ClutterEvent* event);
    void touchEnded(ClutterEvent* event);
    void setDelegate(CategoryCardDelegate *delegate);
    CategoryCardDelegate *delegate;
    UIView *midLayer;
    void layoutSubviews() override;
    virtual ~CategoryCard();
private:
    UIImageView *baseImage;
    UILabel *lblTitle;
};
#endif /* CATEGORYCARD_H */

