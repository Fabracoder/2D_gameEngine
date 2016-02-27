#pragma once 
int main(void);
void loadTextures(GLuint *arr); 
bool drawGL_Stuff();
bool drawBackground(int *world,int x,int y, int w, int h);
bool drawSprites(int *localSprites[64]);
void gameLogic();
void loadBG_Textures(int *BGtextures[64]);
void drawTileSeg(int tileNumber, int locX, int locY, double  segX, double segY); 