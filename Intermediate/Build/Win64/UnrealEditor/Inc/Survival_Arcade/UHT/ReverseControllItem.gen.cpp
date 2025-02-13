// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Survival_Arcade/ReverseControllItem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReverseControllItem() {}

// Begin Cross Module References
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ABaseItem();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_AReverseControllItem();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_AReverseControllItem_NoRegister();
UPackage* Z_Construct_UPackage__Script_Survival_Arcade();
// End Cross Module References

// Begin Class AReverseControllItem
void AReverseControllItem::StaticRegisterNativesAReverseControllItem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AReverseControllItem);
UClass* Z_Construct_UClass_AReverseControllItem_NoRegister()
{
	return AReverseControllItem::StaticClass();
}
struct Z_Construct_UClass_AReverseControllItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ReverseControllItem.h" },
		{ "ModuleRelativePath", "ReverseControllItem.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AReverseControllItem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AReverseControllItem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABaseItem,
	(UObject* (*)())Z_Construct_UPackage__Script_Survival_Arcade,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AReverseControllItem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AReverseControllItem_Statics::ClassParams = {
	&AReverseControllItem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AReverseControllItem_Statics::Class_MetaDataParams), Z_Construct_UClass_AReverseControllItem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AReverseControllItem()
{
	if (!Z_Registration_Info_UClass_AReverseControllItem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AReverseControllItem.OuterSingleton, Z_Construct_UClass_AReverseControllItem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AReverseControllItem.OuterSingleton;
}
template<> SURVIVAL_ARCADE_API UClass* StaticClass<AReverseControllItem>()
{
	return AReverseControllItem::StaticClass();
}
AReverseControllItem::AReverseControllItem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AReverseControllItem);
AReverseControllItem::~AReverseControllItem() {}
// End Class AReverseControllItem

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_ReverseControllItem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AReverseControllItem, AReverseControllItem::StaticClass, TEXT("AReverseControllItem"), &Z_Registration_Info_UClass_AReverseControllItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AReverseControllItem), 993273882U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_ReverseControllItem_h_3815314024(TEXT("/Script/Survival_Arcade"),
	Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_ReverseControllItem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_ReverseControllItem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
