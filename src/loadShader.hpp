#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "GL/glew.h"

#include "./logger.h"

namespace ost {
//
// COPY PASTE FROM LAB03 (with minor modification)
//
GLuint loadAndCompileShader(const char* fname, GLenum shaderType) {
    // Load a shader from an external file
    std::vector<char> buffer;
    {

        std::ifstream in;
        in.open(fname, std::ios::binary);

        if (in.fail()) {
            LOG_ERROR("in.fail() is true on file %s", fname);
        }
        // Get the number of bytes stored in this file
        in.seekg(0, std::ios::end);
        size_t length = (size_t)in.tellg();

        // Go to start of the file
        in.seekg(0, std::ios::beg);

        // Read the content of the file in a buffer
        buffer.resize(length + 1);
        in.read(&buffer[0], length);
        in.close();
        // Add a valid C - string end
        buffer[length] = '\0';
    }
    const char* src = &buffer[0];

    // Create shaders
    GLuint shader = glCreateShader(shaderType);
    {
        //attach the shader source code to the shader objec
        glShaderSource(shader, 1, &src, NULL);

        // Compile the shader
        glCompileShader(shader);
        // Comile the shader, translates into internal representation and checks for errors.
        GLint compileOK;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compileOK);
        if (!compileOK) {
            char infolog[1024];
            glGetShaderInfoLog(shader, 1024, NULL, infolog);
            glfwTerminate();
            getchar();

            char errormsg[80 + std::strlen(infolog)];
            snprintf(errormsg, 1024, "%s - %s\n", "The program failed to compile with the error:", infolog);
            LOG_ERROR(errormsg);
        }
    }
    return shader;
}

GLuint loadShaderProgram(const char* path_vert_shader, const char* path_frag_shader) {
    // Load and compile the vertex and fragment shaders
    GLuint vertexShader = loadAndCompileShader(path_vert_shader, GL_VERTEX_SHADER);
    GLuint fragmentShader = loadAndCompileShader(path_frag_shader, GL_FRAGMENT_SHADER);


    // Create a program object and attach the two shaders we have compiled, the program object contains
    // both vertex and fragment shaders as well as information about uniforms and attributes common to both.
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    // Now that the fragment and vertex shader has been attached, we no longer need these two separate objects and should delete them.
    // The attachment to the shader program will keep them alive, as long as we keep the shaderProgram.
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Link the different shaders that are bound to this program, this creates a final shader that
    // we can use to render geometry with.
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    return shaderProgram;
}

//
// END OF COPY PASTE FROM LAB03
//
GLuint loadShaderProgram(const char* path_vert_shader, const char* path_geo_shader , const char* path_frag_shader) {
    // Load and compile the vertex and fragment shaders
    GLuint vertexShader = loadAndCompileShader(path_vert_shader, GL_VERTEX_SHADER);
    GLuint geometryShader = loadAndCompileShader(path_geo_shader, GL_GEOMETRY_SHADER);
    GLuint fragmentShader = loadAndCompileShader(path_frag_shader, GL_FRAGMENT_SHADER);

    // Create a program object and attach the two shaders we have compiled, the program object contains
    // both vertex and fragment shaders as well as information about uniforms and attributes common to both.
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, geometryShader);
    glAttachShader(shaderProgram, fragmentShader);

    // Now that the fragment and vertex shader has been attached, we no longer need these two separate objects and should delete them.
    // The attachment to the shader program will keep them alive, as long as we keep the shaderProgram.
    glDeleteShader(vertexShader);
    glDeleteShader(geometryShader);
    glDeleteShader(fragmentShader);

    // Link the different shaders that are bound to this program, this creates a final shader that
    // we can use to render geometry with.
    glLinkProgram(shaderProgram);
    return shaderProgram;
}

}
