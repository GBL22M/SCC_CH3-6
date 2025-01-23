// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SCC_CH3_6/Public/RotatingPlatform.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRotatingPlatform() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
SCC_CH3_6_API UClass* Z_Construct_UClass_ARotatingPlatform();
SCC_CH3_6_API UClass* Z_Construct_UClass_ARotatingPlatform_NoRegister();
UPackage* Z_Construct_UPackage__Script_SCC_CH3_6();
// End Cross Module References

// Begin Class ARotatingPlatform
void ARotatingPlatform::StaticRegisterNativesARotatingPlatform()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARotatingPlatform);
UClass* Z_Construct_UClass_ARotatingPlatform_NoRegister()
{
	return ARotatingPlatform::StaticClass();
}
struct Z_Construct_UClass_ARotatingPlatform_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "RotatingPlatform.h" },
		{ "ModuleRelativePath", "Public/RotatingPlatform.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[] = {
		{ "Category", "Platform|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/RotatingPlatform.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[] = {
		{ "Category", "Platform|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/RotatingPlatform.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotator_MetaData[] = {
		{ "Category", "Platform|Setting Values" },
		{ "ModuleRelativePath", "Public/RotatingPlatform.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_YawValue_MetaData[] = {
		{ "Category", "Platform|Setting Values" },
		{ "ModuleRelativePath", "Public/RotatingPlatform.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PitchValue_MetaData[] = {
		{ "Category", "Platform|Setting Values" },
		{ "ModuleRelativePath", "Public/RotatingPlatform.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RollValue_MetaData[] = {
		{ "Category", "Platform|Setting Values" },
		{ "ModuleRelativePath", "Public/RotatingPlatform.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticMesh;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotator;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_YawValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RollValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARotatingPlatform>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARotatingPlatform_Statics::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x00100000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARotatingPlatform, SceneRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneRoot_MetaData), NewProp_SceneRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARotatingPlatform_Statics::NewProp_StaticMesh = { "StaticMesh", nullptr, (EPropertyFlags)0x00100000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARotatingPlatform, StaticMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaticMesh_MetaData), NewProp_StaticMesh_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ARotatingPlatform_Statics::NewProp_Rotator = { "Rotator", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARotatingPlatform, Rotator), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotator_MetaData), NewProp_Rotator_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARotatingPlatform_Statics::NewProp_YawValue = { "YawValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARotatingPlatform, YawValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_YawValue_MetaData), NewProp_YawValue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARotatingPlatform_Statics::NewProp_PitchValue = { "PitchValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARotatingPlatform, PitchValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PitchValue_MetaData), NewProp_PitchValue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARotatingPlatform_Statics::NewProp_RollValue = { "RollValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARotatingPlatform, RollValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RollValue_MetaData), NewProp_RollValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARotatingPlatform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARotatingPlatform_Statics::NewProp_SceneRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARotatingPlatform_Statics::NewProp_StaticMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARotatingPlatform_Statics::NewProp_Rotator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARotatingPlatform_Statics::NewProp_YawValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARotatingPlatform_Statics::NewProp_PitchValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARotatingPlatform_Statics::NewProp_RollValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARotatingPlatform_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ARotatingPlatform_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_SCC_CH3_6,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARotatingPlatform_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARotatingPlatform_Statics::ClassParams = {
	&ARotatingPlatform::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ARotatingPlatform_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ARotatingPlatform_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARotatingPlatform_Statics::Class_MetaDataParams), Z_Construct_UClass_ARotatingPlatform_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARotatingPlatform()
{
	if (!Z_Registration_Info_UClass_ARotatingPlatform.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARotatingPlatform.OuterSingleton, Z_Construct_UClass_ARotatingPlatform_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARotatingPlatform.OuterSingleton;
}
template<> SCC_CH3_6_API UClass* StaticClass<ARotatingPlatform>()
{
	return ARotatingPlatform::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARotatingPlatform);
ARotatingPlatform::~ARotatingPlatform() {}
// End Class ARotatingPlatform

// Begin Registration
struct Z_CompiledInDeferFile_FID_SCC_CH3_6_Source_SCC_CH3_6_Public_RotatingPlatform_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARotatingPlatform, ARotatingPlatform::StaticClass, TEXT("ARotatingPlatform"), &Z_Registration_Info_UClass_ARotatingPlatform, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARotatingPlatform), 1930200405U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SCC_CH3_6_Source_SCC_CH3_6_Public_RotatingPlatform_h_1068740335(TEXT("/Script/SCC_CH3_6"),
	Z_CompiledInDeferFile_FID_SCC_CH3_6_Source_SCC_CH3_6_Public_RotatingPlatform_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SCC_CH3_6_Source_SCC_CH3_6_Public_RotatingPlatform_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
