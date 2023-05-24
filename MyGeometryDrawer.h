#include<glad/glad.h>
#include <corecrt_math.h>
#include "DrawOutput.h"

#pragma once

class GeometryDrawer
{
public:
	void Draw();
	static GLfloat* TriangleVertices();
	static DrawOutput* DrawTriangle();
};

