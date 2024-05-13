#version 330 core

// Positions/Coordinates
layout (location = 0) in vec3 aPos;
// Colors
layout (location = 1) in vec3 aColor;
// Texture Coordinates
layout (location = 2) in vec2 aTex;


// Outputs the current position for the Fragment Shader
out vec3 crntPos;

// Outputs the color for the Fragment Shader
out vec3 color;
// Outputs the texture coordinates to the Fragment Shader
out vec2 texCoord;


// Imports the transformation matrices
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 translation;
uniform mat4 rotation;
uniform mat4 scale;


void main()
{
	// calculates current position
	crntPos = vec3(model * translation * -rotation * scale * vec4(aPos, 1.0f));
	// Assigns the colors from the Vertex Data to "color"
	color = aColor;
	// Assigns the texture coordinates from the Vertex Data to "texCoord"
	texCoord = mat2(0.0, -1.0, 1.0, 0.0) * aTex;
	// Outputs the positions/coordinates of all vertices
	gl_Position = projection * view * model * vec4(crntPos, 1.0);
}