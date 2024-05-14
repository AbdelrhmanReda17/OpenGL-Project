#include"Model.h"

Model::Model() {}

void Model::Draw(Shader& shader, Camera& camera)
{
	float angle = (float)glfwGetTime();

	for (unsigned int i = 0; i < meshes.size(); i++)
	{

		meshes[i].Mesh::Draw(shader, camera);
	}
}

