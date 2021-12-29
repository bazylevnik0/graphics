#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

// settings
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;

// vertex shader
const char *vertexShaderSource = "#version 330 core\n"
    "in vec3 position;"
    "in vec3 color;"
    "out vec3 Color;"
    "void main()\n"
    "{\n"
        "Color = color;"
    "   gl_Position = vec4(position, 1.0);\n"
    "}\0";
// fragment shader
const char *fragmentShaderSource = "#version 330 core\n"
    "in vec3 Color;"
    "out vec4 FragColor;"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(Color, 1.0);\n"
    "}\n\0";
int main()
{
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create window with context
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "graphics-OpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);
        //check glfw
        if (window == NULL)
        {
          std::cout << "Failed to create GLFW window" << std::endl;
          glfwTerminate();
          return -1;
        }
        //check glad and load all OpenGL function pointers
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
          std::cout << "Failed to initialize GLAD" << std::endl;
          return -1;
        }

    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
         0.0f,  0.5f, 0.0f, 1.0f , 0.0f, 0.0f, // 11 r
         0.5f,  0.5f, 0.0f, 0.0f , 1.0f, 0.0f, // 21 g
         0.0f, -0.5f, 0.0f, 0.0f , 0.0f, 1.0f, // 31 b
         0.0f, -0.5f, 0.0f, 1.0f , 0.0f, 0.0f, // 12 r
        -0.5f, -0.5f, 0.0f, 0.0f , 1.0f, 0.0f, // 22 g
         0.0f,  0.5f, 0.0f, 0.0f , 0.0f, 1.0f  // 32 b
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);             //!!!!!!
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Specify the layout of the vertex data
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(vertices[0]), 0);

    GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
    glEnableVertexAttribArray(colAttrib);
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(vertices[0]), (void*)(3 * sizeof(vertices[0])));


    // update
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe mode
    // render loop
    float counter {1.0f}; int k{-1};
    while (!glfwWindowShouldClose(window))
    {
        // input
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        //clear color back
        glClearColor(1.0f, 0.2f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // change triangle loop
        counter += 0.01f*k;
        if (counter < 0.1f)
        {
         k *= -1;
         counter = 0.11f;
        }
        if (counter > 0.9f)
        {
         k *= -1;
         counter = 0.89f;
        }

        // draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // update
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // clear
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;

   return 0;
}
