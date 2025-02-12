// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Survival_Arcade : ModuleRules
{
	public Survival_Arcade(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] // 프로젝트에서 사용하는 공개된 모듈 (필수 기능)
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
			"UMG"
        });

        PrivateDependencyModuleNames.AddRange(new string[] {  });
 	}
}
