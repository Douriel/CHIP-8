#pragma once
#include <cstdint>
#include <iostream>
#include <random>
#include "SDL.h"
#include <string>

using namespace std;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 255);

