#ifndef _COMPONENT_CANVAS_H_
#define _COMPONENT_CANVAS_H_

#include "Component.h"
#include "Math.h"
#include "SDL\include\SDL_rect.h"

#include <list>
#include <string>

class ElementUI;
class CanvasUI;
class GameObject;

class ComponentCanvas : public Component
{
public:

	ComponentCanvas(GameObject* parent);
	~ComponentCanvas();

	bool Start();
	bool Update();
	bool CleanUp();
	void Draw();

private:

	CanvasUI* canvas;
	bool render_elements = true;
};

#endif