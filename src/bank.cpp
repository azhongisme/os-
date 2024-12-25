#include "bank.h"
#include <assert.h>

BankAlgorithm::BankAlgorithm(const std::string name, const std::vector<int64_t> m, const std::vector<int64_t> allo) 
  : name_(name), max_(m), allocation_(allo) {
    for (size_t i = 0; i < max_.size(); i++) {
      need_.push_back(max_[i] - allocation_[i]);
    }
  }

void BankAlgorithm::UpdateAllocaltion(const std::vector<int64_t> a) { allocation_ = a; }

std::vector<int64_t>& BankAlgorithm::GetAvailable() { return available_; }

void BankAlgorithm::UpdateAvailable() {
  auto a = GetAvailable();
  for (size_t i = 0; i < BankAlgorithm::available_.size(); i++) {
    available_[i] += allocation_[i];
  }
  allocation_.clear();
  need_.clear();
  max_.clear();
}

void BankAlgorithm::SetAvailable(const std::vector<int64_t> a) { available_ = a; }

void BankAlgorithm::SetResource(const std::vector<int64_t> r) { resource_ = r; }

void BankAlgorithm::Print() {
  if (!max_.empty()) {
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
}

void BankAlgorithm::Show(std::vector<BankAlgorithm> b) {
  if (!resource_.empty()) {
    std::cout << "资源总数：";
    for (size_t i = 0; i < BankAlgorithm::resource_.size(); i++) {
      std::cout << BankAlgorithm::resource_[i] << " ";
    }
    std::cout << "\n";
  } else {
    std::cout << "未初始化\n";
  }

  if (!b.empty()) {
    std::cout << "每个进程详情\n";
    for (size_t i = 0; i < b.size(); i++) {
      b[i].Print();
    }
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

bool BankAlgorithm::IsFinished() { return is_finished_; }

std::vector<int64_t> BankAlgorithm::GetNeed() { return need_; }

void BankAlgorithm::SetFinish() { is_finished_ = true; }

std::string BankAlgorithm::GetName() { return name_; }

void BankAlgorithm::Request(const std::vector<int64_t> r) {
  for (size_t i = 0; i < r.size(); i++) {
    assert(need_[i] >= r[i]);
  }
  for (size_t i = 0; i < r.size(); i++) {
    need_[i] -= r[i];
    available_[i] -= r[i];
    allocation_[i] += r[i];
  }
}
