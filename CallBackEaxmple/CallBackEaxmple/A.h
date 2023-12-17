#pragma once
#include <iostream>

typedef void (*INTEFACE)(const char*);
void GetInteface(INTEFACE);
void MakeFriends();
void SayHi(const char*);