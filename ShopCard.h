/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShopCard.h
 * Author: hariharasudhan
 *
 * Created on February 20, 2016, 1:36 AM
 */

#ifndef SHOPCARD_H
#define SHOPCARD_H

#include <UIKit.h>

 typedef struct _ShopDetails{
 	const char *imagePath;
 	const char *title;
 	const char *description;
 	const char *openHours;
 	const char *phoneNumber;
 }ShopDetails;

class ShopCard: public UIView {
public:
    ShopCard(ShopDetails *details);
    ShopCard(const ShopCard& orig);
    virtual ~ShopCard();
    void layoutSubviews() override;
private:
	UIView *containerView;
	UIImageView *image;
	UILabel *title,*description,*phoneNumber,*openHours;
};

#endif /* SHOPCARD_H */

