#pragma once
#include<iostream>
typedef void (*CALLBACK)(const char*);
void GetCallback(CALLBACK);
void FindName(const char* name);
