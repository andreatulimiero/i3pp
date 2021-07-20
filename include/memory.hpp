/*
 * vim:ts=4:sw=4:expandtab
 *
 * i3 - an improved dynamic tiling window manager
 * © 2009 Michael Stapelberg and contributors (see also: LICENSE)
 *
 */
#pragma once

#include <new>

template<typename DataType>
DataType *create_struct() {
  auto mem = malloc(sizeof(DataType));
  return new (mem) DataType{};
}
template<typename DataType>
DataType *create_struct(const std::size_t size) {
  auto mem = malloc(sizeof(DataType)*size);
  return static_cast<DataType*>(new (mem) DataType[size]);
}
