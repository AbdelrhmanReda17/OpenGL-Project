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
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(width, height, "Project Window", NULL, NULL);
	if (window == NULL){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetMouseButtonCallback(window, mouseClick_callback);
	glViewport(0, 0, width, height); // Specify the viewport of OpenGL in the Window
	Shader shaderProgram("default.vert", "default.frag"); // Generates Shader object using shaders default.vert and default.frag
	Mesh floor("floor.txt");
	Model* houseModel = new House();
	Model* bicycleModel = new Bicycle();
	glEnable(GL_DEPTH_TEST);
	while (!glfwWindowShouldClose(window))
	{
		calculateDeltaTime();
		glClearColor(0.2f, 0.5f, 0.3f, 1.0f);// Specify the color of the background
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
		floor.Draw(shaderProgram, camera);
		houseModel->Draw(shaderProgram, camera);
		bicycleModel->Draw(shaderProgram, camera);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	shaderProgram.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
