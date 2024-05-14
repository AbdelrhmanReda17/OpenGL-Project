#include "Mesh.h"

Mesh::Mesh(){}
Mesh::Mesh(std::string fileName)
{
	readMesh(fileName);
	Setup();
	this->model = glm::mat4(1.0f);
}

void Mesh::Setup() {
	VAO.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO(vertices);
	// Generates Element Buffer Object and links it to indices
	EBO EBO(indices);
	// Links VBO attributes such as coordinates and colors to VAO
	VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO.Unbind();
	VBO.Unbind();
	EBO.Unbind();
}



void Mesh::readMesh(std::string filename)
{
		std::ifstream file(filename);
		if (!file.is_open()) {
			std::cerr << "Error: Unable to open file " << filename << std::endl;
			return;
		}
		std::string line;
		while (std::getline(file, line)) {
			std::stringstream ss(line);
			std::string type;
			ss >> type;

			if (type == "v") {
				glm::vec3 position;
				glm::vec3 color;
				ss >> position.x >> position.y >> position.z >> color.r >> color.g >> color.b;
				position += 0.0f;
				color += 0.0f;

				vertices.push_back(Vertex{ position, color });
			}
			else if (type == "f") {
				GLuint index1, index2, index3;
				ss >> index1 >> index2 >> index3;
				indices.push_back(index1); 
				indices.push_back(index2);
				indices.push_back(index3);
			}
		}
		file.close();
}
void Mesh::Draw (Shader& shader,Camera& camera){
	shader.Activate();
	VAO.Bind();
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(this->model));
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}
void Mesh::rotateAroundPivot(float angle, const glm::vec3& axis, const glm::vec3& pivot) {
	glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle), axis);
	glm::mat4 translateToOrigin = glm::translate(glm::mat4(1.0f), -pivot);
	glm::mat4 translateBack = glm::translate(glm::mat4(1.0f), pivot);
	this->model =  translateBack * rotationMatrix * translateToOrigin;
}
void Mesh::scaleMesh(const glm::vec3& scale) {
	this->model = glm::scale(this->model, scale);
}
void Mesh::translateMesh(const glm::vec3& translation) {
	this->model = glm::translate(glm::mat4(1.0f), translation) * this->model;
}
void Mesh::rotateMesh(const glm::vec3& rotation) {
	this->model = glm::rotate(this->model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	this->model = glm::rotate(this->model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	this->model = glm::rotate(this->model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
}

void Mesh::rotateByAngle(float angle, const glm::vec3& axis) {
	glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle), axis);
	this->model = rotationMatrix * this->model;
}
void Mesh::RotateAbout(float angle, const glm::vec3& axis ,glm::vec3& center ) {
	// Center the model by translating it to the origin
	//glm::vec3 center = glm::vec3(0.0f); // Assuming the center is (0,0,0). Adjust if the model's center is different.
	glm::mat4 translationMatrix1 = glm::translate(glm::mat4(1.0f), -center);
	glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle), axis);
	glm::mat4 translationMatrix2 = glm::translate(glm::mat4(1.0f), center);
	// Combine the transformations
	this->model = translationMatrix2 * rotationMatrix * translationMatrix1 * this->model;
}
