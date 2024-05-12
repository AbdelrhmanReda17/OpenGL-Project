#ifndef MODEL_CLASS_H
#define MODEL_CLASS_H

#include"Mesh.h"



class Model
{
public:
	Model(std::vector<Mesh>& );
	void Draw(Shader& shader, Camera& camera);

private:

	// All the meshes and transformations
	std::vector<Mesh> meshes;
	std::vector<glm::vec3> translationsMeshes;
	std::vector<glm::quat> rotationsMeshes;
	std::vector<glm::vec3> scalesMeshes;
	std::vector<glm::mat4> matricesMeshes;

	// Assembles all the floats into vertices
	std::vector<Vertex> assembleVertices
	(
		std::vector<glm::vec3> positions,
		std::vector<glm::vec3> normals,
		std::vector<glm::vec2> texUVs
	);

};
#endif