#include "SDL.h" 
#include "glad/glad.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
		exit(1);
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
	SDL_Window* window = SDL_CreateWindow("main", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 460, SDL_WINDOW_OPENGL);
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	(void)glContext;
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		cout << "Failed to initialize the OpenGL context." << endl;
		exit(1);
	}
	cout << "OpenGL " << GLVersion.major << "." << GLVersion.minor << endl;
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	bool quit = false;
	while (!quit) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);
	}
	SDL_Quit();
	return 0;
}