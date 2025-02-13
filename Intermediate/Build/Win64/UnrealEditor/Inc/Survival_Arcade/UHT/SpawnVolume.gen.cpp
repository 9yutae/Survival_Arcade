// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Survival_Arcade/SpawnVolume.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpawnVolume() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ABushItem_NoRegister();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ASpawnVolume();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ASpawnVolume_NoRegister();
UPackage* Z_Construct_UPackage__Script_Survival_Arcade();
// End Cross Module References

// Begin Class ASpawnVolume Function SpawnBushItem
struct Z_Construct_UFunction_ASpawnVolume_SpawnBushItem_Statics
{
	struct SpawnVolume_eventSpawnBushItem_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Spawning" },
		{ "ModuleRelativePath", "SpawnVolume.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASpawnVolume_SpawnBushItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpawnVolume_eventSpawnBushItem_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASpawnVolume_SpawnBushItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpawnVolume_SpawnBushItem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpawnVolume_SpawnBushItem_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpawnVolume_SpawnBushItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpawnVolume, nullptr, "SpawnBushItem", nullptr, nullptr, Z_Construct_UFunction_ASpawnVolume_SpawnBushItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASpawnVolume_SpawnBushItem_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASpawnVolume_SpawnBushItem_Statics::SpawnVolume_eventSpawnBushItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpawnVolume_SpawnBushItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpawnVolume_SpawnBushItem_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASpawnVolume_SpawnBushItem_Statics::SpawnVolume_eventSpawnBushItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASpawnVolume_SpawnBushItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpawnVolume_SpawnBushItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASpawnVolume::execSpawnBushItem)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->SpawnBushItem();
	P_NATIVE_END;
}
// End Class ASpawnVolume Function SpawnBushItem

// Begin Class ASpawnVolume Function SpawnRandomItem
struct Z_Construct_UFunction_ASpawnVolume_SpawnRandomItem_Statics
{
	struct SpawnVolume_eventSpawnRandomItem_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Spawning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "SpawnVolume.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASpawnVolume_SpawnRandomItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpawnVolume_eventSpawnRandomItem_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASpawnVolume_SpawnRandomItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpawnVolume_SpawnRandomItem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpawnVolume_SpawnRandomItem_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpawnVolume_SpawnRandomItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpawnVolume, nullptr, "SpawnRandomItem", nullptr, nullptr, Z_Construct_UFunction_ASpawnVolume_SpawnRandomItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASpawnVolume_SpawnRandomItem_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASpawnVolume_SpawnRandomItem_Statics::SpawnVolume_eventSpawnRandomItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpawnVolume_SpawnRandomItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpawnVolume_SpawnRandomItem_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASpawnVolume_SpawnRandomItem_Statics::SpawnVolume_eventSpawnRandomItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASpawnVolume_SpawnRandomItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpawnVolume_SpawnRandomItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASpawnVolume::execSpawnRandomItem)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->SpawnRandomItem();
	P_NATIVE_END;
}
// End Class ASpawnVolume Function SpawnRandomItem

// Begin Class ASpawnVolume
void ASpawnVolume::StaticRegisterNativesASpawnVolume()
{
	UClass* Class = ASpawnVolume::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SpawnBushItem", &ASpawnVolume::execSpawnBushItem },
		{ "SpawnRandomItem", &ASpawnVolume::execSpawnRandomItem },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASpawnVolume);
UClass* Z_Construct_UClass_ASpawnVolume_NoRegister()
{
	return ASpawnVolume::StaticClass();
}
struct Z_Construct_UClass_ASpawnVolume_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "SpawnVolume.h" },
		{ "ModuleRelativePath", "SpawnVolume.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scene_MetaData[] = {
		{ "Category", "Spawning" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpawnVolume.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawningBox_MetaData[] = {
		{ "Category", "Spawning" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpawnVolume.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemDataTable_MetaData[] = {
		{ "Category", "Spawning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xba\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "SpawnVolume.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xba\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ABushItemClass_MetaData[] = {
		{ "Category", "Spawning" },
		{ "ModuleRelativePath", "SpawnVolume.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Scene;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawningBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDataTable;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ABushItemClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASpawnVolume_SpawnBushItem, "SpawnBushItem" }, // 3292402405
		{ &Z_Construct_UFunction_ASpawnVolume_SpawnRandomItem, "SpawnRandomItem" }, // 2936149194
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpawnVolume>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpawnVolume_Statics::NewProp_Scene = { "Scene", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpawnVolume, Scene), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scene_MetaData), NewProp_Scene_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpawnVolume_Statics::NewProp_SpawningBox = { "SpawningBox", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpawnVolume, SpawningBox), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawningBox_MetaData), NewProp_SpawningBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpawnVolume_Statics::NewProp_ItemDataTable = { "ItemDataTable", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpawnVolume, ItemDataTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemDataTable_MetaData), NewProp_ItemDataTable_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASpawnVolume_Statics::NewProp_ABushItemClass = { "ABushItemClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpawnVolume, ABushItemClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ABushItem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ABushItemClass_MetaData), NewProp_ABushItemClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASpawnVolume_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawnVolume_Statics::NewProp_Scene,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawnVolume_Statics::NewProp_SpawningBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawnVolume_Statics::NewProp_ItemDataTable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawnVolume_Statics::NewProp_ABushItemClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawnVolume_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASpawnVolume_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Survival_Arcade,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawnVolume_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpawnVolume_Statics::ClassParams = {
	&ASpawnVolume::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ASpawnVolume_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ASpawnVolume_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawnVolume_Statics::Class_MetaDataParams), Z_Construct_UClass_ASpawnVolume_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASpawnVolume()
{
	if (!Z_Registration_Info_UClass_ASpawnVolume.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpawnVolume.OuterSingleton, Z_Construct_UClass_ASpawnVolume_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASpawnVolume.OuterSingleton;
}
template<> SURVIVAL_ARCADE_API UClass* StaticClass<ASpawnVolume>()
{
	return ASpawnVolume::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASpawnVolume);
ASpawnVolume::~ASpawnVolume() {}
// End Class ASpawnVolume

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_SpawnVolume_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASpawnVolume, ASpawnVolume::StaticClass, TEXT("ASpawnVolume"), &Z_Registration_Info_UClass_ASpawnVolume, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpawnVolume), 2943033172U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_SpawnVolume_h_2045210891(TEXT("/Script/Survival_Arcade"),
	Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_SpawnVolume_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_SpawnVolume_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
