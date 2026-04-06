#ifndef MAIN_UTILS_H
# define MAIN_UTILS_H

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <SDL.h>
#include <SDL_opengl.h>

struct S_SetupWindows
{
	SDL_Window		*window;
	ImGuiIO 		io;
	ImVec4			clear_color;
	SDL_GLContext	gl_context; 
};

int		setup(struct S_SetupWindows S_SetupWindows);
void	handle_poll_events(struct S_SetupWindows S_SetupWindows, bool &done);
void	start_frame(struct S_SetupWindows S_SetupWindows);
void	main_loop(struct S_SetupWindows S_SetupWindows);
void	render_frame(struct S_SetupWindows S_SetupWindows);
void	cleanup(struct S_SetupWindows S_SetupWindows);

#endif
