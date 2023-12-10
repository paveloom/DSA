#!/usr/bin/env bash

mapfile -t SOURCES < <(
  find \
    "$MESON_PROJECT_SOURCE_ROOT/src" \
    -type f \
    -name "*.cpp" -o -name "*.h")

clang-check --analyze "${SOURCES[@]}"

cppcheck \
  --check-level=exhaustive \
  --enable=all \
  --inconclusive \
  --quiet \
  --suppressions-list="$MESON_PROJECT_SOURCE_ROOT"/.cppcheck \
  --verbose \
  -I "$MESON_CURRENT_BUILD_DIR" \
  -I "$MESON_PROJECT_SOURCE_ROOT" \
  -I "$MESON_PROJECT_SOURCE_ROOT/include" \
  "${SOURCES[@]}"

cpplint --verbose=0 --quiet "${SOURCES[@]}"

clang-tidy --quiet "${SOURCES[@]}"
