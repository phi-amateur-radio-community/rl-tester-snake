// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/core/Session.hpp
// Header file of session.

#pragma once
#include <fstream>
#include <ui/GridWidget.hpp>
#include <ui/inter/IUiKeyCallBack.hpp>
#include <core/Action.hpp>
#include <util/UnorderList.hpp>
#include <util/Logger.hpp>

using namespace std;

class Session : public IUiKeyCallBack{
    int size_;
    int size_square_;
    int snake_length_{};
    int head_position_{};
    vector<int> table_;
    UnorderedList empty_list_;
    UnorderedList snake_list_;
    const bool gui_;
    const bool replay_;
    string session_name_;
    Logger logger_;
    GridWidget* window_;
    [[nodiscard]] int getRand() const;
    [[nodiscard]] int getMatrixRand() const;
    [[nodiscard]] int getAppleRand() const;
    void addSnake(int position);
    void removeSnake(int position);
    void checkPosition();
    void printTable() const;
    void exitSession(bool status) {}; //TODO
public:
    Session(int size, bool gui, bool log, string session_name);
    Session(int size, string log_path);
    void init();
    void init(int position);
    void step(LogType data);
    bool move(Action action);
    void spawnApple();
    void spawnApple(int location);
    void updateWindow() const;
    bool onClick(Action action) override;
};

struct LogReplayVisitor {
    Session *session_;

    bool operator()(Action action) const;
    bool operator()(SpawnSnake location) const;
    bool operator()(SpawnApple location) const;
};