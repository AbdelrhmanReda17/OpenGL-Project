#include"Model.h"

Model::Model(std::vector<Mesh>& meshes) {
	this->meshes = meshes;
}

void Model::Draw(Shader& shader, Camera& camera)
{
	float angle = (float)glfwGetTime(); // Get the current time as the rotation angle

	// Create the rotation quaternion
	
	// Go over all meshes and draw each one
	for (unsigned int i = 0; i < meshes.size(); i++)
	{
		glm::quat rotation = glm::angleAxis(angle, rotationsMeshes[i]);
		meshes[i].Mesh::Draw(shader, camera, matricesMeshes[i], translationsMeshes[i], rotation, scalesMeshes[i]);
	}
}
