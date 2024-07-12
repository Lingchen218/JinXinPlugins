// Copyright (C) RenZhai.2020.All Rights Reserved.
 /*
 /* The following website explains how to use this set of plug-ins 
 * DocURL：			                
 * Here's how to develop the current plug-in            
 * MarketplaceURL :     https://www.aboutcg.org/courseDetails/979/introduce          
 * If you want to learn more about the UE4 tutorial, please refer to:            
 * URL :				https://zhuanlan.zhihu.com/p/60117613            
 * If you want to learn about the series of tutorials and related plug-ins, you can follow my blog            
 * URL :				http://renzhai.net/            
 * If you want to know our next course arrangement, 
 * you can search the WeChat public house for your attention, then we will push a lot of technical articles.           
 * Sina blog            https://weibo.com/bzrz/profile?S=6cm7d0 // this blog hasn't been used for three or four years now.
 * Maybe you can re enable the first connection later 
 */
using UnrealBuildTool;
using System.IO;

public class SimpleMySQL : ModuleRules
{
    public string ProjectDirectory
    {
        get
        {
            return Path.GetFullPath(Path.Combine(ModuleDirectory,"../../../../"));//项目路径
        }
    }

    private void CopyToProjectBinaries(string FilePathName, ReadOnlyTargetRules Target)
    {
		string BinariesDirectory = Path.Combine(
			bTreatAsEngineModule ? EngineDirectory : ProjectDirectory, "Binaries", Target.Platform.ToString());

        string Filename = Path.GetFileName(FilePathName);

        if(!Directory.Exists(BinariesDirectory))
        {
            Directory.CreateDirectory(BinariesDirectory);
        }

        string ProjectFileFullName = Path.Combine(BinariesDirectory, Filename);
        if (!File.Exists(ProjectFileFullName))
        {
            File.Copy(FilePathName, ProjectFileFullName,true);
        }

        RuntimeDependencies.Add(ProjectFileFullName);
    }

	public SimpleMySQL(ReadOnlyTargetRules Target) : base(Target)
    {
		PublicIncludePaths.AddRange(new string[]
		{
			"Public/MySQL"
		});

		// bUsePrecompiled = true;
		bEnableUndefinedIdentifierWarnings = false;
        PublicDefinitions.Add("NTDDI_WIN7SP1");

        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		if (Target.Platform == UnrealBuildTool.UnrealTargetPlatform.Win64)
		{
			string PluginsDirectory = Path.GetFullPath(Path.Combine(ModuleDirectory, "..", ".."));//路径

			string SQLLibDirectory = "";

			string MysqlVerison = "8.3";
			if (MysqlVerison == "8.3")
			{
				SQLLibDirectory = Path.Combine(PluginsDirectory, "MySQL/8.3"); //MySQL路径		
			}
			else
			{
				SQLLibDirectory = Path.Combine(PluginsDirectory, "MySQL/5.7"); //MySQL路径
			}
			
			string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "x64" : "x86";

			string MysqlPath = Path.Combine(SQLLibDirectory, PlatformString);

			PublicIncludePaths.Add(MysqlPath);

			RuntimeDependencies.Add(Path.Combine(MysqlPath, "libmysql.dll"));
			PublicAdditionalLibraries.Add(Path.Combine(MysqlPath, "libmysql.lib"));

			CopyToProjectBinaries(Path.Combine(MysqlPath, "libmysql.dll"), Target);
			CopyToProjectBinaries(Path.Combine(MysqlPath, "libmysql.lib"), Target);

			if (MysqlVerison == "8.3")
			{
				RuntimeDependencies.Add(Path.Combine(MysqlPath, "libcrypto-3-x64.dll"));
				RuntimeDependencies.Add(Path.Combine(MysqlPath, "libssl-3-x64.dll"));
				
				CopyToProjectBinaries(Path.Combine(MysqlPath, "libcrypto-3-x64.dll"), Target);
				CopyToProjectBinaries(Path.Combine(MysqlPath, "libssl-3-x64.dll"), Target);
			}
		}

        PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Json",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "CoreUObject"
				// ... add private dependencies that you statically link with here ...	
			});

		if (Target.Type != TargetType.Program)
		{
			PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Engine",
				"Launch"
			});
		}

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

		//bUsePrecompiled = true;
		//PrecompileForTargets = PrecompileTargetsType.Any;
	}
}
