#pragma once
#include  <X11/Xlib.h>
#include  <X11/Xatom.h>
#include <X11/Xutil.h>
#include <GLES2/gl2.h>
#include <EGL/egl.h>
#include <memory>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

class PixelSurface {
public:
	PixelSurface();
	void initEGL();
	void closeEGL();
	const EGLDisplay getEGLDisplay() { return this->eglDisplay; };
	const EGLSurface getEGLSurface() { return this->eglSurface; };
	PixelSurface(const PixelSurface& s) = delete;
	PixelSurface(PixelSurface&& s) = delete;
	PixelSurface& operator=(const PixelSurface& s) = delete;
	PixelSurface& operator=(PixelSurface&& s) = delete;
	~PixelSurface();

	GLuint windowWidth=1280;
	GLuint windowHeight=720;
	Display* xDisplay;

private: 
	void initDisplayClient();
	void closeDisplayClient();
	void logConfigs();
	Window xWindow;

	EGLDisplay eglDisplay;
	std::vector<EGLConfig> configs;
	EGLContext	eglContext;
	EGLSurface 	eglSurface;
	EGLint major;
	EGLint minor;

	std::vector<EGLint> attribList;
};
