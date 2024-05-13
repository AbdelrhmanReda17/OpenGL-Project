//------- Ignore this ----------
#include<filesystem>
namespace fs = std::filesystem;
//------------------------------
#include <iostream>
#include "Mesh.h"
#include "Model.h"
#include <math.h>
#include <cmath>

const unsigned int width = 800;
const unsigned int height = 800;
float deltaTime = 0.0f;
float lastFrame = 0.0f;
float lastX = 0.0f;
float lastY = 0.0f;
bool camMode = false;
Camera camera(glm::vec3(0.0f, 2.0f, 0.0f) ,glm::vec3(0.0f,1.0f,0.0f), 0, -90 );

Model loadHouse(std::vector<Texture>& tex) {
	std::vector<Mesh> Meshes;
	Meshes.push_back(Mesh("home.txt", tex));
	Meshes.push_back(Mesh("door.txt", tex));
	Meshes.push_back(Mesh("FirstFloorRWindow.txt", tex));
	Meshes.push_back(Mesh("FirstFloorLWindow.txt", tex));
	Meshes.push_back(Mesh("SecondFloorLWindow.txt", tex));
	Meshes.push_back(Mesh("SecondFloorRWindow.txt", tex));
	Model homeModel(Meshes);
	return homeModel;

}
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
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
		camMode = false;
	}
}

void calculateDeltaTime() {
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}



void HouseInputs(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
	{
		// open door
	}

	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
	{
		// close door
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS) {
		if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
		{
			// open window
		}

		if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
		{
			// close window
		}
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	width = width;
	height = height;
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

	// Load GLAD so it configures OpenGL
	gladLoadGL();
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetMouseButtonCallback(window, mouseClick_callback);
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);


	// Original code from the tutorial
	Texture textures[]
	{
		Texture("microsoft.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		//Texture("microsoft.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};



	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");
	// Store mesh data in vectors for the mesh

	std::vector <Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
	// Create floor mesh
	Mesh floor("floor.txt", tex);

	Model homeModel = loadHouse(tex);


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
		glm::mat4 view = camera.GetViewMatrix();
		shaderProgram.setMat4("view", view);
		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(camera.zoom), (float)width / (float)height, 0.1f, 100.0f);
		shaderProgram.setMat4("projection", projection);

		// Draws different meshes
		floor.Draw(shaderProgram, camera);
		homeModel.Draw(shaderProgram, camera);
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
