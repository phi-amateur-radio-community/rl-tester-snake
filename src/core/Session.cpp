// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/core/Session.cpp
// Program session.

#include <core/Session.hpp>
#include <random>
#include <iostream>

mt19937 rng(random_device{}());

Session::Session(int size, const bool gui) : size_square_(size * size), empty_list_(size_square_), snake_list_(size_square_), gui_(gui) {
    size_ = size;
    table_ = vector<int>(size_square_);
    if (gui) {
        window_ = new GridWidget(size_, table_.data());
        window_->key_call_back_ = this;
    }
}

void Session::init() {
    snake_length_ = 1;
    ranges::fill(table_, 0);
    for (int i = 0; i < size_square_; i++) {
        empty_list_.push(i);
    }
    const int location = getMatrixRand();
    head_position_ = location;
    table_[location] = 1;
    snake_list_.push(location);
    empty_list_.pop(location);
    spawnApple();
}

bool Session::move(const Action action) {
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
    const int location = getAppleRand();
    table_[empty_list_.data_[location]] = -1;
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