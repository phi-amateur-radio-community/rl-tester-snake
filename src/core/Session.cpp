// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/core/Session.cpp
// Program session.

#include <core/Session.hpp>
#include <random>
#include <iostream>
#include <utility>

mt19937 rng(random_device{}());

Session::Session(const int size, const bool gui, const bool log, string session_name)
    : size_(size)
    , size_square_(size * size)
    , empty_list_(size_square_)
    , snake_list_(size_square_)
    , gui_(gui)
    , replay_(false)
    , session_name_(std::move(session_name))
    , logger_(session_name_ + ".parl.log", log)
{
    table_ = vector<int>(size_square_);
    if (gui) {
        window_ = new GridWidget(size_, table_.data());
        window_->key_call_back_ = this;
    }
}

Session::Session(const int size, string log_path)
    : size_(size)
    , size_square_(size * size)
    , empty_list_(size_square_)
    , snake_list_(size_square_)
    , gui_(false)
    , replay_(true)
    , session_name_(std::move(log_path))
    , logger_(log_path)
{
    table_ = vector<int>(size_square_);
    window_ = new GridWidget(size_, table_.data());
    window_->key_call_back_ = this;
}

void Session::init() {
    init(getMatrixRand());
    spawnApple();
}

void Session::init(const int position) {
    snake_length_ = 1;
    ranges::fill(table_, 0);
    for (int i = 0; i < size_square_; i++) {
        empty_list_.push(i);
    }
    logger_.write(SpawnSnake(position));
    head_position_ = position;
    table_[position] = 1;
    snake_list_.push(position);
    empty_list_.pop(position);
}

struct LogReplayVisitor {
    Session *session_;

    bool operator()(const Action action) const {
        return session_->move(action);
    }

    bool operator()(const SpawnSnake location) const {
        session_->init(location.position);
        return true;
    }

    bool operator()(const SpawnApple location) const {
        session_->spawnApple(location.position);
        return true;
    }
};

void Session::step(LogType data) {
    visit(LogReplayVisitor{this}, data);
}

bool Session::move(const Action action) {
    logger_.write(action);
    switch (action) {
        case Action::Up:
            if (head_position_ % size_ == 0) {
                return false;
            }
            head_position_--;
            break;
        case Action::Down:
            if ((head_position_ + 1) % size_ == 0) {
                return false;
            }
            head_position_++;
            break;
        case Action::Right:
            if (head_position_ + size_ >= size_square_) {
                return false;
            }
            head_position_ += size_;
            break;
        case Action::Left:
            if (head_position_ < size_) {
                return false;
            }
            head_position_ -= size_;
            break;
    }
    checkPosition();
    updateWindow();
    return true;
}

void Session::spawnApple() {
    spawnApple(getAppleRand());
}

void Session::spawnApple(const int location) {
    table_[empty_list_.data_[location]] = -1;
    logger_.write(SpawnApple(location));
}

int Session::getRand() const {
    uniform_int_distribution dist(0, size_);
    return dist(rng);
}

int Session::getMatrixRand() const {
    uniform_int_distribution dist(0, size_square_);
    return dist(rng);
}

int Session::getAppleRand() const {
    uniform_int_distribution dist(0, size_square_ - snake_length_);
    return dist(rng);
}

void Session::updateWindow() const {
    if (gui_) {
        window_->update();
    }
}

void Session::printTable() const {
    for (int i = 0; i < size_; i++) {
        for (int j = 0; j < size_; j++) {
            cout << format("{:05} ", table_[j * size_ + i]);
        }
        cout << endl;
    }
}

bool Session::onClick(const Action action) {
    return this->move(action);
}

void Session::addSnake(const int position) {
    snake_list_.push(position);
    empty_list_.pop(position);
}

void Session::removeSnake(const int position) {
    empty_list_.push(position);
    snake_list_.pop(position);
}

void Session::checkPosition() {
    if (table_[head_position_] == -1) {
        table_[head_position_] = ++snake_length_;
        if (snake_length_ == size_square_) {
            exitSession(true);
        }
        addSnake(head_position_);
        spawnApple();
    } else if (table_[head_position_] > 0) {
        exitSession(false);
    } else {
        for (const int& i : snake_list_.data_) {
            if (--table_[i] == 0) {
                removeSnake(i);
            }
        }
        table_[head_position_] = snake_length_;
        addSnake(head_position_);
    }
}