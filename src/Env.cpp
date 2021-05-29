#include "Env.hpp"


bool Env::insert(const std::string_view key, Value *value)
{
  if(m_map.contains(key))
    {
      return false;
    }else
    {
      m_map[key] = value;
      return true;
    }

}

Value *Env::get(const std::string_view key)
{
  auto it = m_map.find(key);
  if(it == m_map.end())
    {
      return m_parent == nullptr ? nullptr : m_parent->get(key);
    }else
    {
      return it->second;
    }
}

Env::~Env()
{
  /*
   *  TODO: lunch garbage collection for the current scope
   *
   * */
}
