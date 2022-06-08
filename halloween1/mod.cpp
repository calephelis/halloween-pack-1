#include "pch.h"

HelperFunctions helper;

std::string VampireCostume[] = { "Black", "Purple" };
std::string WitchCostume[] = { "Red", "Pink" };
std::string CharaSelect[] = { "CSPlus", "Vanilla", "Off/Disabled" };

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		helper = helperFunctions;

		WriteData((int*)0x73094E, 0x1DE9BD4); // attaches Rouge's Treasure Scope model to right hand instead of head

		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");
		for (int i = 0; i < 2; i++)
			VampireCostume[i] = config->getString("CostumeColor", "OutfitColor", "Black");
		for (int i = 0; i < 2; i++)
			WitchCostume[i] = config->getString("CostumeColor", "EyeshadowColor", "Red");
		for (int i = 0; i < 3; i++)
			CharaSelect[i] = config->getString("UI", "StageSel", "CSPlus");
		delete config;

		if (VampireCostume->compare("Black") == 0)
		{
			helper.ReplaceFile("resource\\gd_PC\\PRS\\teriostex.pak", "resource\\gd_PC\\PRS\\teriostexb.pak");
			helper.ReplaceFile("resource\\gd_PC\\PRS\\sh_efftex.pak", "resource\\gd_PC\\PRS\\sh_efftexb.pak");
		}
		if (VampireCostume->compare("Purple") == 0)
		{
			helper.ReplaceFile("resource\\gd_PC\\PRS\\teriostex.pak", "resource\\gd_PC\\PRS\\teriostexp.pak");
			helper.ReplaceFile("resource\\gd_PC\\PRS\\sh_efftex.pak", "resource\\gd_PC\\PRS\\sh_efftexp.pak");
		}

		if (WitchCostume->compare("Red") == 0)
		{
			helper.ReplaceFile("resource\\gd_PC\\PRS\\rougetex.pak", "resource\\gd_PC\\PRS\\rougetexr.pak");
			helper.ReplaceFile("resource\\gd_PC\\PRS\\r_efftex.pak", "resource\\gd_PC\\PRS\\r_efftexr.pak");
		}
		if (WitchCostume->compare("Pink") == 0)
		{
			helper.ReplaceFile("resource\\gd_PC\\PRS\\rougetex.pak", "resource\\gd_PC\\PRS\\rougetexp.pak");
			helper.ReplaceFile("resource\\gd_PC\\PRS\\r_efftex.pak", "resource\\gd_PC\\PRS\\r_efftexp.pak");
		}

		if (CharaSelect->compare("Vanilla") == 0)
		{
			helper.ReplaceFile("resource\\gd_PC\\PRS\\stageMap.pak", "resource\\gd_PC\\PRS\\stageMap_ncs.pak");
			helper.ReplaceFile("resource\\gd_PC\\PRS\\fileSelect.pak", "resource\\gd_PC\\fileSelect\\fileSelect.pak");
			helper.ReplaceFile("resource\\gd_PC\\PRS\\fileSelect_dc.pak", "resource\\gd_PC\\fileSelect\\fileSelect_dc.pak");
		}
		if (CharaSelect->compare("CSPlus") == 0)
		{
			helper.ReplaceFile("resource\\gd_PC\\PRS\\stageMap.pak", "resource\\gd_PC\\PRS\\stageMap_cs.pak");
			helper.ReplaceFile("resource\\gd_PC\\PRS\\fileSelect.pak", "resource\\gd_PC\\fileSelect\\fileSelect.pak");
			helper.ReplaceFile("resource\\gd_PC\\PRS\\fileSelect_dc.pak", "resource\\gd_PC\\fileSelect\\fileSelect_dc.pak");
		}
		if (CharaSelect->compare("Off/Disabled") == 0)
		{
			return;
		}
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}