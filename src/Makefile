SRCFILES = repatcher.cpp
OBJFILES = $(SRCFILES:.cpp=.o)
OUTPUT = librepatcher.a

default:
	g++ -c $(SRCFILES) && ar cr $(OUTPUT) $(OBJFILES) && rm $(OBJFILES)

simplepatcher:
	g++ ../test/simple/loader.cpp -o ../test/simple/loader.exe -I. -L. -lraypatcher

gamepatcher:
	g++ ../test/raylib/loader.cpp -o ../test/raylib/loader.exe -I../test/raylib/include -I. -L. -L../test/raylib/lib  -L../test/raylib/ -lraypatcher -lraylib -lopengl32 -lgdi32 -lwinmm -lws2_32