#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <windows.h>


#include "shades.hpp"
#include "texturre.hpp"


// Width and height for the window
int WIDTH = 500;
int HEIGHT = 500;

void cursor_pos_man(GLFWwindow *window, Shader needs);

float yy = -0.5;

int main()
{
    system("cls");
    std::cout << "LOOK OVER HERE";
    
    //Setting up GLFW
    glfwInit();
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    //Creating a window
    GLFWwindow *windoww = glfwCreateWindow(WIDTH, HEIGHT, "A Face", NULL, NULL);
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

    // Callbacks to receive input from peripharels

    GLfloat squaree[] = {
       -0.8f,  0.8f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.1f, // Top left
        0.8f,  0.8f, 0.0f,   0.0f, 0.0f, 1.0f,   1.0f, 1.0f, // Top right
       -0.8f, -0.8f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f, // Bottom left
        0.8f, -0.8f, 0.0f,   0.0f, 0.0f, 0.0f,   1.0f, 1.0f  // Bottom right
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

    // Initializing a shader program with the given shaders
    Shader sha("C:\\Users\\litia\\OneDrive\\Documents\\FaceMover\\Shaderrs\\ranso.vert", "C:\\Users\\litia\\OneDrive\\Documents\\FaceMover\\Shaderrs\\frag.frag");

    // Array information
    glBufferData(GL_ARRAY_BUFFER, sizeof(squaree), squaree, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(likeThis), likeThis, GL_STATIC_DRAW);
    

    // Vertex array data 
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    // Enabling the vertex attribute and using the shader(s)
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    // Using the shader program
    sha.use();

    // saying hello
    sayhello();
    
    // Call for texture to be generated
    tex("C:\\Users\\litia\\OneDrive\\Documents\\FaceMover\\texturres\\okk.png");
    
    // getting the uniform location
    GLuint modelr = glGetUniformLocation(sha.ID, "model");

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //main loop
    while (!glfwWindowShouldClose(windoww))
    {
        glClearColor(0.1f, 0.0f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glDrawArrays(GL_TRIANGLES, 0, 3);
        // glDrawArrays(GL_TRIANGLES, 1, 3);

        cursor_pos_man(windoww, sha);

        
        for (int i = 0; i < 5; i++)
        {
            // For manipulating the model
           glm::mat4 model;;
           if (i == 0)
           {
                // translate(move) a single model matrix
                model = glm::mat4(1.0f);
                
                // moving it along
                model = glm::translate(model, glm::vec3(0.5f, 0.5f, 0.0f));
                model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.0f));
                glUniformMatrix4fv(modelr, 1, GL_FALSE, glm::value_ptr(model));
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, likeThis);
           }  
           else if (i == 1)
           {
                // translate(move) a single model matrix
                model = glm::mat4(1.0f);
                
                // moving it along
                model = glm::translate(model, glm::vec3(-0.5f, 0.5f, 0.0f));
                model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.0f));
                glUniformMatrix4fv(modelr, 1, GL_FALSE, glm::value_ptr(model));
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, likeThis);
           }          
           else if (i == 2)
           {
                // translate(move) a single model matrix
                model = glm::mat4(1.0f);
                
                // moving it along
                model = glm::translate(model, glm::vec3(0.0f, -0.5f, 0.0f));
                model = glm::scale(model, glm::vec3(0.7f, 0.1f, 0.0f));
                glUniformMatrix4fv(modelr, 1, GL_FALSE, glm::value_ptr(model));
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, likeThis);
           }
            //mouth part that will move
           else if ( i == 3)
           {
                model = glm::mat4(1.0f);
                model = glm::translate(model, glm::vec3(0.5f, yy, 0.0f));
                model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.0f));
                glUniformMatrix4fv(modelr, 1, GL_FALSE, glm::value_ptr(model));
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, likeThis);
           }           
           //mouth part that will move
           else if (i == 4)
           {
                model = glm::mat4(1.0f);
                model = glm::translate(model, glm::vec3(-0.5f, yy, 0.0f));
                model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.0f));
                glUniformMatrix4fv(modelr, 1, GL_FALSE, glm::value_ptr(model));
                cursor_pos_man(windoww, sha);
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, likeThis);
           }
        }
        

        glfwSwapBuffers(windoww);
        glfwPollEvents();
    }
    
    // Deleting some stuff to free memory/storage space
    glDeleteProgram(sha.ID);
    glDeleteTextures(1, &Tex);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    glfwTerminate();
    
    return 0;
}

// Tracking the mouse movements to determine the mouth state
float x_here = 0.1; 
float y_here = 0.1;
bool fi = true;
double x_bef;
double y_bef;


void goneWhere(char direction)
{
    if (direction == 'D')
    {
        if (yy < -0.65)
        {
            return;
        }
        yy -= 0.01;
    }    
    else if (direction == 'U')
    {
        if (yy > -0.35)
        {
            return;
        }
        yy += 0.01;
    }
}

void cursor_pos_man(GLFWwindow *window, Shader needs)
{
    // Variables for the mouses x and y positions
    double xpos, ypos;    
    glm::vec1 th = glm::vec1(0.2);
    GLuint here = glGetUniformLocation(needs.ID, "th");

    glfwGetCursorPos(window, &xpos, &ypos);

    glUniform1f(here, 0.1f);
    if (fi == true)
    {
        y_bef = ypos;
        fi = false;
    }
    if (ypos > y_bef)
    {
        // going down
        goneWhere('D');
    }        
    else if (ypos < y_bef)
    {
        // going up
        goneWhere('U');
    }
    
    y_bef = ypos;
}
