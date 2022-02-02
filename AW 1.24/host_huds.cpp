#include "host_huds.h"
#include "functions.h"

Hud::Hud(game_hudelem_s* elem) {
    Element = elem;
}

game_hudelem_s* precacheElem(int clientId) {
    game_hudelem_s* elem = HudElem_Alloc(clientId, 0);
    elem->ClientNum = clientId;
    return elem;
}

void Hud::setShader(const char* shader, int width, int height, float x, float y, int alignOrg, int alignScreen, float sort, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    Element->elem.type = 0x4;
    Element->elem.alignOrg = alignOrg;
    Element->elem.alignScreen = alignScreen;
    Element->elem.x = x;
    Element->elem.y = y;
    Element->elem.color.r = r;
    Element->elem.color.g = g;
    Element->elem.color.b = b;
    Element->elem.color.a = a;
    Element->elem.Width = width;
    Element->elem.Height = height;
    Element->elem.sort = sort;
    Element->elem.MaterialIndex = G_MaterialIndex(shader);
}
void Hud::setText(char* text, int font, float fontScale, float x, float y, int alignOrg, int alignScreen, float sort, unsigned char r, unsigned char g, unsigned char b, unsigned char a, unsigned char glowR, unsigned char glowG, unsigned char glowB, unsigned char glowA) {
    Element->elem.type = 1;
    Element->elem.font = font;
    Element->elem.FontScale = fontScale;
    Element->elem.alignOrg = alignOrg;
    Element->elem.alignScreen = alignScreen;
    Element->elem.x = x;
    Element->elem.y = y;
    Element->elem.color.r = r;
    Element->elem.color.g = g;
    Element->elem.color.b = b;
    Element->elem.color.a = a;
    Element->elem.glowColor.r = glowR;
    Element->elem.glowColor.g = glowG;
    Element->elem.glowColor.b = glowB;
    Element->elem.glowColor.a = glowA;
    Element->elem.sort = sort;
    Element->elem.text = G_LocalizedStringIndex(text);
    Element->elem.targetent1 = 1;
    Element->elem.targetent2 = 1;
}
void Hud::moveOverTime(float time, float x, float y)
{
    Element->elem.fromX = Element->elem.x;
    Element->elem.fromY = Element->elem.y;
    Element->elem.moveStartTime = Leveltime;
    Element->elem.moveTime = time;
    Element->elem.x = x;
    Element->elem.y = y;
}
void Hud::setY(float y)
{
    Element->elem.y = y;
}
void Hud::changeText(const char* text)
{
    Element->elem.text = G_LocalizedStringIndex(text);
}
void Hud::scaleOverTime(float time, float width, float height) {

    Element->elem.fromWidth = Element->elem.Width;
    Element->elem.fromHeight = Element->elem.Height;
    Element->elem.scaleStartTime = Leveltime;
    Element->elem.scaleTime = time;
    Element->elem.Width = width;
    Element->elem.Height = height;
}

void Hud::fadeOverTime(int time, float red, float green, float blue, float alpha)
{
    Element->elem.fromColor = Element->elem.color;
    Element->elem.fadeStartTime = Leveltime;
    Element->elem.fadeTime = time;
    Element->elem.color.r = red;
    Element->elem.color.g = green;
    Element->elem.color.b = blue;
    Element->elem.color.a = alpha;
}

void Hud::setColor(char r, char g, char b, char a, bool isGlow)
{
    if (isGlow) {
        Element->elem.glowColor.r = r;
        Element->elem.glowColor.g = g;
        Element->elem.glowColor.b = b;
        Element->elem.glowColor.a = a;
    }
    else {
        Element->elem.color.r = r;
        Element->elem.color.g = g;
        Element->elem.color.b = b;
        Element->elem.color.a = a;
    }

}

void Hud::typeWriterText(char* text)
{
    changeText(text);
    Element->elem.fxBirthTime = Leveltime;
    Element->elem.fxLetterTime = 100;
    Element->elem.fxDecayStartTime = 7000;
    Element->elem.fxDecayDuration = 1000;
    Element->elem.flags |= 0x4;
}