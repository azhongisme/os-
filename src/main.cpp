#include "bank.h"
#include <cassert>

std::vector<int64_t> BankAlgorithm::available_;
std::vector<int64_t> BankAlgorithm::resource_;

std::vector<BankAlgorithm> bank;
std::vector<BankAlgorithm> bank_;


void menu() {
  std::cout << "*****************************\n";
  std::cout << "1. 查看系统当前资源使用情况\n";
  std::cout << "2. 分析当前系统安全性\n";
  std::cout << "3. 分配资源\n";
  std::cout << "4. 重新生成系统资源数据\n";
  std::cout << "0. 退出程序\n";
  std::cout << "*****************************\n";
  std::cout << "请选择：\n";
}

void allocate(int& n, int& m) {
  std::cout << "请输入进程数\n";
  std::cin >> n;
  if (!n) {
    return;
  }
  std::cout << "请输入资源类数\n";
  std::cin >> m;
  std::cout << "请输入available\n";
  BankAlgorithm::InitAvailable(m);
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
      assert(x <= max_[i][j]);
      v.push_back(x);
    }
    allocation_.push_back(v);
  }

  std::vector<int64_t> r;
  std::vector<int64_t> a = BankAlgorithm::GetAvailable();

  for (int i = 0 ; i < n; i++) {
    bank.push_back(BankAlgorithm{name[i], max_[i], allocation_[i]});
  }

  for (size_t i = 0; i < m; i++) {
    int64_t temp = 0;
    for (size_t j = 0; j < n; j++) {
      temp += allocation_[j][i];
    }
    r.push_back(temp + a[i]);
  }

  BankAlgorithm::SetResource(r);
  bank_ = bank;
}

void choose() {
  int x;
  std::cin >> x;
  int n, m;
  std::optional<std::string> order;
  std::string str;
  switch(x) {
    case 0: exit(0);
    case 1: 
      BankAlgorithm::Show(bank);
      break;
    case 2:
      order = FindTheResult(bank);
      str = order == std::nullopt ? "找不到安全序列" :  order.value();
      std::cout << str << std::endl;
      if (order) {
        bank.clear();
        bank_.clear();
      }
      break;
    case 3:
      allocate(n, m);
      break;
    case 4:
      BankAlgorithm::Show(bank_);
      break;
    default:
      std::cout << "请重新输入\n";
  }
} 

int main() {
  menu();
  while(true) {
    choose();
  }
}