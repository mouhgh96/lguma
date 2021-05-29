#pragma once
#include <unordered_map>
#include <string_view>
#include "Value.hpp"


class Env {

public:
  Env(Env* parent = nullptr):
    m_parent{parent}{};
  bool insert(const std::string_view key, Value* value);
  Value* get(const std::string_view key);
  ~Env();
private:
  std::unordered_map<std::string_view, Value*> m_map;
  Env* m_parent;
};
