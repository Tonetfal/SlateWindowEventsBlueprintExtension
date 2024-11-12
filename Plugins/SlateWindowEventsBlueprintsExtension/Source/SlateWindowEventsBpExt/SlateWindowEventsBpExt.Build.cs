// Author: Antonio Sidenko (Tonetfal), November 2024

using UnrealBuildTool;

public class SlateWindowEventsBpExt : ModuleRules
{
	public SlateWindowEventsBpExt(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
			}
			);
	}
}
