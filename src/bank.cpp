#include "bank.h"



void BankAlgorithm::UpdateAllocaltion(const std::vector<int64_t> a) {
  allocation_ = a;
}

std::vector<int64_t>& BankAlgorithm::GetAvailable() {
  return available_;
}

void BankAlgorithm::UpdateAvailable() {
  auto a = GetAvailable();
  for (size_t i = 0; i < BankAlgorithm::available_.size(); i++) {
    available_[i] += allocation_[i];
  }
}

void BankAlgorithm::SetAvailable(const std::vector<int64_t> a) {
  available_ = a;
}

void BankAlgorithm::SetResource(const std::vector<int64_t> r) {
  resource_ = r;
}

void BankAlgorithm::Print() {
  std::cout << "process: " << name_ << " max: ";
  for (auto i : max_) {
    std::cout << i << " ";
  }
  std::cout << "allocation: ";
  for (auto i : allocation_) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

void BankAlgorithm::Show(std::vector<BankAlgorithm> b) {
  for (auto item : b) {
    item.Print();
  }
}

void BankAlgorithm::InitAvailable(int n) {
  std::vector<int64_t>a;
  while (n--) {
    int64_t x;
    std::cin >> x;
    a.push_back(x);
  }
  BankAlgorithm::SetAvailable(a);
}

void BankAlgorithm::InitResource(int n) {
  std::vector<int64_t>r;
  while (n--) {
    int64_t x;
    std::cin >> x;
    r.push_back(x);
  }
  BankAlgorithm::SetResource(r);
}