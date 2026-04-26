// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/ui/IUiCallBack.hpp
// Interface of UI callback.

#pragma once

#include <core/Action.hpp>

class IUiKeyCallBack {
public:
    virtual bool onClick(Action action) = 0;
    virtual ~IUiKeyCallBack() = default;
};
