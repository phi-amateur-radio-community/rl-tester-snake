// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/core/Session.hpp
// Header file of session.

#pragma once
#include <QWidget>

using namespace std;

class Session {
    int size_;
    vector<int> table_;
    const bool gui_;
    QWidget* window_;
    public:
    Session(int size, bool gui);
};
