#pragma once
class ShaderHandler
{
	public:
		const char* defaultFragShader = "frag.glsl";
		const char* defaultVertShader = "vertex.glsl";
		static char* ImportDefaultVertexShader();
		static char* ImportDefaultFragShader();
		
};

