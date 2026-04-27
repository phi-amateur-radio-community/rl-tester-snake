// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/util/UnorderList.hpp
// Header file of disordered list.

#pragma once

#include <vector>

using namespace std;

class UnorderedList {
    vector<int> index_;
public:
    vector<int> data_;
    explicit UnorderedList(size_t size);
    void push(int value);
    void pop(int value);
};
