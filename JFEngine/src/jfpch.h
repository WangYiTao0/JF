#pragma once
#include "JF/Core/PlatformDetection.h"

#ifdef JF_PLATFORM_WINDOWS
#ifndef NOMINMAX
// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
#define NOMINMAX
#endif
#endif



#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <fstream>
#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "JF/Core/Base.h"

#include "JF/Core/Log.h"

#include "JF/Debug/Instrumentor.h"

#ifdef JF_PLATFORM_WINDOWS
	#include <Windows.h>
#endif