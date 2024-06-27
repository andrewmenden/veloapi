#ifndef VELO_HPP
#define VELO_HPP

#define VELOAPI __declspec(dllexport)
#define MAX_STRING 256 //ATTENTION: this is a placeholder value

#include <imgui.h>

//debug/internal
void veloRun();
void veloPushID();
void veloPopID();
void veloRenderLabel(const char* label, const char* tooltip);
void veloSetItemWidth(int width);
bool veloRoundingMuliplierIsValid(char*& value);

//startup/shutdown
void veloInit();
void veloShutdown();

//rendering/ui
void veloNewFrame();

void veloBeginModule();
void veloEndModule();

bool veloCategory();

bool veloInt(
    const char* label, 
    int& value, 
    float speed, 
    int min, 
    int max, 
    const char* format, 
    const char* tooltip
);

bool veloFloat(
    const char* label, 
    float& value, 
    float speed, 
    float min, 
    float max, 
    const char* format, 
    const char* tooltip
);

bool veloBool(
    const char* label, 
    bool& value, 
    const char* tooltip
);

bool veloToggle(); //TODO

bool veloHotkey(); //TODO

bool veloVector(
    const char* label, 
    float& valueX, 
    float& valueY, 
    float stepSizeX,  
    float stepSizeY, 
    float minX, 
    float maxX, 
    float minY, 
    float maxY, 
    const char* tooltip
);

bool veloString(
    const char* label, 
    char*& value, 
    const char* tooltip
);

bool veloString(
    const char* label, 
    char*& value, 
    int maxLength,
    const char* tooltip
);

bool veloRoundingMultiplier(
    const char* label,
    char*& value,
    const char* tooltip    
);

bool veloBoolList();
bool veloStringList();
bool veloEnumerator();
bool veloColor();
bool veloColorTransition();
bool veloInputBox();

//imgui wrappers

#endif // VELO_HPP