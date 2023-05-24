#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
// Include the main ReactPhysics3D header file 
#include <reactphysics3d/reactphysics3d.h>

#include "MyGeometryDrawer.h"
#include "ShaderHandler.h"

const int windowWidth = 800;
const int windowHeight = 800;

int main() 
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the moren functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFwindow object of 800 by 800 pixels, naming it "OpenGLTest"
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "OpenGLTest", NULL, NULL);

	const char* vertexShaderSource = "";


	/*GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, )*/


	// Error check if the window fails to create
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	// Load GLAD so it configures OpenGL
	gladLoadGL();

	// Specificy the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, windowWidth, windowHeight);

	// Specifiy the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);

	GeometryDrawer* myDrawer = new GeometryDrawer();
	ShaderHandler* shaderHandler = new ShaderHandler();

	// GLfloat 
	DrawOutput* triangleDraw = myDrawer->DrawTriangle();

	// Main while loop
	while (!glfwWindowShouldClose(window)) {
		
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(triangleDraw->shaderProgram);
		glBindVertexArray(triangleDraw->VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);
		
		// Take care of all GLFW events
		glfwPollEvents();
		
		// shaderHandler->ImportDefaultVertexShader();
	}

	glDeleteVertexArrays(1, &triangleDraw->VAO);
	glDeleteBuffers(1, &triangleDraw->VBO);
	glDeleteProgram(triangleDraw->shaderProgram);

	// Delete window before ending the program
	glfwDestroyWindow(window); 
	// Terminate GLFW before ending the program
	glfwTerminate();

	return 0;
}