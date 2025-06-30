export PATH := C:/w64devkit/bin:$(PATH)

CXX := C:/w64devkit/bin/g++

INCLUDES = -I./include/
LIBS = -lraylib -lwinmm -lgdi32

SRC_DIR = src
SOURCES = $(SRC_DIR)/*.cpp
TARGET = main.exe

all:
	$(CXX) $(INCLUDES) $(SOURCES) main.cpp $(LIBS) -o $(TARGET)

clean:
	del $(TARGET)
