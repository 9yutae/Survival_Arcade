// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Survival_Arcade/SpartaPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpartaPlayerController() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ASpartaPlayerController();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ASpartaPlayerController_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_Survival_Arcade();
// End Cross Module References

// Begin Class ASpartaPlayerController Function ContinueGame
struct Z_Construct_UFunction_ASpartaPlayerController_ContinueGame_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Game Start (\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd)\n" },
#endif
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Game Start (\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpartaPlayerController_ContinueGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpartaPlayerController, nullptr, "ContinueGame", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpartaPlayerController_ContinueGame_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpartaPlayerController_ContinueGame_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASpartaPlayerController_ContinueGame()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpartaPlayerController_ContinueGame_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASpartaPlayerController::execContinueGame)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ContinueGame();
	P_NATIVE_END;
}
// End Class ASpartaPlayerController Function ContinueGame

// Begin Class ASpartaPlayerController Function EndGame
struct Z_Construct_UFunction_ASpartaPlayerController_EndGame_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Game \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Game \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpartaPlayerController_EndGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpartaPlayerController, nullptr, "EndGame", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpartaPlayerController_EndGame_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpartaPlayerController_EndGame_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASpartaPlayerController_EndGame()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpartaPlayerController_EndGame_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASpartaPlayerController::execEndGame)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EndGame();
	P_NATIVE_END;
}
// End Class ASpartaPlayerController Function EndGame

// Begin Class ASpartaPlayerController Function GetHUDWidget
struct Z_Construct_UFunction_ASpartaPlayerController_GetHUDWidget_Statics
{
	struct SpartaPlayerController_eventGetHUDWidget_Parms
	{
		UUserWidget* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASpartaPlayerController_GetHUDWidget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpartaPlayerController_eventGetHUDWidget_Parms, ReturnValue), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASpartaPlayerController_GetHUDWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpartaPlayerController_GetHUDWidget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpartaPlayerController_GetHUDWidget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpartaPlayerController_GetHUDWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpartaPlayerController, nullptr, "GetHUDWidget", nullptr, nullptr, Z_Construct_UFunction_ASpartaPlayerController_GetHUDWidget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASpartaPlayerController_GetHUDWidget_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASpartaPlayerController_GetHUDWidget_Statics::SpartaPlayerController_eventGetHUDWidget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpartaPlayerController_GetHUDWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpartaPlayerController_GetHUDWidget_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASpartaPlayerController_GetHUDWidget_Statics::SpartaPlayerController_eventGetHUDWidget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASpartaPlayerController_GetHUDWidget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpartaPlayerController_GetHUDWidget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASpartaPlayerController::execGetHUDWidget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UUserWidget**)Z_Param__Result=P_THIS->GetHUDWidget();
	P_NATIVE_END;
}
// End Class ASpartaPlayerController Function GetHUDWidget

// Begin Class ASpartaPlayerController Function ShowGameHUD
struct Z_Construct_UFunction_ASpartaPlayerController_ShowGameHUD_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpartaPlayerController_ShowGameHUD_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpartaPlayerController, nullptr, "ShowGameHUD", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpartaPlayerController_ShowGameHUD_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpartaPlayerController_ShowGameHUD_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASpartaPlayerController_ShowGameHUD()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpartaPlayerController_ShowGameHUD_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASpartaPlayerController::execShowGameHUD)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowGameHUD();
	P_NATIVE_END;
}
// End Class ASpartaPlayerController Function ShowGameHUD

// Begin Class ASpartaPlayerController Function ShowGameOverMenu
struct Z_Construct_UFunction_ASpartaPlayerController_ShowGameOverMenu_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Pause Menu \xef\xbf\xbd\xd2\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pause Menu \xef\xbf\xbd\xd2\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpartaPlayerController_ShowGameOverMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpartaPlayerController, nullptr, "ShowGameOverMenu", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpartaPlayerController_ShowGameOverMenu_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpartaPlayerController_ShowGameOverMenu_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASpartaPlayerController_ShowGameOverMenu()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpartaPlayerController_ShowGameOverMenu_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASpartaPlayerController::execShowGameOverMenu)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowGameOverMenu();
	P_NATIVE_END;
}
// End Class ASpartaPlayerController Function ShowGameOverMenu

// Begin Class ASpartaPlayerController Function ShowMainMenu
struct Z_Construct_UFunction_ASpartaPlayerController_ShowMainMenu_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// HUD \xc3\xa2 \xef\xbf\xbd\xd2\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "HUD \xc3\xa2 \xef\xbf\xbd\xd2\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpartaPlayerController_ShowMainMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpartaPlayerController, nullptr, "ShowMainMenu", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpartaPlayerController_ShowMainMenu_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpartaPlayerController_ShowMainMenu_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASpartaPlayerController_ShowMainMenu()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpartaPlayerController_ShowMainMenu_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASpartaPlayerController::execShowMainMenu)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowMainMenu();
	P_NATIVE_END;
}
// End Class ASpartaPlayerController Function ShowMainMenu

// Begin Class ASpartaPlayerController Function ShowPauseMenu
struct Z_Construct_UFunction_ASpartaPlayerController_ShowPauseMenu_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Menu" },
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpartaPlayerController_ShowPauseMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpartaPlayerController, nullptr, "ShowPauseMenu", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpartaPlayerController_ShowPauseMenu_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpartaPlayerController_ShowPauseMenu_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASpartaPlayerController_ShowPauseMenu()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpartaPlayerController_ShowPauseMenu_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASpartaPlayerController::execShowPauseMenu)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowPauseMenu();
	P_NATIVE_END;
}
// End Class ASpartaPlayerController Function ShowPauseMenu

// Begin Class ASpartaPlayerController Function StartGame
struct Z_Construct_UFunction_ASpartaPlayerController_StartGame_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// GameOver Menu \xef\xbf\xbd\xd2\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "GameOver Menu \xef\xbf\xbd\xd2\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpartaPlayerController_StartGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpartaPlayerController, nullptr, "StartGame", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpartaPlayerController_StartGame_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpartaPlayerController_StartGame_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASpartaPlayerController_StartGame()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpartaPlayerController_StartGame_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASpartaPlayerController::execStartGame)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartGame();
	P_NATIVE_END;
}
// End Class ASpartaPlayerController Function StartGame

// Begin Class ASpartaPlayerController Function TogglePauseMenu
struct Z_Construct_UFunction_ASpartaPlayerController_TogglePauseMenu_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Main Menu \xef\xbf\xbd\xd2\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Main Menu \xef\xbf\xbd\xd2\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpartaPlayerController_TogglePauseMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpartaPlayerController, nullptr, "TogglePauseMenu", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpartaPlayerController_TogglePauseMenu_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpartaPlayerController_TogglePauseMenu_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASpartaPlayerController_TogglePauseMenu()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpartaPlayerController_TogglePauseMenu_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASpartaPlayerController::execTogglePauseMenu)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TogglePauseMenu();
	P_NATIVE_END;
}
// End Class ASpartaPlayerController Function TogglePauseMenu

// Begin Class ASpartaPlayerController
void ASpartaPlayerController::StaticRegisterNativesASpartaPlayerController()
{
	UClass* Class = ASpartaPlayerController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ContinueGame", &ASpartaPlayerController::execContinueGame },
		{ "EndGame", &ASpartaPlayerController::execEndGame },
		{ "GetHUDWidget", &ASpartaPlayerController::execGetHUDWidget },
		{ "ShowGameHUD", &ASpartaPlayerController::execShowGameHUD },
		{ "ShowGameOverMenu", &ASpartaPlayerController::execShowGameOverMenu },
		{ "ShowMainMenu", &ASpartaPlayerController::execShowMainMenu },
		{ "ShowPauseMenu", &ASpartaPlayerController::execShowPauseMenu },
		{ "StartGame", &ASpartaPlayerController::execStartGame },
		{ "TogglePauseMenu", &ASpartaPlayerController::execTogglePauseMenu },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASpartaPlayerController);
UClass* Z_Construct_UClass_ASpartaPlayerController_NoRegister()
{
	return ASpartaPlayerController::StaticClass();
}
struct Z_Construct_UClass_ASpartaPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "SpartaPlayerController.h" },
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PauseAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUDWidgetClass_MetaData[] = {
		{ "Category", "HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// HUD Widget Class\n" },
#endif
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "HUD Widget Class" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUDWidgetInstance_MetaData[] = {
		{ "Category", "HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// HUD Widget Instance\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "HUD Widget Instance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MainMenuWidgetClass_MetaData[] = {
		{ "Category", "Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Menu Widget Class\n" },
#endif
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Menu Widget Class" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MainMenuWidgetInstance_MetaData[] = {
		{ "Category", "Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Menu Widget Instance\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Menu Widget Instance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PauseMenuWidgetClass_MetaData[] = {
		{ "Category", "Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Menu Widget Class\n" },
#endif
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Menu Widget Class" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PauseMenuWidgetInstance_MetaData[] = {
		{ "Category", "Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Menu Widget Instance\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Menu Widget Instance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameOverMenuWidgetClass_MetaData[] = {
		{ "Category", "Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Menu Widget Class\n" },
#endif
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Menu Widget Class" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameOverMenuWidgetInstance_MetaData[] = {
		{ "Category", "Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Menu Widget Instance\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpartaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Menu Widget Instance" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SprintAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PauseAction;
	static const UECodeGen_Private::FClassPropertyParams NewProp_HUDWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HUDWidgetInstance;
	static const UECodeGen_Private::FClassPropertyParams NewProp_MainMenuWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MainMenuWidgetInstance;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PauseMenuWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PauseMenuWidgetInstance;
	static const UECodeGen_Private::FClassPropertyParams NewProp_GameOverMenuWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GameOverMenuWidgetInstance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASpartaPlayerController_ContinueGame, "ContinueGame" }, // 1328192645
		{ &Z_Construct_UFunction_ASpartaPlayerController_EndGame, "EndGame" }, // 3601911615
		{ &Z_Construct_UFunction_ASpartaPlayerController_GetHUDWidget, "GetHUDWidget" }, // 52811969
		{ &Z_Construct_UFunction_ASpartaPlayerController_ShowGameHUD, "ShowGameHUD" }, // 2147934502
		{ &Z_Construct_UFunction_ASpartaPlayerController_ShowGameOverMenu, "ShowGameOverMenu" }, // 264446120
		{ &Z_Construct_UFunction_ASpartaPlayerController_ShowMainMenu, "ShowMainMenu" }, // 4031158898
		{ &Z_Construct_UFunction_ASpartaPlayerController_ShowPauseMenu, "ShowPauseMenu" }, // 1061436699
		{ &Z_Construct_UFunction_ASpartaPlayerController_StartGame, "StartGame" }, // 1093844690
		{ &Z_Construct_UFunction_ASpartaPlayerController_TogglePauseMenu, "TogglePauseMenu" }, // 4135625705
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpartaPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_InputMappingContext = { "InputMappingContext", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpartaPlayerController, InputMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputMappingContext_MetaData), NewProp_InputMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpartaPlayerController, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpartaPlayerController, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpartaPlayerController, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_SprintAction = { "SprintAction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpartaPlayerController, SprintAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintAction_MetaData), NewProp_SprintAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_PauseAction = { "PauseAction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpartaPlayerController, PauseAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PauseAction_MetaData), NewProp_PauseAction_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_HUDWidgetClass = { "HUDWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpartaPlayerController, HUDWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUDWidgetClass_MetaData), NewProp_HUDWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_HUDWidgetInstance = { "HUDWidgetInstance", nullptr, (EPropertyFlags)0x00100000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpartaPlayerController, HUDWidgetInstance), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUDWidgetInstance_MetaData), NewProp_HUDWidgetInstance_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_MainMenuWidgetClass = { "MainMenuWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpartaPlayerController, MainMenuWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainMenuWidgetClass_MetaData), NewProp_MainMenuWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_MainMenuWidgetInstance = { "MainMenuWidgetInstance", nullptr, (EPropertyFlags)0x00100000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpartaPlayerController, MainMenuWidgetInstance), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainMenuWidgetInstance_MetaData), NewProp_MainMenuWidgetInstance_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_PauseMenuWidgetClass = { "PauseMenuWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpartaPlayerController, PauseMenuWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PauseMenuWidgetClass_MetaData), NewProp_PauseMenuWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_PauseMenuWidgetInstance = { "PauseMenuWidgetInstance", nullptr, (EPropertyFlags)0x00100000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpartaPlayerController, PauseMenuWidgetInstance), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PauseMenuWidgetInstance_MetaData), NewProp_PauseMenuWidgetInstance_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_GameOverMenuWidgetClass = { "GameOverMenuWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpartaPlayerController, GameOverMenuWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameOverMenuWidgetClass_MetaData), NewProp_GameOverMenuWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_GameOverMenuWidgetInstance = { "GameOverMenuWidgetInstance", nullptr, (EPropertyFlags)0x00100000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpartaPlayerController, GameOverMenuWidgetInstance), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameOverMenuWidgetInstance_MetaData), NewProp_GameOverMenuWidgetInstance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASpartaPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_InputMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_SprintAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_PauseAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_HUDWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_HUDWidgetInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_MainMenuWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_MainMenuWidgetInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_PauseMenuWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_PauseMenuWidgetInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_GameOverMenuWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpartaPlayerController_Statics::NewProp_GameOverMenuWidgetInstance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpartaPlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASpartaPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_Survival_Arcade,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpartaPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpartaPlayerController_Statics::ClassParams = {
	&ASpartaPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ASpartaPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ASpartaPlayerController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpartaPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_ASpartaPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASpartaPlayerController()
{
	if (!Z_Registration_Info_UClass_ASpartaPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpartaPlayerController.OuterSingleton, Z_Construct_UClass_ASpartaPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASpartaPlayerController.OuterSingleton;
}
template<> SURVIVAL_ARCADE_API UClass* StaticClass<ASpartaPlayerController>()
{
	return ASpartaPlayerController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASpartaPlayerController);
ASpartaPlayerController::~ASpartaPlayerController() {}
// End Class ASpartaPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_practice_02_CPP_Survival_Arcade_Source_Survival_Arcade_SpartaPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASpartaPlayerController, ASpartaPlayerController::StaticClass, TEXT("ASpartaPlayerController"), &Z_Registration_Info_UClass_ASpartaPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpartaPlayerController), 4263429021U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_practice_02_CPP_Survival_Arcade_Source_Survival_Arcade_SpartaPlayerController_h_3331880146(TEXT("/Script/Survival_Arcade"),
	Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_practice_02_CPP_Survival_Arcade_Source_Survival_Arcade_SpartaPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_practice_02_CPP_Survival_Arcade_Source_Survival_Arcade_SpartaPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
