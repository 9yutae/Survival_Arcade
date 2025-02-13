// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Survival_Arcade/RedZoneSpawner.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRedZoneSpawner() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AActor();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ABombItem_NoRegister();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ARedZoneSpawner();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ARedZoneSpawner_NoRegister();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ASpawnVolume_NoRegister();
UPackage* Z_Construct_UPackage__Script_Survival_Arcade();
// End Cross Module References

// Begin Class ARedZoneSpawner
void ARedZoneSpawner::StaticRegisterNativesARedZoneSpawner()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARedZoneSpawner);
UClass* Z_Construct_UClass_ARedZoneSpawner_NoRegister()
{
	return ARedZoneSpawner::StaticClass();
}
struct Z_Construct_UClass_ARedZoneSpawner_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "RedZoneSpawner.h" },
		{ "ModuleRelativePath", "RedZoneSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RedZoneStartTime_MetaData[] = {
		{ "Category", "RedZone" },
		{ "ModuleRelativePath", "RedZoneSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BombDropInterval_MetaData[] = {
		{ "Category", "RedZone" },
		{ "ModuleRelativePath", "RedZoneSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BombCountPerDrop_MetaData[] = {
		{ "Category", "RedZone" },
		{ "ModuleRelativePath", "RedZoneSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BombClass_MetaData[] = {
		{ "Category", "RedZone" },
		{ "ModuleRelativePath", "RedZoneSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetSpawnVolume_MetaData[] = {
		{ "Category", "RedZone" },
		{ "ModuleRelativePath", "RedZoneSpawner.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RedZoneStartTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BombDropInterval;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BombCountPerDrop;
	static const UECodeGen_Private::FClassPropertyParams NewProp_BombClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetSpawnVolume;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARedZoneSpawner>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARedZoneSpawner_Statics::NewProp_RedZoneStartTime = { "RedZoneStartTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARedZoneSpawner, RedZoneStartTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RedZoneStartTime_MetaData), NewProp_RedZoneStartTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARedZoneSpawner_Statics::NewProp_BombDropInterval = { "BombDropInterval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARedZoneSpawner, BombDropInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BombDropInterval_MetaData), NewProp_BombDropInterval_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ARedZoneSpawner_Statics::NewProp_BombCountPerDrop = { "BombCountPerDrop", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARedZoneSpawner, BombCountPerDrop), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BombCountPerDrop_MetaData), NewProp_BombCountPerDrop_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ARedZoneSpawner_Statics::NewProp_BombClass = { "BombClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARedZoneSpawner, BombClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ABombItem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BombClass_MetaData), NewProp_BombClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARedZoneSpawner_Statics::NewProp_TargetSpawnVolume = { "TargetSpawnVolume", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARedZoneSpawner, TargetSpawnVolume), Z_Construct_UClass_ASpawnVolume_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetSpawnVolume_MetaData), NewProp_TargetSpawnVolume_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARedZoneSpawner_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARedZoneSpawner_Statics::NewProp_RedZoneStartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARedZoneSpawner_Statics::NewProp_BombDropInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARedZoneSpawner_Statics::NewProp_BombCountPerDrop,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARedZoneSpawner_Statics::NewProp_BombClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARedZoneSpawner_Statics::NewProp_TargetSpawnVolume,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARedZoneSpawner_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ARedZoneSpawner_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Survival_Arcade,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARedZoneSpawner_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARedZoneSpawner_Statics::ClassParams = {
	&ARedZoneSpawner::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ARedZoneSpawner_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ARedZoneSpawner_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARedZoneSpawner_Statics::Class_MetaDataParams), Z_Construct_UClass_ARedZoneSpawner_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARedZoneSpawner()
{
	if (!Z_Registration_Info_UClass_ARedZoneSpawner.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARedZoneSpawner.OuterSingleton, Z_Construct_UClass_ARedZoneSpawner_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARedZoneSpawner.OuterSingleton;
}
template<> SURVIVAL_ARCADE_API UClass* StaticClass<ARedZoneSpawner>()
{
	return ARedZoneSpawner::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARedZoneSpawner);
ARedZoneSpawner::~ARedZoneSpawner() {}
// End Class ARedZoneSpawner

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_RedZoneSpawner_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARedZoneSpawner, ARedZoneSpawner::StaticClass, TEXT("ARedZoneSpawner"), &Z_Registration_Info_UClass_ARedZoneSpawner, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARedZoneSpawner), 4264327004U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_RedZoneSpawner_h_2809209696(TEXT("/Script/Survival_Arcade"),
	Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_RedZoneSpawner_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_RedZoneSpawner_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
