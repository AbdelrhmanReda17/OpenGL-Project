#include "Mesh.h"

Vertex CubeVertices[] =
{ //     COORDINATES     //
	Vertex{glm::vec3(-0.1f, -0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f, -0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f, -0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f, -0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f,  0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f,  0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f,  0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f,  0.1f,  0.1f)}
};

GLuint CubeIndices[] =
{
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
	4, 6, 7
};

class Cube {
public:
	Mesh mesh;
	Cube()
	{
		std::vector<Vertex> vertices(CubeVertices, CubeVertices + sizeof(CubeVertices) / sizeof(Vertex));
		std::vector<GLuint> indices(CubeIndices, CubeIndices + sizeof(CubeIndices) / sizeof(GLuint));
		std::vector<Texture> textures;
		mesh = Mesh(vertices, indices, textures);
	}
	void Draw(Shader& shader, Camera& camera, glm::mat4 matrix, glm::vec3 translation, glm::quat rotation, glm::vec3 scale)
	{
		mesh.Draw(shader, camera, matrix, translation, rotation, scale);
	}	
};