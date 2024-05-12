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
	std::vector<glm::vec3> translationsMeshes = { glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f) };
	std::vector<glm::vec3> rotationsMeshes = { glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f) };
	std::vector<glm::vec3> scalesMeshes = { glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f) };
	std::vector<glm::mat4> matricesMeshes = { glm::mat4(1.0f), glm::mat4(1.0f) };


};
#endif