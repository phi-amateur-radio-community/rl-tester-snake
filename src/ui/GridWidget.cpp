// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/ui/GridWidget.cpp
// Grid layout widget.

#include <ui/GridWidget.hpp>
#include <QPainter>

GridWidget::GridWidget(const int size, QWidget* parent) : QWidget(parent) {
    size_ = size;
    this->setFixedSize(size_*30, size_*30);
    this->update();
    this->show();
}

void GridWidget::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    p.fillRect(this->rect(), BACKGROUND_COLOR);
}