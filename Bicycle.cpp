#include "Model.h"

class Bicycle : public Model {
public:
    Bicycle() : Model() {
        this->LoadModel();
    }
    void LoadModel() override {
        this->meshes.push_back(Mesh("FirstCircle.txt"));
        this->meshes.push_back(Mesh("SecondCircle.txt"));
        this->meshes.push_back(Mesh("Seat.txt"));
        this->meshes.push_back(Mesh("Control.txt"));
        glm::vec3 translationAmount(-0.4f, 0.0f, 0.0f);
        for (auto& mesh : meshes) {
            mesh.translateMesh(translationAmount);
        }
    }
    float attr = 0;
    float RightWheelAngle = 0;
    float LeftWheelAngle = 0;

    void ModelInputs(GLFWwindow* window, float deltaTime) override {
        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
            glm::vec3 translation(0.0f, 0.0f, -0.001f);
            for (auto& mesh : meshes) {
                mesh.translateMesh(translation);
            }
        }
        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) {
            glm::vec3 translation(0.0f, 0.0f, 0.001f);
            for (auto& mesh : meshes) {
                mesh.translateMesh(translation);
            }
        }
        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
            meshes[0].RotateAbout(RightWheelAngle, glm::vec3(0.0f, 1.0f, 0.0f), meshes[0].model * glm::vec4(meshes[0].pivot , 1.0f));
            RightWheelAngle += 0.03f * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
            meshes[1].RotateAbout(LeftWheelAngle, glm::vec3(0.0f, 1.0f, 0.0f), meshes[1].model * glm::vec4(meshes[1].pivot, 1.0f));
            LeftWheelAngle += 0.03f * deltaTime;
        }
        if (isMoving) {
            glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);
            for (auto& mesh : meshes) {
                mesh.RotateAbout(attr, glm::vec3(0.0f, 1.0f, 0.0f), center);
            }
            attr += 0.03f * deltaTime;
        }
    }
};
