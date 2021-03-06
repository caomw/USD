//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
// Payload.cpp
//


#include "pxr/usd/sdf/payload.h"

#include "pxr/base/tf/registryManager.h"
#include "pxr/base/tf/type.h"

#include <ostream>


TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<SdfPayload>();
    TfType::Define<SdfPayloadVector>();
}

SdfPayload::SdfPayload(
    const std::string &assetPath,
    const SdfPath &primPath) :
    _assetPath(assetPath),
    _primPath(primPath)
{
}

SdfPayload::operator bool() const
{
    return not _assetPath.empty();
}

bool
SdfPayload::operator==(const SdfPayload &rhs) const
{
    return _assetPath   == rhs._assetPath and
           _primPath    == rhs._primPath;
}

bool
SdfPayload::operator<(const SdfPayload &rhs) const
{
    return _assetPath   <  rhs._assetPath or
        (_assetPath == rhs._assetPath and _primPath < rhs._primPath);
}

std::ostream & operator<<( std::ostream &out,
                           const SdfPayload &payload )
{
    return out << "SdfPayload("
        << payload.GetAssetPath() << ", "
        << payload.GetPrimPath() << ")";
}
