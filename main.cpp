//------- Ignore this ----------
#include<filesystem>
namespace fs = std::filesystem;
//------------------------------


#include <iostream>
#include "Mesh.h"
#include "Model.h"


Vertex HouseVertices[] = {
	Vertex{glm::vec3(-0.2f, 0.0f, 0.2f), glm::vec3(0.8, 0.8, 0.8)},
	Vertex{glm::vec3(-0.2f, 0.0f, -0.2f), glm::vec3(0.8, 0.8, 0.8)},
	Vertex{glm::vec3(0.0f, 0.0f, -0.2f), glm::vec3(0.8, 0.8, 0.8)},
	Vertex{glm::vec3(0.0f, 0.0f, 0.2f), glm::vec3(0.8, 0.8, 0.8)},
	Vertex{glm::vec3(-0.2f, -0.3f, 0.2f), glm::vec3(0.8, 0.8, 0.8)},
	Vertex{glm::vec3(-0.2f, -0.3f, -0.2f), glm::vec3(0.8, 0.8, 0.8)},
	Vertex{glm::vec3(0.0f, -0.3f, -0.2f), glm::vec3(0.8, 0.8, 0.8)},
	Vertex{glm::vec3(0.0f, -0.3f, 0.2f), glm::vec3(0.8, 0.8, 0.8)},
	// 2nd floor
	Vertex{glm::vec3(-0.2f, -0.3f, 0.2f), glm::vec3(0, 0.8, 0.8)},
	Vertex{glm::vec3(-0.2f, -0.3f, -0.2f), glm::vec3(0, 0.8, 0.8)},
	Vertex{glm::vec3(0.0f, -0.3f, -0.2f), glm::vec3(0, 0.8, 0.8)},
	Vertex{glm::vec3(0.0f, -0.3f, 0.2f), glm::vec3(0, 0.8, 0.8)},
	Vertex{glm::vec3(-0.2f, -0.6f, 0.2f), glm::vec3(0, 0.8, 0.8)},
	Vertex{glm::vec3(-0.2f, -0.6f, -0.2f), glm::vec3(0, 0.8, 0.8)},
	Vertex{glm::vec3(0.0f, -0.6f, -0.2f), glm::vec3(0, 0.8, 0.8)},
	Vertex{glm::vec3(0.0f, -0.6f, 0.2f), glm::vec3(0, 0.8, 0.8)},
};


GLuint HouseIndices[] = {
		0, 1, 2,
		0, 2, 3,
		0, 4, 7,
		0, 7, 3,
		3, 7, 6,
		3, 6, 2,
		2, 6, 5,
		2, 5, 1,
		1, 5, 4,
		1, 4, 0,
		4, 5, 6,
		4, 6, 7,

		8, 9, 10,
		8, 10, 11,
		8, 12, 15,
		8, 15, 11,
		11, 15, 14,
		11, 14, 10,
		10, 14, 13,
		10, 13, 9,
		9, 13, 12,
		9, 12, 8,
		12, 13, 14,
		12, 14, 15
};



const unsigned int width = 800;
const unsigned int height = 800;


Vertex vertices[] =
{ //               COORDINATES           /            COLORS          /           NORMALS      /
	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(1.0f ,	0.0f, -1.0f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(1.0f ,	0.0f,  1.0f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 0.0f)}
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3
};


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

	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);


	/*
	* I'm doing this relative path thing in order to centralize all the resources into one folder and not
	* duplicate them between tutorial folders. You can just copy paste the resources from the 'Resources'
	* folder and then give a relative path from this folder to whatever resource you want to get to.
	* Also note that this requires C++17, so go to Project Properties, C/C++, Language, and select C++17
	*/


	// Original code from the tutorial
	Texture textures[]
	{
		Texture("microsoft.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		//Texture("microsoft.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};



	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");
	// Store mesh data in vectors for the mesh
	std::vector <Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector <GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	std::vector <Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
	// Create floor mesh
	Mesh floor(verts, ind, tex);


	std::vector<Vertex> vertices(HouseVertices, HouseVertices + sizeof(HouseVertices) / sizeof(Vertex));
	std::vector<GLuint> indices(HouseIndices, HouseIndices + sizeof(HouseIndices) / sizeof(GLuint));
	Mesh cube(vertices, indices, tex);

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Creates camera object
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));



	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.2f, 0.5f, 0.3f, 1.0f);		
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);


		// Draws different meshes
		floor.Draw(shaderProgram, camera);
		cube.Draw(shaderProgram, camera, glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::quat(1.0f, 0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
		// light.Draw(lightShader, camera);
		// myCube.Draw(shaderProgram, camera);


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