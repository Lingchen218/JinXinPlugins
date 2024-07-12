// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../Plugins/RENZHAI_PLUGIN/SimpleMySQL/Source/SimpleMySQL/Public/Blueprint/SimpleMysqlObject.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimpleMysqlObject() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
SIMPLEMYSQL_API UClass* Z_Construct_UClass_USimpleMysqlObject();
SIMPLEMYSQL_API UClass* Z_Construct_UClass_USimpleMysqlObject_NoRegister();
UPackage* Z_Construct_UPackage__Script_SimpleMySQL();
// End Cross Module References

// Begin Class USimpleMysqlObject
void USimpleMysqlObject::StaticRegisterNativesUSimpleMysqlObject()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USimpleMysqlObject);
UClass* Z_Construct_UClass_USimpleMysqlObject_NoRegister()
{
	return USimpleMysqlObject::StaticClass();
}
struct Z_Construct_UClass_USimpleMysqlObject_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Blueprint/SimpleMysqlObject.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Blueprint/SimpleMysqlObject.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USimpleMysqlObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_USimpleMysqlObject_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleMySQL,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleMysqlObject_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USimpleMysqlObject_Statics::ClassParams = {
	&USimpleMysqlObject::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleMysqlObject_Statics::Class_MetaDataParams), Z_Construct_UClass_USimpleMysqlObject_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_USimpleMysqlObject()
{
	if (!Z_Registration_Info_UClass_USimpleMysqlObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USimpleMysqlObject.OuterSingleton, Z_Construct_UClass_USimpleMysqlObject_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USimpleMysqlObject.OuterSingleton;
}
template<> SIMPLEMYSQL_API UClass* StaticClass<USimpleMysqlObject>()
{
	return USimpleMysqlObject::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(USimpleMysqlObject);
USimpleMysqlObject::~USimpleMysqlObject() {}
// End Class USimpleMysqlObject

// Begin Registration
struct Z_CompiledInDeferFile_FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Blueprint_SimpleMysqlObject_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USimpleMysqlObject, USimpleMysqlObject::StaticClass, TEXT("USimpleMysqlObject"), &Z_Registration_Info_UClass_USimpleMysqlObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USimpleMysqlObject), 3352865949U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Blueprint_SimpleMysqlObject_h_3017436316(TEXT("/Script/SimpleMySQL"),
	Z_CompiledInDeferFile_FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Blueprint_SimpleMysqlObject_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Blueprint_SimpleMysqlObject_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
