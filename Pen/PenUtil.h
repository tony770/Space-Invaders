#pragma once

#define START_PEN_GAME(GameClass) \
	int main() \
	{ \
		GameClass __pen__game;\
		__pen__game.Run();\
		return 0;\
	}\

#ifdef PEN_WINDOWS
	#ifdef PEN_LIB
		#define PEN_API __declspec(dllexport)
	#else
		#define PEN_API __declspec(dllimport)
	#endif
#else  
	#define PEN_API
#endif

#ifdef PEN_DEBUG
	#define PEN_LOG(x) std::cout << x << std::endl;
#else
	#define PEN_LOG(x)
#endif