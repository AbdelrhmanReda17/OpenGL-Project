//------- Ignore this ----------
#include<filesystem>
namespace fs = std::filesystem;
//------------------------------
#include <iostream>
#include "Mesh.h"
#include "Model.h"
#include <math.h>
#include <cmath>
#include "House.cpp"
#include "Bicycle.cpp"

unsigned int width = 800;
unsigned int height = 800;
float deltaTime = 0.0f;
float lastFrame = 0.0f;
float lastX = 0.0f;
float lastY = 0.0f;
bool camMode = false , isAnimated = false;
Camera camera(glm::vec3(2.0f, 0.2f, 0.05f), glm::vec3(0.0f,1.0f, 0.0f), 180, 0);

void input(GLFWwindow* window) {
	// Handles camera inputs
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.processKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.processKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.processKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.processKeyboard(RIGHT, deltaTime);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;	
	if (!camMode) return;
	camera.processMouseMovement(xoffset, yoffset);
}

void mouseClick_callback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
		camMode = true;
		isAnimated = false;
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
		camMode = false;
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		isAnimated = true;
	}
}

void calculateDeltaTime() {
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

void framebuffer_size_callback(GLFWwindow* window, int w, int h) {
	width = w;
	height = h;
	glViewport(0, 0, width, height);
}

int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);


	//buildCircle(0.02f, 6);

	// Load GLAD so it configures OpenGL
	gladLoadGL();
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetMouseButtonCallback(window, mouseClick_callback);
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);

	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");
	// Store mesh data in vectors for the mesh
	// Create Models
	Mesh floor("floor.txt");
	Model* houseModel = new House();
	Model* bicycleModel = new Bicycle();
	
	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Calculate delta time
		calculateDeltaTime();

		// Specify the color of the background
		glClearColor(0.2f, 0.5f, 0.3f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		input(window);		
		bicycleModel->isMoving = isAnimated;
		houseModel->ModelInputs(window , deltaTime);
		bicycleModel->ModelInputs(window, deltaTime);
		glm::mat4 view = camera.GetViewMatrix();
		shaderProgram.setMat4("view", view);

		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(camera.zoom), (float)width / (float)height, 0.1f, 100.0f);
		shaderProgram.setMat4("projection", projection);

		// Draws different meshes
		floor.Draw(shaderProgram, camera);
		houseModel->Draw(shaderProgram, camera);
		bicycleModel->Draw(shaderProgram, camera);

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}


	// Delete all the objects we've created
	shaderProgram.Delete();

	//lightShader.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}
