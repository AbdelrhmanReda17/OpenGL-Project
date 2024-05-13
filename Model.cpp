#include"Model.h"

Model::Model(std::vector<Mesh>& meshes) {
	this->meshes = meshes;
	matricesMeshes.resize(meshes.size());
	translationsMeshes.resize(meshes.size());
	rotationsMeshes.resize(meshes.size());
	scalesMeshes.resize(meshes.size());
	for (unsigned int i = 0; i < meshes.size(); i++) {
		matricesMeshes[i] = glm::mat4(1.0f);
		translationsMeshes[i] = glm::vec3(0.0f);
		rotationsMeshes[i] = glm::vec3(0.0f);
		scalesMeshes[i] = glm::vec3(1.0f);
	}
}

void Model::Draw(Shader& shader, Camera& camera)
{
	float angle = (float)glfwGetTime();

	for (unsigned int i = 0; i < meshes.size(); i++)
	{

		meshes[i].Mesh::Draw(shader, camera, matricesMeshes[i], translationsMeshes[i], rotationsMeshes[i], scalesMeshes[i]);
	}
}
