// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/core/Session.hpp
// Header file of session.

#pragma once
#include <ui/GridWidget.hpp>
#include <random>

using namespace std;

class Session {
    int size_;
    int size_square_;
    int snake_length_;
    vector<int> table_;
    vector<int> empty_list_;
    vector<int> snake_list_;
    const bool gui_;
    GridWidget* window_;
    int getRand() const;
    int getMatrixRand() const;
    int getAppleRand() const;
    void spawnApple();
public:
    Session(int size, bool gui);
    void init();
};
