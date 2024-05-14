#include "Model.h"

class Bicycle : public Model {
public:
    Bicycle() : Model() {
        this->LoadModel();
    }

    glm::vec3 initialRightPivot = glm::vec3(0.38f, 0.21f, 0.6045f);
    glm::vec3 initialLeftPivot = glm::vec3(0.305f, 0.21f, 0.6045f);
    glm::vec3 rightpivot;
    glm::vec3 leftpivot;

    void LoadModel() override {
        this->meshes.push_back(Mesh("FirstCircle.txt"));
        this->meshes.push_back(Mesh("SecondCircle.txt"));
        this->meshes.push_back(Mesh("Seat.txt"));
        this->meshes.push_back(Mesh("Control.txt"));
        glm::vec3 translationAmount(-0.4f, 0.0f, 0.0f);
        for (auto& mesh : meshes) {
            mesh.translateMesh(translationAmount);
        }
        UpdatePivots();
    }

    float attr = 0;
    float RightWheelAngle = 0;
    float LeftWheelAngle = 0;

    void UpdatePivots() {
        rightpivot = glm::vec3(meshes[0].model * glm::vec4(initialRightPivot, 1.0f));
        leftpivot = glm::vec3(meshes[1].model * glm::vec4(initialLeftPivot, 1.0f));
    }

    void ModelInputs(GLFWwindow* window, float deltaTime) override {
        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
            glm::vec3 translation(0.0f, 0.0f, -0.001f);
            for (auto& mesh : meshes) {
                mesh.translateMesh(translation);
            }
            UpdatePivots();
        }
        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) {
            glm::vec3 translation(0.0f, 0.0f, 0.001f);
            for (auto& mesh : meshes) {
                mesh.translateMesh(translation);
            }
            UpdatePivots();
        }
        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
            meshes[0].RotateAbout(RightWheelAngle, glm::vec3(0.0f, 1.0f, 0.0f), rightpivot);
            RightWheelAngle += 0.05f * deltaTime;
        }
        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
            meshes[1].RotateAbout(LeftWheelAngle, glm::vec3(0.0f, 1.0f, 0.0f), leftpivot);
            LeftWheelAngle += 0.05f * deltaTime;
        }
        if (isMoving) {
            glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);
            for (auto& mesh : meshes) {
                mesh.RotateAbout(attr, glm::vec3(0.0f, 1.0f, 0.0f), center);
            }
            attr += 0.05f * deltaTime;
            UpdatePivots();
        }
    }
};
