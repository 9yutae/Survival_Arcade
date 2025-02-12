// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Survival_Arcade/SpartaGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpartaGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameMode();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ASpartaGameMode();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ASpartaGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_Survival_Arcade();
// End Cross Module References

// Begin Class ASpartaGameMode
void ASpartaGameMode::StaticRegisterNativesASpartaGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASpartaGameMode);
UClass* Z_Construct_UClass_ASpartaGameMode_NoRegister()
{
	return ASpartaGameMode::StaticClass();
}
struct Z_Construct_UClass_ASpartaGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "SpartaGameMode.h" },
		{ "ModuleRelativePath", "SpartaGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpartaGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ASpartaGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameMode,
	(UObject* (*)())Z_Construct_UPackage__Script_Survival_Arcade,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpartaGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpartaGameMode_Statics::ClassParams = {
	&ASpartaGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpartaGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ASpartaGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASpartaGameMode()
{
	if (!Z_Registration_Info_UClass_ASpartaGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpartaGameMode.OuterSingleton, Z_Construct_UClass_ASpartaGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASpartaGameMode.OuterSingleton;
}
template<> SURVIVAL_ARCADE_API UClass* StaticClass<ASpartaGameMode>()
{
	return ASpartaGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASpartaGameMode);
ASpartaGameMode::~ASpartaGameMode() {}
// End Class ASpartaGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_practice_02_CPP_Survival_Arcade_Source_Survival_Arcade_SpartaGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASpartaGameMode, ASpartaGameMode::StaticClass, TEXT("ASpartaGameMode"), &Z_Registration_Info_UClass_ASpartaGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpartaGameMode), 348826745U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_practice_02_CPP_Survival_Arcade_Source_Survival_Arcade_SpartaGameMode_h_1500826500(TEXT("/Script/Survival_Arcade"),
	Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_practice_02_CPP_Survival_Arcade_Source_Survival_Arcade_SpartaGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_practice_02_CPP_Survival_Arcade_Source_Survival_Arcade_SpartaGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
