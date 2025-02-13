// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BombItem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef SURVIVAL_ARCADE_BombItem_generated_h
#error "BombItem.generated.h already included, missing '#pragma once' in BombItem.h"
#endif
#define SURVIVAL_ARCADE_BombItem_generated_h

#define FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_BombItem_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnHit);


#define FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_BombItem_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABombItem(); \
	friend struct Z_Construct_UClass_ABombItem_Statics; \
public: \
	DECLARE_CLASS(ABombItem, ABaseItem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Survival_Arcade"), NO_API) \
	DECLARE_SERIALIZER(ABombItem)


#define FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_BombItem_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABombItem(ABombItem&&); \
	ABombItem(const ABombItem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABombItem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABombItem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABombItem) \
	NO_API virtual ~ABombItem();


#define FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_BombItem_h_7_PROLOG
#define FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_BombItem_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_BombItem_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_BombItem_h_10_INCLASS_NO_PURE_DECLS \
	FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_BombItem_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SURVIVAL_ARCADE_API UClass* StaticClass<class ABombItem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_9yuta_Documents_UE5_project_Survival_Arcade_Source_Survival_Arcade_BombItem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
