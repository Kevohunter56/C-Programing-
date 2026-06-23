gcc main.c glad.c ^
-I./include ^
-I./glfw-3.4.bin.WIN64\include ^
-L./glfw-3.4.bin.WIN64\lib-mingw-w64 ^
-lglfw3 -lopengl32 -lgdi32 ^
-o app.exe