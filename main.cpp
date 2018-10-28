#include "moveshape.h"
#include <iostream>
#include <memory>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glfw3.lib")

static void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	} else if ((key == GLFW_KEY_LEFT || key == GLFW_KEY_RIGHT || key == GLFW_KEY_UP || key == GLFW_KEY_DOWN) && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		keyVal = key;
	}
}

int main() {
	GLFWwindow* window;

    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(800, 600, "Move Me", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

	float ratio;
	int width = 800;
	int height = 600;

	ratio = (float)width / (float)height;

    glfwMakeContextCurrent(window);
    std::unique_ptr<Circle> circle(new Circle(0.3f, 0.6f, 1.0f, 0.8f));

    while (!glfwWindowShouldClose(window))
    {
        glfwGetFramebufferSize(window, &width, &height);

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);//Buffer enabled for color writing

        glMatrixMode(GL_PROJECTION);//Projection matrix stack
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.0f, 1.0f, -1.0f, 1.0f);//Projection

        glMatrixMode(GL_MODELVIEW);//Modelview matrix stack
        glLoadIdentity();

		glfwSetKeyCallback(window, key_callback);

		circle->moveCircle(keyVal);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

	return 0;
}