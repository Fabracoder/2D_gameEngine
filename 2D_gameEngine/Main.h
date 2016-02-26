#pragma once 
int main(void);
void loadTextures(GLuint *arr); 
bool drawGL_Stuff();
bool drawBackground(int *world,int x,int y, int w, int h);
bool drawSprites(int *localSprites);
void gameLogic();
void drawTileSeg(char  filename[], int locX, int locY, double  segX, double segY); 