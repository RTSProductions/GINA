build:
	clang++ --std=c++17 src/*.cpp -o GINA -I/usr/local/Cellar/raylib/4.5.0/include/ -L/usr/local/Cellar/raylib/4.5.0/lib/ -I/usr/local/Cellar/bullet/3.25/include/bullet/ -L/usr/local/Cellar/bullet/3.25/lib/ -lraylib -lBulletCollision -lBulletDynamics -lLinearMath -framework IOKit -framework Cocoa -framework OpenGL -I/usr/local/Cellar/glm/0.9.9.8/include/ -L/usr/local/Cellar/glm/0.9.9.8/lib/ 

build-app:
	clang++ --std=c++17 src/*.cpp -o GINA.app -I/usr/local/Cellar/raylib/4.5.0/include/ -L/usr/local/Cellar/raylib/4.5.0/lib/ -I/usr/local/Cellar/bullet/3.25/include/bullet/ -L/usr/local/Cellar/bullet/3.25/lib/ -lraylib -lBulletCollision -lBulletDynamics -lLinearMath -framework IOKit -framework Cocoa -framework OpenGL -I/usr/local/Cellar/glm/0.9.9.8/include/ -L/usr/local/Cellar/glm/0.9.9.8/lib/ 
