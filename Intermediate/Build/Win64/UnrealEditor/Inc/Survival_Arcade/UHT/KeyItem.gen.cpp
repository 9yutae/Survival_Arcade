// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Survival_Arcade/KeyItem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKeyItem() {}

// Begin Cross Module References
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ABaseItem();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_AKeyItem();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_AKeyItem_NoRegister();
UPackage* Z_Construct_UPackage__Script_Survival_Arcade();
// End Cross Module References

// Begin Class AKeyItem
void AKeyItem::StaticRegisterNativesAKeyItem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AKeyItem);
UClass* Z_Construct_UClass_AKeyItem_NoRegister()
{
	return AKeyItem::StaticClass();
}
struct Z_Construct_UClass_AKeyItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "KeyItem.h" },
		{ "ModuleRelativePath", "KeyItem.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AKeyItem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AKeyItem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABaseItem,
	(UObject* (*)())Z_Construct_UPackage__Script_Survival_Arcade,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AKeyItem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AKeyItem_Statics::ClassParams = {
	&AKeyItem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AKeyItem_Statics::Class_MetaDataParams), Z_Construct_UClass_AKeyItem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AKeyItem()
{
	if (!Z_Registration_Info_UClass_AKeyItem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AKeyItem.OuterSingleton, Z_Construct_UClass_AKeyItem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AKeyItem.OuterSingleton;
}
template<> SURVIVAL_ARCADE_API UClass* StaticClass<AKeyItem>()
{
	return AKeyItem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AKeyItem);
AKeyItem::~AKeyItem() {}
// End Class AKeyItem

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_practice_02_CPP_Survival_Arcade_Source_Survival_Arcade_KeyItem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AKeyItem, AKeyItem::StaticClass, TEXT("AKeyItem"), &Z_Registration_Info_UClass_AKeyItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AKeyItem), 4056431009U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_practice_02_CPP_Survival_Arcade_Source_Survival_Arcade_KeyItem_h_2407796724(TEXT("/Script/Survival_Arcade"),
	Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_practice_02_CPP_Survival_Arcade_Source_Survival_Arcade_KeyItem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_practice_02_CPP_Survival_Arcade_Source_Survival_Arcade_KeyItem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
