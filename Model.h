#ifndef MODEL_CLASS_H
#define MODEL_CLASS_H

#include"Mesh.h"



class Model
{
public:
	Model();
	void Draw(Shader& shader, Camera& camera);
	virtual void LoadModel() = 0;
	virtual void ModelInputs(GLFWwindow* window , float deltaTime) = 0;
	std::vector<Mesh> meshes;
	bool isMoving = false;

private:
	// All the meshes and transformations
	
};
#endif