// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/util/UnorderList.cpp
// High-efficiency disordered list.

#include <algorithm>
#include <util/UnorderList.hpp>

UnorderedList::UnorderedList(const size_t size) {
    data_.reserve(size);
    index_.resize(size);
    ranges::fill(index_.begin(), index_.end(), -1);
}

void UnorderedList::push(const int value) {
    if (value >= index_.size()) {
        return;
    }
    index_[value] = static_cast<int>(data_.size());
    data_.push_back(value);
}

void UnorderedList::pop(const int value) {
    if (value >= index_.size() || value < 0) {
        return;
    }
    data_[index_[value]] = data_.back();
    index_[data_.back()] = index_[value];
    data_.pop_back();
    index_[value] = -1;
}