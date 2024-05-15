#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include<string>

#include"VAO.h"
#include"EBO.h"
#include"Camera.h"
#include<glm/gtx/vector_angle.hpp>

class Mesh
{
private: 
	void readMesh(std::string path);
public:
	std::vector <Vertex> vertices;
	std::vector <GLuint> indices;
	glm::mat4 model;
	glm::vec3 pivot;
	VAO VAO;
	// Initializes the mesh
	Mesh(std::string filename);
	Mesh();
	void Setup();
	void meshTranslate(const glm::vec3& translation);
	void meshRotate(const glm::vec3& rotation);
	void rotateAroundPivot(float angle, const glm::vec3& axis);
	void meshRotatebyAngle(float angle, const glm::vec3& axis);
	void meshRotateAboutPoint(float angle, const glm::vec3& axis, glm::vec3 point);
	void Draw(Shader& shader, Camera& camera);
};
#endif