## 1. Setup development environment - macOS and Ubuntu

### How to Install required libraries  

1. Go to [LAB03](http://prod3.imt.hig.no/imt2531/imt2531_lectures/tree/master/lab03).
2. Copy the `GLFW/`, `GLEW/`, and `GLM/` to the root directory of project.
3. Download `stb_image.h` form [here](https://github.com/nothings/stb/blob/master/stb_image.h) and place it in `stb/stb_image.h`.

### How to run python tool

Make sure you have `python3` correctly installed
```
$ /usr/local/bin/python3 --version
Python 3.6.4
```
To run `./exec.py`
```
$ ./exec.py --help
usage: exec.py [-h] [-r]

optional arguments:
  -h, --help  show this help message and exit
  -r, --run   run only
```



## 2. References

glBufferSubData - https://www.khronos.org/opengl/wiki/Buffer_Object#Data_Specification - 04.02.18 <br>
Texture/texture-blending tutorial - https://learnopengl.com/Getting-started/Textures 04.02.18 <br>
Texturing a cube - http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/ - 04.02.18 <br>
Texture kittens OpenGL tutorial - https://open.gl/textures - 04.02.18 <br>
Texture sampler GLSL - https://www.khronos.org/opengl/wiki/Sampler_(GLSL)#Binding_textures_to_samplers - 03.02.18 <br>
VBO's and VAO's  - http://headerphile.com/sdl2/opengl-part-2-vertexes-vbos-and-vaos/ - 02.02.18