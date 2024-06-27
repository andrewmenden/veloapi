#include <velo.hpp>

static int currentID = 1;
static int globalItemWidth = 70;

void veloPushID()
{
    ImGui::PushID(currentID++);
}
void veloPopID()
{
    ImGui::PopID();
}
void veloRenderLabel(const char* label, const char* tooltip)
{
    if (strlen(label) > 0)
    {
        ImGui::SameLine();
        ImGui::Text("%s", label);
    }
    if (ImGui::IsItemHovered() && strlen(tooltip) > 0)
    {
        ImGui::SetTooltip("%s", tooltip);
    }
}

static char* test = new char[MAX_STRING];
void veloRun()
{
    veloNewFrame();
    ImGui::Begin("testtest");
    veloRoundingMultiplier("test", test, "test");
    ImGui::End();
}

void veloSetItemWidth(int width)
{
    globalItemWidth = width;
}
bool veloRoundingMuliplierIsValid(char*& value)
{
    int i = 0;
    char c = value[0];
    bool decimalFound = false;
    while (c != '\0')
    {
        if (c == '.')
        {
            if (decimalFound)
                return false;
            decimalFound = true;
        }
        else if (c < '0' || c>'9')
            return false;
        c = value[++i];
    }
    return true;
}

void veloInit();
void veloShutdown();

void veloNewFrame()
{
    currentID = 1;
}

void veloBeginModule();
void veloEndModule();

bool veloCategory();

bool veloInt(const char* label, int& value, float speed, int min, int max, const char* format, const char* tooltip)
{
    ImGui::SetNextItemWidth(globalItemWidth);
    veloPushID();
    bool t =ImGui::DragInt("##veloInt", &value, speed, min, max, format);
    veloPopID();
    veloRenderLabel(label, tooltip);
    return t;
}
bool veloFloat(const char* label, float& value, float speed, float min, float max, const char* format, const char* tooltip)
{
    ImGui::SetNextItemWidth(globalItemWidth);
    veloPushID();
    bool t = ImGui::DragFloat("##veloFloat", &value, speed, min, max, format);
    veloPopID();
    veloRenderLabel(label, tooltip);
    return t;
}
bool veloBool(const char* label, bool& value, const char* tooltip)
{
    veloPushID();
    bool t = ImGui::Checkbox("##veloBool", &value);
    veloPopID();
    veloRenderLabel(label, tooltip);
    return t;
}
bool veloVector(const char* label, float& valueX, float& valueY, float stepSizeX, float stepSizeY, float minX, float maxX, float minY, float maxY, const char* tooltip)
{
    ImGui::SetNextItemWidth(globalItemWidth);
    veloPushID();
    bool t = ImGui::DragFloat("##veloVector1", &valueX, stepSizeX, minX, maxX, "%.2f");
    veloPopID();
    ImGui::SetNextItemWidth(globalItemWidth);
    veloPushID();
    ImGui::SameLine();
    t |= ImGui::DragFloat("##veloVector2", &valueY, stepSizeY, minY, maxY, "%.2f");
    veloPopID();
    veloRenderLabel(label, tooltip);
    return t;
}
bool veloString(const char* label, char*& value, const char* tooltip)
{
    ImGui::SetNextItemWidth(globalItemWidth);
    veloPushID();
    bool t = ImGui::InputText("##veloString", value, MAX_STRING);
    veloPopID();
    veloRenderLabel(label, tooltip);
    return t;
}

bool veloString(const char* label, char*& value, int maxLength, const char* tooltip)
{
    ImGui::SetNextItemWidth(globalItemWidth);
    veloPushID();
    bool t = ImGui::InputText("##veloString", value, maxLength);
    veloPopID();
    veloRenderLabel(label, tooltip);
    return t;
}

bool veloRoundingMultiplier(const char* label, char*& value, const char* tooltip)
{
    //ATTENTION: we copy the string every call, in order to roll back a bad change -- possibly, there is a better way to do this!
    char previous[MAX_STRING]{};
    strcpy(previous, value);
    bool t = true;
    ImGui::SetNextItemWidth(globalItemWidth);
    veloPushID();
    if (ImGui::InputText("##veloRoundingMultiplier", value, MAX_STRING))
    {
        if (!veloRoundingMuliplierIsValid(value))
        {
            strcpy(value, previous);
            t = false;
        }
    }
    veloPopID();
    veloRenderLabel(label, tooltip);    
    return t;
}
