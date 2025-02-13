// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Survival_Arcade/RandomItem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRandomItem() {}

// Begin Cross Module References
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ABaseItem();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ARandomItem();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ARandomItem_NoRegister();
UPackage* Z_Construct_UPackage__Script_Survival_Arcade();
// End Cross Module References

// Begin Class ARandomItem
void ARandomItem::StaticRegisterNativesARandomItem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARandomItem);
UClass* Z_Construct_UClass_ARandomItem_NoRegister()
{
	return ARandomItem::StaticClass();
}
struct Z_Construct_UClass_ARandomItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "RandomItem.h" },
		{ "ModuleRelativePath", "RandomItem.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARandomItem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ARandomItem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABaseItem,
	(UObject* (*)())Z_Construct_UPackage__Script_Survival_Arcade,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARandomItem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARandomItem_Statics::ClassParams = {
	&ARandomItem::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARandomItem_Statics::Class_MetaDataParams), Z_Construct_UClass_ARandomItem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARandomItem()
{
	if (!Z_Registration_Info_UClass_ARandomItem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARandomItem.OuterSingleton, Z_Construct_UClass_ARandomItem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARandomItem.OuterSingleton;
}
template<> SURVIVAL_ARCADE_API UClass* StaticClass<ARandomItem>()
{
	return ARandomItem::StaticClass();
}
ARandomItem::ARandomItem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARandomItem);
ARandomItem::~ARandomItem() {}
// End Class ARandomItem

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_RandomItem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARandomItem, ARandomItem::StaticClass, TEXT("ARandomItem"), &Z_Registration_Info_UClass_ARandomItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARandomItem), 1485573600U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_RandomItem_h_4073537001(TEXT("/Script/Survival_Arcade"),
	Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_RandomItem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_RandomItem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
