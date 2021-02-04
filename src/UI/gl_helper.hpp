#pragma once
#include <glad/glad.h>

class Framebuffer {
public:
	Framebuffer() = default;
	Framebuffer(Framebuffer&& other) noexcept;
	Framebuffer(int width, int height);
	~Framebuffer();

	Framebuffer& operator=(Framebuffer&& other) noexcept;
	Framebuffer& operator=(const Framebuffer& other) = delete;

	operator bool() const;

	GLenum framebuffer = 0;
	GLenum color = 0;
private:
	GLenum depth_stencil = 0;
};

class Shader {
public:
	Shader() = default;
	Shader(Shader&& other) noexcept;
	Shader(const char* vert, const char* frag);

	~Shader();

	Shader& operator=(Shader&& other) noexcept;
	Shader& operator=(const Shader& other) = delete;

	operator bool() const;

	void set_float(const std::string& name, float val);
	void set_int(const std::string& name, int val);
	void set_texture(const std::string& name, GLenum tex);

	void use();
	void draw();
private:
	static GLuint compile_shaders(const char* vert, const char* frag);

	GLuint vao_id = 0, uv_id = 0, vb_id = 0;
	GLuint program = 0;
};
