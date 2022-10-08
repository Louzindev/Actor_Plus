#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define HAVE_STDINT_H
#include <iostream>
#include "sampgdk.h"
#include "amx/amx.h"
#include "plugincommon.h"


typedef void(*logprintf_t)(const char* format, ...);
extern logprintf_t logprintf;

#endif