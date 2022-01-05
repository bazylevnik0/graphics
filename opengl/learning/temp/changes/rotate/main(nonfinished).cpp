#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cmath>

//define PI


// settings
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;

// vertex shader
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x ,aPos.y ,aPos.z, 1.0);\n"
    "}\0";
// fragment shader
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.0f , 1.0f , 1.0f , 1.0f);\n"
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
         0.0f,  0.1f, 0.0f, // 11
         0.1f,  0.1f, 0.0f, // 21
         0.0f, -0.1f, 0.0f, // 31
         0.0f, -0.1f, 0.0f, // 12
        -0.1f, -0.1f, 0.0f, // 22
         0.0f,  0.1f, 0.0f  // 32
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);             //!!!!!!
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // update
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe mode
    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // input & change
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        {
            std::cout << "up" << std::endl;
            for ( int i{1}; i < 18; i+=3)
            {
                vertices[i] += 0.001f;
            }
        }
        if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        {
            std::cout << "down" << std::endl;
            for ( int i{1}; i < 18; i+=3)
            {
                vertices[i] -= 0.001f;
            }
        }

        if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        {

            std::cout << "left" << std::endl;
            for ( int i{0}; i < 18; i+=3)
            {
                float x_old = vertices[i];
                float y_old = vertices[i+1];

                float angle_old = (std::atan(y_old/x_old) * 180)/ 3.14159265359;
                if(y_old <= 0)
                    angle_old += 180.0f;

                std::cout << x_old << " " << y_old << " " << angle_old << std::endl;
                float angle_new = angle_old + 1.0f;

                float r {0.0f};
                    r = std::sqrt( x_old*x_old + y_old*y_old );
                float x_new =std::cos((3.14159265359f*angle_new)/180)*r;
                float y_new =std::sin((3.14159265359f*angle_new)/180)*r;
                std::cout << x_new << " " << y_new << " " << angle_new << std::endl;
                vertices[i]   = x_new;
                vertices[i+1] = y_new;

                std::cout << r << std::endl;
            }
        }
        if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        {
            std::cout << "right" << std::endl;
            for ( int i{0}; i < 18; i+=3)
            {
                float x_old = vertices[i];
                float y_old = vertices[i+1];

                float angle_old = (std::atan(y_old/x_old) * 180)/ 3.14159265359;
                if(y_old <= 0)
                    angle_old += 180.0f;

                std::cout << x_old << " " << y_old << " " << angle_old << std::endl;
                float angle_new = angle_old - 1.0f;

                float r {0.0f};
                    r = std::sqrt( x_old*x_old + y_old*y_old );
                float x_new =std::cos((3.14159265359f*angle_new)/180)*r;
                float y_new =std::sin((3.14159265359f*angle_new)/180)*r;
                std::cout << x_new << " " << y_new << " " << angle_new << std::endl;
                vertices[i]   = x_new;
                vertices[i+1] = y_new;

                std::cout << r << std::endl;
            }
        }



        //clear color back
        glClearColor(1.0f, 0.2f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // update
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

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
