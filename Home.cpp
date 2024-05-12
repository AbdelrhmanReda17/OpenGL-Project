#include "Model.h"

class Home {
public:
    Vertex HouseVertices[16]; // Declare an array of Vertex objects
	GLuint HouseIndices[69];
	Texture textures[1];

    Home() {
        // Initialize the array of Vertex objects
        HouseVertices[0] = Vertex{ glm::vec3(-0.2f, 0.0f, 0.2f), glm::vec3(1, 0, 0) };
        HouseVertices[1] = Vertex{ glm::vec3(-0.2f, 0.0f, -0.2f), glm::vec3(0.8, 0.8, 0.8) };
        HouseVertices[2] = Vertex{ glm::vec3(0.0f, 0.0f, -0.2f), glm::vec3(0.8, 0.8, 0.8) };
        HouseVertices[3] = Vertex{ glm::vec3(0.0f, 0.0f, 0.2f), glm::vec3(0.8, 0.8, 0.8) };
        HouseVertices[4] = Vertex{ glm::vec3(-0.2f, -0.3f, 0.2f), glm::vec3(0.8, 0.8, 0.8) };
        HouseVertices[5] = Vertex{ glm::vec3(-0.2f, -0.3f, -0.2f), glm::vec3(0.8, 0.8, 0.8) };
        HouseVertices[6] = Vertex{ glm::vec3(0.0f, -0.3f, -0.2f), glm::vec3(0.8, 0.8, 0.8) };
        HouseVertices[7] = Vertex{ glm::vec3(0.0f, -0.3f, 0.2f), glm::vec3(0.8, 0.8, 0.8) };
        HouseVertices[8] = Vertex{ glm::vec3(-0.2f, -0.3f, 0.2f), glm::vec3(0, 0.8, 0.8) };
        HouseVertices[9] = Vertex{ glm::vec3(-0.2f, -0.3f, -0.2f), glm::vec3(0, 0.8, 0.8) };
        HouseVertices[10] = Vertex{ glm::vec3(0.0f, -0.3f, -0.2f), glm::vec3(0, 0.8, 0.8) };
        HouseVertices[11] = Vertex{ glm::vec3(0.0f, -0.3f, 0.2f), glm::vec3(0, 0.8, 0.8) };
        HouseVertices[12] = Vertex{ glm::vec3(-0.2f, -0.6f, 0.2f), glm::vec3(0, 0.8, 0.8) };
        HouseVertices[13] = Vertex{ glm::vec3(-0.2f, -0.6f, -0.2f), glm::vec3(0, 0.8, 0.8) };
        HouseVertices[14] = Vertex{ glm::vec3(0.0f, -0.6f, -0.2f), glm::vec3(0, 0.8, 0.8) };
        HouseVertices[15] = Vertex{ glm::vec3(0.0f, -0.6f, 0.2f), glm::vec3(0, 0.8, 0.8) };
		///////////////////////////////////
		HouseIndices[0] = 0;
		HouseIndices[1] = 1;
		HouseIndices[2] = 2;

		HouseIndices[3] = 0;
		HouseIndices[4] = 2;
		HouseIndices[5] = 3;

		HouseIndices[6] = 0;
		HouseIndices[7] = 4;
		HouseIndices[8] = 7;

		HouseIndices[9] = 0;
		HouseIndices[10] = 7;
		HouseIndices[11] = 3;

		HouseIndices[12] = 3;
		HouseIndices[13] = 6;
		HouseIndices[14] = 2;

		HouseIndices[15] = 2;
		HouseIndices[16] = 6;
		HouseIndices[17] = 5;

		HouseIndices[18] = 2;
		HouseIndices[19] = 5;
		HouseIndices[20] = 1;

		HouseIndices[21] = 1;
		HouseIndices[22] = 5;
		HouseIndices[23] = 4;

		HouseIndices[24] = 1;
		HouseIndices[25] = 4;
		HouseIndices[26] = 0;


		HouseIndices[27] = 4;
		HouseIndices[28] = 5;
		HouseIndices[29] = 6;


		HouseIndices[30] = 4;
		HouseIndices[31] = 6;
		HouseIndices[32] = 7;


		HouseIndices[33] = 8;
		HouseIndices[34] = 9;
		HouseIndices[35] = 10;


		HouseIndices[36] = 8;
		HouseIndices[37] = 10;
		HouseIndices[38] = 11;


		HouseIndices[39] = 8;
		HouseIndices[40] = 12;
		HouseIndices[41] = 15;


		HouseIndices[42] = 8;
		HouseIndices[43] = 15;
		HouseIndices[44] = 11;


		HouseIndices[45] = 11;
		HouseIndices[46] = 15;
		HouseIndices[47] = 14;


		HouseIndices[48] = 11;
		HouseIndices[49] = 14;
		HouseIndices[50] = 10;


		HouseIndices[51] = 10;
		HouseIndices[52] = 14;
		HouseIndices[53] = 13;


		HouseIndices[54] = 10;
		HouseIndices[55] = 13;
		HouseIndices[56] = 9;


		HouseIndices[57] = 9;
		HouseIndices[58] = 13;
		HouseIndices[59] = 12;


		HouseIndices[60] = 9;
		HouseIndices[61] = 12;
		HouseIndices[62] = 8;


		HouseIndices[63] = 12;
		HouseIndices[64] = 13;
		HouseIndices[65] = 14;


		HouseIndices[66] = 12;
		HouseIndices[67] = 14;
		HouseIndices[68] = 15;

		textures[0] = Texture("microsoft.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE);
    }

	Model getModel() {

		std::vector<Vertex> vertices(HouseVertices, HouseVertices + sizeof(HouseVertices) / sizeof(Vertex));
		std::vector<GLuint> indices(HouseIndices, HouseIndices + sizeof(HouseIndices) / sizeof(GLuint));
		std::vector <Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
		Mesh cube(vertices, indices, tex);
		std::vector<Mesh> meshes = { cube };
		Model cubeModel(meshes);
		return cubeModel;
	}
};
