// Fill out your copyright notice in the Description page of Project Settings.


#include "MapConverting.h"

FString UMapConverting::ConvertMapToString(TMap<FString, float> Map)
{
    FString MapAsString;
    for (const auto& [key, value] : Map) {
        MapAsString += key + "=" + FString::SanitizeFloat(Map[key]) + ", ";
    }
    MapAsString.RemoveAt(MapAsString.Len() - 3, 2);
    return MapAsString;
}

TMap<FString, float> UMapConverting::ConvertStringToMap(FString MapAsString)
{
    TMap<FString, float> StringAsMap;
    TArray<FString> StringAsArray;
    MapAsString.ParseIntoArray(StringAsArray, TEXT(","), true);

    for (FString Str : StringAsArray)
    {
        TArray<FString> KeyValue;
            Str.ParseIntoArray(KeyValue, TEXT("="), true);
        StringAsMap.Add(KeyValue[0], FCString::Atof(*KeyValue[1]));
    }
    return StringAsMap;
}