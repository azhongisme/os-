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

  std::cout << "please input " << m << "nums to init available\n";
  BankAlgorithm::InitAvailable(m);

  std::cout << "please input m nums to init the CPU resource\n";
  BankAlgorithm::InitResource(m);

  std::cout << "please init process details\n";
  std::cout << "请输入" << n << "个进程名\n";
  std::vector<std::string>name;
  for (int i = 0; i < n; i++) {
    std::string temp;
    std::cin >> temp;
    name.push_back(temp);
  }

  std::vector<std::vector<int64_t>> max_;
  std::vector<std::vector<int64_t>> allocation_;

  std::cout << "请输入" << n << "个进程的max\n";
  for (size_t i = 0 ; i < n; i++) {
    std::cout << name[i] << ": ";
    std::vector<int64_t> v;
    for (size_t j = 0; j < m; j++) {
      int64_t x;
      std::cin >> x;
      v.push_back(x);
    }
    max_.push_back(v);
  }

  std::cout << "请输入" << n << "个进程的allocation\n";
  for (size_t i = 0 ; i < n; i++) {
    std::cout << name[i] << ": ";
    std::vector<int64_t> v;
    for (size_t j = 0; j < m; j++) {
      int64_t x;
      std::cin >> x;
      v.push_back(x);
    }
    allocation_.push_back(v);
  }

  for (int i = 0 ; i < n; i++) {
    bank.push_back(BankAlgorithm{name[i], max_[i], allocation_[i]});
  }

  BankAlgorithm::Show(bank);

  auto order = FindTheResult(bank);
  if (order == std::nullopt) {
    std::cout << "there can't find a way to finish these process\n";
  } else {
    std::cout << order.value() << std::endl;
  }

}