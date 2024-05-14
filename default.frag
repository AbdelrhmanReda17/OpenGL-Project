#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;

// Imports the color from the Vertex Shader
in vec3 outColor;

void main(){
	FragColor = vec4(outColor,1.0f);
}

