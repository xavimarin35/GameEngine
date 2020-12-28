#include "PanelScene.h"
#include "ModuleCamera3D.h"
#include "Viewport.h"
#include "ModuleWindow.h"
#include "ModuleRenderer3D.h"
#include "ModuleSceneIntro.h"

PanelScene::PanelScene()
{
}

PanelScene::~PanelScene()
{
}

bool PanelScene::Start()
{
	this->active = true;

	return true;
}

bool PanelScene::Draw()
{
	if (!App->gui->Pscene->active)
		return false;

	if (App->gui->Pscene->active)
	{
		if (ImGui::Begin("Scene", &active, ImGuiWindowFlags_NoScrollbar))
		{
			if (ImGui::IsWindowHovered()) App->camera->isOnScene = true;
			else App->camera->isOnScene = false;
		}

		/*ImVec2 vMin = ImGui::GetWindowContentRegionMin();
		ImVec2 vMax = ImGui::GetWindowContentRegionMax();

		vMin.x += ImGui::GetWindowPos().x;
		vMin.y += ImGui::GetWindowPos().y;
		vMax.x += ImGui::GetWindowPos().x;
		vMax.y += ImGui::GetWindowPos().y;

		ImGui::GetForegroundDrawList()->AddRect(vMin, vMax, IM_COL32(255, 255, 0, 255));

		new_size = ImGui::GetContentRegionAvail();*/

		ImVec2 newSize = ImGui::GetWindowSize();
		if (newSize.x != size.x || newSize.y != size.y)
		{
			resizedLastFrame = true;
			size = newSize;
			float newAR = size.x / size.y;
			App->camera->GetEditorCamera()->GetComponentCamera()->SetRatio(newAR);
		}
		else
			resizedLastFrame = false;

		ImGui::Image((ImTextureID)App->renderer3D->scene_tex, ImVec2((float)newSize.x, (float)newSize.y), ImVec2(0, 1), ImVec2(1, 0));

		ImGuizmo::SetDrawlist();

		if (App->scene_intro->GOselected != nullptr && App->scene_intro->GOselected->data.active)
			App->gui->DrawGuizmo();
		
		ImGui::End();
	}

	return true;
}
