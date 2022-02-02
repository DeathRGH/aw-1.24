#pragma once

#define Leveltime *(int*)(0x6395980 + 0x4EC)

union hudelem_color_t
{
    struct
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    };
    int rgba;
};

struct hudelem_s
{
    short targetent1;
    short targetent2;
    int font;
    int alignOrg;
    int alignScreen;
    float x;
    float y;
    float z;
    int type;
    float FontScale;
    int FromFontScale;
    int FontScaleStartTime;
    int FontScaleTime;
    hudelem_color_t color;
    hudelem_color_t fromColor;
    int fadeStartTime;
    int fadeTime;
    int label;
    int Width;
    int Height;
    int MaterialIndex;
    int fromWidth;
    int fromHeight;
    int moveStartTime;
    int moveTime;
    float fromX;
    float fromY;
    int fromAlignOrg;
    int fromAlignScreen;
    int scaleStartTime;
    int scaleTime;
    int time;
    int duration;
    float value;
    int text;
    float sort;
    hudelem_color_t glowColor;
    int fxBirthTime;
    int fxLetterTime;
    int fxDecayStartTime;
    int fxDecayDuration;
    int soundID;
    int unknown;
    int flags;
};

struct game_hudelem_s
{
    hudelem_s elem;
    int ClientNum;
    int team;
    int archived;
    int showInKillcam;
};

struct Hud {
    Hud(game_hudelem_s* Element);
    void setShader(const char* shader, int width, int height, float x, float y, int alignOrg, int alignScreen, float sort, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    void setText(char* text, int font, float fontScale, float x, float y, int alignOrg, int alignScreen, float sort, unsigned char r, unsigned char g, unsigned char b, unsigned char a, unsigned char glowR, unsigned char glowG, unsigned char glowB, unsigned char glowA);
    void moveOverTime(float time, float x, float y);
    void setY(float y);
    void changeText(const char* text);
    void scaleOverTime(float time, float width, float height);
    void fadeOverTime(int time, float red, float green, float blue, float alpha);
    void setColor(char r, char g, char b, char a, bool isGlow);
    void typeWriterText(char* text);
    game_hudelem_s* Element;
};

extern game_hudelem_s* precacheElem(int clientId);

typedef struct hudelem_s* hudelem_t;
typedef struct game_hudelem_s* game_hudelem_t;