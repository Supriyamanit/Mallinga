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

class LaunchScreen {
public:
    LaunchScreen();
    LaunchScreen(const LaunchScreen& orig);
    virtual ~LaunchScreen();
    UIView* containerView;
private:
	UIView* touchMe;

};

#endif /* LAUNCHSCREEN_H */

