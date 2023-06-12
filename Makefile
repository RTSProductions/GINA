build:
	clang++ --std=c++17 *.cpp -o GINA -I/usr/local/Cellar/raylib/4.5.0/include/ -L/usr/local/Cellar/raylib/4.5.0/lib/ -lraylib -framework IOKit -framework Cocoa -framework OpenGL -I/usr/local/Cellar/glm/0.9.9.8/include/ -L/usr/local/Cellar/glm/0.9.9.8/lib/ 

build-app:
	clang++ --std=c++17 *.cpp -o GINA.app -I/usr/local/Cellar/raylib/4.5.0/include/ -L/usr/local/Cellar/raylib/4.5.0/lib/ -lraylib -framework IOKit -framework Cocoa -framework OpenGL -I/usr/local/Cellar/glm/0.9.9.8/include/ -L/usr/local/Cellar/glm/0.9.9.8/lib/ 
