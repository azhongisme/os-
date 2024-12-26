#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include <iostream>
#include <optional>

class BankAlgorithm {
private:
  std::string name_;
  std::vector<int64_t> max_;
  std::vector<int64_t> allocation_;
  std::vector<int64_t> need_;
  bool is_finished_{false}; 
  static std::vector<int64_t> available_;
  static std::vector<int64_t> resource_;

public:
  BankAlgorithm() = delete;
  
  BankAlgorithm(const std::string name, const std::vector<int64_t> m, const std::vector<int64_t> allo);
  
  ~ BankAlgorithm() = default;

  void UpdateAllocaltion(const std::vector<int64_t> a);
  
  //Finish a process
  void UpdateAvailable();

  static std::vector<int64_t>& GetAvailable();

  static void SetAvailable(const std::vector<int64_t> a);

  static void SetResource(const std::vector<int64_t> a);

  static void InitAvailable(int n);

  static void InitResource(int n);

  void Print();

  static void Show(std::vector<BankAlgorithm> b);

  bool IsFinished();

  void SetFinish();

  void Request(const std::vector<int64_t> r);

  std::vector<int64_t> GetNeed();

  std::string GetName();

};

inline bool AllIsFinished(std::vector<BankAlgorithm> &b) {
  for (size_t i = 0 ; i < b.size(); i++) {
      if (!b[i].IsFinished()) {
        return false;
    }
  }
  return true;
}

inline std::pair<bool, int> IsSafe(std::vector<BankAlgorithm> &b, int index) {
  if (AllIsFinished(b)) {
    return std::make_pair(true, -1);
  }

  for (size_t i = index + 1; i < b.size(); i++) {
    if (b[i].IsFinished()) {
      continue;
    }
    auto need = b[i].GetNeed();
    auto available = BankAlgorithm::GetAvailable();
    for (size_t j = 0; j < need.size(); j++) {
      if (need[j] > available[j]) {
        break;
      }
      if (j == need.size() - 1) {
        return std::make_pair(true, i);
      }
    }
  }

  for (size_t i = 0; i < index && index >= 0; i++) {
    if (b[i].IsFinished()) {
      continue;
    }
    auto need = b[i].GetNeed();
    auto available = BankAlgorithm::GetAvailable();
    for (size_t j = 0; j < need.size(); j++) {
      if (need[j] > available[j]) {
        break;
      }
      if (j == need.size() - 1) {
        return std::make_pair(true, i);
      }
    }
  }
  
  return std::make_pair(false, -1);
}

inline std::optional<std::string> FindTheResult(std::vector<BankAlgorithm> &b) {
  std::string order = "process order: ";
  auto res = IsSafe(b, -1);

  while (res.first && res.second != -1) {
    int index = res.second;
    b[index].SetFinish();
    b[index].UpdateAvailable();
    order += b[index].GetName() + " ";
    res = IsSafe(b, res.second);
  }
  if (!res.first) {
    return std::nullopt;
  }
  return order;
}



#endif