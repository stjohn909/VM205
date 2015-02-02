CXX = g++

# Update these paths to match your installation
# You may also need to update the linker option rpath, which sets where to look for
# the SDL2 libraries at runtime to match your install
SDL_LIB = -L/usr/local/lib -lSDL2 -Wl,-rpath=/usr/local/lib
SDL_INCLUDE = -I/usr/local/include

BCM_LIB = -L/usr/local/lib -lbcm2835
BCM_INCLUDE = -I/usr/local/include

GLES_LIB = -L/opt/vc/lib -lGLESv2
GLES_INCLUDE = -I/opt/vc/include

LIBS = $(SDL_LIB) $(BCM_LIB) $(GLES_LIB)
INCS = -Iinclude $(SDL_INCLUDE) $(BCM_INCLUDE) $(GLES_INCLUDE)

# You may need to change -std=c++11 to -std=c++0x if your compiler is a bit older
CXXFLAGS = -Wall -c -std=c++11 $(INCS)
LDFLAGS = $(LIBS)
TARGET = vm205

SRCS = \
	src/main.cpp \
	src/Data.cpp \
	src/Trace.cpp \
	src/VM205.cpp \
	src/Viewer.cpp \
	src/Trigger.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $^ $(LDFLAGS) -o $@

clean:
	@$(RM) $(TARGET) $(OBJS)
