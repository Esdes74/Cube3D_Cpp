#ifndef MAIN_UTILS_H
# define MAIN_UTILS_H

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <SDL.h>
#include <SDL_opengl.h>

typedef struct S_SetupWindows
{
	SDL_Window		*window;
	ImGuiIO 		io;
	ImVec4			clear_color;
	SDL_GLContext	gl_context; 
}	SetupWindows;

int		setup(SetupWindows& S_SetupWindows);
void	handle_poll_events(SetupWindows& S_SetupWindows, bool &done);
void	start_frame(SetupWindows& S_SetupWindows);
void	main_loop(SetupWindows& S_SetupWindows);
void	render_frame(SetupWindows& S_SetupWindows);
void	cleanup(SetupWindows& S_SetupWindows);

#endif
