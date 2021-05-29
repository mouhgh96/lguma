#pragma once

#define NON_COPYABLE(class)\
  class(const class&) = delete;\
  class& operator=(const class&) = delete;

