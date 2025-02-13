// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Survival_Arcade/BushItem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBushItem() {}

// Begin Cross Module References
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ABaseItem();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ABushItem();
SURVIVAL_ARCADE_API UClass* Z_Construct_UClass_ABushItem_NoRegister();
UPackage* Z_Construct_UPackage__Script_Survival_Arcade();
// End Cross Module References

// Begin Class ABushItem
void ABushItem::StaticRegisterNativesABushItem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABushItem);
UClass* Z_Construct_UClass_ABushItem_NoRegister()
{
	return ABushItem::StaticClass();
}
struct Z_Construct_UClass_ABushItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "BushItem.h" },
		{ "ModuleRelativePath", "BushItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DecelerationRate_MetaData[] = {
		{ "Category", "Bush" },
		{ "ModuleRelativePath", "BushItem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DecelerationRate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABushItem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABushItem_Statics::NewProp_DecelerationRate = { "DecelerationRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABushItem, DecelerationRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DecelerationRate_MetaData), NewProp_DecelerationRate_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABushItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABushItem_Statics::NewProp_DecelerationRate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABushItem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABushItem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABaseItem,
	(UObject* (*)())Z_Construct_UPackage__Script_Survival_Arcade,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABushItem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABushItem_Statics::ClassParams = {
	&ABushItem::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ABushItem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ABushItem_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABushItem_Statics::Class_MetaDataParams), Z_Construct_UClass_ABushItem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABushItem()
{
	if (!Z_Registration_Info_UClass_ABushItem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABushItem.OuterSingleton, Z_Construct_UClass_ABushItem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABushItem.OuterSingleton;
}
template<> SURVIVAL_ARCADE_API UClass* StaticClass<ABushItem>()
{
	return ABushItem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABushItem);
ABushItem::~ABushItem() {}
// End Class ABushItem

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_BushItem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABushItem, ABushItem::StaticClass, TEXT("ABushItem"), &Z_Registration_Info_UClass_ABushItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABushItem), 3814400627U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_BushItem_h_2944299187(TEXT("/Script/Survival_Arcade"),
	Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_BushItem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_BushItem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
