#ifndef NETWORKPROGRAM_INITSCREEN_H
#define NETWORKPROGRAM_INITSCREEN_H
#include <gtk/gtk.h>
#include "applicationScreen.h"
#include "handleLogicHomeScreen.h"
#include "handleLogicLoginScreen.h"
#include "handleLogicRegisterScreen.h"
#include "handleLogicGameScreen.h"
#include "handleLogicMainScreen.h"

void initHomeScreen(UserData *userData);
void initLoginScreen(UserData *userData);
void initRegisterScreen(UserData *userData);
void initGameScreen(UserData *userData);
void initMainScreen(UserData *userData);
void initApplication(UserData *userData);
#endif
