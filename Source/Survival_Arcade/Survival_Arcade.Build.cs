// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Survival_Arcade : ModuleRules
{
	public Survival_Arcade(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] // ������Ʈ���� ����ϴ� ������ ��� (�ʼ� ���)
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
