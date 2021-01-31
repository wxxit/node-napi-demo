#include <string>

class Car {
public:
  virtual ~Car() = default;
  virtual std::string Name() = 0;
  virtual std::string Country() = 0;
};