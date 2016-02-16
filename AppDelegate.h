/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AppDelegate.h
 * Author: f22labs
 *
 * Created on 16 February, 2016, 12:23 PM
 */

#ifndef APPDELEGATE_H
#define APPDELEGATE_H
#include <UIKit.h>

class AppDelegate: public UIResponder {
public:
    AppDelegate();
    AppDelegate(const AppDelegate& orig);
    void didLaunchApplicationWithOption(int argc,char *argv[],UIApplication *superView);
    CGSize resizeScreen();
    virtual ~AppDelegate();
private:

};

#endif /* APPDELEGATE_H */

