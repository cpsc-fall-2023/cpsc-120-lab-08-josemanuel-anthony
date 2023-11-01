// Anthony Moore
// AntMoore@csu.fullerton.edu
// @anthonymmoore
// Partners: @JosemSandoval

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments{argv, argv + argc};

  if (arguments.size() <= 1) {
    std::cerr << "error: you must supply at least one number" << std::endl;
    return 1;
  }

  double sum = 0.0;
  int count = 0;

  for (int i = 1; i < arguments.size(); i++) {
    try {
      double value = std::stod(arguments[i]);
      sum += value;
      count++;
    } catch (std::invalid_argument& e) {
      std::cerr << "error: invalid input at argument " << i << std::endl;
      return 1;
    } catch (std::out_of_range& e) {
      std::cerr << "error: argument " << i << "is out of range" << std::endl;
      return 1;
    }
  }

  double average = sum / count;

  std::cout << "average = " << average << std::endl;
  return 0;
}
