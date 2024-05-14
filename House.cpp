#include "Model.h"


class House : public Model
{
	public:
	float angle = 0.0f;
	House() : Model() { this->LoadModel();  }
	void LoadModel() override {
		this->meshes.push_back(Mesh("home.txt"));
		this->meshes.push_back(Mesh("door.txt"));
		this->meshes.push_back(Mesh("FirstFloorRWindow.txt"));
		this->meshes.push_back(Mesh("FirstFloorLWindow.txt"));
		this->meshes.push_back(Mesh("SecondFloorLWindow.txt"));
		this->meshes.push_back(Mesh("SecondFloorRWindow.txt"));
	}
	void ModelInputs(GLFWwindow* window , float deltaTime)  override {
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS && glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) != GLFW_PRESS)
		{
			if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
			{
				Rotate(this->meshes[1], true, glm::vec3(0.2f, 0.75f, 0.05f) , deltaTime);
			}
			if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
			{
				Rotate(this->meshes[1], false, glm::vec3(0.2f, 0.75f, 0.05f) , deltaTime);
			}
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS) {
			if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
			{
				Rotate(this->meshes[2], true, glm::vec3(0.2, 0.24, -0.10), deltaTime);
				Rotate(this->meshes[3], true, glm::vec3(0.2, 0.24, 0.18) , deltaTime);
				Rotate(this->meshes[4], true, glm::vec3(0.2, 0.49, 0.18) , deltaTime);
				Rotate(this->meshes[5], true, glm::vec3(0.2, 0.49, -0.10) , deltaTime);
			}
			if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
			{
				Rotate(this->meshes[2], false, glm::vec3(0.2, 0.24, -0.10) , deltaTime);
				Rotate(this->meshes[3], false, glm::vec3(0.2, 0.24, 0.18) , deltaTime);
				Rotate(this->meshes[4], false, glm::vec3(0.2, 0.49, 0.18) , deltaTime);
				Rotate(this->meshes[5], false, glm::vec3(0.2, 0.49, -0.10) , deltaTime);
			}
		}
	}
	void Rotate(Mesh& mesh, bool isOpen, glm::vec3 pivot , float deltaTime) {
		if (isOpen) {
			if (this->angle <= -120) return;
			this->angle -= 200.0f * deltaTime;
		}
		else {
			if (this->angle >= 0) return;
			this->angle += 200.0f * deltaTime;
		}
		mesh.rotateAroundPivot(this->angle, glm::vec3(0.0f, 1.0f, 0.0f), pivot);
	}
};