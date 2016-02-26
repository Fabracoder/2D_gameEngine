/*********************************************************************
 How to compile this on different platforms:

 gcc Main.c DrawUtils.c `pkg-config --cflags --libs sdl2 gl glew` -o CFramework
*/
#define SDL_MAIN_HANDLED
#include<SDL.h>
#include<GL/glew.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include"DrawUtils.h" 
#include "Main.h"

/* Set this to true to force the game to exit */
char shouldExit = 0;

/* The previous frame's keyboard state */
unsigned char kbPrevState[SDL_NUM_SCANCODES] = {0};

/* The current frame's keyboard state */
const unsigned char* kbState = NULL;

/* position of the sprite */
int spritePos[2] = { 10, 10 };
int spriteBallPos[2] = { -100, -100 };

/* Texture for the sprite */
GLuint spriteTex;
GLuint spriteTex2;
GLuint spriteTexFireBall; 
GLuint textureArr[64];

/* World */
//int worldWidth = 400;
//int worldHeight = 400;
int world[400][400];

bool isFacingRight = true;
bool isFacingRightBall = true;

/* size of the sprite */
int spriteSize[2];

int main(void)
{
    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Could not initialize SDL. ErrorCode=%s\n", SDL_GetError());
        return 1;
    }
	 

    /* Create the window, OpenGL context */
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_Window* window = SDL_CreateWindow(
            "HW 2 for Oliver Seet",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            640, 480,
            SDL_WINDOW_OPENGL);
    if (!window) {
        fprintf(stderr, "Could not create window. ErrorCode=%s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_GL_CreateContext(window);

    /* Make sure we have a recent version of OpenGL */
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK) {
        fprintf(stderr, "Could not initialize glew. ErrorCode=%s\n", glewGetErrorString(glewError));
        SDL_Quit();
        return 1;
    }
    if (GLEW_VERSION_3_0) {
        fprintf(stderr, "OpenGL 3.0 or greater supported: Version=%s\n",
                 glGetString(GL_VERSION));
    } else {
        fprintf(stderr, "OpenGL max supported version is too low.\n");
        SDL_Quit();
        return 1;
    }

    /* Setup OpenGL state */
    glViewport(0, 0, 640, 480);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, 640, 480, 0, 0, 100);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    /* Load the texture */

	loadTextures(&textureArr);

    



	kbState = SDL_GetKeyboardState(NULL);


    /* The game loop */
    while (!shouldExit) {
        assert(glGetError() == GL_NO_ERROR);
        memcpy(kbPrevState, kbState, sizeof(kbPrevState));
        
        /* Handle OS message pump */
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    shouldExit = 1;
            }
        }
 			
        /* Game logic */

		gameLogic();

   


		drawGL_Stuff();

        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

			
		glDrawSprite(textureArr[0], spritePos[2], spritePos[3], spriteSize[0], spriteSize[1]);
		 
 
		if(isFacingRight)
			{
				glDrawSprite(textureArr[1], spritePos[0], spritePos[1], spriteSize[0], spriteSize[1]);
			}
			else
			{
				glDrawSprite(textureArr[2], spritePos[0], spritePos[1], spriteSize[0], spriteSize[1]);
			}
			
        /* Present to the player */
        SDL_GL_SwapWindow(window);
    }

    SDL_Quit();

    return 0;
}
 
bool drawGL_Stuff()
{
//	drawBackground(&world, camera.getX(), camera.getY(), camera.getW(), camera.getH());
//	drawSprites();

	return false;
}

bool drawBackground(int * world, int x, int y, int w, int h)
{ 
	return false;
}



bool drawSprites(int * localSprites)
{
	return false;
}

void gameLogic()
{
	if (kbState[SDL_SCANCODE_ESCAPE]) {
		shouldExit = 1;
	}

	if (kbState[SDL_SCANCODE_LEFT]) {
		if (spritePos[0]>0)
		{
			isFacingRight = false;
			spritePos[0] -= 1;

		}

	}
	if (kbState[SDL_SCANCODE_RIGHT]) {
		if (spritePos[0] < 610)
		{
			isFacingRight = true;
			spritePos[0] += 1;
		}
	}
	if (kbState[SDL_SCANCODE_UP]) {
		if (spritePos[1] > 0)
		{
			spritePos[1] -= 1;
		}
	}
	if (kbState[SDL_SCANCODE_DOWN]) {
		if (spritePos[1] < 430)
		{
			spritePos[1] += 1;
		}
	}
	if (kbState[SDL_SCANCODE_SPACE])
	{
		isFacingRightBall = isFacingRight;

		spriteBallPos[0] = spritePos[0];
		spriteBallPos[1] = spritePos[1];

	}

	if (isFacingRightBall)
	{
		spriteBallPos[0]++;
	}
	else
	{
		spriteBallPos[0]--;
	}
}

void drawTileSeg(char filename[], int locX, int locY, double segX, double segY)
{
}


void loadTextures(GLuint *arr)
{
	arr[0] = glTexImageTGAFile("fireball.tga", &spriteSize[0], &spriteSize[1]);
	arr[1] = glTexImageTGAFile("Mega-Man-transparent.tga", &spriteSize[0], &spriteSize[1]);
	arr[2] = glTexImageTGAFile("Mega-Man-transparentR.tga", &spriteSize[0], &spriteSize[1]);
	
}
 