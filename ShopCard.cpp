/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShopCard.cpp
 * Author: hariharasudhan
 * 
 * Created on February 20, 2016, 1:36 AM
 */

#include "ShopCard.h"
#include <UIKit.h>
#include <stdlib.h>

static void on_paint_cb(ClutterActor *actor) {
    gint hand_width, hand_height;
    hand_width = clutter_actor_get_width(actor);
    hand_height = clutter_actor_get_height(actor);
    cogl_path_round_rectangle(1,1,hand_width-2,hand_height-2,10,3);
    CoglColor *color = cogl_color_new();
    cogl_color_init_from_4f(color,0.95,0.95,0.95,1);
    cogl_set_source_color(color);
    cogl_path_fill();
    cogl_path_round_rectangle(1,1,hand_width-2,hand_height-2,10,3);
    cogl_clip_push_from_path();
    
}

static void on_post_paint_cb(void) {
    cogl_clip_pop();
}


static UILabel* getLabelWithText(const char *text){
    UILabel  *label  = new UILabel();
    label->setText(text);
    label->setFontWithSize("DIN Condensed,30px");
    label->setTextColor(UIColorFromRGB(0x434343));
    return label;
}

ShopCard::ShopCard(ShopDetails *details) {
    containerView = new UIView();
    g_signal_connect(containerView->view, "paint", G_CALLBACK(on_paint_cb), NULL);
    g_signal_connect_after(containerView->view, "paint", G_CALLBACK(on_post_paint_cb), NULL);
    this->addSubView(containerView);
    gfloat ypos = 1080*3/5;
    char imagePath[100];
    sprintf(imagePath,"images/shops/shoe.png");
    image = UIImageView::initWithImage(UIImage::imageNamed(imagePath));
    image->setSize(550,ypos);
    containerView->addSubView(image);
    image->setContentGravity(CLUTTER_CONTENT_GRAVITY_RESIZE_FILL);

    title = getLabelWithText(details->title);
    this->addSubView(title);
    title->setPosition(0,ypos);
}

ShopCard::ShopCard(const ShopCard& orig) {
}

ShopCard::~ShopCard() {
}

void ShopCard::layoutSubviews(){
    containerView->setSize(this->getSize());
}