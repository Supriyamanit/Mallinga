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
    cogl_color_init_from_4f(color,1,1,1,1);
    cogl_set_source_color(color);
    cogl_path_fill();
    cogl_path_round_rectangle(1,1,hand_width-2,hand_height-2,10,3);
    cogl_clip_push_from_path();
    
}

static void on_post_paint_cb(void) {
    cogl_clip_pop();
}

ShopCard::ShopCard() {
	g_signal_connect(containerView->view, "paint", G_CALLBACK(on_paint_cb), NULL);
    g_signal_connect_after(containerView->view, "paint", G_CALLBACK(on_post_paint_cb), NULL);
}

ShopCard::ShopCard(const ShopCard& orig) {
}

ShopCard::~ShopCard() {
}

