#include "bank.h"

std::vector<int64_t> BankAlgorithm::available_;
std::vector<int64_t> BankAlgorithm::resource_; 

int main() {
  std::vector<BankAlgorithm> bank;
  std::cout << "please input how many process\n";
  int n;
  std::cin >> n;

  std::cout << "please input the kinds of resources\n";
  int m;
  std::cin >> m;

  std::cout << "please input m nums to init available\n";
  BankAlgorithm::InitAvailable(m);

  std::cout << "please input m nums to init the CPU resource\n";
  BankAlgorithm::InitResource(m);

  std::cout << "please init process details\n";
  while (n--) {
    std::cout << "please input process name\n";
    std::string name;
    std::cin >> name;


    std::cout << "please input process max\n";
    std::vector<int64_t> maxn;
    for (size_t i = 0; i < m; i++) {
      int64_t x;
      std::cin >> x;
      maxn.push_back(x);
    }

    std::cout << "please input process allocation\n";

    std::vector<int64_t> a;
    for (size_t i = 0; i < m; i++) {
      int64_t x;
      std::cin >> x;
      a.push_back(x);
    }
    BankAlgorithm b{name, maxn, a};
    bank.push_back(b);
  }

  BankAlgorithm::Show(bank);
}