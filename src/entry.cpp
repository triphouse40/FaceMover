#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "shades.hpp"


int main()
{
    std::cout << "LOOK OVER HERE";
    
    //Setting up GLFW
    glfwInit();
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    //Creating a window
    GLFWwindow *windoww = glfwCreateWindow(500, 500, "A Face", NULL, NULL);
    if (windoww == NULL)
    {
        std::cout << "Could not create the window yung man";
        glfwTerminate();
        return -1;
    }

    //Setting the created window to the current context
    glfwMakeContextCurrent(windoww);

    //loading glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
       std::cout << "Could not load glad yung man";
       glfwTerminate();
       return -1;
    }
    
    //setting the window viewport
    glViewport(0, 0, 500, 500);


    GLfloat squaree[] = {
       -0.8f,  0.8f, 0.0f, 1.0f, 0.0f, 0.0f,// Top left
        0.8f,  0.8f, 0.0f, 0.0f, 0.0f, 1.0f,// Top right
       -0.8f, -0.8f, 0.0f, 0.0f, 1.0f, 0.0f,// Bottom left
        0.8f, -0.8f, 0.0f, 1.0f, 1.0f, 1.0f,// Bottom right
    };

    // Element/Index array for how to draw the square
    GLint likeThis[] = {
        0, 1, 2,
        3, 2, 1
    };

    // Creating array objects
    GLuint VAO, VBO, EBO;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);

    // Binding the array for use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBindVertexArray(VAO);

    Shader sha("C:\\Users\\litia\\OneDrive\\Documents\\FaceMover\\Shaderrs\\ranso.vert", "C:\\Users\\litia\\OneDrive\\Documents\\FaceMover\\Shaderrs\\frag.frag");

    // Array information
    glBufferData(GL_ARRAY_BUFFER, sizeof(squaree), squaree, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(likeThis), likeThis, GL_STATIC_DRAW);
    

    // Vertex array data 
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    // Enabling the vertex attribute and using the shader(s)
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    sha.use();

    //main loop
    while (!glfwWindowShouldClose(windoww))
    {
        glClearColor(0.1f, 0.0f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glDrawArrays(GL_TRIANGLES, 0, 3);
        // glDrawArrays(GL_TRIANGLES, 1, 3);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, likeThis);
        

        glfwSwapBuffers(windoww);
        glfwPollEvents();
    }
    

    glfwTerminate();
    
    return 0;
}