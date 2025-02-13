// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Survival_Arcade/HealItem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHealItem() {}

// Begin Cross Module References
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ABaseItem();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_AHealItem();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_AHealItem_NoRegister();
UPackage* Z_Construct_UPackage__Script_Survival_Arcade();
// End Cross Module References

// Begin Class AHealItem
void AHealItem::StaticRegisterNativesAHealItem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHealItem);
UClass* Z_Construct_UClass_AHealItem_NoRegister()
{
	return AHealItem::StaticClass();
}
struct Z_Construct_UClass_AHealItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "HealItem.h" },
		{ "ModuleRelativePath", "HealItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealAmount_MetaData[] = {
		{ "Category", "Item" },
		{ "ModuleRelativePath", "HealItem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_HealAmount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHealItem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AHealItem_Statics::NewProp_HealAmount = { "HealAmount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealItem, HealAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealAmount_MetaData), NewProp_HealAmount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHealItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealItem_Statics::NewProp_HealAmount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHealItem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AHealItem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABaseItem,
	(UObject* (*)())Z_Construct_UPackage__Script_Survival_Arcade,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHealItem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AHealItem_Statics::ClassParams = {
	&AHealItem::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AHealItem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AHealItem_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHealItem_Statics::Class_MetaDataParams), Z_Construct_UClass_AHealItem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AHealItem()
{
	if (!Z_Registration_Info_UClass_AHealItem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHealItem.OuterSingleton, Z_Construct_UClass_AHealItem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AHealItem.OuterSingleton;
}
template<> SURVIVAL_ARCADE_API UClass* StaticClass<AHealItem>()
{
	return AHealItem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AHealItem);
AHealItem::~AHealItem() {}
// End Class AHealItem

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_HealItem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AHealItem, AHealItem::StaticClass, TEXT("AHealItem"), &Z_Registration_Info_UClass_AHealItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHealItem), 1688576002U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_HealItem_h_2939778599(TEXT("/Script/Survival_Arcade"),
	Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_HealItem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_HealItem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
