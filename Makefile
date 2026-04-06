CXX = g++

NAME := example_sdl2_opengl3

IMGUI_DIR := lib_imgui/

OBJ_DIR := .obj/
BACKENDS_DIR := $(IMGUI_DIR)backends/

SOURCES =	imgui.cpp \
			imgui_demo.cpp \
			imgui_draw.cpp \
			imgui_tables.cpp \
			imgui_widgets.cpp \
			main_utils.cpp

BACKENDS_SOURCES =	imgui_impl_sdl2.cpp \
					imgui_impl_opengl3.cpp

SRC = $(addprefix $(IMGUI_DIR), $(SOURCES))
SRC += $(addprefix $(BACKENDS_DIR), $(BACKENDS_SOURCES))
SRC += main.cpp

OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(basename $(notdir $(SRC)))))
UNAME_S := $(shell uname -s)
LINUX_GL_LIBS = -lGL

CXXFLAGS = -I$(IMGUI_DIR) -I$(IMGUI_DIR)backends `sdl2-config --cflags`
CXXFLAGS += -g -Wall -Wformat
LIBS = $(LINUX_GL_LIBS) -ldl `sdl2-config --libs`
CFLAGS = $(CXXFLAGS)

#
### BUILD RULES
#

all: mkdir $(NAME)
	@echo Build complete for $(ECHO_MESSAGE)

$(OBJ_DIR)%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)%.o:$(IMGUI_DIR)%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)%.o:$(BACKENDS_DIR)%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

mkdir:
	@mkdir -p $(OBJ_DIR)

clean:
	rm -f $(NAME) $(OBJS)
