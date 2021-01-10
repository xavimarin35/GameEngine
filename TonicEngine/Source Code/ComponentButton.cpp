#include "Application.h"
#include "ComponentButton.h"
#include "ButtonUI.h"
#include "ModuleSceneIntro.h"
#include "ModuleGUI.h"

ComponentButton::ComponentButton(GameObject* parent) : Component(COMPONENT_TYPE::BUTTON_UI, parent)
{
	type = COMPONENT_TYPE::BUTTON_UI;
	object = parent;

	button = new ButtonUI(this);

	hover_color = { 0.9f, 0.9f, 0.9f };
	pressed_color = { 0.7f, 0.7f, 0.7f };
}

ComponentButton::~ComponentButton()
{
}

bool ComponentButton::Start()
{
	return true;
}

bool ComponentButton::Update()
{
	button->Update();

	return true;
}

bool ComponentButton::CleanUp()
{
	return true;
}

void ComponentButton::Draw()
{ 

}

void ComponentButton::DrawInspector()
{
	GameObject* go = App->scene_intro->GOselected;

	ImGui::Spacing();

	if (ImGui::CollapsingHeader("UI - Button", ImGuiTreeNodeFlags_DefaultOpen) && go->GetComponentButtonUI() != nullptr)
	{
		ImGui::Spacing();

		ImGui::Text("This is the Button component");

		ImGui::Spacing();
		ImGui::Separator();

		ImGui::PushItemWidth(150);
		if (ImGui::Combo("Event Call", &button_function, "Load Street\0\Change vsync"))
		{
			switch (button_function)
			{
			case 0:
				App->scene_intro->Create3DObject(OBJECTS3D::STREET);
				break;

			case 1:
				App->vsyncB = !App->vsyncB;

				if (App->vsyncB) {
					SDL_GL_SetSwapInterval(1);
					LOG_C("VSYNC activated");
				}

				else if (!App->vsyncB){
					SDL_GL_SetSwapInterval(0);
					LOG_C("VSYNC deactivated");
				}
				break;
			}
		}
	}
}
