#ifndef MODEL_CLASS_H
#define MODEL_CLASS_H

#include"Mesh.h"



class Model
{
public:
	Model(std::vector<Mesh>&);
	void Draw(Shader& shader, Camera& camera);

private:
	// All the meshes and transformations
	std::vector<Mesh> meshes;
	std::vector<glm::vec3> translationsMeshes;
	std::vector<glm::vec3> rotationsMeshes;
	std::vector<glm::vec3> scalesMeshes;
	std::vector<glm::mat4> matricesMeshes;
};
#endif