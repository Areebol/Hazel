#include "hzpch.h"
#include "Shader.h"

#include <glad/glad.h>

Hazel::Shader::Shader(const std::string& vertexSrc, const std::string& fragmentSrc)
{
	// 1.1. 创建顶点着色器
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	// Send the vertex shader source code to GL
	// Note that std::string's .c_str is NULL character terminated.
	// 1.2. 附加顶点着色器源码到顶点着色器对象
	const GLchar* source = vertexSrc.c_str();
	glShaderSource(vertexShader, 1, &source, 0);
	// 1.3. 编译顶点着色器
	glCompileShader(vertexShader);
	// 1.4. 检查编译结果
	GLint isCompiled = 0;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		// 1.4.2. 打印编译失败信息
		GLint maxLength = 0;
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

		// We don't need the shader anymore.
		glDeleteShader(vertexShader);

		HZ_CORE_ERROR("{0}", infoLog.data());
		HZ_CORE_ASSERT(false, "Vertex shader compilation failure!");
		return;
	}

	// 2.1. 创建片段着色器
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	// Send the fragment shader source code to GL
	// Note that std::string's .c_str is NULL character terminated.
	// 2.2. 附加片段着色器源码到着色器对象
	source = fragmentSrc.c_str();
	glShaderSource(fragmentShader, 1, &source, 0);
	// 2.2. 编译
	glCompileShader(fragmentShader);
	// 2.4. 检查编译结果
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		// 2.4.2 打印错误信息
		GLint maxLength = 0;
		glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

		// We don't need the shader anymore.
		glDeleteShader(fragmentShader);
		// Either of them. Don't leak shaders.
		glDeleteShader(vertexShader);

		HZ_CORE_ERROR("{0}", infoLog.data());
		HZ_CORE_ASSERT(false, "Fragment shader compilation failure!");
		return;
	}

	// Vertex and fragment shaders are successfully compiled.
	// Now time to link them together into a program.
	// Get a program object.
	// 3.1. 创建渲染程序对象
	m_RendererID = glCreateProgram();
	GLuint program = m_RendererID;

	// 3.2. 连接shader和程序对象
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	// 3.3. 连接程序对象和GL
	glLinkProgram(program);

	// 3.4. 检查链接是否成功
	GLint isLinked = 0;
	glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

		// We don't need the program anymore.
		glDeleteProgram(program);
		// Don't leak shaders either.
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		HZ_CORE_ERROR("{0}", infoLog.data());
		HZ_CORE_ASSERT(false, "Shader link failure!");
		return;
	}

	// Always detach shaders after a successful link.
	// 3.5. 删除着色器对象
	glDetachShader(program, vertexShader);
	glDetachShader(program, fragmentShader);
}

Hazel::Shader::~Shader()
{
	glDeleteProgram(m_RendererID);
}

void Hazel::Shader::Bind() const
{
	glUseProgram(m_RendererID);
}

void Hazel::Shader::Unbind() const
{
	glUseProgram(0);
}
