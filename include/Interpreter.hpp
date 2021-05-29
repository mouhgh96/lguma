#pragma once
#include "Ast.hpp"
#include "Env.hpp"
#include <memory>

class Interpreter {

public:
  Interpreter(std::unique_ptr<AstNode> program, Env &global_env)
      : m_program{std::move(program)}, m_global_env{global_env} {};

private:
  std::unique_ptr<AstNode> m_program;
  Env &m_global_env;
};
