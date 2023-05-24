#include "MyGeometryDrawer.h"
#include "ShaderHandler.h"

void GeometryDrawer::Draw() {

}

GLfloat* GeometryDrawer::TriangleVertices()
{
	GLfloat vertices[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f
	};

	//int v = sizeof(vertices) / sizeof(vertices[0]);

	//GLfloat* c = new GLfloat[v];

	//for (int i = 0; i < v; i++) {
	//	c[i] = vertices[i];
	//}

	return vertices;

}

DrawOutput* GeometryDrawer::DrawTriangle() {

	GLfloat vertices[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f
	};

	char* defaultVertexShader = ShaderHandler::ImportDefaultVertexShader();
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &defaultVertexShader, NULL);
	glCompileShader(vertexShader);

	char* defaultFragmentShader = ShaderHandler::ImportDefaultFragShader();
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader,1, &defaultFragmentShader, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	
	
	GLuint VAO, VBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	DrawOutput* drawOutput = new DrawOutput();
	drawOutput->VAO = VAO;
	drawOutput->VBO = VBO;
	drawOutput->shaderProgram = shaderProgram;

	return drawOutput;

}
