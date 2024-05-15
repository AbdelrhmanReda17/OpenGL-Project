#include"Model.h"

Model::Model() {}

void Model::Draw(Shader& shader, Camera& camera)
{
	for (auto& mesh : this->meshes) {
		mesh.Draw(shader, camera);
	}
}
void Model::Translate(glm::vec3 translation) {
	for (auto& mesh : this->meshes) {
		mesh.meshTranslate(translation);
	}
}