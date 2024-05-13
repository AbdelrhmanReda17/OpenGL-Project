#include "Model.h"

class Home {
public:
    Vertex HouseVertices[36]; // Declare an array of Vertex objects
	GLuint HouseIndices[99]; //+6 +6
	Texture textures[1];

    Home() {
        // Initialize the array of Vertex objects
		// 
		// 
		//base
        HouseVertices[0] = Vertex{ glm::vec3(-0.2f, -0.00001f, 0.2f), glm::vec3(0.8, 0.8, 0.8) };
        HouseVertices[1] = Vertex{ glm::vec3(-0.2f, -0.00001f, -0.2f), glm::vec3(0.8, 0.8, 0.8) };
        HouseVertices[2] = Vertex{ glm::vec3(0.0f, -0.00001f, -0.2f), glm::vec3(0.8, 0.8, 0.8) }; /* front right buttom*/
        HouseVertices[3] = Vertex{ glm::vec3(0.0f, -0.00001f, 0.2f), glm::vec3(0.8, 0.8, 0.8) }; /*front left buttom*/


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

		//First Floor

		//DOOR
		HouseVertices[16] = Vertex{ glm::vec3(0.001f, 0.0f, 0.05f), glm::vec3(0.541, 0.294, 0.078) }; //buttom left
		HouseVertices[17] = Vertex{ glm::vec3(0.001f, 0.0f, -0.05f), glm::vec3(0.541, 0.294, 0.078) }; //buttom right
		HouseVertices[18] = Vertex{ glm::vec3(0.001f, -0.15f, 0.05f), glm::vec3(0.541, 0.294, 0.078) }; //top left
		HouseVertices[19] = Vertex{ glm::vec3(0.001f, -0.15f, -0.05f), glm::vec3(0.541, 0.294, 0.078) }; //top right

		//Left Window
		HouseVertices[20] = Vertex{ glm::vec3(0.001f, -0.2f, 0.18f), glm::vec3(0.541, 0.294, 0.078) }; //buttom left
		HouseVertices[21] = Vertex{ glm::vec3(0.001f, -0.2f, 0.10f), glm::vec3(0.541, 0.294, 0.078) }; //buttom right
		HouseVertices[22] = Vertex{ glm::vec3(0.001f, -0.28f, 0.18f), glm::vec3(0.541, 0.294, 0.078) }; //top left
		HouseVertices[23] = Vertex{ glm::vec3(0.001f, -0.28f, 0.10f), glm::vec3(0.541, 0.294, 0.078) }; //top right

		//right Window
		HouseVertices[24] = Vertex{ glm::vec3(0.001f, -0.2f, -0.18f), glm::vec3(0.541, 0.294, 0.078) }; //buttom left
		HouseVertices[25] = Vertex{ glm::vec3(0.001f, -0.2f, -0.10f), glm::vec3(0.541, 0.294, 0.078) }; //buttom right
		HouseVertices[26] = Vertex{ glm::vec3(0.001f, -0.28f, -0.18f), glm::vec3(0.541, 0.294, 0.078) }; //top left
		HouseVertices[27] = Vertex{ glm::vec3(0.001f, -0.28f, -0.10f), glm::vec3(0.541, 0.294, 0.078) }; //top right



		//Second FLoor

		//Left Window
		HouseVertices[28] = Vertex{ glm::vec3(0.001f, -0.5f, 0.18f), glm::vec3(0.541, 0.294, 0.078) }; //buttom left
		HouseVertices[29] = Vertex{ glm::vec3(0.001f, -0.5f, 0.10f), glm::vec3(0.541, 0.294, 0.078) }; //buttom right
		HouseVertices[30] = Vertex{ glm::vec3(0.001f, -0.58f, 0.18f), glm::vec3(0.541, 0.294, 0.078) }; //top left
		HouseVertices[31] = Vertex{ glm::vec3(0.001f, -0.58f, 0.10f), glm::vec3(0.541, 0.294, 0.078) }; //top right

		//Right Window

		HouseVertices[32] = Vertex{ glm::vec3(0.001f, -0.5f, -0.18f), glm::vec3(0.541, 0.294, 0.078) }; //buttom left
		HouseVertices[33] = Vertex{ glm::vec3(0.001f, -0.5f, -0.10f), glm::vec3(0.541, 0.294, 0.078) }; //buttom right
		HouseVertices[34] = Vertex{ glm::vec3(0.001f, -0.58f, -0.18f), glm::vec3(0.541, 0.294, 0.078) }; //top left
		HouseVertices[35] = Vertex{ glm::vec3(0.001f, -0.58f, -0.10f), glm::vec3(0.541, 0.294, 0.078) }; //top right

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

		//First FLoor

		//door
		HouseIndices[69] = 16;
		HouseIndices[70] = 17;
		HouseIndices[71] = 18;
		HouseIndices[72] = 19;
		HouseIndices[73] = 17;
		HouseIndices[74] = 18;

		//left window
		HouseIndices[75] = 20;
		HouseIndices[76] = 21;
		HouseIndices[77] = 22;
		HouseIndices[78] = 23;
		HouseIndices[79] = 21;
		HouseIndices[80] = 22;

		//right window 
		HouseIndices[81] = 24;
		HouseIndices[82] = 25;
		HouseIndices[83] = 26;
		HouseIndices[84] = 27;
		HouseIndices[85] = 25;
		HouseIndices[86] = 26;

		//Second FLoor

		//left window
		HouseIndices[87] = 28;
		HouseIndices[88] = 29;
		HouseIndices[89] = 30;
		HouseIndices[90] = 31;
		HouseIndices[91] = 29;
		HouseIndices[92] = 30;

		//right window
		HouseIndices[93] = 32;
		HouseIndices[94] = 33;
		HouseIndices[95] = 34;
		HouseIndices[96] = 35;
		HouseIndices[97] = 33;
		HouseIndices[98] = 34;

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
