// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/core/Session.hpp
// Header file of session.

#pragma once
#include <ui/GridWidget.hpp>
#include <ui/inter/IUiKeyCallBack.hpp>
#include <core/Action.hpp>
#include <random>

using namespace std;

class Session : public IUiKeyCallBack{
    int size_;
    int size_square_;
    int snake_length_{};
    int head_position_{};
    vector<int> table_;
    vector<int> empty_list_;
    vector<int> snake_list_;
    const bool gui_;
    GridWidget* window_;
    [[nodiscard]] int getRand() const;
    [[nodiscard]] int getMatrixRand() const;
    [[nodiscard]] int getAppleRand() const;
    void spawnApple();
public:
    Session(int size, bool gui);
    void init();
    bool move(Action action);
    void updateWindow() const;
    bool onClick(Action action) override;
};