###########################################################
#                     Main project                        #
###########################################################
MAIN := Motor

LIBRAIRY_DIR := lib/
IMGUI_DIR := $(LIBRAIRY_DIR)lib_imgui/

OBJ_DIR := .obj/
BACKENDS_DIR := $(IMGUI_DIR)backends/
OPTIONS_DIR := $(LIBRAIRY_DIR)options/
CLI_DIR := $(LIBRAIRY_DIR)cli/

IMGUI_SOURCES =	imgui.cpp \
				imgui_demo.cpp \
				imgui_draw.cpp \
				imgui_tables.cpp \
				imgui_widgets.cpp \
				main_utils.cpp

BACKENDS_SOURCES =	imgui_impl_sdl2.cpp \
					imgui_impl_opengl3.cpp

SRC = $(addprefix $(IMGUI_DIR), $(IMGUI_SOURCES))
SRC += $(addprefix $(BACKENDS_DIR), $(BACKENDS_SOURCES))
SRC +=	main.cpp

OBJS =	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(basename $(notdir $(SRC)))))

IMGUI_HEADEARS :=	main_utils.h

OPTIONS_HEADERS :=	Options.hpp

CLI_HEADERS :=	Cli.hpp \
				Utils.hpp

HDS = $(addprefix $(IMGUI_DIR), $(IMGUI_HEADEARS))
HDS += $(addprefix $(OPTIONS_DIR), $(OPTIONS_HEADERS))
HDS += $(addprefix $(CLI_DIR), $(CLI_HEADERS))

###########################################################
#                     Test project                        #
###########################################################
TEST := Tests

TESTS_DIR := tests/
TESTS_OBJ_DIR := $(TESTS_DIR).obj/
TESTS_LIBRAIRY_DIR := $(TESTS_DIR)lib/

TESTS_SOURCES :=	tests.cpp

TESTS_HEADERS :=	AbstractTest.hpp \
					CliTest.hpp \
					OptionTest.hpp

HEADERS :=	$(addprefix $(TESTS_LIBRAIRY_DIR), $(TESTS_HEADERS))

TESTS_OBJ =	$(addprefix $(TESTS_OBJ_DIR), \
			$(addsuffix .o, $(basename $(notdir $(TESTS_SOURCES)))))

###########################################################
#                   Global variables                      #
###########################################################

CXX = g++

LINUX_GL_LIBS = -lGL

INCLUDES :=	-I$(IMGUI_DIR) \
			-I$(BACKENDS_DIR) \
			-I$(OPTIONS_DIR) \
			-I$(CLI_DIR)

CXXFLAGS = $(INCLUDES) `sdl2-config --cflags`
CXXFLAGS += -g -Wall -Wformat
LIBS = $(LINUX_GL_LIBS) -ldl `sdl2-config --libs`

###########################################################
#                     Builds rules                        #
###########################################################

#
### MAIN
#

all: mkdir $(MAIN)

$(OBJ_DIR)%.o: %.cpp $(HDS)
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)%.o: $(IMGUI_DIR)%.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)%.o: $(BACKENDS_DIR)%.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

$(MAIN): $(OBJS)
	@$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)
	@echo Build complete for main project

#
### TESTS
#

tests: mkdir $(MAIN) $(TEST)

$(TESTS_OBJ_DIR)%.o: $(TESTS_DIR)%.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -Itests/lib/ -c -o $@ $<

$(TEST): $(TESTS_OBJ)
	@$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)
	@echo Tests build complete

#
### Global
#

mkdir:
	@mkdir -p $(OBJ_DIR) $(TESTS_OBJ_DIR)

clean:
	@rm -f $(MAIN) $(OBJS)

re: clean all

.PHONY: all mkdir clean re tests