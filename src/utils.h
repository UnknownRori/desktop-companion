/*
 * Copyright (c) 2026 UnknownRori
 * Licensed under the PolyForm Noncommercial License 1.0.0
 * See LICENSE file in repository root for full terms.
 */

#pragma once

#include <raylib.h>

#define VEC2(X, Y)       (Vector2) {(X), (Y)}
#define VEC2_ZERO        (Vector2) {0, 0}
#define RECT(X, Y, W, H) (Rectangle) {(X), (Y), (W), (H)}
#define HAS(bit, flag)   (((bit) & (flag)) == (flag))
#define ARRAY_LEN(X)     (sizeof((X)) / sizeof((X)[0]))
