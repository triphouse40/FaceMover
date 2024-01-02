#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void sayhello()
{
    printf("\nHello to you guys\n");
}

GLuint Tex;
GLint width, height, nrChannels;

void tex(char *path_to_image)
{
    // reads the image to memory
    unsigned char *texdata = stbi_load(path_to_image, &width, &height, &nrChannels, 0);
    
    // Creating a texture object
    glGenTextures(1, &Tex);
    glBindTexture(GL_TEXTURE_2D, Tex);

    // Setting the image parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if(texdata)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texdata);
        glGenerateMipmap(GL_TEXTURE_2D);
        std::cout << "Your texture sir....\n";
    }
    else
    {
        std::cout << "FAILED TO GET A TEXTURE FROM YOUR IMAGE BRA...\n";
    }

    // freeing the memory used
    stbi_image_free(texdata);
    
}