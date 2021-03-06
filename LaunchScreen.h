/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LaunchScreen.h
 * Author: f22labs
 *
 * Created on 20 February, 2016, 8:47 AM
 */

#ifndef LAUNCHSCREEN_H
#define LAUNCHSCREEN_H
#include <glib.h>
#include <UIKit.h>
#include "constants.h" 

class LaunchScreen: public UITapGestureProtocol {
public:
    LaunchScreen();
    LaunchScreen(const LaunchScreen& orig);
    virtual ~LaunchScreen();
    void buildStartButton();
    void buildLogo();
    UIView* containerView;
    void didTapViewWithEvent(ClutterTapAction *event, UIView *view);
private:
	UIView* touchMe;
	UIView* mallLogo;

};

#endif /* LAUNCHSCREEN_H */

