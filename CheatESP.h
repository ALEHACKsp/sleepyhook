#pragma once
namespace CheatESP
{
	static float width = 0;
	static float height = 0;
	void DrawPlayer(cActor* pActor, bool bIsBot, bool bIsHenchMan, bool bIsHenchManNEW, bool bIsHenchManGang1, bool bIsHenchManGang2, bool bIsHenchManGang3);
	void DrawMarker(cActor* pActor, const char* sMarkerName);
	void DrawMarkerFromTier(cActor* pActor, const char* sMarkerName, BYTE bTier);

	std::string TextFormat(const char* format, ...)
	{
		va_list argptr;
		va_start(argptr, format);

		char buffer[2048];
		vsprintf(buffer, format, argptr);

		va_end(argptr);

		return buffer;
	}
	std::string string_To_UTF8(const std::string& str)
	{
		int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

		wchar_t* pwBuf = new wchar_t[nwLen + 1];
		ZeroMemory(pwBuf, nwLen * 2 + 2);

		::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

		int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

		char* pBuf = new char[nLen + 1];
		ZeroMemory(pBuf, nLen + 1);

		::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

		std::string retStr(pBuf);

		delete[]pwBuf;
		delete[]pBuf;

		pwBuf = NULL;
		pBuf = NULL;

		return retStr;

	}
	void DrawStrokeText(int x, int y, const ImVec4& color, const char* str)
	{
		ImFont a;
		std::string utf_8_1 = std::string(str);
		std::string utf_8_2 = string_To_UTF8(utf_8_1);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::GetColorU32(color), utf_8_2.c_str());
	}
	void DrawRoundedRect(int x, int y, int w, int h, ImU32& color, int thickness)
	{
		ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(w, h), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 0, 0, 3);
		ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(w, h), ImGui::GetColorU32(color), 0, 0, thickness);
	}
	void DrawLine(int x1, int y1, int x2, int y2, const ImVec4& color, int thickness)
	{
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::GetColorU32(color), thickness);
	}
	void DrawCorneredBox(int X, int Y, int W, int H, const ImU32& color, int thickness) {

		float lineW = (W / 3);
		float lineH = (H / 3);

		//black outlines
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);

		//corners
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::GetColorU32(color), thickness);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::GetColorU32(color), thickness);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::GetColorU32(color), thickness);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::GetColorU32(color), thickness);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::GetColorU32(color), thickness);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::GetColorU32(color), thickness);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
	}
	bool GetDrawPos(cActor* pActor, RECT& vDrawPos, Vector4 vColor);
	bool GetPlayerName(cActor* pActor, char* sPlayerName);
}

auto BoxColor = ImGui::GetColorU32({ 255, 255,255, 255 });

void CheatESP::DrawPlayer(cActor* pActor, bool bIsBot, bool bIsHenchMan, bool bIsHenchManNEW, bool bIsHenchManGang1, bool bIsHenchManGang2, bool bIsHenchManGang3)
{
	if (!pActor) return;
	if (!pActor->SceneComponent) return;
	if (!pActor->PlayerState) return;
	if (!pActor->PlayerMesh) return;
	if (!Settings::Menu::ESP_OnTeam && Settings::Local::LocalTeam != 0)
		if (Settings::Local::LocalTeam == pActor->PlayerState->TeamIndex)
			return;

	Vector4 DrawColor;
	if (Settings::Menu::ESP_CheckKO && pActor->IsDBNO())
		DrawColor = Settings::Menu::ESPKnockedDownColor;
	else if (Settings::Menu::ESP_CheckVisible && EngineHelper::Internal::LineOfSightTo(pActor))
		DrawColor = Settings::Menu::ESPVisibleColor;
	else if (bIsBot)
		DrawColor = Settings::Menu::ESPBotColor;
	else if (Settings::Menu::MARK_Shark)
		DrawColor = Settings::Menu::SharkColor;
	else if (Settings::Menu::MARK_Llama)
		DrawColor = Settings::Menu::LlamaColor;
	else if (bIsHenchMan || bIsHenchManNEW || bIsHenchManGang1 || bIsHenchManGang2 || bIsHenchManGang3)
		DrawColor = Settings::Menu::ESPHenchManColor;
	else
		DrawColor = Settings::Menu::ESPColor;

	RECT rDraw;
	if (!GetDrawPos(pActor, rDraw, DrawColor)) // We draw bones in here.
		return;

	// 2D Box
	if (Settings::Menu::ESP_2DBox)
	{

		RenderHelper::Box(Vector2(rDraw.left, rDraw.top), Vector2(rDraw.right, rDraw.bottom), Settings::Menu::ESP_Thickness, DrawColor);


		// down is the fill box thing so dont enable shit crashes too much

		//if (Settings::Menu::ESP_FillBox)
			// RenderHelper::Box(Vector2(rDraw.left, rDraw.top), Vector2(rDraw.right, rDraw.bottom), Settings::Menu::ESP_Thickness, DrawColor.ToColor(.15f), DrawColor);
		//else
		//	RenderHelper::Box(Vector2(rDraw.left, rDraw.top), Vector2(rDraw.right, rDraw.bottom), Settings::Menu::ESP_Thickness, DrawColor);
	}

	if (Settings::Menu::ESP_CornerESP)
	{
		RenderHelper::Box(Vector2(rDraw.top), Vector2(rDraw.bottom), Settings::Menu::ESP_Thickness, DrawColor);
	}

	if (Settings::Menu::ESP_Crosshair)
	{
		DrawLine(width / 2 - Settings::Menu::ESP_CrosshairScale, height / 2 - 0, width / 2 + Settings::Menu::ESP_CrosshairScale, height / 2 + 0, ImVec4(color_red, color_green, color_blue, 255), Settings::Menu::ESP_CrosshairThickness); //white
		DrawLine(width / 2 + 0, height / 2 - Settings::Menu::ESP_CrosshairScale, width / 2 - 0, height / 2 + Settings::Menu::ESP_CrosshairScale, ImVec4(color_red, color_green, color_blue, 255), Settings::Menu::ESP_CrosshairThickness); //white		
	}

	// Only when we have a valid local pawn.
	if (Settings::Local::bIsValid)
	{
		const float YOffset = 2;

		bool bHasDrawText = false;
		char sDrawText[1024];

		// Name & Distance
		
	
		if (Settings::Menu::ESP_Distance)
		{
			bHasDrawText = true;
			sprintf(sDrawText, _xor("[%.0fM]\0").c_str(), Settings::Local::Camera.Location.Distance(pActor->SceneComponent->RelativeLocation));
		}

		if (bHasDrawText)
		{
			if (Settings::Menu::ESP_FillText)
				RenderHelper::Text(RenderHelper::pFonts[1], Vector2(rDraw.left + (rDraw.right / 2), rDraw.top - (Settings::Menu::ESP_FontSize + YOffset)), sDrawText, DrawColor, Settings::Menu::TextFillColor, Settings::Menu::ESP_FontSize, true);
			else
				RenderHelper::Text(RenderHelper::pFonts[1], Vector2(rDraw.left + (rDraw.right / 2), rDraw.top - (Settings::Menu::ESP_FontSize + YOffset)), sDrawText, DrawColor, Settings::Menu::ESP_FontSize, true);
		}
	}
}

void CheatESP::DrawMarker(cActor* pActor, const char* sMarkerName)
{
	if (!pActor) return;
	if (!pActor->SceneComponent) return;

	float fDistance = Settings::Local::Camera.Location.Distance(pActor->SceneComponent->RelativeLocation);
	float fRadius = (fDistance > 50) ? 3.0f : 5.5f;
	if (fDistance > Settings::Menu::MARK_MaxDistance || fDistance < 10.0f)
		return;

	Vector3 vScreenPos;
	if (!EngineHelper::Internal::WorldToScreen(pActor->SceneComponent->RelativeLocation, &vScreenPos))
		return;

	char sBuffer[256];
	if (Settings::Menu::ESP_Distance)
		sprintf(sBuffer, _xor("[%.0fM] %s\0").c_str(), fDistance, sMarkerName);
	else
		sprintf(sBuffer, _xor("%s\0").c_str(), sMarkerName);

	RenderHelper::Cirlce(vScreenPos.ToVec2(), Settings::Menu::ESP_Thickness, fRadius, Settings::Menu::MarkerColor);
	vScreenPos.y += (fRadius + 3.0f);

	if (Settings::Menu::ESP_FillText)
		RenderHelper::Text(RenderHelper::pFonts[1], vScreenPos.ToVec2(), sBuffer, Settings::Menu::MarkerColor, Settings::Menu::TextFillColor, Settings::Menu::ESP_FontSize, true);
	else
		RenderHelper::Text(RenderHelper::pFonts[1], vScreenPos.ToVec2(), sBuffer, Settings::Menu::MarkerColor, Settings::Menu::ESP_FontSize, true);
}

void CheatESP::DrawMarkerFromTier(cActor* pActor, const char* sMarkerName, BYTE bTier)
{
	if (!pActor) return;
	if (!pActor->SceneComponent) return;

	float fDistance = Settings::Local::Camera.Location.Distance(pActor->SceneComponent->RelativeLocation);
	float fRadius = (fDistance > 50) ? 3.0f : 5.5f;
	if (fDistance > Settings::Menu::MARK_MaxDistance)
		return;

	Vector3 vScreenPos;
	if (!EngineHelper::Internal::WorldToScreen(pActor->SceneComponent->RelativeLocation, &vScreenPos))
		return;

	char sBuffer[256];
	if (Settings::Menu::ESP_Distance)
		sprintf(sBuffer, _xor("[%.0fM] %s\0").c_str(), fDistance, sMarkerName);
	else
		sprintf(sBuffer, _xor("%s\0").c_str(), sMarkerName);

	RenderHelper::Cirlce(vScreenPos.ToVec2(), Settings::Menu::ESP_Thickness, fRadius, EngineHelper::Toggle::TierToColor(bTier));
	vScreenPos.y += (fRadius + 3.0f);

	if (Settings::Menu::ESP_FillText)
		RenderHelper::Text(RenderHelper::pFonts[1], vScreenPos.ToVec2(), sBuffer, EngineHelper::Toggle::TierToColor(bTier), Settings::Menu::TextFillColor, Settings::Menu::ESP_FontSize, true);
	else
		RenderHelper::Text(RenderHelper::pFonts[1], vScreenPos.ToVec2(), sBuffer, EngineHelper::Toggle::TierToColor(bTier), Settings::Menu::ESP_FontSize, true);
}


bool CheatESP::GetDrawPos(cActor* pActor, RECT& vDrawPos, Vector4 vColor)
{
	if (!pActor) return false;
	if (!pActor->SceneComponent) return false;
	if (!pActor->PlayerMesh) return false;

	Vector3 vPos[100];
	std::vector<int32_t> nBoneIDS = { 66 ,65 ,36 ,2 ,9 ,62,10,38,11,39,67,74,73,80,68,75,71,78,72,79 };
	std::vector<std::vector<int32_t>> nBonePairs = {
	{99, 1},
	{1, 3},
	{2, 4},
	{2, 5},
	{4, 6},
	{5, 7},
	{6, 8},
	{7, 9},
	{3, 10},
	{3, 11},
	{10, 12},
	{11, 13},
	{12, 14},
	{13, 15},
	{14, 16},
	{15, 17},
	{16, 18},
	{17, 19}
	};

	size_t nIndex = 0;

	float minX = FLT_MAX;
	float maxX = -FLT_MAX;
	float minY = FLT_MAX;
	float maxY = -FLT_MAX;

	for (auto ID : nBoneIDS)
	{
		bool bResult = false;
		if (ID == 66)
		{
			Vector3 vWorldPos;
			if (EngineHelper::Internal::GetBoneWorld(pActor, 66, &vWorldPos))
			{
				EngineHelper::Internal::WorldToScreen(vWorldPos, &vPos[99]);
				vWorldPos.z += 15.5f;
				bResult = EngineHelper::Internal::WorldToScreen(vWorldPos, &vPos[nIndex]);
			}
		}
		else
		{
			nIndex++;
			bResult = EngineHelper::Internal::GetBoneScreen(pActor, ID, &vPos[nIndex]);
		}

		if (bResult)
		{
			minX = min(vPos[nIndex].x, minX);
			maxX = max(vPos[nIndex].x, maxX);
			minY = min(vPos[nIndex].y, minY);
			maxY = max(vPos[nIndex].y, maxY);
		}
	}

	RECT rResult;
	rResult.top = minY;
	rResult.bottom = maxY - minY;
	rResult.left = minX;
	rResult.right = maxX - minX;

	vDrawPos = rResult;

	// Draw Bones..
	if (Settings::Menu::ESP_Bones)
		for (auto Pair : nBonePairs)
			RenderHelper::Line(vPos[Pair.at(0)].ToVec2(), vPos[Pair.at(1)].ToVec2(), Settings::Menu::ESP_Thickness, vColor);

	return true;
}

bool CheatESP::GetPlayerName(cActor* pActor, char* sPlayerName)
{
	if (!pActor) return false;
	if (!pActor->PlayerState)return false;
	if (!Hook_ProcessEvent::Details::bIsHooked) return false;

	FString Buffer;
	SpoofCall(Hook_ProcessEvent::HkProcessEvent, (PVOID)pActor->PlayerState, (PVOID)Settings::BaseOffsets::GetPlayerName, (PVOID)&Buffer, (PVOID)0);
	if (!Buffer.c_str())
		return false;

	wcstombs(sPlayerName, Buffer.c_str(), sizeof(sPlayerName));

	EngineHelper::UObjects::FreeObjName((uintptr_t)Buffer.c_str());

	return true;
}

