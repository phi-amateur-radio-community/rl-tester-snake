// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/core/Session.cpp
// Program session.

#include <core/Session.hpp>

mt19937 rng(random_device{}());

Session::Session(int size, bool gui) : gui_(gui) {
    size_ = size;
    size_square_ = size * size;
    table_ = vector<int>(size_square_);
    empty_list_ = vector<int>(size_square_);
    snake_list_ = vector<int>();
    snake_list_.reserve(size_square_);
    init();
    if (gui) {
        window_ = new GridWidget(size_, table_.data());
    }
}

void Session::init() {
    snake_length_ = 1;
    ranges::fill(table_, 0);
    for (int i = 0; i < size_square_; i++) {
        empty_list_[i] = i;
    }
    const int location = getMatrixRand();
    table_[location] = 1;
    snake_list_.push_back(location);
    empty_list_[location] = empty_list_.back();
    empty_list_.pop_back();
    spawnApple();
}

void Session::spawnApple() {
    int location = getAppleRand();
    table_[empty_list_[location]] = -1;
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
