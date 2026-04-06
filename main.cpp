// Dear ImGui: standalone example application for SDL2 + OpenGL
// (SDL is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)

// Learn about Dear ImGui:
// - FAQ                  https://dearimgui.com/faq
// - Getting Started      https://dearimgui.com/getting-started
// - Documentation        https://dearimgui.com/docs (same as your local docs/ folder).
// - Introduction, links and more at the top of imgui.cpp

#include "main_utils.h"

// Main code
int main(int ac, char** av)
{
	int	setup_result;
	struct S_SetupWindows S_SetupWindows;

	setup_result = setup(S_SetupWindows);
	if (setup_result != 0)
	{
		return setup_result;
	}

	// Main loop
	bool done = false;
	while (!done)
	{
		handle_poll_events(S_SetupWindows, done);
		if (SDL_GetWindowFlags(S_SetupWindows.window) & SDL_WINDOW_MINIMIZED)
		{
			SDL_Delay(10);
			continue;
		}

		start_frame(S_SetupWindows);

		main_loop(S_SetupWindows);

		render_frame(S_SetupWindows);
	}

	cleanup(S_SetupWindows);

	return 0;
}
